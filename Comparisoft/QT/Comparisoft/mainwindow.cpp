#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include <QFileDialog>
#include <QDebug>
#include <QDate>
#include <iostream>
#include <fstream>
using namespace std;

#if !defined(_WIN32)
    #include <sys/stat.h>
#endif

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QString refFile;
    QString prodFile;
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_RunVTK_clicked()
{
    QObject *parent;

    QString program = "./VSVTK.exe";
    QStringList argv;
    QLineEdit* fileReference = findChild<QLineEdit*>("Reference_File_Text");
    QLineEdit* fileProduction = findChild<QLineEdit*>("Production_File_Text");
    argv << fileReference->text() << fileProduction->text();

    QProcess *VTK = new QProcess(parent);
    VTK->start(program, argv);
    VTK->waitForStarted();
    window()->hide();
    VTK->waitForFinished();
    window()->show();
    VTK->close();

}

MainWindow::userInfo getInfoFields(QString rFilePath) {

    MainWindow::userInfo info;

    /* Save beginning of filepath for determining save location */
    info.filePath = rFilePath.mid(0, rFilePath.indexOf("/", rFilePath.indexOf("/") + 1));

    /* Parse file path to find client name */
    /* Assumption: client name in format of Dr.Name */
    rFilePath = rFilePath.mid(rFilePath.lastIndexOf("/") + 1, rFilePath.length());
    QString client = rFilePath.left(rFilePath.indexOf("_"));
    info.client = client.left(client.indexOf(".") + 1);
    client = client.mid(client.indexOf(".") + 1, client.length());
    info.client.append(" " + client);

    /* Parse file path to find patient name */
    /* Assumption: patient name in format Last_First */
    rFilePath = rFilePath.mid(rFilePath.indexOf("_") + 1, rFilePath.length());
    QString patient_last = rFilePath.mid(0, rFilePath.indexOf("_"));
    rFilePath = rFilePath.mid(rFilePath.indexOf("_") + 1, rFilePath.length());
    QString patient_first = rFilePath.mid(0, rFilePath.indexOf("_"));
    info.patient = patient_first;
    info.patient.append(" " + patient_last);

    /* Parse file path to find file description */
    /* Assumption: file description exists following a space after file time */
    rFilePath = rFilePath.mid(rFilePath.indexOf("_") + 1, rFilePath.length());

    if (rFilePath.contains(".")) {
        rFilePath = rFilePath.mid(rFilePath.indexOf(" ") + 1, rFilePath.length());
        info.fileDescription = rFilePath.left(rFilePath.indexOf("."));
    }
    else {
        info.fileDescription = rFilePath.mid(rFilePath.indexOf(" ") + 1, rFilePath.length());
    }

    return info;
}

void MainWindow::on_Reference_File_Button_clicked()
{
    QString filepathR = fileDialog();
    QLineEdit* fileReference = findChild<QLineEdit*>("Reference_File_Text");
    fileReference->setText(filepathR);

    MainWindow::userInfo info = getInfoFields(fileReference->text());

    QLineEdit* clientRef = MainWindow::findChild<QLineEdit*>("Client_Name");
    clientRef->setText(info.client);
    QLineEdit* patientRef = MainWindow::findChild<QLineEdit*>("Patient_Name");
    patientRef->setText(info.patient);
    QLineEdit* fileDescRef = MainWindow::findChild<QLineEdit*>("File_Description");
    fileDescRef->setText(info.fileDescription);

    QLineEdit* savePath = MainWindow::findChild<QLineEdit*>("Save_Location");
    savePath->setText(info.filePath + "/Comparisoft/Reports/");

    QLineEdit* saveFile = MainWindow::findChild<QLineEdit*>("File_Name");
    QDate date = QDate::currentDate();
    QString newFileName = "Report_";
    newFileName.append(QString::number(date.year()));
    newFileName.append("-");
    newFileName.append(QString::number(date.month()));
    newFileName.append("-");
    newFileName.append(QString::number(date.day()));
    newFileName.append("_");
    newFileName.append(info.client.replace(" ", ""));
    newFileName.append("_");
    newFileName.append(info.patient.replace(" ", ""));
    newFileName.append("_");
    newFileName.append(info.fileDescription.replace(" ", ""));
    newFileName.append(".txt");
    saveFile->setText(newFileName);
}

void MainWindow::on_Production_File_Button_clicked()
{
    QString filepathP = fileDialog();
    QLineEdit* fileProduction = findChild<QLineEdit*>("Production_File_Text");
    fileProduction->setText(filepathP);
}

QString MainWindow::fileDialog()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Select File"), "", tr("STL (*.stl)"));
    return filename;
}

void MainWindow::on_Config_Button_clicked()
{
    QStackedWidget* view_holder = findChild<QStackedWidget*>("View_Holder");
    view_holder->setCurrentIndex(1);

    std::string sPath = "/tmp/test";

    QString savePath = MainWindow::findChild<QLineEdit*>("Save_Location")->text();

    mode_t u_mode = 0733;
    int error = 0;

    /* For Windows environments */
    #if defined(_WIN32)
        error = _mkdir(savePath.toStdString().c_str());
    #else
        error = mkdir(savePath.toStdString().c_str(), u_mode);
    #endif

    /* Error has occurred */
    if (error != 0) {
    }

    QString saveFile = MainWindow::findChild<QLineEdit*>("File_Name")->text();
    ofstream comparison_report;
    QString filepath = savePath;
    filepath.append("/");
    filepath.append(saveFile);
    comparison_report.open (filepath.toLatin1().data());
    comparison_report << "Writing this to a file.\n";
    comparison_report.close();
}

void MainWindow::on_saveLocation_clicked()
{
    QString fileSavePath = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "", QFileDialog::ShowDirsOnly);
    QLineEdit* fileSave = findChild<QLineEdit*>("Save_Location");
    fileSave->setText(fileSavePath);
}
