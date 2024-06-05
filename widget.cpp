#include "widget.h"
#include "ui_widget.h"
#include "itemwidget.h"
#include "widgetmanage.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
//    ui->treeWidget->setStyleSheet("QTreeWidget::item:selected { background-color: none; }");

    ui->treeWidget->setRootIsDecorated(false);
    ui->treeWidget->setHeaderHidden(true);
    QTreeWidgetItem *root = new QTreeWidgetItem(ui->treeWidget, QStringList(""));

    itemWidget *item0 = new itemWidget;
    ui->treeWidget->setItemWidget(root, 0, item0);
    item0->setText(QStringLiteral("导航一"));
    item0->setIcon(":/images/iconfont-xingxing.svg");
    widget2TreeItem.insert(item0, root);

    itemWidget *item01 = new itemWidget;
    item01->setText(QStringLiteral("子项一"));
    QTreeWidgetItem *child1 = new QTreeWidgetItem(root, QStringList(""));
    ui->treeWidget->setItemWidget(child1, 0, item01);
    widget2TreeItem.insert(item01, child1);

    itemWidget *item02 = new itemWidget;
    item02->setText(QStringLiteral("子项二"));
    QTreeWidgetItem *child2 = new QTreeWidgetItem(root, QStringList(""));
    ui->treeWidget->setItemWidget(child2, 0, item02);
    widget2TreeItem.insert(item02, child2);

    itemWidget *item1 = new itemWidget;
    item1->setText(QStringLiteral("导航二"));
    QTreeWidgetItem *root1 = new QTreeWidgetItem(ui->treeWidget, QStringList(""));
    ui->treeWidget->setItemWidget(root1, 0, item1);
    item1->setIcon(":/images/iconfont-shouji.svg");
    widget2TreeItem.insert(item1, root1);

    itemWidget *item2 = new itemWidget;
    item2->setText(QStringLiteral("导航三"));
    QTreeWidgetItem *root2 = new QTreeWidgetItem(ui->treeWidget, QStringList(""));
    ui->treeWidget->setItemWidget(root2, 0, item2);
    item2->setIcon(":/images/iconfont-shipin.svg");

    widget2TreeItem.insert(item2, root2);

    connect(widgetManage::getInstance(), &widgetManage::SIG_ItemExpendClick,[=](QWidget*widget){
        if(widget2TreeItem.contains(widget)){

            if(widget2TreeItem[widget]->isExpanded()){
                ui->treeWidget->collapseItem(widget2TreeItem[widget]);
            } else {
                ui->treeWidget->expandItem(widget2TreeItem[widget]);
            }
        }
    } );

    connect(ui->treeWidget, &QTreeWidget::itemExpanded, [=](QTreeWidgetItem *item){
        QWidget *wgt = ui->treeWidget->itemWidget(item, 0);
        if(nullptr == wgt){
            return ;
        }

        itemWidget* itemWgt = qobject_cast<itemWidget*>(wgt);
        if(nullptr == itemWgt){
            return ;
        }
        itemWgt->setExpend(true);
    });

    connect(ui->treeWidget, &QTreeWidget::itemCollapsed, [=](QTreeWidgetItem *item){
        QWidget *wgt = ui->treeWidget->itemWidget(item, 0);
        if(nullptr == wgt){
            return ;
        }

        itemWidget* itemWgt = qobject_cast<itemWidget*>(wgt);
        if(nullptr == itemWgt){
            return ;
        }
        itemWgt->setExpend(false);
    });

    QMap<QWidget*, QTreeWidgetItem*>::const_iterator it;
    for (it = widget2TreeItem.constBegin(); it != widget2TreeItem.constEnd(); ++it) {
        QWidget* widget = it.key();
        QTreeWidgetItem* item = it.value();
        item->setFlags(item->flags() & ~Qt::ItemIsSelectable);
        itemWidget* itemWgt = qobject_cast<itemWidget*>(widget);
        if(itemWgt){
            itemWgt->setExpendIconVisible(item->childCount() != 0);
        }
    }

}

Widget::~Widget()
{
    delete ui;
}

