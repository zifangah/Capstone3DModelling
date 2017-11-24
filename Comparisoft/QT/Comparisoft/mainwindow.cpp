#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
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
    argv << "VSVTK.exe" << "lowerModel.stl" << "upperModel.stl";

    QProcess *VTK = new QProcess(parent);
    VTK->start(program, argv);
    VTK->waitForStarted();
    window()->hide();
    VTK->waitForFinished();
    window()->show();
    VTK->close();

}
