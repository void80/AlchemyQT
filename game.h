#ifndef GAME_H
#define GAME_H

// QT
#include <QObject>

// PROJECT
#include "model.h"
#include "recipe.h"

class Game : public QObject
{
    Q_OBJECT
    Q_PROPERTY(ElementModel* elements READ elements NOTIFY elementsChanged)
    Q_PROPERTY(ElementModel* selectedElement READ selectedElement NOTIFY selectedElementChanged)
public:
    Game();

public:
    ElementModel* elements() {return &m_shownElements;}
    ElementModel* selectedElement() {return &m_selectedElement;}
    Q_INVOKABLE void addElement();
    Q_INVOKABLE void selectElement(int index);
    Q_INVOKABLE void combineElement(int index);

signals:
    void elementsChanged();
    void selectedElementChanged();

private:
    ElementModel m_shownElements;
    ElementModel m_selectedElement;

    std::set<Element const *> m_knownElements;

    std::map<QString, Element> m_allElements;
    std::list<Recipe> m_recipies;
};

#endif // GAME_H
