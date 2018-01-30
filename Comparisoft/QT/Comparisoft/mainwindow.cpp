#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include <QFileDialog>
#include <QDebug>
#include <QDate>
#include <QMessageBox>
#include <iostream>
#include <fstream>
using namespace std;

/* Mac/Linux environment detected */
#if !defined(_WIN32)
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <dirent.h>
/* Windows environment detected */
#else
    #include <direct.h>
    #include <windows.h>
    #include <io.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <tchar.h>
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
    QString copy = rFilePath;
    int final_pos;
    int pos = copy.indexOf("/") + 1;
    final_pos = pos;
    copy = copy.mid(pos, copy.length());
    pos = copy.indexOf("/") + 1;
    final_pos += pos;
    copy = copy.mid(pos, copy.length());
    pos = copy.indexOf("/");
    final_pos += pos;
    info.filePath = rFilePath.mid(0, final_pos);

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
    std::string sPath = "/tmp/test";

    //move from setup to config
    QStackedWidget* view_holder = findChild<QStackedWidget*>("View_Holder");

    QString savePath = MainWindow::findChild<QLineEdit*>("Save_Location")->text();

    int error = 0;

    QString rFilePath = MainWindow::findChild<QLineEdit*>("Reference_File_Text")->text();
    QString copy = rFilePath;
    int final_pos;
    int pos = copy.indexOf("/") + 1;
    final_pos = pos;
    copy = copy.mid(pos, copy.length());
    pos = copy.indexOf("/") + 1;
    final_pos += pos;
    copy = copy.mid(pos, copy.length());
    pos = copy.indexOf("/");
    final_pos += pos;
    rFilePath = rFilePath.mid(0, final_pos);

    QString default_path = rFilePath;
    QString home = rFilePath;
    default_path.append("/Comparisoft/Reports/");

    int ret;
    bool cancel = false;
    bool setup_default = false;
    bool exists = false;
    bool empty = false;

    QString path;

    if (savePath.contains(default_path)) {
        path = default_path;
        setup_default = true;
    }

    else {
        path = savePath;
    }

    empty = savePath.trimmed().isEmpty();

    /* Windows environment detected */
    #if defined(_WIN32)
       if (_taccess_s((LPCTSTR) path.toStdString().c_str(), 0 ) == 0) {
            struct _stat status;
            _tstat((LPCTSTR) path.toStdString().c_str(), &status);
            exists = ((status.st_mode & S_IFDIR) != 0);
        }

        else {
            exists = false;
        }

    /* Mac/Linux environment detected */
    #else
        if (opendir(path.toStdString().c_str())) {
            exists = true;
        }
    #endif

    QMessageBox msgBox;

    if (exists == false && !empty) {
        msgBox.setText("The directory specified does not exist.");
        if (setup_default) {
            msgBox.setInformativeText("Do you want to create a new Reports directory?");
        }
        else {
            msgBox.setInformativeText("Do you want to create the specified directory?");
        }
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Ok);
        ret = msgBox.exec();

        bool err = false;

        switch (ret) {
          case QMessageBox::Ok:
            /* For Windows environments */
            #if defined(_WIN32)
                if (setup_default) {
                    error = _mkdir(home.append("/Comparisoft").toStdString().c_str());
                }
                else {
                    error = _mkdir(path.toStdString().c_str());
                }

                /* Error has occurred */
                if (error != 0) {
                    QMessageBox msgBox2;
                    msgBox2.setText("An error occurred creating the directory.");
                    msgBox2.setInformativeText("Please select a different save location.");
                    msgBox2.setStandardButtons(QMessageBox::Ok);
                    msgBox2.setDefaultButton(QMessageBox::Ok);
                    msgBox2.exec();

                    qInfo( "Error occurred creating directory:");
                    perror ("The following error occurred");
                    cancel = true;
                }

                error = _mkdir(home.append("/Reports").toStdString().c_str());

                /* Error has occurred */
                if (error != 0) {
                    QMessageBox msgBox2;
                    msgBox2.setText("An error occurred creating the directory.");
                    msgBox2.setInformativeText("Please select a different save location.");
                    msgBox2.setStandardButtons(QMessageBox::Ok);
                    msgBox2.setDefaultButton(QMessageBox::Ok);
                    msgBox2.exec();

                    qInfo( "Error occurred creating directory:");
                    perror ("The following error occurred");
                    cancel = true;
                }
            /* For Mac/Linux environments */
            #else
                /* Directory does not yet exist */
                if (setup_default) {
                    error = mkdir(home.append("/Comparisoft").toStdString().c_str(), 0777);
                }

                else {
                    error = mkdir(path.toStdString().c_str(), 0777);
                }

                err = false;

                /* Error has occurred */
                if (error != 0) {
                    err = true;

                    QMessageBox msgBox2;
                    msgBox2.setText("An error occurred creating the directory.");
                    msgBox2.setInformativeText("Please select a different save location.");
                    msgBox2.setStandardButtons(QMessageBox::Ok);
                    msgBox2.setDefaultButton(QMessageBox::Ok);
                    msgBox2.exec();

                    qInfo( "Error occurred creating directory:");
                    perror ("The following error occurred");
                    qDebug("Directory: %s", home.toStdString().c_str());
                    cancel = true;
                }

                if (!err) {
                    if (setup_default) {
                        error = mkdir(home.append("/Reports").toStdString().c_str(), 0777);
                    }

                    else {
                        error = mkdir(path.toStdString().c_str(), 0777);
                    }

                    /* Error has occurred */
                    if (error != 0) {
                        QMessageBox msgBox2;
                        msgBox2.setText("An error occurred creating the directory.");
                        msgBox2.setInformativeText("Please select a different save location.");
                        msgBox2.setStandardButtons(QMessageBox::Ok);
                        msgBox2.setDefaultButton(QMessageBox::Ok);
                        msgBox2.exec();

                        qInfo( "Error occurred creating directory:");
                        perror ("The following error occurred");
                        cancel = true;
                    }
                }
            #endif
            break;
          case QMessageBox::Cancel:
              cancel = true;
          default:
              cancel = true;
        }
    }

    /* File path not selected */
    if (savePath.trimmed().isEmpty()) {
        QMessageBox msgBox;
        msgBox.setText("Please select a save location.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        ret = msgBox.exec();
    }

    QString saveFile = MainWindow::findChild<QLineEdit*>("File_Name")->text();
    QString client = MainWindow::findChild<QLineEdit*>("Client_Name")->text();
    QString patient = MainWindow::findChild<QLineEdit*>("Patient_Name")->text();

    ofstream comparison_report;
    QString filepath = savePath;
    filepath.append("/");
    filepath.append(saveFile);
    comparison_report.open (filepath.toLatin1().data());
    comparison_report << "Comparisoft\n";
    comparison_report << "Client: " << client.toStdString() << "\n";
    comparison_report << "Patient: " << patient.toStdString() << "\n";
    comparison_report.close();

    if (!savePath.trimmed().isEmpty() && !cancel) {
        view_holder->setCurrentIndex(1);
    }
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
