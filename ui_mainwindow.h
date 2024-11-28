/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QwtPlot *qwtPlot;
    QGroupBox *groupBox;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *lineEdit_temp;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *lineEdit_accx;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLineEdit *lineEdit_accy;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QLineEdit *lineEdit_accz;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QLineEdit *lineEdit_gyrx;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_6;
    QLineEdit *lineEdit_gyry;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_7;
    QLineEdit *lineEdit_gyrz;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_8;
    QLineEdit *lineEdit_cpsx;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_9;
    QLineEdit *lineEdit_cpsy;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_10;
    QLineEdit *lineEdit_cpsz;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_start;
    QPushButton *pushButton_end;
    QPushButton *pushButton_help;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1018, 752);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 1001, 671));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        qwtPlot = new QwtPlot(verticalLayoutWidget);
        qwtPlot->setObjectName(QStringLiteral("qwtPlot"));

        horizontalLayout->addWidget(qwtPlot);

        groupBox = new QGroupBox(verticalLayoutWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(325, 0));
        groupBox->setMaximumSize(QSize(325, 16777215));
        verticalLayoutWidget_2 = new QWidget(groupBox);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 20, 311, 631));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(verticalLayoutWidget_2);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        lineEdit_temp = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_temp->setObjectName(QStringLiteral("lineEdit_temp"));
        lineEdit_temp->setMaximumSize(QSize(200, 40));
        lineEdit_temp->setFocusPolicy(Qt::NoFocus);
        lineEdit_temp->setContextMenuPolicy(Qt::DefaultContextMenu);
        lineEdit_temp->setAlignment(Qt::AlignCenter);
        lineEdit_temp->setReadOnly(true);

        horizontalLayout_3->addWidget(lineEdit_temp);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_2 = new QLabel(verticalLayoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_4->addWidget(label_2);

        lineEdit_accx = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_accx->setObjectName(QStringLiteral("lineEdit_accx"));
        lineEdit_accx->setMaximumSize(QSize(200, 40));
        lineEdit_accx->setFocusPolicy(Qt::NoFocus);
        lineEdit_accx->setAlignment(Qt::AlignCenter);
        lineEdit_accx->setReadOnly(true);

        horizontalLayout_4->addWidget(lineEdit_accx);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_3 = new QLabel(verticalLayoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_5->addWidget(label_3);

        lineEdit_accy = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_accy->setObjectName(QStringLiteral("lineEdit_accy"));
        lineEdit_accy->setMaximumSize(QSize(200, 40));
        lineEdit_accy->setFocusPolicy(Qt::NoFocus);
        lineEdit_accy->setAlignment(Qt::AlignCenter);
        lineEdit_accy->setReadOnly(true);

        horizontalLayout_5->addWidget(lineEdit_accy);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_4 = new QLabel(verticalLayoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_6->addWidget(label_4);

        lineEdit_accz = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_accz->setObjectName(QStringLiteral("lineEdit_accz"));
        lineEdit_accz->setMaximumSize(QSize(200, 40));
        lineEdit_accz->setFocusPolicy(Qt::NoFocus);
        lineEdit_accz->setAlignment(Qt::AlignCenter);
        lineEdit_accz->setDragEnabled(false);
        lineEdit_accz->setReadOnly(true);

        horizontalLayout_6->addWidget(lineEdit_accz);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_5 = new QLabel(verticalLayoutWidget_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_7->addWidget(label_5);

        lineEdit_gyrx = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_gyrx->setObjectName(QStringLiteral("lineEdit_gyrx"));
        lineEdit_gyrx->setMaximumSize(QSize(200, 40));
        lineEdit_gyrx->setFocusPolicy(Qt::NoFocus);
        lineEdit_gyrx->setAlignment(Qt::AlignCenter);
        lineEdit_gyrx->setReadOnly(true);

        horizontalLayout_7->addWidget(lineEdit_gyrx);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_6 = new QLabel(verticalLayoutWidget_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_8->addWidget(label_6);

        lineEdit_gyry = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_gyry->setObjectName(QStringLiteral("lineEdit_gyry"));
        lineEdit_gyry->setMaximumSize(QSize(200, 40));
        lineEdit_gyry->setFocusPolicy(Qt::NoFocus);
        lineEdit_gyry->setAlignment(Qt::AlignCenter);
        lineEdit_gyry->setReadOnly(true);

        horizontalLayout_8->addWidget(lineEdit_gyry);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_7 = new QLabel(verticalLayoutWidget_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_9->addWidget(label_7);

        lineEdit_gyrz = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_gyrz->setObjectName(QStringLiteral("lineEdit_gyrz"));
        lineEdit_gyrz->setMaximumSize(QSize(200, 40));
        lineEdit_gyrz->setFocusPolicy(Qt::NoFocus);
        lineEdit_gyrz->setAlignment(Qt::AlignCenter);
        lineEdit_gyrz->setReadOnly(true);

        horizontalLayout_9->addWidget(lineEdit_gyrz);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_8 = new QLabel(verticalLayoutWidget_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_10->addWidget(label_8);

        lineEdit_cpsx = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_cpsx->setObjectName(QStringLiteral("lineEdit_cpsx"));
        lineEdit_cpsx->setMaximumSize(QSize(200, 40));
        lineEdit_cpsx->setFocusPolicy(Qt::NoFocus);
        lineEdit_cpsx->setAlignment(Qt::AlignCenter);
        lineEdit_cpsx->setReadOnly(true);

        horizontalLayout_10->addWidget(lineEdit_cpsx);


        verticalLayout_2->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_9 = new QLabel(verticalLayoutWidget_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_11->addWidget(label_9);

        lineEdit_cpsy = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_cpsy->setObjectName(QStringLiteral("lineEdit_cpsy"));
        lineEdit_cpsy->setMaximumSize(QSize(200, 40));
        lineEdit_cpsy->setFocusPolicy(Qt::NoFocus);
        lineEdit_cpsy->setAlignment(Qt::AlignCenter);
        lineEdit_cpsy->setReadOnly(true);

        horizontalLayout_11->addWidget(lineEdit_cpsy);


        verticalLayout_2->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_10 = new QLabel(verticalLayoutWidget_2);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_12->addWidget(label_10);

        lineEdit_cpsz = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_cpsz->setObjectName(QStringLiteral("lineEdit_cpsz"));
        lineEdit_cpsz->setMaximumSize(QSize(200, 40));
        lineEdit_cpsz->setFocusPolicy(Qt::NoFocus);
        lineEdit_cpsz->setAlignment(Qt::AlignCenter);
        lineEdit_cpsz->setReadOnly(true);

        horizontalLayout_12->addWidget(lineEdit_cpsz);


        verticalLayout_2->addLayout(horizontalLayout_12);


        horizontalLayout->addWidget(groupBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 690, 1001, 51));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_start = new QPushButton(horizontalLayoutWidget_2);
        pushButton_start->setObjectName(QStringLiteral("pushButton_start"));

        horizontalLayout_2->addWidget(pushButton_start);

        pushButton_end = new QPushButton(horizontalLayoutWidget_2);
        pushButton_end->setObjectName(QStringLiteral("pushButton_end"));

        horizontalLayout_2->addWidget(pushButton_end);

        pushButton_help = new QPushButton(horizontalLayoutWidget_2);
        pushButton_help->setObjectName(QStringLiteral("pushButton_help"));

        horizontalLayout_2->addWidget(pushButton_help);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MPU9250\345\233\276\345\203\217\346\225\260\346\215\256\346\230\276\347\244\272\345\267\245\345\205\267", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "\346\225\260\346\215\256", 0));
        label->setText(QApplication::translate("MainWindow", "\346\270\251    \345\272\246", 0));
        label_2->setText(QApplication::translate("MainWindow", "\345\212\240\351\200\237\345\272\246 X", 0));
        label_3->setText(QApplication::translate("MainWindow", "\345\212\240\351\200\237\345\272\246 Y", 0));
        label_4->setText(QApplication::translate("MainWindow", "\345\212\240\351\200\237\345\272\246 Z", 0));
        label_5->setText(QApplication::translate("MainWindow", "\350\247\222\351\200\237\345\272\246 X", 0));
        label_6->setText(QApplication::translate("MainWindow", "\350\247\222\351\200\237\345\272\246 Y", 0));
        label_7->setText(QApplication::translate("MainWindow", "\350\247\222\351\200\237\345\272\246 Z", 0));
        label_8->setText(QApplication::translate("MainWindow", "\347\243\201\345\212\233\350\256\241 X", 0));
        label_9->setText(QApplication::translate("MainWindow", "\347\243\201\345\212\233\350\256\241 Y", 0));
        label_10->setText(QApplication::translate("MainWindow", "\347\243\201\345\212\233\350\256\241 Z", 0));
        pushButton_start->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\344\277\235\345\255\230", 0));
        pushButton_end->setText(QApplication::translate("MainWindow", "\347\273\223\346\235\237\344\277\235\345\255\230", 0));
        pushButton_help->setText(QApplication::translate("MainWindow", "\344\275\277\347\224\250\350\257\264\346\230\216", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
