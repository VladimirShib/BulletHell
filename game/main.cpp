#include <SFML/System.hpp>
#include "levels.h"
#include "player.h"

constexpr unsigned ANTIALIASING_LEVEL = 8;
constexpr unsigned WINDOW_WIDTH = 800;
constexpr unsigned WINDOW_HEIGHT = 600;
constexpr unsigned MAX_FPS = 60;

void createWindow(sf::RenderWindow& window)
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = ANTIALIASING_LEVEL;
    window.create(
        sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
        "YoRHa Game", sf::Style::Default, settings);
    window.setFramerateLimit(MAX_FPS);
}

void pollEvents(sf::RenderWindow& window, GameState& gameState, sf::Clock& clock)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }

        switch (gameState.state)
        {
        case GameWindow::MENU:
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Q)
                {
                    gameState.level = 1;
                    gameState.state = GameWindow::GAME; // start the game at level one
                    clock.restart();
                }
                else if (event.key.code == sf::Keyboard::L)
                {
                    gameState.state = GameWindow::SELECTION; // go to level selection menu
                }
            }
            break;
        case GameWindow::SELECTION:
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Num1)
                {
                    gameState.level = 1;
                    gameState.state = GameWindow::GAME; // start the game at the chosen level
                }
                else if (event.key.code == sf::Keyboard::Num2)
                {
                    gameState.level = 2;
                    gameState.state = GameWindow::GAME; // start the game at the chosen level
                }
            }
            break;
        case GameWindow::GAME:
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                gameState.state = GameWindow::PAUSE;
            }
            break;
        case GameWindow::PAUSE:
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                gameState.state = GameWindow::GAME;
                clock.restart();
            }
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::M)
            {
                gameState.state = GameWindow::MENU;
            }
            break;
        default:
            break;
        }
    }
}

void update(sf::RenderWindow& window, GameState& gameState, Player& player, Data& data, Bullets& bullets, sf::Clock& clock)
{
    switch (gameState.state)
    {
    case GameWindow::GAME:
    {
        const float deltaTime = clock.restart().asSeconds();
        updatePlayer(window, player, data);
        updateBullets(data, bullets, deltaTime);
    }
        break;
    default:
        break;
    }
}

void render(sf::RenderWindow& window, GameState& gameState, const Player& player, const Bullets& bullets)
{
    window.clear(sf::Color(0xC7, 0xC3, 0x9B));

    switch (gameState.state)
    {
    case GameWindow::PAUSE:
    case GameWindow::GAME:
    {
        window.draw(player);
        for (auto& bullet : bullets.playerBullets)
        {
            window.draw(bullet);
        }
    }
        break;
    default:
        break;
    }

    window.display();
}

int main()
{
    sf::RenderWindow window;
    createWindow(window);

    GameState gameState;
    gameState.state = GameWindow::MENU;
    gameState.level = 0;

    Player player;
    player.setPosition(sf::Vector2f(400, 300));

    Data data;
    Bullets bullets;

    sf::Clock clock;
    while (window.isOpen())
    {
        pollEvents(window, gameState, clock);
        update(window, gameState, player, data, bullets, clock);
        render(window, gameState, player, bullets);
    }
}