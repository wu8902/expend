#include "itemwidget.h"
#include "ui_itemwidget.h"
#include "widgetmanage.h"

itemWidget::itemWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::itemWidget)
{
    ui->setupUi(this);

    connect(ui->pushButton_2, &QPushButton::clicked, [=](){
       emit widgetManage::getInstance()->SIG_ItemExpendClick(this);
    });
    ui->iconButton->setVisible(false);
}

itemWidget::~itemWidget()
{
    delete ui;
}

void itemWidget::setText(const QString &text)
{
    ui->pushButton->setText(text);
}

void itemWidget::setIcon(const QString &iconPath)
{
    ui->iconButton->setVisible(true);
    ui->iconButton->setIcon(QIcon(iconPath));
}

void itemWidget::setExpend(bool isExpend)
{
    ui->pushButton_2->setIcon(isExpend ? QIcon(":/images/arrow_down.svg"):QIcon(":/images/arrow_right.svg"));
}

void itemWidget::setExpendIconVisible(bool isVisble)
{
    ui->pushButton_2->setVisible(isVisble);
}

void itemWidget::mousePressEvent(QMouseEvent *event)
{
    emit widgetManage::getInstance()->SIG_ItemExpendClick(this);
    return QWidget::mousePressEvent(event);
}
