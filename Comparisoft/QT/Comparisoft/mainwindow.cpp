#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include <QFileDialog>
#include <QDebug>

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
    QTextEdit* fileProduction = findChild<QTextEdit*>("Production_File_Text");
    argv << fileReference->text();
    QString productionfiles = fileProduction->toPlainText();
    //qInfo() << productionfiles;
    QStringList pFileList = productionfiles.split(QRegularExpression("\n"),QString::SkipEmptyParts);
    foreach(QString line, pFileList){
        //qInfo() << line;
        argv << line;
    }

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
}

void MainWindow::on_Production_File_Button_clicked()
{
    QStringList filepathPlist = fileDialogMulti();
    QTextEdit* fileProduction = findChild<QTextEdit*>("Production_File_Text");
    foreach (QString filepath, filepathPlist) {
        fileProduction->append(filepath);
    }

}

QString MainWindow::fileDialog()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Select File"), "", tr("STL (*.stl)"));
    return filename;
}

QStringList MainWindow::fileDialogMulti()
{
    QStringList filenames = QFileDialog::getOpenFileNames(this, tr("Select File"), "", tr("STL (*.stl)"));
    return filenames;
}

void MainWindow::on_Config_Button_clicked()
{
    QStackedWidget* view_holder = findChild<QStackedWidget*>("View_Holder");
    view_holder->setCurrentIndex(1);
}

void MainWindow::on_ReturnToMainPage_clicked()
{
    QStackedWidget* view_holder = findChild<QStackedWidget*>("View_Holder");
    view_holder->setCurrentIndex(0);
}

void MainWindow::on_Settings_Button_clicked()
{
    QStackedWidget* view_holder = findChild<QStackedWidget*>("View_Holder");
    view_holder->setCurrentIndex(2);
}

void MainWindow::on_Settings_Button_2_clicked()
{
    QStackedWidget* view_holder = findChild<QStackedWidget*>("View_Holder");
    view_holder->setCurrentIndex(2);
}

void MainWindow::on_Return_to_Setup_Button_clicked()
{
    QStackedWidget* view_holder = findChild<QStackedWidget*>("View_Holder");
    view_holder->setCurrentIndex(0);
}

void MainWindow::on_Return_to_Configuration_Button_clicked()
{
    QStackedWidget* view_holder = findChild<QStackedWidget*>("View_Holder");
    view_holder->setCurrentIndex(1);
}

void MainWindow::on_Clear_Production_Files_clicked()
{
    QTextEdit* fileProduction = findChild<QTextEdit*>("Production_File_Text");
    fileProduction->clear();
}
