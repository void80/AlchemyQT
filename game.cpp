
// STD
#include <iostream>

// PROJECT
#include "game.h"

Game::Game()
{

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
