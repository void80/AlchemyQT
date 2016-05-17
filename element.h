#ifndef ELEMENT_H
#define ELEMENT_H

// STD
#include <set>

// QT
#include <QString>

// FORWARD
class Recipe;


class Element
{
public:
    Element(const QString &name);

public:
    QString name() const {return m_name;}

    void addAsEduct(Recipe const *recipe);
    void addAsProduct(Recipe const *recipe);

private:
    QString m_name;

    std::set<Recipe const *> m_asEduct;
    std::set<Recipe const *> m_asProduct;

};

#endif // ELEMENT_H
