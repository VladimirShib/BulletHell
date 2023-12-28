#pragma once

#include "headers.hpp"
#include "sound.hpp"

constexpr int MAX_MAIN_MENU_ITEMS = 3;
constexpr int MAX_SELECTION_MENU_ITEMS = 32;

class Menu : public sf::Drawable
{
public:
    Menu();

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(background, states);
        target.draw(titleShadow, states);
        target.draw(title, states);
        target.draw(select, states);
        target.draw(selectButtons, states);
        target.draw(confirm, states);
        target.draw(confirmButton, states);
    }

    sf::Font font;
    sf::Text title;
    sf::Text titleShadow;
    sf::Text select;
    sf::Text selectButtons;
    sf::Text confirm;
    sf::Text confirmButton;
    sf::VertexArray background;
};

class MainMenuSelectedItem : public sf::Drawable, public sf::Transformable
{
public:
    MainMenuSelectedItem();

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        target.draw(background, states);
    }

    sf::VertexArray background;
};

class MainMenu : public sf::Drawable
{
public:
    MainMenu(int record);

    void PollEvents(sf::RenderWindow& window, sf::Event& event, bool& isTransitioning, int& level, MusicManager& sounds);
    void MoveUp(MusicManager& sounds);
    void MoveDown(MusicManager& sounds);
    int GetPressedItem() { return selectedItemIndex; }

public:
    bool toSelection;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(background, states);
        target.draw(statistics, states);
        target.draw(selectedItem, states);
        for (int i = 0; i < MAX_MAIN_MENU_ITEMS; ++i)
        {
            target.draw(menuItem[i], states);
        }
    }

    int selectedItemIndex;
    sf::Font font;
    sf::Text menuItem[MAX_MAIN_MENU_ITEMS];
    sf::Text statistics;
    sf::VertexArray background;
    MainMenuSelectedItem selectedItem;

    sf::Vector2f menuPositions[MAX_MAIN_MENU_ITEMS];
};

class SelectionMenuSelectedItem : public sf::Drawable, public sf::Transformable
{
public:
    SelectionMenuSelectedItem();

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        target.draw(background, states);
    }

    sf::VertexArray background;
};

class Selection : public sf::Drawable
{
public:
    Selection();

    void PollEvents(sf::RenderWindow& window, sf::Event& event, bool& isTransitioning, int& level, MusicManager& sounds);
    void MoveUp(MusicManager& sounds);
    void MoveDown(MusicManager& sounds);
    void MoveLeft(MusicManager& sounds);
    void MoveRight(MusicManager& sounds);
    int GetPressedItem() { return selectedItemIndex; }

public:
    bool toMainMenu;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(background, states);
        target.draw(selectedItem, states);
        for (int i = 0; i < MAX_SELECTION_MENU_ITEMS; ++i)
        {
            target.draw(menuItem[i], states);
        }
        target.draw(hintText, states);
        target.draw(backButton, states);
        target.draw(backText, states);
    }

    int selectedItemIndex;
    sf::Font font;
    sf::Text menuItem[MAX_SELECTION_MENU_ITEMS];
    sf::Text hintText;
    sf::Text backButton;
    sf::Text backText;
    sf::VertexArray background;
    SelectionMenuSelectedItem selectedItem;

    sf::Vector2f menuPositions[MAX_SELECTION_MENU_ITEMS];
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

class Complete : public sf::Drawable
{
public:
    Complete();

    void FadingIn();
    void Reset();

public:
    bool isNotVisible;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(background, states);
        if (!isNotVisible)
        {
            target.draw(levelComplete, states);
        }
    }

    sf::Font font;
    sf::Text levelComplete;
    sf::VertexArray background;
    int alphaDark;
    int alphaLight;
    int transitionSpeedDark;
    int transitionSpeedLight;
};

class Failed : public sf::Drawable
{
public:
    Failed();

    void FadingIn();
    void Reset();

public:
    bool isNotVisible;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(background, states);
        if (!isNotVisible)
        {
            target.draw(levelFailed, states);
        }
    }

    sf::Font font;
    sf::Text levelFailed;
    sf::VertexArray background;
    int alphaDark;
    int alphaLight;
    int transitionSpeedDark;
    int transitionSpeedLight;
};

struct Screens
{
    Transition transition;
    Pause pause;
    Complete complete;
    Failed failed;
};

class StatScreen : public sf::Drawable
{
public:
    StatScreen(int previousRecord, int newRecord);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(background, states);
        target.draw(result, states);
        target.draw(title, states);
        target.draw(record, states);
        target.draw(levels, states);
        target.draw(button, states);
    }

    sf::Font font;
    sf::Text result;
    sf::Text title;
    sf::Text record;
    sf::Text levels;
    sf::Text button;
    sf::VertexArray background;
};