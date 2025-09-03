/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *insertButton;
    QPushButton *tableButton;
    QLabel *label_5;
    QWidget *page_3;
    QTableWidget *tableWidget;
    QPushButton *deleteButton;
    QPushButton *searchButton;
    QLineEdit *lineEdit_3;
    QPushButton *backButton_2;
    QLabel *label_4;
    QPushButton *searchButton_2;
    QWidget *page_2;
    QPushButton *pushButton;
    QLineEdit *lineEdit_2;
    QPushButton *backButton;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(645, 393);
        Widget->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 131, 16));
        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 10, 631, 381));
        QFont font;
        font.setFamilies({QString::fromUtf8("Yu Gothic UI")});
        stackedWidget->setFont(font);
        stackedWidget->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        page = new QWidget();
        page->setObjectName("page");
        insertButton = new QPushButton(page);
        insertButton->setObjectName("insertButton");
        insertButton->setGeometry(QRect(270, 140, 80, 31));
        insertButton->setFont(font);
        insertButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        insertButton->setStyleSheet(QString::fromUtf8("background-color: #000060; \n"
"color: white;             \n"
"border-radius: 0px;\n"
"padding: 5px; "));
        insertButton->setAutoDefault(false);
        tableButton = new QPushButton(page);
        tableButton->setObjectName("tableButton");
        tableButton->setGeometry(QRect(270, 200, 80, 31));
        tableButton->setFont(font);
        tableButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        tableButton->setStyleSheet(QString::fromUtf8("background-color: #000060; \n"
"color: white;             \n"
"border-radius: 0px;\n"
"padding: 5px; "));
        label_5 = new QLabel(page);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(170, 10, 281, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Yu Gothic UI")});
        font1.setPointSize(16);
        label_5->setFont(font1);
        label_5->setStyleSheet(QString::fromUtf8("font-size: 16pt;color: #333333;"));
        label_5->setMargin(0);
        label_5->setIndent(54);
        stackedWidget->addWidget(page);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        tableWidget = new QTableWidget(page_3);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(70, 80, 231, 192));
        tableWidget->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        tableWidget->horizontalHeader()->setMinimumSectionSize(28);
        tableWidget->horizontalHeader()->setDefaultSectionSize(115);
        deleteButton = new QPushButton(page_3);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setGeometry(QRect(400, 290, 91, 31));
        deleteButton->setFont(font);
        deleteButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        deleteButton->setStyleSheet(QString::fromUtf8("background-color: #000060; \n"
"color: white;             \n"
"border-radius: 0px;\n"
" \n"
"padding:5px;\n"
"  "));
        searchButton = new QPushButton(page_3);
        searchButton->setObjectName("searchButton");
        searchButton->setGeometry(QRect(400, 140, 91, 31));
        searchButton->setFont(font);
        searchButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        searchButton->setStyleSheet(QString::fromUtf8("background-color: #000060; \n"
"color: white;             \n"
"border-radius: 0px;\n"
"padding: 5px; "));
        lineEdit_3 = new QLineEdit(page_3);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(402, 80, 191, 24));
        backButton_2 = new QPushButton(page_3);
        backButton_2->setObjectName("backButton_2");
        backButton_2->setGeometry(QRect(499, 290, 91, 31));
        backButton_2->setFont(font);
        backButton_2->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        backButton_2->setStyleSheet(QString::fromUtf8("background-color: #000060; \n"
"color: white;             \n"
"border-radius: 0px;\n"
"padding: 5px; "));
        label_4 = new QLabel(page_3);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(340, 80, 61, 16));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Yu Gothic UI")});
        font2.setPointSize(9);
        label_4->setFont(font2);
        searchButton_2 = new QPushButton(page_3);
        searchButton_2->setObjectName("searchButton_2");
        searchButton_2->setGeometry(QRect(520, 140, 91, 31));
        searchButton_2->setFont(font);
        searchButton_2->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        searchButton_2->setStyleSheet(QString::fromUtf8("background-color: #000060; \n"
"color: white;             \n"
"border-radius: 0px;\n"
"padding: 5px; "));
        stackedWidget->addWidget(page_3);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        pushButton = new QPushButton(page_2);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(380, 120, 80, 31));
        pushButton->setFont(font);
        pushButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: #000060; \n"
"color: white;             \n"
"border-radius: 0px;\n"
"padding: 5px; "));
        lineEdit_2 = new QLineEdit(page_2);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(350, 70, 113, 24));
        backButton = new QPushButton(page_2);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(380, 220, 80, 31));
        backButton->setFont(font);
        backButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        backButton->setStyleSheet(QString::fromUtf8("background-color: #000060; \n"
"color: white;             \n"
"border-radius: 0px;\n"
"padding: 5px; "));
        lineEdit = new QLineEdit(page_2);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(190, 70, 111, 24));
        label_2 = new QLabel(page_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(330, 70, 49, 16));
        label_3 = new QLabel(page_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(160, 70, 49, 16));
        pushButton_2 = new QPushButton(page_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(190, 220, 101, 31));
        pushButton_2->setFont(font);
        pushButton_2->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: #000060; \n"
"color: white;             \n"
"border-radius: 0px;\n"
"padding: 5px; "));
        stackedWidget->addWidget(page_2);

        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QString());
        insertButton->setText(QCoreApplication::translate("Widget", "Insert Points", nullptr));
        tableButton->setText(QCoreApplication::translate("Widget", "View Points", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "Proximity Scanning System", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Widget", "X", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Widget", "Y", nullptr));
        deleteButton->setText(QCoreApplication::translate("Widget", "Delete", nullptr));
        searchButton->setText(QCoreApplication::translate("Widget", "Search Square", nullptr));
        backButton_2->setText(QCoreApplication::translate("Widget", "Back", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "Set Radius", nullptr));
        searchButton_2->setText(QCoreApplication::translate("Widget", "Visualize", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "Enter", nullptr));
        backButton->setText(QCoreApplication::translate("Widget", "Back", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "Y:", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "X:", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "Pre-Defined pts", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
