
#include "myplugin.h"

#include <QDebug>

#include "sometype.h"

#include "mydependency.h"

MyPlugin::MyPlugin(QObject* parent)
: QObject(parent)
{
}

void MyPlugin::doSomething()
{
    qDebug() << typeid(TYPE_TO_REGISTER).name();
    auto s1 = registerType<TYPE_TO_REGISTER>();
    auto s2 = registerType<TYPE_TO_REGISTER>();
    
    qDebug() << "in plugin1" << s1;
    qDebug() << "in plugin1" << s2;
}
