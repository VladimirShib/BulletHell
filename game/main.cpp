#include "headers.h"
#include "screens.h"
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
        "YoRHa Game", sf::Style::Titlebar | sf::Style::Close, settings);
    window.setFramerateLimit(MAX_FPS);
}

void pollEvents(sf::RenderWindow& window, GameState& gameState, Screens& screens, sf::Clock& clock)
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
            switch (event.type)
            {
            case sf::Event::KeyPressed:
                switch (event.key.code)
                {
                case sf::Keyboard::Up:
                case sf::Keyboard::W:
                    screens.menu.MoveUp();
                    break;
                case sf::Keyboard::Down:
                case sf::Keyboard::S:
                    screens.menu.MoveDown();
                    break;
                case sf::Keyboard::Return:
                case sf::Keyboard::Space:
                    switch (screens.menu.getPressedItem())
                    {
                    case 0:
                    {
                        gameState.state = GameWindow::FADING_FROM_MENU;
                        gameState.level = 1;
                        screens.transition.fading = true;
                        //gameState.state = GameWindow::GAME; // start the game at level one
                    }
                        break;
                    case 1:
                        std::cout << "Select level button pressed\n";
                        // gameState.state = GameWindow::SELECTION; // go to level selection menu
                        break;
                    case 2:
                        window.close();
                        break;
                    default:
                        break;
                    }
                default:
                    break;
                }
            default:
                break;
            }
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
            switch (event.type)
            {
            case sf::Event::KeyPressed:
                switch (event.key.code)
                {
                case sf::Keyboard::Escape:
                {
                    gameState.state = GameWindow::GAME;
                    clock.restart();
                }
                    break;
                case sf::Keyboard::Q:
                    gameState.state = GameWindow::MENU;
                    break;
                default:
                    break;
                }
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
}

void update(sf::RenderWindow& window, GameState& gameState, Screens& screens, Player& player, Bullets& bullets, sf::Clock& clock)
{
    switch (gameState.state)
    {
    case GameWindow::FADING_FROM_MENU:
    case GameWindow::FADING_TO_GAME:
        screens.transition.ToGame(gameState, clock);
        break;
    case GameWindow::GAME:
    {
        const float deltaTime = clock.restart().asSeconds();
        updatePlayer(window, player);
        updateBullets(player, bullets, deltaTime);
    }
        break;
    default:
        break;
    }
}

void render(sf::RenderWindow& window, GameState& gameState, Screens& screens, const Player& player, const Bullets& bullets)
{
    window.clear(sf::Color(0xC7, 0xC3, 0x9B));

    switch (gameState.state)
    {
    case GameWindow::MENU:
        window.draw(screens.menu);
        break;
    case GameWindow::FADING_FROM_MENU:
    {
        window.draw(screens.menu);
        window.draw(screens.transition);
    }
        break;
    case GameWindow::FADING_TO_GAME:
    {
        window.draw(player);
        window.draw(screens.transition);
    }
        break;
    case GameWindow::GAME:
    {
        window.draw(player);
        for (auto& bullet : bullets.playerBullets)
        {
            window.draw(bullet);
        }
    }
        break;
    case GameWindow::PAUSE:
    {
        window.draw(player);
        for (auto& bullet : bullets.playerBullets)
        {
            window.draw(bullet);
        }
        window.draw(screens.pause);
        break;
    }
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

    Screens screens;

    Player player;
    player.setPosition(sf::Vector2f(400, 300));

    Bullets bullets;

    sf::Clock clock;
    while (window.isOpen())
    {
        pollEvents(window, gameState, screens, clock);
        update(window, gameState, screens, player, bullets, clock);
        render(window, gameState, screens, player, bullets);
    }
}