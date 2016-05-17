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
    Recipe(Element &firstEduct, Element &secondEduct, std::vector<Element *> const &products);

private:

    Element &m_firstEduct;
    Element &m_secondEduct;
    std::vector<Element *> m_products;
};

#endif // RECIPE_H
