#pragma once

#include "headers.h"

struct Data
{
    sf::Vector2f playerPosition;
    sf::Vector2f mousePosition;
    sf::Vector2f delta;
    float angleRad;
    float angleDeg;
};

class PlayerBullet : public sf::Drawable, public sf::Transformable
{
public:
    PlayerBullet();

    float speed = 700.f;
    sf::Vector2f position;
    sf::Vector2f velocity;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        target.draw(playerBullet, states);
    }

    sf::VertexArray playerBullet;
};

struct Bullets
{
    sf::Clock clock;
    const float shootingDelay = 0.1f;
    std::vector<PlayerBullet> playerBullets;
};

class Player : public sf::Drawable, public sf::Transformable
{
public:
    // Define the shapes for the player
    Player();

    Data data;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // Apply the transform
        states.transform *= getTransform();

        // Draw the vertex array
        target.draw(ship, states);
    }

    sf::VertexArray ship;
};

void updatePlayer(sf::RenderWindow& window, Player& player);
void updateBullets(Player& player, Bullets& bullets, const float& deltaTime);