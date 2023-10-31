#pragma once

#include "headers.h"
#include "levels.h"

constexpr int MAX_MAIN_MENU_ITEMS = 3;

class MenuSelectedBg : public sf::Drawable, public sf::Transformable
{
public:
    MenuSelectedBg();

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        target.draw(background, states);
    }

    sf::VertexArray background;
};

class Menu : public sf::Drawable
{
public:
    Menu();

    void MoveUp();
    void MoveDown();
    int getPressedItem() { return selectedItemIndex; }

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(menuAllBg, states);
        target.draw(menuSelectedBg, states);
        for (int i = 0; i < MAX_MAIN_MENU_ITEMS; ++i)
        {
            target.draw(menu[i], states);
        }
    }

    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_MAIN_MENU_ITEMS];
    sf::VertexArray menuAllBg;
    MenuSelectedBg menuSelectedBg;

    sf::Vector2f menuPositions[MAX_MAIN_MENU_ITEMS];
};

class Transition : public sf::Drawable
{
public:
    Transition();

    bool fading = false;
    float alpha;
    void ToGame(GameState& gameState, sf::Clock& clock);
    // void ToMenu();

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(rectangle, states);
    }

    sf::VertexArray rectangle;
};

class Pause : public sf::Drawable
{
public:
    Pause();

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(background, states);
        target.draw(textCenter, states);
        target.draw(buttons, states);
        target.draw(actions, states);
    }

    sf::Font font;
    sf::Text textCenter;
    sf::Text buttons;
    sf::Text actions;
    sf::VertexArray background;
};

struct Screens
{
    Menu menu;
    Transition transition;
    Pause pause;
};