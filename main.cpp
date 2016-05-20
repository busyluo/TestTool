#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QStandardItemModel>

#include "ViewModels/treeviewmodel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    TreeViewModel model;
    QStandardItem * parentItem = model.invisibleRootItem();

    for (int j = 0; j < 4; ++j) {
        parentItem = model.invisibleRootItem();
        for (int i = 0; i < 4; ++i) {
            QStandardItem *item = new QStandardItem();
            item->setData(QString("item %0").arg(i), TreeViewModel::TextRole);
            item->setData(true, TreeViewModel::CheckBoxRole);
            parentItem->appendRow(item);
            parentItem = item;
        }

    }

    qmlRegisterUncreatableType<TreeViewModel>("ulan.treeviewmodel", 1, 0,
                                                       "TreeViewModel", "Cannot create a TreeViewModel instance.");
    engine.rootContext()->setContextProperty("treeViewModel", &model);
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    return app.exec();
}
