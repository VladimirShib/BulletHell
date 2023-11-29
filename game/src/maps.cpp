#include "maps.h"

Level0::Level0() : player(275.f, 125.f, 450.f) // passing playing field parameters to player constructor
{
    player.playerPosition = sf::Vector2f(500.f, 515.f);
    player.setPosition(player.playerPosition);
    player.setRotation(-90);
    enemy.enemyPosition = sf::Vector2f(500.f, 250.f);
    enemy.setPosition(enemy.enemyPosition);
    levelStatus = 0;
    map.setPrimitiveType(sf::Quads);

    const std::vector<sf::Vector2f> points = {
        {-205.f, 95.f}, {1205.f, 95.f}, {1205.f, 125.f}, {-205.f, 125.f},
        {-205.f, 575.f}, {1205.f, 575.f}, {1205.f, 605.f}, {-205.f, 605.f},
        {245.f, -205.f}, {275.f, -205.f}, {275.f, 905.f}, {245.f, 905.f},
        {725.f, -205.f}, {755.f, -205.f}, {755.f, 905.f}, {725.f, 905.f}
    };
    for (auto& point : points)
    {
        map.append(sf::Vertex(point, sf::Color(0xE6, 0xE4, 0xC4)));
    }
}

void Level0::Update(sf::RenderWindow& window, sf::View& view, sf::Clock& clock)
{
    deltaTime = clock.restart().asSeconds();
    player.Update(window, view, deltaTime);
    enemy.Update(deltaTime, player.playerPosition);
    CheckCollision();

    if (player.health <= 0)
    {
        levelStatus = 2;
    }
    if (enemy.health <= 0)
    {
        levelStatus = 1;
    }
}

Level1::Level1() : player(275.f, 125.f, 450.f)
{
    player.playerPosition = sf::Vector2f(500.f, 515.f);
    player.setPosition(player.playerPosition);
    player.setRotation(-90);
    enemy.enemyPosition = sf::Vector2f(500.f, 250.f);
    enemy.setPosition(enemy.enemyPosition);
    levelStatus = 0;
    map.setPrimitiveType(sf::Quads);

    const std::vector<sf::Vector2f> points = {
        {-205.f, 95.f}, {1205.f, 95.f}, {1205.f, 125.f}, {-205.f, 125.f},
        {-205.f, 575.f}, {1205.f, 575.f}, {1205.f, 605.f}, {-205.f, 605.f},
        {245.f, -205.f}, {275.f, -205.f}, {275.f, 905.f}, {245.f, 905.f},
        {725.f, -205.f}, {755.f, -205.f}, {755.f, 905.f}, {725.f, 905.f}
    };
    for (auto& point : points)
    {
        map.append(sf::Vertex(point, sf::Color(0xE6, 0xE4, 0xC4)));
    }
}

void Level1::Update(sf::RenderWindow& window, sf::View& view, sf::Clock& clock)
{
    deltaTime = clock.restart().asSeconds();
    player.Update(window, view, deltaTime);
    enemy.Update(deltaTime, player.playerPosition);
    CheckCollision();

    if (player.health <= 0)
    {
        levelStatus = 2;
    }
    if (enemy.health <= 0)
    {
        levelStatus = 1;
    }
}

Level2::Level2() : player(275.f, 125.f, 450.f)
{
    player.playerPosition = sf::Vector2f(500.f, 515.f);
    player.setPosition(player.playerPosition);
    player.setRotation(-90);
    enemy.enemyPosition = sf::Vector2f(500.f, 250.f);
    enemy.setPosition(enemy.enemyPosition);
    levelStatus = 0;
    map.setPrimitiveType(sf::Quads);

    const std::vector<sf::Vector2f> points = {
        {-205.f, 95.f}, {1205.f, 95.f}, {1205.f, 125.f}, {-205.f, 125.f},
        {-205.f, 575.f}, {1205.f, 575.f}, {1205.f, 605.f}, {-205.f, 605.f},
        {245.f, -205.f}, {275.f, -205.f}, {275.f, 905.f}, {245.f, 905.f},
        {725.f, -205.f}, {755.f, -205.f}, {755.f, 905.f}, {725.f, 905.f}
    };
    for (auto& point : points)
    {
        map.append(sf::Vertex(point, sf::Color(0xE6, 0xE4, 0xC4)));
    }
}

void Level2::Update(sf::RenderWindow& window, sf::View& view, sf::Clock& clock)
{
    deltaTime = clock.restart().asSeconds();
    player.Update(window, view, deltaTime);
    enemy.Update(deltaTime, player.playerPosition);
    CheckCollision();

    if (player.health <= 0)
    {
        levelStatus = 2;
    }
    if (enemy.health <= 0)
    {
        levelStatus = 1;
    }
}