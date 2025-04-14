class insertPage;
class pointsTable;

#ifndef WIDGET_H
#define WIDGET_H

#include "Quadtree.h"

#include <QWidget>


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

    void on_backButton_2_clicked();

    void on_backButton_clicked();

    void on_pushButton_clicked();

    void populateTableWidget();

    void on_searchButton_clicked();

    void on_pushButton_2_clicked();

    void on_searchButton_2_clicked();

private:
    Ui::Widget *ui;

    Quadtree *quadtree; // quadtree pointer
    
signals:
    void pointInserted();  // Custom signal
};
#endif // WIDGET_H
