/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QRadioButton *radioButton_1;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_6;
    QRadioButton *radioButton_7;
    QRadioButton *radioButton_8;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QLabel *labelAide;
    QSpacerItem *verticalSpacer;
    QLineEdit *valeurOption;
    QSpacerItem *verticalSpacer_2;
    QPushButton *btnOk;
    QLabel *numeroOption;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(734, 490);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 0, 711, 431));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(horizontalLayoutWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMaximumSize(QSize(300, 16777215));
        radioButton_1 = new QRadioButton(groupBox);
        radioButton_1->setObjectName(QStringLiteral("radioButton_1"));
        radioButton_1->setGeometry(QRect(10, 30, 151, 21));
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(10, 70, 161, 17));
        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(10, 110, 161, 17));
        radioButton_5 = new QRadioButton(groupBox);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));
        radioButton_5->setGeometry(QRect(10, 190, 151, 17));
        radioButton_4 = new QRadioButton(groupBox);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));
        radioButton_4->setGeometry(QRect(10, 150, 161, 22));
        radioButton_6 = new QRadioButton(groupBox);
        radioButton_6->setObjectName(QStringLiteral("radioButton_6"));
        radioButton_6->setGeometry(QRect(10, 230, 171, 22));
        radioButton_7 = new QRadioButton(groupBox);
        radioButton_7->setObjectName(QStringLiteral("radioButton_7"));
        radioButton_7->setGeometry(QRect(10, 270, 161, 22));
        radioButton_8 = new QRadioButton(groupBox);
        radioButton_8->setObjectName(QStringLiteral("radioButton_8"));
        radioButton_8->setGeometry(QRect(10, 310, 171, 22));

        horizontalLayout->addWidget(groupBox);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        labelAide = new QLabel(horizontalLayoutWidget);
        labelAide->setObjectName(QStringLiteral("labelAide"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelAide->sizePolicy().hasHeightForWidth());
        labelAide->setSizePolicy(sizePolicy1);
        labelAide->setFrameShape(QFrame::Box);
        labelAide->setAlignment(Qt::AlignCenter);
        labelAide->setMargin(10);

        verticalLayout->addWidget(labelAide, 0, Qt::AlignHCenter);

        verticalSpacer = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer);

        valeurOption = new QLineEdit(horizontalLayoutWidget);
        valeurOption->setObjectName(QStringLiteral("valeurOption"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(valeurOption->sizePolicy().hasHeightForWidth());
        valeurOption->setSizePolicy(sizePolicy2);
        valeurOption->setMaximumSize(QSize(200, 16777215));
        valeurOption->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(valeurOption, 0, Qt::AlignHCenter);

        verticalSpacer_2 = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer_2);

        btnOk = new QPushButton(horizontalLayoutWidget);
        btnOk->setObjectName(QStringLiteral("btnOk"));
        sizePolicy2.setHeightForWidth(btnOk->sizePolicy().hasHeightForWidth());
        btnOk->setSizePolicy(sizePolicy2);
        btnOk->setMaximumSize(QSize(100, 16777215));

        verticalLayout->addWidget(btnOk, 0, Qt::AlignHCenter);


        horizontalLayout->addLayout(verticalLayout);

        numeroOption = new QLabel(centralWidget);
        numeroOption->setObjectName(QStringLiteral("numeroOption"));
        numeroOption->setEnabled(true);
        numeroOption->setGeometry(QRect(144, 428, 371, 111));
        numeroOption->setInputMethodHints(Qt::ImhHiddenText);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 734, 25));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Projet R\303\251seau M1", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Options disponibles", 0));
        radioButton_1->setText(QApplication::translate("MainWindow", "SO_REUSEADDR", 0));
        radioButton_2->setText(QApplication::translate("MainWindow", "SO_RCVBUF", 0));
        radioButton_3->setText(QApplication::translate("MainWindow", "SO_SNDBUF", 0));
        radioButton_5->setText(QApplication::translate("MainWindow", "SO_DEBUG", 0));
        radioButton_4->setText(QApplication::translate("MainWindow", "SO_KEEPALIVE", 0));
        radioButton_6->setText(QApplication::translate("MainWindow", "SO_OOBINLINE", 0));
        radioButton_7->setText(QApplication::translate("MainWindow", "SO_DONTROUTE", 0));
        radioButton_8->setText(QApplication::translate("MainWindow", "SO_BROADCAST", 0));
        labelAide->setText(QApplication::translate("MainWindow", "<html><head/><body><p>Choisissez une option, entrez la valeur souhait\303\251e et cliquez sur OK</p></body></html>", 0));
        valeurOption->setInputMask(QString());
        valeurOption->setPlaceholderText(QApplication::translate("MainWindow", "Valeur pour l'option", 0));
        btnOk->setText(QApplication::translate("MainWindow", "OK", 0));
        numeroOption->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
