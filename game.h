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
    Q_PROPERTY(ElementModel* lastResults READ lastResults NOTIFY lastResultsChanged)
public:
    Game();

public:
    ElementModel* elements() {return &m_shownElements;}
    ElementModel* selectedElement() {return &m_shownSelectedElement;}
    ElementModel* lastResults() {return &m_shownLastResults;}
    Q_INVOKABLE void selectElement(int index);
    Q_INVOKABLE void combineElement(int index);

    Q_INVOKABLE void setShowTerminal(bool value);
    Q_INVOKABLE void setShowCurrentlyFinished(bool value);

    std::list<Recipe>::iterator findRecipe(Element const &firstEduct, Element const &secondEduct);
signals:
    void elementsChanged();
    void selectedElementChanged();
    void lastResultsChanged();

private:
    Element &getOrCreateElement(QString const &name);
    void addOrCombineRecipe(Element &firstEduct, Element &secondEduct, Element *product);
    void updateShownElements();

    bool shouldBeShown(Element const *element) const;
    bool isKnown(Element const *element) const;
private:
    ElementModel m_shownElements;
    ElementModel m_shownSelectedElement;
    ElementModel m_shownLastResults;

    Element const *m_selectedElement;
    std::set<Element const *> m_knownElements;

    std::map<QString, Element> m_allElements;
    std::list<Recipe> m_recipies;

    bool m_showCurrentlyFinished;
};

#endif // GAME_H
