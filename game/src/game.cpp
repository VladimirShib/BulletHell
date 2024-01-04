#include "game.hpp"

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
    maxLevelsCleared = 0;
    freshStart = false;
    showingStat = false;
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
            ManageMenu(screens.transition, sounds);
            break;
        case GameState::GAME:
            ManageGame(screens, sounds);
            break;
        default:
            break;
        }
    }
}

void Game::ManageMenu(Transition& transition, MusicManager& sounds)
{
    Menu menu;
    sounds.TurnOnMenuMusic();

    while (window.isOpen())
    {
        switch (state)
        {
        case GameState::MENU:
            ManageMainMenu(menu, transition, sounds);
            break;
        case GameState::SELECTION:
            ManageSelectionMenu(menu, transition, sounds);
            break;
        case GameState::GAME:
            return;
        default:
            break;
        }
    }
}

void Game::ManageMainMenu(const Menu& menu, Transition& transition, MusicManager& sounds)
{
    MainMenu mainMenu(maxLevelsCleared);

    while (transition.isTransitioning)
    {
        transition.FadingOut();
        window.clear(sf::Color(0xC6, 0xC2, 0xA5));
        window.setView(window.getDefaultView());
        window.draw(menu);
        window.draw(mainMenu);
        window.draw(transition);
        window.display();
        sounds.FadeOut();
    }

    if (showingStat)
    {
        StatScreen stats(previousRecord, currentLevel);

        window.clear(sf::Color(0xC6, 0xC2, 0xA5));
        window.draw(menu);
        window.draw(mainMenu);
        window.draw(stats);
        window.display();
        while (showingStat)
        {
            window.pollEvent(event);
            if (event.type = sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                case sf::Keyboard::Return:
                case sf::Keyboard::Space:
                case sf::Keyboard::Escape:
                    sounds.pressSound.play();
                    showingStat = false;
                }
            }
        }
    }

    while (window.isOpen())
    {
        mainMenu.PollEvents(window, event, transition.isTransitioning, currentLevel, sounds);
        if (mainMenu.toSelection)
        {
            state = GameState::SELECTION;
            mainMenu.toSelection = false;
            return;
        }
        window.clear(sf::Color(0xC6, 0xC2, 0xA5));
        window.draw(menu);
        window.draw(mainMenu);
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

void Game::ManageSelectionMenu(const Menu& menu, Transition& transition, MusicManager& sounds)
{
    Selection selection;

    while (window.isOpen())
    {
        selection.PollEvents(window, event, transition.isTransitioning, currentLevel, sounds);
        if (selection.toMainMenu)
        {
            state = GameState::MENU;
            selection.toMainMenu = false;
            return;
        }
        window.clear(sf::Color(0xC6, 0xC2, 0xA5));
        window.draw(menu);
        window.draw(selection);
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
    if (currentLevel == 0)
    {
        freshStart = true;
    }
    while (window.isOpen())
    {
        levelStatus = loadLevel(window, view, event, clock, screens, sounds, currentLevel);
        switch (levelStatus)
        {
        case 1: // level completed
            currentLevel++;
            if (currentLevel < 27) // if level exists
            {
                break;
            }
        case 2: // level failed
        case 3: // exited manually
            if (freshStart && currentLevel > maxLevelsCleared)
            {
                previousRecord = maxLevelsCleared;
                maxLevelsCleared = currentLevel;
                showingStat = true;
            }
            freshStart = false;
            state = GameState::MENU;
            return;
        default:
            break;
        }
    }
}