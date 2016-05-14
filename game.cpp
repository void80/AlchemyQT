
// STD
#include <iostream>

// PROJECT
#include "game.h"

Game::Game()
{
    m_elements.addElement(Element("Air"));
    m_elements.addElement(Element("Water"));
    m_elements.addElement(Element("Fire"));
    m_elements.addElement(Element("Earth"));
}

void Game::addElement()
{
    m_elements.addElement(Element("New Element"));
    std::cout << "Added Element" << std::endl;
}
