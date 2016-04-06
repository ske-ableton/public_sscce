
#include "otherplugin.h"

#include <QDebug>

#include "sometype.h"

#include "mydependency.h"

OtherPlugin::OtherPlugin(QObject* parent)
: QObject(parent)
{
}

void OtherPlugin::doSomething()
{
    qDebug() << typeid(TYPE_TO_REGISTER).name();
    auto s1 = registerType<TYPE_TO_REGISTER>();
    auto s2 = registerType<TYPE_TO_REGISTER>();

    qDebug() << "in plugin2" << s1;
    qDebug() << "in plugin2" << s2;
}
