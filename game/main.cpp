#include <SFML/System.hpp>
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

void pollEvents(sf::RenderWindow& window)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
    }
}

void update(sf::RenderWindow& window, Player& player, Data& data, Bullets& bullets, sf::Clock& clock)
{
    const float deltaTime = clock.restart().asSeconds();
    updatePlayer(window, player, data);
    updateBullets(data, bullets, deltaTime);
}

void render(sf::RenderWindow& window, const Player& player, const Bullets& bullets)
{
    window.clear(sf::Color(0xC7, 0xC3, 0x9B));
    window.draw(player);
    for (auto& bullet : bullets.playerBullets)
    {
        window.draw(bullet);
    }
    window.display();
}

int main()
{
    sf::RenderWindow window;
    createWindow(window);

    Player player;
    player.setPosition(sf::Vector2f(400, 300));

    Data data;
    Bullets bullets;

    sf::Clock clock;
    while (window.isOpen())
    {
        pollEvents(window);
        update(window, player, data, bullets, clock);
        render(window, player, bullets);
    }
}