#pragma once

#include "headers.h"

struct Walls
{
    float top;
    float right;
    float bottom;
    float left;
};

class Bullet : public sf::Drawable, public sf::Transformable
{
public:
    Bullet();

    float speed;
    sf::Vector2f position;
    sf::Vector2f velocity;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        target.draw(bullet, states);
    }

    sf::VertexArray bullet;
};

class Player : public sf::Drawable, public sf::Transformable
{
public:
    // Define the shapes for the player
    Player(float top, float right, float bottom, float left);

    void Update(sf::RenderWindow& window, const float& deltaTime);
    void UpdateBullets(const float& deltaTime);
    void Fire();

public:
    sf::Vector2f playerPosition;
    sf::Vector2f mousePosition;
    sf::Vector2f delta; // distance between mouse cursor and player
    float angleRad;
    float angleDeg;
    std::vector<Bullet> bullets;
    Walls walls;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // Apply the transform
        states.transform *= getTransform();

        // Draw the vertex array
        target.draw(ship, states);

        for (const Bullet& bullet : bullets)
        {
            target.draw(bullet);
        }
    }

    sf::Vertex vertices[20];
    sf::VertexArray ship;
    float shootingDelay;
    float timeSinceLastShot;
};