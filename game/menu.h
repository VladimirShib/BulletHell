#pragma once

#include <SFML/Graphics.hpp>

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