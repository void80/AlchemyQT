
// STD
#include <iostream>

// QT
#include <QFile>
#include <QTextStream>

// PROJECT
#include "game.h"

Game::Game()
{
    QFile inputFile(":/input.txt");
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
                QStringList recipies = formulaSplit[1].split(", ");
                for(auto &recipe: recipies)
                {
                    QStringList eductSplit = recipe.split(" + ");
                    if(eductSplit.size() == 2)
                    {
                        Recipe newRecipe(getOrCreateElement(eductSplit[0]), getOrCreateElement(eductSplit[1]), &product);
                        addOrCombineRecipe(newRecipe);
                    }
                }
            }
        }
    }

    m_shownElements.addElement(Element("Air"));
    m_shownElements.addElement(Element("Water"));
    m_shownElements.addElement(Element("Fire"));
    m_shownElements.addElement(Element("Earth"));

    m_selectedElement.addElement(Element("Selected"));
}

void Game::addElement()
{
    m_shownElements.addElement(Element("New Element"));
    std::cout << "Added Element" << std::endl;
}

void Game::selectElement(int index)
{
    if(index > -1 && index < m_shownElements.size())
    {
        m_selectedElement.setOneElement(m_shownElements[index]);
    }
    else
    {
        m_selectedElement.clear();
    }
    std::cout << index << " has been clicked" << std::endl;
}


void Game::combineElement(int index)
{
    if(index > -1 && index < m_shownElements.size())
    {

    }
}

Element &Game::getOrCreateElement(const QString &name)
{
    if(m_allElements.find(name) == m_allElements.end())
    {
        m_allElements.emplace(name, Element(name))
    }

    return m_allElements[name];
}

void Game::addOrCombineRecipe(Recipe recipe) // TODO: rvalue ref?
{
    auto oldRecipe = m_recipies.find(recipe);

    if(oldRecipe != m_recipies.end())
    {
        recipe.combine(*oldRecipe);
        m_recipies.erase(oldRecipe);
    }

    m_recipies.insert(recipe);
}
