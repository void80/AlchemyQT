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
    ~Recipe();

    operator // need rule of 3 (4)


public:
    void addProduct(Element *product);

    Element const &firstEduct() const;
    Element const &secondEduct() const;

private:
    Element &m_firstEduct;
    Element &m_secondEduct;
    std::vector<Element *> m_products;
};

class CompareUsingEducts
{
public:
    bool operator()(Recipe const &lhs, Recipe const &rhs);
};


#endif // RECIPE_H
