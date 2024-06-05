#include "itemwidget.h"
#include "ui_itemwidget.h"

itemWidget::itemWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::itemWidget)
{
    ui->setupUi(this);

    connect(ui->pushButton_2, &QPushButton::click, [=](){
       emit SIG_expendClick();
    });
}

itemWidget::~itemWidget()
{
    delete ui;
}

void itemWidget::setText(const QString &text)
{
    ui->pushButton->setText(text);
}
