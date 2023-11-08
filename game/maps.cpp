#include "maps.h"

Level0::Level0() : player(125.f, 725.f, 575.f, 275.f) // passing walls coords to player constructor
{
    player.playerPosition = sf::Vector2f(500.f, 515.f);
    player.setPosition(player.playerPosition);
    player.setRotation(-90);
    enemy.enemyPosition = sf::Vector2f(500.f, 250.f);
    enemy.setPosition(enemy.enemyPosition);
    levelStatus = 0;
    map.setPrimitiveType(sf::Quads);

    const std::vector<sf::Vector2f> points = {
        {0.f, 95.f}, {1000.f, 95.f}, {1000.f, 125.f}, {0.f, 125.f},
        {0.f, 575.f}, {1000.f, 575.f}, {1000.f, 605.f}, {0.f, 605.f},
        {245.f, 0.f}, {275.f, 0.f}, {275.f, 700.f}, {245.f, 700.f},
        {725.f, 0.f}, {755.f, 0.f}, {755.f, 700.f}, {725.f, 700.f}
    };
    for (auto& point : points)
    {
        map.append(sf::Vertex(point, sf::Color(0xE6, 0xE4, 0xC4)));
    }
}

void Level0::Update(sf::RenderWindow& window, sf::Clock& clock)
{
    deltaTime = clock.restart().asSeconds();
    player.Update(window, deltaTime);
    enemy.Update(deltaTime, player.playerPosition);
    CheckCollision();
}

Level1::Level1()
{
    map.setPrimitiveType(sf::Quads);

    const std::vector<sf::Vector2f> points = {
        {100.f, 100.f}, {150.f, 100.f}, {150.f, 500.f}, {100.f, 500.f},
        {200.f, 100.f}, {250.f, 100.f}, {250.f, 500.f}, {200.f, 500.f}
    };
    for (auto& point : points)
    {
        map.append(sf::Vertex(point, sf::Color(0xE6, 0xE4, 0xC4)));
    }
}