#ifndef TREEVIEWMODEL_H
#define TREEVIEWMODEL_H

#include <QStandardItemModel>

class TreeViewModel : public QStandardItemModel
{
    Q_OBJECT
public:
    explicit TreeViewModel(QObject *parent = 0);

    enum Roles {
        TextRole,
        CheckBoxRole
    };
    Q_ENUM(Roles)

    /*
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE
    {
        if (index.isValid()) {
            switch (role) {
            case StringRole:
                return QVariant( this->data(index, Qt::DisplayRole));
            case CheckboxRole:
                return QVariant( this->data(index, Qt::CheckStateRole));
            default:
                break;
            }
        }
        return QStandardItemModel::data(index, role);
    }*/

    QHash<int,QByteArray> roleNames() const Q_DECL_OVERRIDE
    {
         QHash<int, QByteArray> result;
         result[TextRole] = "textRole";
         result[CheckBoxRole] = "checkBoxRole";
         return result;
    }
};

#endif // TREEVIEWMODEL_H
