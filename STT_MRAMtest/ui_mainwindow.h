/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_15;
    QPushButton *connect;
    QSpacerItem *horizontalSpacer_14;
    QLabel *connect_state;
    QWidget *layoutWidget_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_18;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_8;
    QTextEdit *input_q0_prob;
    QSpacerItem *horizontalSpacer_19;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_20;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_9;
    QTextEdit *input_q1_prob;
    QSpacerItem *horizontalSpacer_21;
    QWidget *layoutWidget_5;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_22;
    QLabel *label_10;
    QSpacerItem *horizontalSpacer_23;
    QTextEdit *input_R0_average_deviation;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer_28;
    QLabel *label_12;
    QSpacerItem *horizontalSpacer_29;
    QTextEdit *input_R0_standard_deviation;
    QHBoxLayout *horizontalLayout_13;
    QSpacerItem *horizontalSpacer_31;
    QLabel *label_13;
    QSpacerItem *horizontalSpacer_32;
    QTextEdit *input_R1_average_deviation;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_25;
    QLabel *label_11;
    QSpacerItem *horizontalSpacer_26;
    QTextEdit *input_R1_standard_deviation;
    QLabel *label_14;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *begin;
    QSpacerItem *horizontalSpacer_3;
    QLabel *led;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QTextEdit *input_frame;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_11;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QTextEdit *input_information_source;
    QSpacerItem *horizontalSpacer_12;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_13;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_4;
    QTextEdit *error_frame_result;
    QSpacerItem *horizontalSpacer_15;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_16;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_5;
    QTextEdit *error_rate_result;
    QSpacerItem *horizontalSpacer_17;
    QSpacerItem *horizontalSpacer_6;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(557, 566);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(140, 10, 231, 25));
        horizontalLayout_15 = new QHBoxLayout(layoutWidget);
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        horizontalLayout_15->setContentsMargins(0, 0, 0, 0);
        connect = new QPushButton(layoutWidget);
        connect->setObjectName(QStringLiteral("connect"));

        horizontalLayout_15->addWidget(connect);

        horizontalSpacer_14 = new QSpacerItem(20, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_14);

        connect_state = new QLabel(layoutWidget);
        connect_state->setObjectName(QStringLiteral("connect_state"));

        horizontalLayout_15->addWidget(connect_state);

        layoutWidget_4 = new QWidget(centralWidget);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(20, 210, 231, 149));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_4);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget_4);
        label_8->setObjectName(QStringLiteral("label_8"));
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        label_8->setFont(font);

        verticalLayout_3->addWidget(label_8);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_18);

        label_6 = new QLabel(layoutWidget_4);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMaximumSize(QSize(16777215, 28));

        horizontalLayout_8->addWidget(label_6);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_8);

        input_q0_prob = new QTextEdit(layoutWidget_4);
        input_q0_prob->setObjectName(QStringLiteral("input_q0_prob"));
        input_q0_prob->setMaximumSize(QSize(16777215, 28));

        horizontalLayout_8->addWidget(input_q0_prob);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_19);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_20);

        label_7 = new QLabel(layoutWidget_4);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMaximumSize(QSize(16777215, 28));

        horizontalLayout_9->addWidget(label_7);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_9);

        input_q1_prob = new QTextEdit(layoutWidget_4);
        input_q1_prob->setObjectName(QStringLiteral("input_q1_prob"));
        input_q1_prob->setMaximumSize(QSize(16777215, 28));

        horizontalLayout_9->addWidget(input_q1_prob);

        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_21);


        verticalLayout_3->addLayout(horizontalLayout_9);

        layoutWidget_5 = new QWidget(centralWidget);
        layoutWidget_5->setObjectName(QStringLiteral("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(20, 370, 231, 181));
        verticalLayout_4 = new QVBoxLayout(layoutWidget_5);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget_5);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font);

        verticalLayout_4->addWidget(label_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_22);

        label_10 = new QLabel(layoutWidget_5);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMinimumSize(QSize(50, 0));
        label_10->setMaximumSize(QSize(70, 28));

        horizontalLayout_10->addWidget(label_10);

        horizontalSpacer_23 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_23);

        input_R0_average_deviation = new QTextEdit(layoutWidget_5);
        input_R0_average_deviation->setObjectName(QStringLiteral("input_R0_average_deviation"));
        input_R0_average_deviation->setMaximumSize(QSize(155, 28));

        horizontalLayout_10->addWidget(input_R0_average_deviation);


        verticalLayout_4->addLayout(horizontalLayout_10);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalSpacer_28 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_28);

        label_12 = new QLabel(layoutWidget_5);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setMinimumSize(QSize(50, 0));
        label_12->setMaximumSize(QSize(150, 28));

        horizontalLayout_12->addWidget(label_12);

        horizontalSpacer_29 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_29);

        input_R0_standard_deviation = new QTextEdit(layoutWidget_5);
        input_R0_standard_deviation->setObjectName(QStringLiteral("input_R0_standard_deviation"));
        input_R0_standard_deviation->setMaximumSize(QSize(155, 28));

        horizontalLayout_12->addWidget(input_R0_standard_deviation);


        verticalLayout_4->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalSpacer_31 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_31);

        label_13 = new QLabel(layoutWidget_5);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setMinimumSize(QSize(50, 0));
        label_13->setMaximumSize(QSize(16777215, 28));

        horizontalLayout_13->addWidget(label_13);

        horizontalSpacer_32 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_32);

        input_R1_average_deviation = new QTextEdit(layoutWidget_5);
        input_R1_average_deviation->setObjectName(QStringLiteral("input_R1_average_deviation"));
        input_R1_average_deviation->setMaximumSize(QSize(155, 28));

        horizontalLayout_13->addWidget(input_R1_average_deviation);


        verticalLayout_4->addLayout(horizontalLayout_13);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalSpacer_25 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_25);

        label_11 = new QLabel(layoutWidget_5);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setMinimumSize(QSize(50, 0));
        label_11->setMaximumSize(QSize(16777215, 28));

        horizontalLayout_11->addWidget(label_11);

        horizontalSpacer_26 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_26);

        input_R1_standard_deviation = new QTextEdit(layoutWidget_5);
        input_R1_standard_deviation->setObjectName(QStringLiteral("input_R1_standard_deviation"));
        input_R1_standard_deviation->setMaximumSize(QSize(155, 28));

        horizontalLayout_11->addWidget(input_R1_standard_deviation);


        verticalLayout_4->addLayout(horizontalLayout_11);

        label_14 = new QLabel(layoutWidget_5);
        label_14->setObjectName(QStringLiteral("label_14"));

        verticalLayout_4->addWidget(label_14);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 50, 231, 149));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        begin = new QPushButton(layoutWidget1);
        begin->setObjectName(QStringLiteral("begin"));

        horizontalLayout_3->addWidget(begin);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        led = new QLabel(layoutWidget1);
        led->setObjectName(QStringLiteral("led"));
        led->setMinimumSize(QSize(100, 0));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        led->setFont(font1);

        horizontalLayout_3->addWidget(led);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);

        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(16777215, 28));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        input_frame = new QTextEdit(layoutWidget1);
        input_frame->setObjectName(QStringLiteral("input_frame"));
        input_frame->setMaximumSize(QSize(16777215, 28));

        horizontalLayout->addWidget(input_frame);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_10);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_11);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(16777215, 28));

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        input_information_source = new QTextEdit(layoutWidget1);
        input_information_source->setObjectName(QStringLiteral("input_information_source"));
        input_information_source->setMaximumSize(QSize(16777215, 28));

        horizontalLayout_2->addWidget(input_information_source);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_12);


        verticalLayout->addLayout(horizontalLayout_2);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(260, 50, 282, 61));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        verticalLayout_2->addWidget(label_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_13);

        label_4 = new QLabel(layoutWidget2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(16777215, 28));

        horizontalLayout_4->addWidget(label_4);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        error_frame_result = new QTextEdit(layoutWidget2);
        error_frame_result->setObjectName(QStringLiteral("error_frame_result"));
        error_frame_result->setMaximumSize(QSize(16777215, 28));

        horizontalLayout_4->addWidget(error_frame_result);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_15);


        horizontalLayout_6->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_16);

        label_5 = new QLabel(layoutWidget2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMaximumSize(QSize(16777215, 28));

        horizontalLayout_5->addWidget(label_5);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        error_rate_result = new QTextEdit(layoutWidget2);
        error_rate_result->setObjectName(QStringLiteral("error_rate_result"));
        error_rate_result->setMaximumSize(QSize(16777215, 28));

        horizontalLayout_5->addWidget(error_rate_result);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_17);


        horizontalLayout_6->addLayout(horizontalLayout_5);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);


        verticalLayout_2->addLayout(horizontalLayout_6);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        connect->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245", 0));
        connect_state->setText(QString());
        label_8->setText(QApplication::translate("MainWindow", "\344\277\241\351\201\223\350\275\254\347\247\273\346\246\202\347\216\207", 0));
        label_6->setText(QApplication::translate("MainWindow", "q0(0->0)", 0));
        label_7->setText(QApplication::translate("MainWindow", "q1(1->1)", 0));
        label_9->setText(QApplication::translate("MainWindow", "\344\277\241\351\201\223\350\275\254\347\247\273\346\246\202\347\216\207", 0));
        label_10->setText(QApplication::translate("MainWindow", "R0\345\235\207\345\267\256", 0));
        label_12->setText(QApplication::translate("MainWindow", "R0\346\240\207\345\207\206\345\267\256", 0));
        label_13->setText(QApplication::translate("MainWindow", "R1\345\235\207\345\267\256", 0));
        label_11->setText(QApplication::translate("MainWindow", "R1\346\240\207\345\207\206\345\267\256", 0));
        label_14->setText(QApplication::translate("MainWindow", "                         \345\215\225\344\275\215\357\274\210\346\254\247\345\247\206\357\274\211", 0));
        begin->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213", 0));
        led->setText(QApplication::translate("MainWindow", "\342\227\213", 0));
        label->setText(QApplication::translate("MainWindow", "\346\265\213\350\257\225\345\270\247\346\225\260", 0));
        label_2->setText(QApplication::translate("MainWindow", "\344\277\241\346\272\220\345\217\202\346\225\260", 0));
        label_3->setText(QApplication::translate("MainWindow", "\346\265\213\350\257\225\347\273\223\346\236\234", 0));
        label_4->setText(QApplication::translate("MainWindow", "\350\257\257\345\270\247\347\216\207", 0));
        label_5->setText(QApplication::translate("MainWindow", "\350\257\257\347\240\201\347\216\207", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
