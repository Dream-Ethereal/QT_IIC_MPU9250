/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_status;
    QPushButton *btn_send_data;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *btn_read_data;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btn_clear_black;
    QPushButton *btn_clear_white;
    QPushButton *btn_draw_circle;
    QTextEdit *te_read;
    QTextEdit *te_send;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QTextEdit *te_device_addr;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QTextEdit *te_reg_addr;
    QLineEdit *lineEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_status = new QLabel(centralwidget);
        label_status->setObjectName(QString::fromUtf8("label_status"));
        label_status->setGeometry(QRect(10, 520, 191, 21));
        btn_send_data = new QPushButton(centralwidget);
        btn_send_data->setObjectName(QString::fromUtf8("btn_send_data"));
        btn_send_data->setGeometry(QRect(400, 210, 80, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(200, 130, 71, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(400, 130, 71, 16));
        btn_read_data = new QPushButton(centralwidget);
        btn_read_data->setObjectName(QString::fromUtf8("btn_read_data"));
        btn_read_data->setGeometry(QRect(200, 210, 80, 20));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 10, 191, 91));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        btn_clear_black = new QPushButton(verticalLayoutWidget);
        btn_clear_black->setObjectName(QString::fromUtf8("btn_clear_black"));

        verticalLayout_2->addWidget(btn_clear_black);

        btn_clear_white = new QPushButton(verticalLayoutWidget);
        btn_clear_white->setObjectName(QString::fromUtf8("btn_clear_white"));

        verticalLayout_2->addWidget(btn_clear_white);

        btn_draw_circle = new QPushButton(verticalLayoutWidget);
        btn_draw_circle->setObjectName(QString::fromUtf8("btn_draw_circle"));

        verticalLayout_2->addWidget(btn_draw_circle);

        te_read = new QTextEdit(centralwidget);
        te_read->setObjectName(QString::fromUtf8("te_read"));
        te_read->setGeometry(QRect(200, 150, 191, 51));
        te_read->setReadOnly(true);
        te_send = new QTextEdit(centralwidget);
        te_send->setObjectName(QString::fromUtf8("te_send"));
        te_send->setGeometry(QRect(400, 150, 191, 51));
        te_send->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhMultiLine|Qt::ImhPreferNumbers|Qt::ImhPreferUppercase|Qt::ImhUppercaseOnly);
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(30, 150, 151, 72));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        te_device_addr = new QTextEdit(horizontalLayoutWidget);
        te_device_addr->setObjectName(QString::fromUtf8("te_device_addr"));

        horizontalLayout->addWidget(te_device_addr);

        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(20, 180, 162, 72));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        te_reg_addr = new QTextEdit(horizontalLayoutWidget_2);
        te_reg_addr->setObjectName(QString::fromUtf8("te_reg_addr"));

        horizontalLayout_2->addWidget(te_reg_addr);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(400, 100, 113, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_status->setText(QApplication::translate("MainWindow", "\347\212\266\346\200\201\357\274\232", nullptr));
        btn_send_data->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\350\257\273\346\225\260\346\215\256", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\345\206\231\346\225\260\346\215\256", nullptr));
        btn_read_data->setText(QApplication::translate("MainWindow", "\350\257\273\345\217\226", nullptr));
        btn_clear_black->setText(QApplication::translate("MainWindow", "\346\270\205\345\261\217\357\274\210\351\273\221\350\211\262\357\274\211", nullptr));
        btn_clear_white->setText(QApplication::translate("MainWindow", "\346\270\205\345\261\217\357\274\210\347\231\275\350\211\262\357\274\211", nullptr));
        btn_draw_circle->setText(QApplication::translate("MainWindow", "\347\224\273\345\234\206", nullptr));
        label->setText(QApplication::translate("MainWindow", "\350\256\276\345\244\207\345\234\260\345\235\200: 0x", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\345\257\204\345\255\230\345\231\250\345\234\260\345\235\200: 0x", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
