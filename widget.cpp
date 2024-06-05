#include "widget.h"
#include "ui_widget.h"
#include "itemwidget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->treeWidget->setRootIsDecorated(false);

    QTreeWidgetItem *root = new QTreeWidgetItem(ui->treeWidget, QStringList(""));


    itemWidget *item0 = new itemWidget;
    ui->treeWidget->setItemWidget(root, 0, item0);
    item0->setText(QStringLiteral("导航一"));
    connect(item0, &itemWidget::SIG_expendClick,[=](){
        ui->treeWidget->expandItem(root);
    });

    itemWidget *item01 = new itemWidget;
    item01->setText(QStringLiteral("子项一"));
    QTreeWidgetItem *child1 = new QTreeWidgetItem(root, QStringList(""));
    ui->treeWidget->setItemWidget(child1, 0, item01);

    itemWidget *item02 = new itemWidget;
    item02->setText(QStringLiteral("子项二"));
    QTreeWidgetItem *child2 = new QTreeWidgetItem(root, QStringList(""));
    ui->treeWidget->setItemWidget(child2, 0, item02);

    itemWidget *item1 = new itemWidget;
    item1->setText(QStringLiteral("导航二"));
    QTreeWidgetItem *root1 = new QTreeWidgetItem(ui->treeWidget, QStringList(""));
    ui->treeWidget->setItemWidget(root1, 0, item1);

    itemWidget *item2 = new itemWidget;
    item2->setText(QStringLiteral("导航三"));
    QTreeWidgetItem *root2 = new QTreeWidgetItem(ui->treeWidget, QStringList(""));
    ui->treeWidget->setItemWidget(root2, 0, item2);
}

Widget::~Widget()
{
    delete ui;
}

