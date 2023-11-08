#pragma once

#include "headers.h"
#include "screens.h"
#include "levels.h"

constexpr unsigned ANTIALIASING_LEVEL = 8;
constexpr unsigned WINDOW_WIDTH = 1000;
constexpr unsigned WINDOW_HEIGHT = 700;
constexpr unsigned MAX_FPS = 60;

enum struct GameState
{
    MENU,
    SELECTION,
    GAME
};

class Game
{
public:
    Game();
    void Run();
    void ManageMainMenu(Transition& transition);
    void ManageGame(Transition& transition, const Pause& pause);

public:
    sf::Event event;
    sf::Clock clock;
    int currentLevel;

private:
    sf::RenderWindow window;
    GameState state;
};