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
public:
    Game();

public:
    ElementModel* elements() {return &m_elements;}
    Q_INVOKABLE void addElement();

signals:
    void elementsChanged();

private:
    ElementModel m_elements;

};

#endif // GAME_H
