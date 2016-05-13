#include "model.h"


QHash<int, QByteArray> ElementModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    return roles;
}


Element::Element(const QString &name)
    : m_name(name)
{
}

ElementModel::ElementModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

void ElementModel::addElement(const Element &animal)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_elements << animal;
    endInsertRows();
}

int ElementModel::rowCount(const QModelIndex & parent) const {
    Q_UNUSED(parent);
    return m_elements.count();
}

QVariant ElementModel::data(QModelIndex const &index, int role) const
{
    if(index.row() < 0 || index.row() >= m_elements.count())
    {
        return QVariant();
    }

    const Element &animal = m_elements[index.row()];
    if(role == NameRole)
    {
        return animal.name();
    }

    return QVariant();
}
