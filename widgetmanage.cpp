#include "widgetmanage.h"

widgetManage *widgetManage::instance = nullptr;

widgetManage::widgetManage(QObject *parent) : QObject(parent)
{

}

widgetManage *widgetManage::getInstance()
{
    if(instance == nullptr){
        instance = new widgetManage;
    }
    return instance;
}
