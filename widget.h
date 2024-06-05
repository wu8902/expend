#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMap>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class QTreeWidgetItem;
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    QMap<QWidget*, QTreeWidgetItem*> widget2TreeItem;
};
#endif // WIDGET_H
