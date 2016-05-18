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

    std::set<const Recipe *> const &asEduct() const {return m_asEduct;}

private:
    QString m_name;

    std::set<Recipe const *> m_asEduct;
    std::set<Recipe const *> m_asProduct;

};

inline bool operator==(Element const &lhs, Element const &rhs)
{
    return lhs.name() == rhs.name();
}

#endif // ELEMENT_H
