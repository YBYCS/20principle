/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *et_title;
    QLineEdit *et_intervalDuration;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *et_restDuration;
    QPushButton *bt_isOpen;
    QPushButton *bt_start;
    QLabel *label_4;
    QPushButton *bt_save;
    QHBoxLayout *horizontalLayout;
    QLabel *lb_explain;
    QLCDNumber *Timer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(552, 348);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(2, -1, 2, -1);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(15);
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 4, 0, 1, 1);

        et_title = new QLineEdit(centralwidget);
        et_title->setObjectName(QString::fromUtf8("et_title"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(et_title->sizePolicy().hasHeightForWidth());
        et_title->setSizePolicy(sizePolicy1);
        et_title->setMinimumSize(QSize(300, 40));

        gridLayout->addWidget(et_title, 5, 1, 1, 3);

        et_intervalDuration = new QLineEdit(centralwidget);
        et_intervalDuration->setObjectName(QString::fromUtf8("et_intervalDuration"));
        sizePolicy1.setHeightForWidth(et_intervalDuration->sizePolicy().hasHeightForWidth());
        et_intervalDuration->setSizePolicy(sizePolicy1);
        et_intervalDuration->setMinimumSize(QSize(300, 40));

        gridLayout->addWidget(et_intervalDuration, 3, 1, 1, 3);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(0, 0));
        label->setFont(font);

        gridLayout->addWidget(label, 3, 0, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 5, 0, 1, 1);

        et_restDuration = new QLineEdit(centralwidget);
        et_restDuration->setObjectName(QString::fromUtf8("et_restDuration"));
        sizePolicy1.setHeightForWidth(et_restDuration->sizePolicy().hasHeightForWidth());
        et_restDuration->setSizePolicy(sizePolicy1);
        et_restDuration->setMinimumSize(QSize(300, 40));
        et_restDuration->setInputMethodHints(Qt::ImhNone);
        et_restDuration->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(et_restDuration, 4, 1, 1, 3);

        bt_isOpen = new QPushButton(centralwidget);
        bt_isOpen->setObjectName(QString::fromUtf8("bt_isOpen"));
        sizePolicy1.setHeightForWidth(bt_isOpen->sizePolicy().hasHeightForWidth());
        bt_isOpen->setSizePolicy(sizePolicy1);
        bt_isOpen->setMinimumSize(QSize(40, 50));

        gridLayout->addWidget(bt_isOpen, 6, 1, 1, 1);

        bt_start = new QPushButton(centralwidget);
        bt_start->setObjectName(QString::fromUtf8("bt_start"));
        sizePolicy1.setHeightForWidth(bt_start->sizePolicy().hasHeightForWidth());
        bt_start->setSizePolicy(sizePolicy1);
        bt_start->setMinimumSize(QSize(130, 50));
        bt_start->setMaximumSize(QSize(50, 70));
        bt_start->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(bt_start, 6, 3, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 6, 0, 1, 1);

        bt_save = new QPushButton(centralwidget);
        bt_save->setObjectName(QString::fromUtf8("bt_save"));
        bt_save->setMinimumSize(QSize(0, 50));

        gridLayout->addWidget(bt_save, 6, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lb_explain = new QLabel(centralwidget);
        lb_explain->setObjectName(QString::fromUtf8("lb_explain"));
        lb_explain->setFont(font);

        horizontalLayout->addWidget(lb_explain);

        Timer = new QLCDNumber(centralwidget);
        Timer->setObjectName(QString::fromUtf8("Timer"));
        Timer->setMinimumSize(QSize(400, 75));

        horizontalLayout->addWidget(Timer);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 552, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "20-20-20", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\344\274\221\346\201\257\346\227\266\351\225\277:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\351\227\264\351\232\224\346\227\266\351\225\277:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\217\220\351\206\222\345\206\205\345\256\271:", nullptr));
        bt_isOpen->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        bt_start->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\350\256\241\346\227\266", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\346\230\257\345\220\246\345\274\200\346\234\272\345\220\257\345\212\250:", nullptr));
        bt_save->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
        lb_explain->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
