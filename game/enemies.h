#pragma once

#include "headers.h"

class OrangeBullet : public sf::Drawable, public sf::Transformable
{
public:
    OrangeBullet();

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

class PurpleBullet : public sf::Drawable, public sf::Transformable
{
public:
    PurpleBullet();

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

class Level0Enemy : public sf::Drawable, public sf::Transformable
{
public:
    Level0Enemy();

    void Update(const float& deltaTime, const sf::Vector2f& playerPosition);
    void UpdateBullets(const float& deltaTime, const sf::Vector2f& playerPosition);
    sf::FloatRect GetBounds();

public:
    int health;
    sf::Vector2f enemyPosition;
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
    float elapsedTime;
    float wavePhase;
    float amplitude;
    float period;
    bool isOrange;
    float shootingDelay;
    float timeSinceLastShot;
    sf::Vector2f delta;
    float angleRad;
};

class Level1Enemy : public sf::Drawable, public sf::Transformable
{
public:
    Level1Enemy();

    void Update(const float& deltaTime, const sf::Vector2f& playerPosition);
    void UpdateBullets(const float& deltaTime, const sf::Vector2f& playerPosition);
    sf::FloatRect GetBounds();

public:
    int health;
    sf::Vector2f enemyPosition;
    std::vector<PurpleBullet> purpleBullets;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        for (const PurpleBullet& bullet : purpleBullets)
        {
            target.draw(bullet);
        }
        target.draw(enemy, states);
    }

    sf::VertexArray enemy;
    float elapsedTime;
    float wavePhase;
    float speedX;
    float speedY;
    float shootingDelay;
    float timeSinceLastShot;
    sf::Vector2f delta;
    float angleRad;
    float leftOffsetAngle;
    float rightOffsetAngle;
};