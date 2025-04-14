/********************************************************************************
** Form generated from reading UI file 'pointstable.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POINTSTABLE_H
#define UI_POINTSTABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pointsTable
{
public:
    QTableWidget *tableWidget;
    QPushButton *searchButton;
    QPushButton *deleteButton;
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *backButton;

    void setupUi(QWidget *pointsTable)
    {
        if (pointsTable->objectName().isEmpty())
            pointsTable->setObjectName("pointsTable");
        pointsTable->resize(497, 300);
        tableWidget = new QTableWidget(pointsTable);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(20, 50, 201, 192));
        searchButton = new QPushButton(pointsTable);
        searchButton->setObjectName("searchButton");
        searchButton->setGeometry(QRect(410, 110, 80, 24));
        deleteButton = new QPushButton(pointsTable);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setGeometry(QRect(310, 110, 80, 24));
        lineEdit = new QLineEdit(pointsTable);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(312, 50, 181, 24));
        label = new QLabel(pointsTable);
        label->setObjectName("label");
        label->setGeometry(QRect(250, 50, 61, 16));
        backButton = new QPushButton(pointsTable);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(410, 260, 80, 24));

        retranslateUi(pointsTable);

        QMetaObject::connectSlotsByName(pointsTable);
    } // setupUi

    void retranslateUi(QWidget *pointsTable)
    {
        pointsTable->setWindowTitle(QCoreApplication::translate("pointsTable", "Form", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("pointsTable", "X", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("pointsTable", "Y", nullptr));
        searchButton->setText(QCoreApplication::translate("pointsTable", "Search", nullptr));
        deleteButton->setText(QCoreApplication::translate("pointsTable", "Delete", nullptr));
        label->setText(QCoreApplication::translate("pointsTable", "Set Radius", nullptr));
        backButton->setText(QCoreApplication::translate("pointsTable", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pointsTable: public Ui_pointsTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POINTSTABLE_H
