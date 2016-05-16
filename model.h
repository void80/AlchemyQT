#ifndef MODEL_H
#define MODEL_H

//#include <QObject>
#include <QAbstractListModel>
#include <QStringList>

class Element
{
public:
    Element(const QString &name);

    QString name() const {return m_name;}

private:
    QString m_name;

};


class ElementModel: public QAbstractListModel
{
    Q_OBJECT
public:
    enum AnimalRoles
    {
        NameRole = Qt::UserRole + 1
    };

    ElementModel(QObject *parent = 0);

    void addElement(const Element &element);

    int rowCount(const QModelIndex & parent = QModelIndex()) const;

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

    int size() const { return m_elements.size(); }
    void setOneElement(Element const &element);
    void clear();

    Element const &operator[](int index) const {return m_elements[index];}

protected:
    QHash<int, QByteArray> roleNames() const;
private:
    QList<Element> m_elements;
};


#endif // MODEL_H
