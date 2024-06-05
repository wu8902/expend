#ifndef ITEMWIDGET_H
#define ITEMWIDGET_H

#include <QWidget>

namespace Ui {
class itemWidget;
}

class itemWidget : public QWidget
{
    Q_OBJECT

public:
    explicit itemWidget(QWidget *parent = nullptr);
    ~itemWidget();

    void setText(const QString &text);

    void setIcon(const QString &iconPath);

    void setExpend(bool isExpend);

    void setExpendIconVisible(bool isVisble);

protected:

    virtual void mousePressEvent(QMouseEvent *event) override;

signals:

    void SIG_expendClick();

private:
    Ui::itemWidget *ui;
};

#endif // ITEMWIDGET_H
