#include "game.h"

Game::Game() : window(
    sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
    "YoRHa Game",
    sf::Style::Titlebar, // | sf::Style::Close,
    sf::ContextSettings(0, 0, ANTIALIASING_LEVEL, 1, 1)
)
{
    window.setFramerateLimit(MAX_FPS);
    state = GameState::MENU;
}

void Game::Run()
{
    Transition transition;
    Pause pause;

    while (window.isOpen())
    {
        switch (state)
        {
        case GameState::MENU:
            ManageMainMenu(transition);
            break;
        case GameState::GAME:
            ManageGame(transition, pause);
            break;
        default:
            break;
        }
    }
}

void Game::ManageMainMenu(Transition& transition)
{
    Menu menu;

    while (transition.isTransitioning)
    {
        transition.FadingOut();
        window.clear(sf::Color(0xC6, 0xC2, 0xA5));
        window.draw(menu);
        window.draw(transition);
        window.display();
    }

    while (window.isOpen())
    {
        menu.PollEvents(window, event, transition.isTransitioning, currentLevel);
        window.clear(sf::Color(0xC6, 0xC2, 0xA5));
        window.draw(menu);
        if (transition.isTransitioning)
        {
            transition.FadingIn();
            window.draw(transition);
            if (transition.screenOff)
            {
                state = GameState::GAME;
                return;
            }
        }
        window.display();
    }
}

void Game::ManageGame(Transition& transition, const Pause& pause)
{
    int levelStatus;
    while (window.isOpen())
    {
        switch (currentLevel)
        {
        case 0:
        {
            levelStatus = playLevel0(window, event, clock, transition, pause);
            switch (levelStatus)
            {
            case 2:
                state = GameState::MENU;
                return;
            default:
                break;
            }
        }
            break;
        default:
            break;
        }
    }
}