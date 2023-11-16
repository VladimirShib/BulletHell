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
    MusicManager sounds;

    while (window.isOpen())
    {
        switch (state)
        {
        case GameState::MENU:
            ManageMainMenu(screens.transition, sounds);
            break;
        case GameState::GAME:
            ManageGame(screens, sounds);
            break;
        default:
            break;
        }
    }
}

void Game::ManageMainMenu(Transition& transition, MusicManager& sounds)
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
        sounds.FadeOut();
    }
    sounds.TurnOnMenuMusic();

    while (window.isOpen())
    {
        menu.PollEvents(window, event, transition.isTransitioning, currentLevel, sounds);
        window.clear(sf::Color(0xC6, 0xC2, 0xA5));
        window.draw(menu);
        if (transition.isTransitioning)
        {
            transition.FadingIn();
            window.draw(transition);
            sounds.FadeOut();
            if (transition.screenOff)
            {
                state = GameState::GAME;
                return;
            }
        }
        window.display();
    }
}

void Game::ManageGame(Screens& screens, MusicManager& sounds)
{
    int levelStatus;
    while (window.isOpen())
    {
        switch (currentLevel)
        {
        case 0:
        {
            levelStatus = playLevel0(window, view, event, clock, screens, sounds);
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
            levelStatus = playLevel1(window, view, event, clock, screens, sounds);
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