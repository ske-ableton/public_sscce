
#include <QCoreApplication>
#include <QPluginLoader>
#include <QDebug>

#include <unordered_map>
#include <typeindex>
#include <typeinfo>

#include "mydependency.h"
#include "sometype.h"

#include "myplugininterface.h"

int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);

    // Pre-registering the type fixes the problem
    // registerType<TYPE_TO_REGISTER>();

    for (QString pluginName : {"myplugin", "otherplugin"})
    {
        QPluginLoader loader(BUILD_DIR "/lib" + pluginName + ".so");
        // Setting this hint fixes the problem
        // loader.setLoadHints(QLibrary::ExportExternalSymbolsHint);
        QObject* obj = loader.instance();
        MyPluginInterface* iface = qobject_cast<MyPluginInterface*>(obj);
        Q_ASSERT(iface);
        iface->doSomething();
    }
    
    return 0;
}
