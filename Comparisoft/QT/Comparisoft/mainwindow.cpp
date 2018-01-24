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
    #include <sys/types.h>
    #include <sys/stat.h>
#else
    #include <direct.h>
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

    //create argument list
    QStringList argv;

    //argument 0: program name
    //this is done automatically

    //argument 1: Client_Name
    QLineEdit* cname = findChild<QLineEdit*>("Client_Name");
    argv << cname->text();

    //argument 2: Patient_Name
    QLineEdit* pname = findChild<QLineEdit*>("Patient_Name");
    argv << pname->text();

    //argument 3: File_Description
    QLineEdit* fdesc = findChild<QLineEdit*>("File_Description");
    argv << fdesc->text();

    //argument 4: Save_Location
    QLineEdit* sloc = findChild<QLineEdit*>("Save_Location");
    argv << sloc->text();

    //argument 5: File_Name
    QLineEdit* fname = findChild<QLineEdit*>("File_Name");
    argv << fname->text();

    //argument 6: Technician_Name
    QLineEdit* tname = findChild<QLineEdit*>("Technician_Name");
    argv << tname->text();

    //argument 7: Product_Name
    QLineEdit* prodname = findChild<QLineEdit*>("Product_Name");
    argv << prodname->text();

    //argument 8: Production_Date
    QLineEdit* pdate = findChild<QLineEdit*>("Production_Date");
    argv << pdate->text();

    //argument 9: Product_Description
    QTextEdit* pdesc = findChild<QTextEdit*>("Product_Description");
    argv << pdesc->toPlainText();

    //argument 10: Report_Type
    QComboBox* rtype = findChild<QComboBox*>("Report_Type");
    argv << rtype->currentText();

    //argument 11: Confidence_Level
    QSpinBox* clevel = findChild<QSpinBox*>("Confidence_Level");
    argv << clevel->cleanText();

    //argument 12: Error_Bound
    QSpinBox* ebound = findChild<QSpinBox*>("Error_Bound");
    argv << ebound->cleanText();

    //argument 13: Error_Unit
    QComboBox* eunit = findChild<QComboBox*>("Error_Unit");
    argv << eunit->currentText();

    //argument 14: Alignment_Type
    QComboBox* atype = findChild<QComboBox*>("Alignment_Type");
    argv << atype->currentText();

    //argument 15: Ref_Attempt
    QLineEdit* refattempt = findChild<QLineEdit*>("Ref_Attempt");
    argv << refattempt->text();

    //argument 16: Prod_Attempt
    QLineEdit* prodattempt = findChild<QLineEdit*>("Prod_Attempt");
    argv << prodattempt->text();

    //argument 17: referance file
    QLineEdit* fileReference = findChild<QLineEdit*>("Reference_File_Text");
    argv << fileReference->text();

    //argument 18+:production file(s)
    QTextEdit* fileProduction = findChild<QTextEdit*>("Production_File_Text");


    //insert multiple production files
    QString productionfiles = fileProduction->toPlainText();
    QStringList pFileList = productionfiles.split(QRegularExpression("\n"), QString::SkipEmptyParts);
    foreach(QString line, pFileList){
        argv << line;
    }

    //launch the vtk program, then hide the UI until it closes
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
    //get referance file
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
    //get production files
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
    //move from setup to config
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
        qInfo( "Error occurred creating directory: errno:");
        qDebug() << error;
    }

    QString fileReference = findChild<QLineEdit*>("Reference_File_Text")->text();
    MainWindow::userInfo info = getInfoFields(fileReference);

    QString saveFile = MainWindow::findChild<QLineEdit*>("File_Name")->text();
    ofstream comparison_report;
    QString filepath = savePath;
    filepath.append("/");
    filepath.append(saveFile);
    comparison_report.open (filepath.toLatin1().data());
    comparison_report << "Comparisoft\n";
    comparison_report << "Client: " << info.client.toStdString() << "\n";
    comparison_report << "Patient: " << info.patient.toStdString() << "\n";
    comparison_report.close();
}

void MainWindow::on_ReturnToMainPage_clicked()
{
    //Move from config to setup
    QStackedWidget* view_holder = findChild<QStackedWidget*>("View_Holder");
    view_holder->setCurrentIndex(0);
}

void MainWindow::on_Clear_Production_Files_clicked()
{
    //clear the production files
    QTextEdit* fileProduction = findChild<QTextEdit*>("Production_File_Text");
    fileProduction->clear();
}

void MainWindow::on_saveLocationButton_clicked()
{
    //browse for a save location
    QString fileSavePath = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "", QFileDialog::ShowDirsOnly);
    QLineEdit* fileSave = findChild<QLineEdit*>("Save_Location");
    fileSave->setText(fileSavePath);
}
