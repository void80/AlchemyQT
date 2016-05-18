
// PROJECT
#include "element.h"


Element::Element(const QString &name)
    : m_name(name)
{
}

void Element::addAsEduct(const Recipe *recipe)
{
    m_asEduct.insert(recipe);
}

void Element::addAsProduct(const Recipe *recipe)
{
    m_asProduct.insert(recipe);
}

