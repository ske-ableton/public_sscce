
#pragma once

#include <QObject>

#include "myplugininterface.h"

class MyPlugin : public QObject, public MyPluginInterface
{
    Q_OBJECT
    Q_INTERFACES(MyPluginInterface)
    Q_PLUGIN_METADATA(IID "org.example.MyPluginInterface")
public:
    MyPlugin(QObject* parent = nullptr);
    
    void doSomething() override;
};
