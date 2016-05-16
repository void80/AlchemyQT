#ifndef GAME_H
#define GAME_H

// QT
#include <QObject>

// PROJECT
#include "model.h"

class Game : public QObject
{
    Q_OBJECT
    Q_PROPERTY(ElementModel* elements READ elements NOTIFY elementsChanged)
    Q_PROPERTY(ElementModel* selectedElement READ selectedElement NOTIFY selectedElementChanged)
public:
    Game();

public:
    ElementModel* elements() {return &m_elements;}
    ElementModel* selectedElement() {return &m_selectedElement;}
    Q_INVOKABLE void addElement();

signals:
    void elementsChanged();
    void selectedElementChanged();

private:
    ElementModel m_elements;
    ElementModel m_selectedElement;
};

#endif // GAME_H
