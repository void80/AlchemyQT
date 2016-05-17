#ifndef RECIPE_H
#define RECIPE_H

// STD
#include <vector>

// PROJECT

// FORWARD
class Element;

class Recipe
{
public:
    Recipe(Element &firstEduct, Element &secondEduct, Element *product);

public:
    void addProduct(Element *product);

    Element const &firstEduct() const;
    Element const &secondEduct() const;

private:
    Element &m_firstEduct;
    Element &m_secondEduct;
    std::vector<Element *> m_products;
};

bool hasSameEducts(const Recipe &lhs, Element const &firstEduct, Element const &secondEduct);
bool haveSameEducts(const Recipe &lhs, const Recipe &rhs);

#endif // RECIPE_H
