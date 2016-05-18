
// PROJECT
#include "recipe.h"
#include "element.h"


Recipe::Recipe(Element &firstEduct, Element &secondEduct, Element *product)
    : m_firstEduct(firstEduct)
    , m_secondEduct(secondEduct)
    , m_products()
{
    m_firstEduct.addAsEduct(this);
    m_secondEduct.addAsEduct(this);
    addProduct(product);
}


void Recipe::addProduct(Element *product)
{
    m_products.push_back(product);
    product->addAsProduct(this);
}

bool haveSameEducts(const Recipe &lhs, const Recipe &rhs)
{
    return hasSameEducts(lhs, rhs.firstEduct(), rhs.secondEduct());
}


bool hasSameEducts(const Recipe &lhs, Element const &firstEduct, Element const &secondEduct)
{
    return
        (lhs.firstEduct() == firstEduct && lhs.secondEduct() == secondEduct)
    ||  (lhs.firstEduct() == secondEduct && lhs.secondEduct() == firstEduct)
    ;
}
