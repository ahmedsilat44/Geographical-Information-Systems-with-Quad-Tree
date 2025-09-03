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
        stackedWidget->setGeometry(QRect(-10, 30, 631, 381));
        stackedWidget->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        page = new QWidget();
        page->setObjectName("page");
        insertButton = new QPushButton(page);
        insertButton->setObjectName("insertButton");
        insertButton->setGeometry(QRect(270, 140, 80, 24));
        insertButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        insertButton->setAutoDefault(false);
        tableButton = new QPushButton(page);
        tableButton->setObjectName("tableButton");
        tableButton->setGeometry(QRect(270, 200, 80, 24));
        tableButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
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
        tableWidget->setGeometry(QRect(70, 80, 241, 192));
        tableWidget->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        deleteButton = new QPushButton(page_3);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setGeometry(QRect(330, 140, 80, 24));
        searchButton = new QPushButton(page_3);
        searchButton->setObjectName("searchButton");
        searchButton->setGeometry(QRect(430, 140, 80, 24));
        lineEdit_3 = new QLineEdit(page_3);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(402, 80, 181, 24));
        backButton_2 = new QPushButton(page_3);
        backButton_2->setObjectName("backButton_2");
        backButton_2->setGeometry(QRect(500, 290, 80, 24));
        backButton_2->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        label_4 = new QLabel(page_3);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(340, 80, 61, 16));
        searchButton_2 = new QPushButton(page_3);
        searchButton_2->setObjectName("searchButton_2");
        searchButton_2->setGeometry(QRect(520, 140, 80, 24));
        stackedWidget->addWidget(page_3);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        pushButton = new QPushButton(page_2);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(200, 280, 80, 24));
        lineEdit_2 = new QLineEdit(page_2);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(350, 70, 113, 24));
        backButton = new QPushButton(page_2);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(380, 280, 80, 24));
        backButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        lineEdit = new QLineEdit(page_2);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(190, 70, 113, 24));
        label_2 = new QLabel(page_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(330, 70, 49, 16));
        label_3 = new QLabel(page_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(160, 70, 49, 16));
        pushButton_2 = new QPushButton(page_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(80, 290, 80, 24));
        stackedWidget->addWidget(page_2);

        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QString());
        insertButton->setText(QCoreApplication::translate("Widget", "Insert Points", nullptr));
        tableButton->setText(QCoreApplication::translate("Widget", "View Points", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Widget", "X", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Widget", "Y", nullptr));
        deleteButton->setText(QCoreApplication::translate("Widget", "Delete", nullptr));
        searchButton->setText(QCoreApplication::translate("Widget", "Search Square", nullptr));
        backButton_2->setText(QCoreApplication::translate("Widget", "Back", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "Set Radius", nullptr));
        searchButton_2->setText(QCoreApplication::translate("Widget", "Search Circle", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "Enter", nullptr));
        backButton->setText(QCoreApplication::translate("Widget", "Back", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "Y:", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "X:", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "pre", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
