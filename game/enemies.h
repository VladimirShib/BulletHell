#pragma once

#include "headers.h"

class OrangeBullet : public sf::Drawable, public sf::Transformable
{
public:
    OrangeBullet();

public:
    float speed = 400.f;
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

class PurpleBullet : public sf::Drawable, public sf::Transformable
{
public:
    PurpleBullet();

public:
    float speed = 300.f;
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

class Level0Enemy : public sf::Drawable, public sf::Transformable
{
public:
    Level0Enemy();

    void Update(const float& deltaTime, const sf::Vector2f& playerPosition);
    void UpdateBullets(const float& deltaTime, const sf::Vector2f& playerPosition);

public:
    sf::Vector2f enemyPosition;
    int health;
    std::vector<OrangeBullet> orangeBullets;
    std::vector<PurpleBullet> purpleBullets;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        for (const OrangeBullet& bullet : orangeBullets)
        {
            target.draw(bullet);
        }
        for (const PurpleBullet& bullet : purpleBullets)
        {
            target.draw(bullet);
        }
        target.draw(enemy, states);
    }

    sf::VertexArray enemy;
    double elapsedTime;
    float amplitude;
    float period;
    bool isOrange;
    float shootingDelay;
    float timeSinceLastShot;
    sf::Vector2f delta;
    float angleRad;
};