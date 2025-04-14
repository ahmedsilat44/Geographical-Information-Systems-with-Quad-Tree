/********************************************************************************
** Form generated from reading UI file 'insertpage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERTPAGE_H
#define UI_INSERTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_insertPage
{
public:
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLabel *label_2;
    QPushButton *enterPoint;
    QPushButton *backButton;

    void setupUi(QWidget *insertPage)
    {
        if (insertPage->objectName().isEmpty())
            insertPage->setObjectName("insertPage");
        insertPage->resize(348, 300);
        lineEdit = new QLineEdit(insertPage);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(40, 40, 113, 24));
        lineEdit_2 = new QLineEdit(insertPage);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(200, 40, 113, 24));
        label = new QLabel(insertPage);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 40, 49, 16));
        label_2 = new QLabel(insertPage);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(180, 40, 49, 16));
        enterPoint = new QPushButton(insertPage);
        enterPoint->setObjectName("enterPoint");
        enterPoint->setGeometry(QRect(40, 250, 80, 24));
        backButton = new QPushButton(insertPage);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(230, 250, 80, 24));

        retranslateUi(insertPage);

        QMetaObject::connectSlotsByName(insertPage);
    } // setupUi

    void retranslateUi(QWidget *insertPage)
    {
        insertPage->setWindowTitle(QCoreApplication::translate("insertPage", "Form", nullptr));
        label->setText(QCoreApplication::translate("insertPage", "X:", nullptr));
        label_2->setText(QCoreApplication::translate("insertPage", "Y:", nullptr));
        enterPoint->setText(QCoreApplication::translate("insertPage", "Enter", nullptr));
        backButton->setText(QCoreApplication::translate("insertPage", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class insertPage: public Ui_insertPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERTPAGE_H
