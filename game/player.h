#pragma once

#include "headers.h"

// struct Walls
// {
//     float top;
//     float right;
//     float bottom;
//     float left;
// };

class Bullet : public sf::Drawable, public sf::Transformable
{
public:
    Bullet();

    sf::FloatRect GetBounds();

public:
    float speed;
    sf::Vector2f position;
    sf::Vector2f velocity;
    bool hit;

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
    Player(float left, float top, float size);

    void Update(sf::RenderWindow& window, sf::View& view, const float& deltaTime);
    void UpdateBullets(const float& deltaTime);
    void Fire();
    void GotHit();
    void GotHitOnce();
    void GotHitTwice();
    sf::FloatRect GetBounds();

public:
    int health;
    float lastGotHit;
    sf::Vector2f playerPosition;
    sf::Vector2i mousePositionWindow;
    sf::Vector2f mousePositionView;
    sf::Vector2f delta; // distance between mouse cursor and player
    float angleRad;
    float angleDeg;
    std::vector<Bullet> bullets;
    sf::FloatRect playingField;

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
    float invulnerable;
};