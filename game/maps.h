#pragma once

#include "headers.h"
#include "player.h"
#include "enemies.h"

class Level0 : public sf::Drawable
{
public:
    Level0();

    void Update(sf::RenderWindow& window, sf::Clock& clock);
    void CheckCollision();

public:
    Player player;
    Level0Enemy enemy;
    float deltaTime;
    int levelStatus; // 0 - in progress, 1 - completed, 2 - failed

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(map, states);
        if (enemy.health > 0)
        {
            target.draw(enemy, states);
        }
        if (player.health > 0)
        {
            target.draw(player, states);
        }
    }

    sf::VertexArray map;
};

class Level1 : public sf::Drawable
{
public:
    Level1();

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(map, states);
    }

    sf::VertexArray map;
};