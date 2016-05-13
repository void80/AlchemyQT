#ifndef GAME_H
#define GAME_H

// QT
#include <QObject>

// PROJECT
#include "model.h"

class Game : public QObject
{
    Q_OBJECT
public:
    Game();

public:
    Q_INVOKABLE ElementModel &elements() {return m_elements;}

private:
    ElementModel m_model;

};

#endif // GAME_H
