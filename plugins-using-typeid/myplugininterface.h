
#pragma once

#include <QObject>

class MyPluginInterface
{
public:
    virtual ~MyPluginInterface() {}
    
    virtual void doSomething() = 0;
};

Q_DECLARE_INTERFACE(MyPluginInterface, "org.example.MyPluginInterface/1.0")
