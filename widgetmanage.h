#ifndef WIDGETMANAGE_H
#define WIDGETMANAGE_H

#include <QObject>

class widgetManage : public QObject
{
    Q_OBJECT
public:

    static widgetManage *getInstance();

signals:

    void SIG_ItemExpendClick(QWidget *widget);

private:

    explicit widgetManage(QObject *parent = nullptr);

    static widgetManage* instance;


};

#endif // WIDGETMANAGE_H
