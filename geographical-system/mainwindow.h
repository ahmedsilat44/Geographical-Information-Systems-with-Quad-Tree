class insertPage;
class pointsTable;

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "insertpage.h"
#include "pointstable.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_insertButton_clicked();

    void on_tableButton_clicked();

private:
    Ui::Widget *ui;
    insertPage *insertpage;
    pointsTable *pointstable;
};
#endif // WIDGET_H
