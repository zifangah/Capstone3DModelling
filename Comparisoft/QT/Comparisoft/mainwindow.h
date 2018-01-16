#pragma once

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    struct userInfo {
        QString client;
        QString patient;
        QString fileDescription;
    };

private slots:
    void on_RunVTK_clicked();

    void on_Reference_File_Button_clicked();

    void on_Production_File_Button_clicked();

    QString fileDialog();

    void on_Config_Button_clicked();

    void on_ReturnToMainPage_clicked();

    void on_Settings_Button_clicked();

    void on_Settings_Button_2_clicked();

    void on_Return_to_Setup_Button_clicked();

    void on_Return_to_Configuration_Button_clicked();

private:
    Ui::MainWindow *ui;
};

// MAINWINDOW_H
