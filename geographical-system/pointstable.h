class Widget;

#ifndef POINTSTABLE_H
#define POINTSTABLE_H

#include <QWidget>
#include "mainwindow.h"

namespace Ui {
class pointsTable;
}

class pointsTable : public QWidget
{
    Q_OBJECT

public:
    explicit pointsTable(QWidget *parent = nullptr);
    ~pointsTable();

private slots:
    void on_backButton_clicked();

private:
    Ui::pointsTable *ui;
    Widget *mainwindow;
};

#endif // POINTSTABLE_H
