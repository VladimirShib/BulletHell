#pragma once

#include "headers.h"

constexpr int MAX_MAIN_MENU_ITEMS = 3;

class MenuSelectedItem : public sf::Drawable, public sf::Transformable
{
public:
    MenuSelectedItem();

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

    void PollEvents(sf::RenderWindow& window, sf::Event& event, bool& isTransitioning, int& level);
    void MoveUp();
    void MoveDown();
    int GetPressedItem() { return selectedItemIndex; }

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(background, states);
        target.draw(menuSelectedItem, states);
        target.draw(titleShadow, states);
        target.draw(title, states);
        for (int i = 0; i < MAX_MAIN_MENU_ITEMS; ++i)
        {
            target.draw(menuItem[i], states);
        }
        target.draw(select, states);
        target.draw(selectButtons, states);
        target.draw(confirm, states);
        target.draw(confirmButton, states);
    }

    int selectedItemIndex;
    sf::Font font;
    sf::Text title;
    sf::Text titleShadow;
    sf::Text menuItem[MAX_MAIN_MENU_ITEMS];
    sf::Text select;
    sf::Text selectButtons;
    sf::Text confirm;
    sf::Text confirmButton;
    sf::VertexArray background;
    MenuSelectedItem menuSelectedItem;

    sf::Vector2f menuPositions[MAX_MAIN_MENU_ITEMS];
};

class Transition : public sf::Drawable
{
public:
    Transition();

    void FadingIn();
    void FadingOut();

public:
    bool isTransitioning;
    bool screenOff;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(rectangle, states);
    }

    sf::VertexArray rectangle;
    int alpha;
    int transitionSpeed;
};

class Pause : public sf::Drawable
{
public:
    Pause();

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(background, states);
        target.draw(paused, states);
        target.draw(resumeText, states);
        target.draw(resumeButton, states);
        target.draw(exitText, states);
        target.draw(exitButton, states);
    }

    sf::Font font;
    sf::Text paused;
    sf::Text resumeText;
    sf::Text resumeButton;
    sf::Text exitText;
    sf::Text exitButton;
    sf::VertexArray background;
};