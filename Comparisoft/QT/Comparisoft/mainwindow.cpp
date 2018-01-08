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
    QLineEdit* fileReferance = findChild<QLineEdit*>("Referance_File_Text");
    QLineEdit* fileProduction = findChild<QLineEdit*>("Production_File_Text");
    argv << fileReferance->text() << fileProduction->text();

    QProcess *VTK = new QProcess(parent);
    VTK->start(program, argv);
    VTK->waitForStarted();
    window()->hide();
    VTK->waitForFinished();
    window()->show();
    VTK->close();

}


void MainWindow::on_Referance_File_Button_clicked()
{
    QString filepathR = fileDialog();
    QLineEdit* fileReferance = findChild<QLineEdit*>("Referance_File_Text");
    fileReferance->setText(filepathR);
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

void MainWindow::on_Settings_Button_clicked()
{

}

void MainWindow::on_Config_Button_clicked()
{
    QStackedWidget* view_holder = findChild<QStackedWidget*>("View_Holder");
    view_holder->setCurrentIndex(1);
}
