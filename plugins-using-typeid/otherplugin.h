
#pragma once

#include <QObject>

#include "myplugininterface.h"

class OtherPlugin : public QObject, public MyPluginInterface
{
    Q_OBJECT
    Q_INTERFACES(MyPluginInterface)
    Q_PLUGIN_METADATA(IID "org.example.MyPluginInterface")
public:
    OtherPlugin(QObject* parent = nullptr);
    
    void doSomething() override;
};
