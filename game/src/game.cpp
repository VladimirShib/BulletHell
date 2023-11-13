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
    view.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
}

void Game::Run()
{
    Screens screens;

    while (window.isOpen())
    {
        switch (state)
        {
        case GameState::MENU:
            ManageMainMenu(screens.transition);
            break;
        case GameState::GAME:
            ManageGame(screens);
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
        window.setView(window.getDefaultView());
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

void Game::ManageGame(Screens& screens)
{
    int levelStatus;
    while (window.isOpen())
    {
        switch (currentLevel)
        {
        case 0:
        {
            levelStatus = playLevel0(window, view, event, clock, screens);
            switch (levelStatus)
            {
            case 1: // level completed
                currentLevel++;
                break;
            case 2: // level failed
            case 3: // exited manually
                state = GameState::MENU;
                return;
            default:
                break;
            }
        }
            break;
        case 1:
        {
            levelStatus = playLevel1(window, view, event, clock, screens);
            switch (levelStatus)
            {
            case 1:
                // currentLevel++;
                // break;
            case 2:
            case 3:
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