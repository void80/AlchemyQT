
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

Element const &Recipe::firstEduct() const
{
    return m_firstEduct;
}

Element const &Recipe::secondEduct() const
{
    return m_secondEduct;
}



bool CompareUsingEducts::operator()(const Recipe &lhs, const Recipe &rhs)
{
    auto lhsFirst = &lhs.firstEduct();
    auto lhsSecond = &lhs.secondEduct();
    if(lhsSecond < lhsFirst)
    {
        std::swap(lhsFirst, lhsSecond);
    }

    auto rhsFirst = &rhs.firstEduct();
    auto rhsSecond = &rhs.secondEduct();
    if(rhsSecond < rhsFirst)
    {
        std::swap(rhsFirst, rhsSecond);
    }


    if(lhsFirst != rhsFirst)
    {
        return lhsFirst < rhsFirst;
    }
    else
    {
        return lhsSecond < rhsSecond;
    }
}
