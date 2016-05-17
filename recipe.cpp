
// PROJECT
#include "recipe.h"
#include "element.h"


Recipe::Recipe(Element &firstEduct, Element &secondEduct, std::vector<Element *> const &products)
    : m_firstEduct(firstEduct)
    , m_secondEduct(secondEduct)
    , m_products(products)
{
    m_firstEduct.addAsEduct(this);
    m_secondEduct.addAsEduct(this);
    for(auto &product: m_products)
    {
        product->addAsProduct(this);
    }
}
