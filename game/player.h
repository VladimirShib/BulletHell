#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class PlayerBullet : public sf::Drawable, public sf::Transformable
{
public:
    float speed = 700.f;
    sf::Vector2f position;
    sf::Vector2f velocity;

    PlayerBullet();

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        target.draw(playerBullet, states);
    }

    sf::VertexArray playerBullet;
};

class Player : public sf::Drawable, public sf::Transformable
{
public:
    // Define the shapes for the player
    Player();

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

struct Data
{
    sf::Vector2f playerPosition;
    sf::Vector2f mousePosition;
    sf::Vector2f delta;
    float angleRad;
    float angleDeg;
};

struct Bullets
{
    sf::Clock clock;
    const float shootingDelay = 0.1f;
    std::vector<PlayerBullet> playerBullets;
};

void updatePlayer(sf::RenderWindow& window, Player& player, Data& data);
void updateBullets(Data& data, Bullets& bullets, const float& deltaTime);