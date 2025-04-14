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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *insertButton;
    QPushButton *tableButton;
    QLabel *label;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 600);
        Widget->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        insertButton = new QPushButton(Widget);
        insertButton->setObjectName("insertButton");
        insertButton->setGeometry(QRect(280, 120, 80, 24));
        insertButton->setCursor(QCursor(Qt::CursorShape::SplitVCursor));
        insertButton->setAutoDefault(false);
        tableButton = new QPushButton(Widget);
        tableButton->setObjectName("tableButton");
        tableButton->setGeometry(QRect(280, 180, 80, 24));
        tableButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 131, 16));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        insertButton->setText(QCoreApplication::translate("Widget", "Insert Points", nullptr));
        tableButton->setText(QCoreApplication::translate("Widget", "View Points", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
