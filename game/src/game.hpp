#pragma once

#include "headers.hpp"
#include "screens.hpp"
#include "levels.hpp"

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
    void ManageMenu(Transition& transition, MusicManager& sounds);
    void ManageMainMenu(const Menu& menu, Transition& transition, MusicManager& sounds);
    void ManageSelectionMenu(const Menu& menu, Transition& transition, MusicManager& sounds);
    void ManageGame(Screens& screens, MusicManager& sounds);

public:
    sf::RenderWindow window;
    sf::View view;
    sf::Event event;
    sf::Clock clock;

private:
    GameState state;
    int currentLevel;
};