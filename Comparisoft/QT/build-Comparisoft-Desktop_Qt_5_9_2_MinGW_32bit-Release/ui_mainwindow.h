/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_12;
    QStackedWidget *View_Holder;
    QWidget *Main_Page;
    QVBoxLayout *verticalLayout_13;
    QWidget *widget;
    QVBoxLayout *verticalLayout_14;
    QHBoxLayout *horizontalLayout_6;
    QWidget *widget_5;
    QLabel *Banner;
    QPushButton *Settings_Button;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *Reference_File_Text;
    QSpacerItem *verticalSpacer_6;
    QPushButton *Reference_File_Button;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *Production_File_Text;
    QVBoxLayout *verticalLayout_34;
    QPushButton *Production_File_Button;
    QPushButton *Clear_Production_Files;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *Ref_Attempt;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLineEdit *Prod_Attempt;
    QFrame *line;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_4;
    QLineEdit *Client_Name;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_5;
    QLineEdit *Patient_Name;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_6;
    QLineEdit *File_Description;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_7;
    QLineEdit *Save_Location;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_8;
    QLineEdit *File_Name;
    QVBoxLayout *verticalLayout_10;
    QPushButton *Config_Button;
    QWidget *Config_Page;
    QVBoxLayout *verticalLayout_15;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_16;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *ReturnToMainPage;
    QWidget *widget_6;
    QLabel *Banner_2;
    QWidget *widget_7;
    QPushButton *Settings_Button_2;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_17;
    QLabel *label_15;
    QVBoxLayout *verticalLayout_20;
    QLabel *label;
    QHBoxLayout *horizontalLayout_21;
    QComboBox *Report_Type;
    QHBoxLayout *horizontalLayout_13;
    QVBoxLayout *verticalLayout_21;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_19;
    QSpinBox *Confidence_Level;
    QVBoxLayout *verticalLayout_22;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_12;
    QSpinBox *Error_Bound;
    QComboBox *Error_Unit;
    QHBoxLayout *horizontalLayout_14;
    QVBoxLayout *verticalLayout_23;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout_20;
    QComboBox *Allignment_Type;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_18;
    QLabel *label_16;
    QVBoxLayout *verticalLayout_24;
    QLabel *label_12;
    QLineEdit *Technician_Name;
    QVBoxLayout *verticalLayout_25;
    QLabel *label_13;
    QLineEdit *Product_Name;
    QVBoxLayout *verticalLayout_26;
    QLabel *label_14;
    QLineEdit *Production_Date;
    QVBoxLayout *verticalLayout_19;
    QHBoxLayout *horizontalLayout_18;
    QVBoxLayout *verticalLayout_32;
    QLabel *label_20;
    QPlainTextEdit *Product_Description;
    QVBoxLayout *verticalLayout_33;
    QSpacerItem *verticalSpacer_5;
    QPushButton *RunVTK;
    QWidget *Settings_Page;
    QVBoxLayout *verticalLayout_28;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_27;
    QHBoxLayout *horizontalLayout_15;
    QPushButton *Return_to_Setup_Button;
    QWidget *widget_2;
    QLabel *Banner_3;
    QWidget *widget_8;
    QPushButton *Return_to_Configuration_Button;
    QHBoxLayout *horizontalLayout_16;
    QVBoxLayout *verticalLayout_29;
    QLabel *label_17;
    QLineEdit *Model_Working_Directory;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_30;
    QLabel *label_18;
    QLineEdit *Reports_Working_Directory;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_19;
    QLineEdit *Aligned_Models_Save_Location;
    QSpacerItem *verticalSpacer_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1318, 674);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        verticalLayout_12 = new QVBoxLayout(centralWidget);
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(-1, 7, -1, 7);
        View_Holder = new QStackedWidget(centralWidget);
        View_Holder->setObjectName(QStringLiteral("View_Holder"));
        View_Holder->setMinimumSize(QSize(0, 0));
        Main_Page = new QWidget();
        Main_Page->setObjectName(QStringLiteral("Main_Page"));
        Main_Page->setEnabled(true);
        verticalLayout_13 = new QVBoxLayout(Main_Page);
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        widget = new QWidget(Main_Page);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMaximumSize(QSize(16777215, 100));
        verticalLayout_14 = new QVBoxLayout(widget);
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setContentsMargins(11, 11, 11, 11);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setSizeConstraint(QLayout::SetMinimumSize);
        widget_5 = new QWidget(widget);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_6->addWidget(widget_5);

        Banner = new QLabel(widget);
        Banner->setObjectName(QStringLiteral("Banner"));
        Banner->setMaximumSize(QSize(16777215, 50));
        Banner->setTextFormat(Qt::RichText);
        Banner->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(Banner);

        Settings_Button = new QPushButton(widget);
        Settings_Button->setObjectName(QStringLiteral("Settings_Button"));
        Settings_Button->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_6->addWidget(Settings_Button);


        verticalLayout_14->addLayout(horizontalLayout_6);


        verticalLayout_13->addWidget(widget);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        Reference_File_Text = new QLineEdit(Main_Page);
        Reference_File_Text->setObjectName(QStringLiteral("Reference_File_Text"));
        Reference_File_Text->setMinimumSize(QSize(600, 0));

        horizontalLayout->addWidget(Reference_File_Text);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout->addItem(verticalSpacer_6);

        Reference_File_Button = new QPushButton(Main_Page);
        Reference_File_Button->setObjectName(QStringLiteral("Reference_File_Button"));

        horizontalLayout->addWidget(Reference_File_Button);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        Production_File_Text = new QTextEdit(Main_Page);
        Production_File_Text->setObjectName(QStringLiteral("Production_File_Text"));

        horizontalLayout_2->addWidget(Production_File_Text);

        verticalLayout_34 = new QVBoxLayout();
        verticalLayout_34->setSpacing(6);
        verticalLayout_34->setObjectName(QStringLiteral("verticalLayout_34"));
        Production_File_Button = new QPushButton(Main_Page);
        Production_File_Button->setObjectName(QStringLiteral("Production_File_Button"));

        verticalLayout_34->addWidget(Production_File_Button);

        Clear_Production_Files = new QPushButton(Main_Page);
        Clear_Production_Files->setObjectName(QStringLiteral("Clear_Production_Files"));

        verticalLayout_34->addWidget(Clear_Production_Files);


        horizontalLayout_2->addLayout(verticalLayout_34);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_2 = new QLabel(Main_Page);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_4->addWidget(label_2);

        Ref_Attempt = new QLineEdit(Main_Page);
        Ref_Attempt->setObjectName(QStringLiteral("Ref_Attempt"));

        horizontalLayout_4->addWidget(Ref_Attempt);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_3 = new QLabel(Main_Page);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_5->addWidget(label_3);

        Prod_Attempt = new QLineEdit(Main_Page);
        Prod_Attempt->setObjectName(QStringLiteral("Prod_Attempt"));

        horizontalLayout_5->addWidget(Prod_Attempt);


        verticalLayout_4->addLayout(horizontalLayout_5);


        horizontalLayout_3->addLayout(verticalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout_5);

        line = new QFrame(Main_Page);
        line->setObjectName(QStringLiteral("line"));
        line->setLineWidth(1);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label_4 = new QLabel(Main_Page);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setTextFormat(Qt::RichText);

        verticalLayout_7->addWidget(label_4);

        Client_Name = new QLineEdit(Main_Page);
        Client_Name->setObjectName(QStringLiteral("Client_Name"));

        verticalLayout_7->addWidget(Client_Name);


        horizontalLayout_7->addLayout(verticalLayout_7);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_5 = new QLabel(Main_Page);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_6->addWidget(label_5);

        Patient_Name = new QLineEdit(Main_Page);
        Patient_Name->setObjectName(QStringLiteral("Patient_Name"));

        verticalLayout_6->addWidget(Patient_Name);


        horizontalLayout_7->addLayout(verticalLayout_6);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        label_6 = new QLabel(Main_Page);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_8->addWidget(label_6);

        File_Description = new QLineEdit(Main_Page);
        File_Description->setObjectName(QStringLiteral("File_Description"));

        verticalLayout_8->addWidget(File_Description);


        horizontalLayout_8->addLayout(verticalLayout_8);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        label_7 = new QLabel(Main_Page);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_9->addWidget(label_7);

        Save_Location = new QLineEdit(Main_Page);
        Save_Location->setObjectName(QStringLiteral("Save_Location"));

        verticalLayout_9->addWidget(Save_Location);


        horizontalLayout_8->addLayout(verticalLayout_9);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        label_8 = new QLabel(Main_Page);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_11->addWidget(label_8);

        File_Name = new QLineEdit(Main_Page);
        File_Name->setObjectName(QStringLiteral("File_Name"));

        verticalLayout_11->addWidget(File_Name);


        horizontalLayout_9->addLayout(verticalLayout_11);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        Config_Button = new QPushButton(Main_Page);
        Config_Button->setObjectName(QStringLiteral("Config_Button"));
        Config_Button->setMinimumSize(QSize(100, 75));

        verticalLayout_10->addWidget(Config_Button);


        horizontalLayout_9->addLayout(verticalLayout_10);


        verticalLayout_3->addLayout(horizontalLayout_9);


        verticalLayout_2->addLayout(verticalLayout_3);


        verticalLayout_13->addLayout(verticalLayout_2);

        View_Holder->addWidget(Main_Page);
        Config_Page = new QWidget();
        Config_Page->setObjectName(QStringLiteral("Config_Page"));
        verticalLayout_15 = new QVBoxLayout(Config_Page);
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setContentsMargins(11, 11, 11, 11);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        widget_3 = new QWidget(Config_Page);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMaximumSize(QSize(16777215, 100));
        verticalLayout_16 = new QVBoxLayout(widget_3);
        verticalLayout_16->setSpacing(6);
        verticalLayout_16->setContentsMargins(11, 11, 11, 11);
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setSizeConstraint(QLayout::SetMinimumSize);
        ReturnToMainPage = new QPushButton(widget_3);
        ReturnToMainPage->setObjectName(QStringLiteral("ReturnToMainPage"));
        ReturnToMainPage->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_10->addWidget(ReturnToMainPage);

        widget_6 = new QWidget(widget_3);
        widget_6->setObjectName(QStringLiteral("widget_6"));

        horizontalLayout_10->addWidget(widget_6);

        Banner_2 = new QLabel(widget_3);
        Banner_2->setObjectName(QStringLiteral("Banner_2"));
        Banner_2->setMaximumSize(QSize(16777215, 50));
        Banner_2->setTextFormat(Qt::RichText);
        Banner_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(Banner_2);

        widget_7 = new QWidget(widget_3);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        widget_7->setMinimumSize(QSize(0, 76));

        horizontalLayout_10->addWidget(widget_7);

        Settings_Button_2 = new QPushButton(widget_3);
        Settings_Button_2->setObjectName(QStringLiteral("Settings_Button_2"));
        Settings_Button_2->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_10->addWidget(Settings_Button_2);


        verticalLayout_16->addLayout(horizontalLayout_10);


        verticalLayout_15->addWidget(widget_3);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setSpacing(6);
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        label_15 = new QLabel(Config_Page);
        label_15->setObjectName(QStringLiteral("label_15"));

        verticalLayout_17->addWidget(label_15);

        verticalLayout_20 = new QVBoxLayout();
        verticalLayout_20->setSpacing(6);
        verticalLayout_20->setObjectName(QStringLiteral("verticalLayout_20"));
        label = new QLabel(Config_Page);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_20->addWidget(label);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        Report_Type = new QComboBox(Config_Page);
        Report_Type->setObjectName(QStringLiteral("Report_Type"));

        horizontalLayout_21->addWidget(Report_Type);


        verticalLayout_20->addLayout(horizontalLayout_21);


        verticalLayout_17->addLayout(verticalLayout_20);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        verticalLayout_21 = new QVBoxLayout();
        verticalLayout_21->setSpacing(6);
        verticalLayout_21->setObjectName(QStringLiteral("verticalLayout_21"));
        label_9 = new QLabel(Config_Page);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_21->addWidget(label_9);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        Confidence_Level = new QSpinBox(Config_Page);
        Confidence_Level->setObjectName(QStringLiteral("Confidence_Level"));

        horizontalLayout_19->addWidget(Confidence_Level);


        verticalLayout_21->addLayout(horizontalLayout_19);


        horizontalLayout_13->addLayout(verticalLayout_21);

        verticalLayout_22 = new QVBoxLayout();
        verticalLayout_22->setSpacing(6);
        verticalLayout_22->setObjectName(QStringLiteral("verticalLayout_22"));
        label_10 = new QLabel(Config_Page);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout_22->addWidget(label_10);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(7);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        Error_Bound = new QSpinBox(Config_Page);
        Error_Bound->setObjectName(QStringLiteral("Error_Bound"));

        horizontalLayout_12->addWidget(Error_Bound);

        Error_Unit = new QComboBox(Config_Page);
        Error_Unit->setObjectName(QStringLiteral("Error_Unit"));

        horizontalLayout_12->addWidget(Error_Unit);


        verticalLayout_22->addLayout(horizontalLayout_12);


        horizontalLayout_13->addLayout(verticalLayout_22);


        verticalLayout_17->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        verticalLayout_23 = new QVBoxLayout();
        verticalLayout_23->setSpacing(6);
        verticalLayout_23->setObjectName(QStringLiteral("verticalLayout_23"));
        label_11 = new QLabel(Config_Page);
        label_11->setObjectName(QStringLiteral("label_11"));

        verticalLayout_23->addWidget(label_11);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        Allignment_Type = new QComboBox(Config_Page);
        Allignment_Type->setObjectName(QStringLiteral("Allignment_Type"));

        horizontalLayout_20->addWidget(Allignment_Type);


        verticalLayout_23->addLayout(horizontalLayout_20);


        horizontalLayout_14->addLayout(verticalLayout_23);


        verticalLayout_17->addLayout(horizontalLayout_14);


        horizontalLayout_11->addLayout(verticalLayout_17);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_11->addItem(verticalSpacer);

        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setSpacing(6);
        verticalLayout_18->setObjectName(QStringLiteral("verticalLayout_18"));
        label_16 = new QLabel(Config_Page);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setMinimumSize(QSize(0, 0));

        verticalLayout_18->addWidget(label_16);

        verticalLayout_24 = new QVBoxLayout();
        verticalLayout_24->setSpacing(6);
        verticalLayout_24->setObjectName(QStringLiteral("verticalLayout_24"));
        label_12 = new QLabel(Config_Page);
        label_12->setObjectName(QStringLiteral("label_12"));

        verticalLayout_24->addWidget(label_12);

        Technician_Name = new QLineEdit(Config_Page);
        Technician_Name->setObjectName(QStringLiteral("Technician_Name"));

        verticalLayout_24->addWidget(Technician_Name);


        verticalLayout_18->addLayout(verticalLayout_24);

        verticalLayout_25 = new QVBoxLayout();
        verticalLayout_25->setSpacing(6);
        verticalLayout_25->setObjectName(QStringLiteral("verticalLayout_25"));
        label_13 = new QLabel(Config_Page);
        label_13->setObjectName(QStringLiteral("label_13"));

        verticalLayout_25->addWidget(label_13);

        Product_Name = new QLineEdit(Config_Page);
        Product_Name->setObjectName(QStringLiteral("Product_Name"));

        verticalLayout_25->addWidget(Product_Name);


        verticalLayout_18->addLayout(verticalLayout_25);

        verticalLayout_26 = new QVBoxLayout();
        verticalLayout_26->setSpacing(6);
        verticalLayout_26->setObjectName(QStringLiteral("verticalLayout_26"));
        label_14 = new QLabel(Config_Page);
        label_14->setObjectName(QStringLiteral("label_14"));

        verticalLayout_26->addWidget(label_14);

        Production_Date = new QLineEdit(Config_Page);
        Production_Date->setObjectName(QStringLiteral("Production_Date"));

        verticalLayout_26->addWidget(Production_Date);


        verticalLayout_18->addLayout(verticalLayout_26);


        horizontalLayout_11->addLayout(verticalLayout_18);


        verticalLayout_15->addLayout(horizontalLayout_11);

        verticalLayout_19 = new QVBoxLayout();
        verticalLayout_19->setSpacing(6);
        verticalLayout_19->setObjectName(QStringLiteral("verticalLayout_19"));
        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        verticalLayout_32 = new QVBoxLayout();
        verticalLayout_32->setSpacing(6);
        verticalLayout_32->setObjectName(QStringLiteral("verticalLayout_32"));
        label_20 = new QLabel(Config_Page);
        label_20->setObjectName(QStringLiteral("label_20"));

        verticalLayout_32->addWidget(label_20);

        Product_Description = new QPlainTextEdit(Config_Page);
        Product_Description->setObjectName(QStringLiteral("Product_Description"));

        verticalLayout_32->addWidget(Product_Description);


        horizontalLayout_18->addLayout(verticalLayout_32);

        verticalLayout_33 = new QVBoxLayout();
        verticalLayout_33->setSpacing(6);
        verticalLayout_33->setObjectName(QStringLiteral("verticalLayout_33"));
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_33->addItem(verticalSpacer_5);

        RunVTK = new QPushButton(Config_Page);
        RunVTK->setObjectName(QStringLiteral("RunVTK"));
        RunVTK->setMinimumSize(QSize(100, 75));
        RunVTK->setMaximumSize(QSize(200, 16777215));
        RunVTK->setLayoutDirection(Qt::LeftToRight);

        verticalLayout_33->addWidget(RunVTK);


        horizontalLayout_18->addLayout(verticalLayout_33);


        verticalLayout_19->addLayout(horizontalLayout_18);


        verticalLayout_15->addLayout(verticalLayout_19);

        View_Holder->addWidget(Config_Page);
        Settings_Page = new QWidget();
        Settings_Page->setObjectName(QStringLiteral("Settings_Page"));
        verticalLayout_28 = new QVBoxLayout(Settings_Page);
        verticalLayout_28->setSpacing(6);
        verticalLayout_28->setContentsMargins(11, 11, 11, 11);
        verticalLayout_28->setObjectName(QStringLiteral("verticalLayout_28"));
        widget_4 = new QWidget(Settings_Page);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setMaximumSize(QSize(16777215, 100));
        verticalLayout_27 = new QVBoxLayout(widget_4);
        verticalLayout_27->setSpacing(6);
        verticalLayout_27->setContentsMargins(11, 11, 11, 11);
        verticalLayout_27->setObjectName(QStringLiteral("verticalLayout_27"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        horizontalLayout_15->setSizeConstraint(QLayout::SetMinimumSize);
        Return_to_Setup_Button = new QPushButton(widget_4);
        Return_to_Setup_Button->setObjectName(QStringLiteral("Return_to_Setup_Button"));
        Return_to_Setup_Button->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_15->addWidget(Return_to_Setup_Button);

        widget_2 = new QWidget(widget_4);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(0, 73));

        horizontalLayout_15->addWidget(widget_2);

        Banner_3 = new QLabel(widget_4);
        Banner_3->setObjectName(QStringLiteral("Banner_3"));
        Banner_3->setMaximumSize(QSize(16777215, 50));
        Banner_3->setTextFormat(Qt::RichText);
        Banner_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_15->addWidget(Banner_3);

        widget_8 = new QWidget(widget_4);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        widget_8->setMinimumSize(QSize(0, 73));

        horizontalLayout_15->addWidget(widget_8);

        Return_to_Configuration_Button = new QPushButton(widget_4);
        Return_to_Configuration_Button->setObjectName(QStringLiteral("Return_to_Configuration_Button"));
        Return_to_Configuration_Button->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_15->addWidget(Return_to_Configuration_Button);


        verticalLayout_27->addLayout(horizontalLayout_15);


        verticalLayout_28->addWidget(widget_4);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        verticalLayout_29 = new QVBoxLayout();
        verticalLayout_29->setSpacing(6);
        verticalLayout_29->setObjectName(QStringLiteral("verticalLayout_29"));
        label_17 = new QLabel(Settings_Page);
        label_17->setObjectName(QStringLiteral("label_17"));

        verticalLayout_29->addWidget(label_17);

        Model_Working_Directory = new QLineEdit(Settings_Page);
        Model_Working_Directory->setObjectName(QStringLiteral("Model_Working_Directory"));

        verticalLayout_29->addWidget(Model_Working_Directory);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_29->addItem(verticalSpacer_2);


        horizontalLayout_16->addLayout(verticalLayout_29);

        verticalLayout_30 = new QVBoxLayout();
        verticalLayout_30->setSpacing(6);
        verticalLayout_30->setObjectName(QStringLiteral("verticalLayout_30"));
        label_18 = new QLabel(Settings_Page);
        label_18->setObjectName(QStringLiteral("label_18"));

        verticalLayout_30->addWidget(label_18);

        Reports_Working_Directory = new QLineEdit(Settings_Page);
        Reports_Working_Directory->setObjectName(QStringLiteral("Reports_Working_Directory"));

        verticalLayout_30->addWidget(Reports_Working_Directory);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_30->addItem(verticalSpacer_3);

        label_19 = new QLabel(Settings_Page);
        label_19->setObjectName(QStringLiteral("label_19"));

        verticalLayout_30->addWidget(label_19);

        Aligned_Models_Save_Location = new QLineEdit(Settings_Page);
        Aligned_Models_Save_Location->setObjectName(QStringLiteral("Aligned_Models_Save_Location"));

        verticalLayout_30->addWidget(Aligned_Models_Save_Location);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_30->addItem(verticalSpacer_4);


        horizontalLayout_16->addLayout(verticalLayout_30);


        verticalLayout_28->addLayout(horizontalLayout_16);

        View_Holder->addWidget(Settings_Page);

        verticalLayout_12->addWidget(View_Holder);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1318, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        View_Holder->setCurrentIndex(0);
        Report_Type->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        Banner->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:26pt; font-weight:600; color:#b6fd01;\">Comparisoft</span></p></body></html>", Q_NULLPTR));
        Settings_Button->setText(QApplication::translate("MainWindow", "Settings", Q_NULLPTR));
        Reference_File_Button->setText(QApplication::translate("MainWindow", "Reference File", Q_NULLPTR));
        Production_File_Button->setText(QApplication::translate("MainWindow", "Production File", Q_NULLPTR));
        Clear_Production_Files->setText(QApplication::translate("MainWindow", "Clear", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Attempt:", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Attempt:", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Client Name:</span></p></body></html>", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Patient Name:</span></p></body></html>", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">File Description:</span></p></body></html>", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Save Location:</span></p></body></html>", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">File Name:</span></p></body></html>", Q_NULLPTR));
        Config_Button->setText(QApplication::translate("MainWindow", "Configure", Q_NULLPTR));
        ReturnToMainPage->setText(QApplication::translate("MainWindow", "Setup", Q_NULLPTR));
        Banner_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:26pt; font-weight:600; color:#b6fd01;\">Comparisoft</span></p></body></html>", Q_NULLPTR));
        Settings_Button_2->setText(QApplication::translate("MainWindow", "Settings", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600;\">Run Configuration</span></p></body></html>", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "<b>Report Type:</b>", Q_NULLPTR));
        Report_Type->clear();
        Report_Type->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Error Report", Q_NULLPTR)
        );
        Report_Type->setCurrentText(QApplication::translate("MainWindow", "Error Report", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "<b>Confidence Level:</b>", Q_NULLPTR));
        Confidence_Level->setSuffix(QApplication::translate("MainWindow", "%", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">within +/-</span></p></body></html>", Q_NULLPTR));
        Error_Unit->clear();
        Error_Unit->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "nm", Q_NULLPTR)
         << QApplication::translate("MainWindow", "mm", Q_NULLPTR)
        );
        label_11->setText(QApplication::translate("MainWindow", "<b>Alignment type:</b>", Q_NULLPTR));
        Allignment_Type->clear();
        Allignment_Type->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Standard", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Quick", Q_NULLPTR)
        );
        label_16->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600;\">Report Information</span></p></body></html>", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "<b>Technician Name:</b>", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "<b>Product Type:</b>", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "<b>Production Date:</b>", Q_NULLPTR));
        label_20->setText(QApplication::translate("MainWindow", "<b>Product Description</b>", Q_NULLPTR));
        RunVTK->setText(QApplication::translate("MainWindow", "Align", Q_NULLPTR));
        Return_to_Setup_Button->setText(QApplication::translate("MainWindow", "Setup", Q_NULLPTR));
        Banner_3->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:26pt; font-weight:600; color:#b6fd01;\">Comparisoft</span></p></body></html>", Q_NULLPTR));
        Return_to_Configuration_Button->setText(QApplication::translate("MainWindow", "Configuration", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "<b>Model Working Directory:</b>", Q_NULLPTR));
        label_18->setText(QApplication::translate("MainWindow", "<b>Reports Working Directory:</b>", Q_NULLPTR));
        label_19->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Aligned Models Save Location</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
