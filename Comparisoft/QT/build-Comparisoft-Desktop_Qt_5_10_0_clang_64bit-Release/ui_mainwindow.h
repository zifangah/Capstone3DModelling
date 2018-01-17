/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *ReferanceFileText;
    QPushButton *Referance_File_Button;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *ProductionFileText;
    QPushButton *Production_File_Button;
    QPushButton *RunVTK;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1269, 683);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 771, 451));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        ReferanceFileText = new QLineEdit(verticalLayoutWidget);
        ReferanceFileText->setObjectName(QStringLiteral("ReferanceFileText"));

        horizontalLayout->addWidget(ReferanceFileText);

        Referance_File_Button = new QPushButton(verticalLayoutWidget);
        Referance_File_Button->setObjectName(QStringLiteral("Referance_File_Button"));

        horizontalLayout->addWidget(Referance_File_Button);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        ProductionFileText = new QLineEdit(verticalLayoutWidget);
        ProductionFileText->setObjectName(QStringLiteral("ProductionFileText"));

        horizontalLayout_2->addWidget(ProductionFileText);

        Production_File_Button = new QPushButton(verticalLayoutWidget);
        Production_File_Button->setObjectName(QStringLiteral("Production_File_Button"));

        horizontalLayout_2->addWidget(Production_File_Button);


        verticalLayout->addLayout(horizontalLayout_2);

        RunVTK = new QPushButton(verticalLayoutWidget);
        RunVTK->setObjectName(QStringLiteral("RunVTK"));

        verticalLayout->addWidget(RunVTK);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1269, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        Referance_File_Button->setText(QApplication::translate("MainWindow", "Referance File", nullptr));
        Production_File_Button->setText(QApplication::translate("MainWindow", "Prodiction File", nullptr));
        RunVTK->setText(QApplication::translate("MainWindow", "Run VTK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
