
// STD
#include <iostream>

// QT
#include <QFile>
#include <QTextStream>

// PROJECT
#include "game.h"

Game::Game()
    : m_showCurrentlyFinished(true)
{
    QFile inputFile(":/recipies.txt");
    inputFile.open(QIODevice::ReadOnly);

    QTextStream in(&inputFile);
    for(auto line = in.readLine(); !line.isNull(); line = in.readLine())
    {
        bool isKnown = false;
        if(line.startsWith("*"))
        {
            isKnown = true;
            line.remove(0, 1);
        }
        QStringList numberSplit = line.split(". ");
        if(numberSplit.size() == 2)
        {
            QString formula = numberSplit[1];
            QStringList formulaSplit = formula.split(" = ");
            if(formulaSplit.size() == 2)
            {
                Element &product = getOrCreateElement(formulaSplit[0]);
                if(isKnown)
                {
                    m_knownElements.insert(&product);
                }
                QStringList recipies = formulaSplit[1].split(", ");
                for(auto &recipe: recipies)
                {
                    QStringList eductSplit = recipe.split(" + ");
                    if(eductSplit.size() == 2)
                    {
                        addOrCombineRecipe(getOrCreateElement(eductSplit[0]), getOrCreateElement(eductSplit[1]), &product);
                    }
                }
            }
            else if(formulaSplit.size() == 1)
            {
                Element &product = getOrCreateElement(formulaSplit[0]);
                if(isKnown)
                {
                    m_knownElements.insert(&product);
                }
            }
        }
    }

    updateShownElements();
}


void Game::selectElement(int index)
{
    if(index > -1 && index < m_shownElements.size())
    {
        m_shownSelectedElement.setOneElement(m_shownElements[index]);
        m_selectedElement = m_shownElements[index];
    }
    else
    {
        m_shownSelectedElement.clear();
        m_selectedElement = nullptr;
    }
    std::cout << index << " has been left clicked" << std::endl;
}


void Game::combineElement(int index)
{
    if(index > -1 && index < m_shownElements.size())
    {
        m_shownLastResults.clear();
        auto clickedElement = m_shownElements[index];
        if(m_selectedElement != nullptr)
        {
            // TODO: only search in attached recipies of the element
            auto recipe = findRecipe(*clickedElement, *m_selectedElement);

            if(recipe != m_recipies.end())
            {
                bool changed = false;
                QString productText = "";
                for(auto product: recipe->products())
                {
                    changed |= m_knownElements.insert(product).second;
                    productText += product->name() + ", ";
                    m_shownLastResults.addElement(product);
                }

                if(changed)
                {
                    updateShownElements();
                }
                std::cout << m_selectedElement->name().toStdString() << " + " << clickedElement->name().toStdString() << " --> " << productText.toStdString() << std::endl;
            }
            else
            {
                std::cout << m_selectedElement->name().toStdString() << " + " << clickedElement->name().toStdString() << " --> no reaction" << std::endl;
            }
        }
    }
    std::cout << index << " has been right clicked" << std::endl;
}

void Game::setShowTerminal(bool value)
{
    std::cout << "Show Terminal is now: " << value << std::endl;
}

void Game::setShowCurrentlyFinished(bool value)
{
    if(m_showCurrentlyFinished != value)
    {
        m_showCurrentlyFinished = value;
        updateShownElements();
    }
}

Element &Game::getOrCreateElement(const QString &name)
{
    if(m_allElements.find(name) == m_allElements.end())
    {
        m_allElements.emplace(name, Element(name));
    }

    return m_allElements.at(name);
}

std::list<Recipe>::iterator Game::findRecipe(Element const &firstEduct, Element const &secondEduct)
{
    for(auto oldCandidate = m_recipies.begin(); oldCandidate != m_recipies.end(); ++oldCandidate)
    {
        if(hasSameEducts(*oldCandidate, firstEduct, secondEduct))
        {
            return oldCandidate;
        }
    }

    return  m_recipies.end();
}

void Game::addOrCombineRecipe(Element &firstEduct, Element &secondEduct, Element *product)
{
    auto oldRecipe = findRecipe(firstEduct, secondEduct);

    if(oldRecipe != m_recipies.end())
    {
        oldRecipe->addProduct(product);
    }
    else
    {
        m_recipies.emplace_back(firstEduct, secondEduct, product);
    }

}

void Game::updateShownElements()
{
    m_shownElements.clear();
    for(auto &element: m_knownElements)
    {
        if(shouldBeShown(element))
        {
            m_shownElements.addElement(element);
        }
    }
}

bool Game::shouldBeShown(Element const *element) const
{
    if(!m_showCurrentlyFinished)
    {
        for(Recipe const* recipe: element->asEduct())
        {
            if(isKnown(&recipe->firstEduct()) && isKnown(&recipe->secondEduct()))
            {
                // recipe can be currently crafted
                for(Element const* product: recipe->products())
                {
                    if(!isKnown(product))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    return true;
}

bool Game::isKnown(Element const *element) const
{
    return m_knownElements.find(element) != m_knownElements.end();
}

