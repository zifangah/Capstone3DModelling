#pragma once
class MainWindow : public QMainWindow
{
	Q_OBJECT
public: MainWindow();
protected: void closeEvent(QCloseEvent *event);
};