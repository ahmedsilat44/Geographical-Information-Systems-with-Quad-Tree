class Widget;

#ifndef INSERTPAGE_H
#define INSERTPAGE_H

#include <QWidget>
#include "mainwindow.h"

namespace Ui {
class insertPage;
}

class insertPage : public QWidget
{
    Q_OBJECT

public:
    explicit insertPage(QWidget *parent = nullptr);
    ~insertPage();

private slots:
    void on_backButton_clicked();

private:
    Ui::insertPage *ui;
    Widget *mainwindow;
};

#endif // INSERTPAGE_H
