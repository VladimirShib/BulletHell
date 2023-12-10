#include "enemies.hpp"

namespace
{
    struct EnemySounds
    {
        EnemySounds()
        {
            if (!hitBuffer.loadFromFile("game/sounds/sfx/enemy_hit.wav"))
            {
                std::cout << "Couldn't load sound \"enemy_hit\".";
            }
            hit.setBuffer(hitBuffer);

            if (!explodeBuffer.loadFromFile("game/sounds/sfx/enemy_explode.wav"))
            {
                std::cout << "Couldn't load sound \"enemy_explode\".";
            }
            explode.setBuffer(explodeBuffer);
        }

        sf::SoundBuffer hitBuffer;
        sf::Sound hit;
        sf::SoundBuffer explodeBuffer;
        sf::Sound explode;
    };

    EnemySounds enemySounds;

    void constructBallEnemy(sf::VertexArray& vertices)
    {
        vertices.setPrimitiveType(sf::TriangleFan);
        
        vertices.append(sf::Vertex(sf::Vector2f(0.f, 0.f), sf::Color(0x50, 0x4E, 0x48)));
        vertices.append(sf::Vertex(sf::Vector2f(25.f, 0.f), sf::Color(0x50, 0x4E, 0x48)));
        vertices.append(sf::Vertex(sf::Vector2f(21.6f, 12.5f), sf::Color(0x50, 0x4E, 0x48)));
        vertices.append(sf::Vertex(sf::Vector2f(12.5f, 21.6f), sf::Color(0x50, 0x4E, 0x48)));
        vertices.append(sf::Vertex(sf::Vector2f(0.f, 25.0f), sf::Color(0x50, 0x4E, 0x48)));
        vertices.append(sf::Vertex(sf::Vector2f(-12.5f, 21.6f), sf::Color(0x50, 0x4E, 0x48)));
        vertices.append(sf::Vertex(sf::Vector2f(-21.6f, 12.5f), sf::Color(0x50, 0x4E, 0x48)));
        vertices.append(sf::Vertex(sf::Vector2f(-25.f, 0.f), sf::Color(0x50, 0x4E, 0x48)));
        vertices.append(sf::Vertex(sf::Vector2f(-21.6f, -12.5f), sf::Color(0x50, 0x4E, 0x48)));
        vertices.append(sf::Vertex(sf::Vector2f(-12.5f, -21.6f), sf::Color(0x50, 0x4E, 0x48)));
        vertices.append(sf::Vertex(sf::Vector2f(0.f, -25.0f), sf::Color(0x50, 0x4E, 0x48)));
        vertices.append(sf::Vertex(sf::Vector2f(12.5f, -21.6f), sf::Color(0x50, 0x4E, 0x48)));
        vertices.append(sf::Vertex(sf::Vector2f(21.6f, -12.5f), sf::Color(0x50, 0x4E, 0x48)));
        vertices.append(sf::Vertex(sf::Vector2f(25.f, 0.f), sf::Color(0x50, 0x4E, 0x48)));
    }
}

OrangeBullet::OrangeBullet()
{
    speed = 300.f;
    hit = false;
    bullet.setPrimitiveType(sf::TriangleFan);

    bullet.append(sf::Vertex(sf::Vector2f(0.f, 0.f), sf::Color(0xF9, 0x7F, 0x1B)));
    bullet.append(sf::Vertex(sf::Vector2f(15.f, 0.f), sf::Color(0xF9, 0x7F, 0x1B)));
    bullet.append(sf::Vertex(sf::Vector2f(13.f, 7.5f), sf::Color(0xF9, 0x7F, 0x1B)));
    bullet.append(sf::Vertex(sf::Vector2f(7.5f, 13.f), sf::Color(0xF9, 0x7F, 0x1B)));
    bullet.append(sf::Vertex(sf::Vector2f(0.f, 15.f), sf::Color(0xF9, 0x7F, 0x1B)));
    bullet.append(sf::Vertex(sf::Vector2f(-7.5f, 13.f), sf::Color(0xF9, 0x7F, 0x1B)));
    bullet.append(sf::Vertex(sf::Vector2f(-13.f, 7.5f), sf::Color(0xF9, 0x7F, 0x1B)));
    bullet.append(sf::Vertex(sf::Vector2f(-15.f, 0.f), sf::Color(0xF9, 0x7F, 0x1B)));
    bullet.append(sf::Vertex(sf::Vector2f(-13.f, -7.5f), sf::Color(0xF9, 0x7F, 0x1B)));
    bullet.append(sf::Vertex(sf::Vector2f(-7.5f, -13.f), sf::Color(0xF9, 0x7F, 0x1B)));
    bullet.append(sf::Vertex(sf::Vector2f(0.f, -15.f), sf::Color(0xF9, 0x7F, 0x1B)));
    bullet.append(sf::Vertex(sf::Vector2f(7.5f, -13.f), sf::Color(0xF9, 0x7F, 0x1B)));
    bullet.append(sf::Vertex(sf::Vector2f(13.f, -7.5f), sf::Color(0xF9, 0x7F, 0x1B)));
    bullet.append(sf::Vertex(sf::Vector2f(15.f, 0.f), sf::Color(0xF9, 0x7F, 0x1B)));
}

sf::FloatRect OrangeBullet::GetBounds()
{
    return getTransform().transformRect(bullet.getBounds());
}

PurpleBullet::PurpleBullet()
{
    speed = 300.f;
    hit = false;
    bullet.setPrimitiveType(sf::TriangleFan);

    bullet.append(sf::Vertex(sf::Vector2f(0.f, 0.f), sf::Color(0x3E, 0x02, 0x5C)));
    bullet.append(sf::Vertex(sf::Vector2f(15.f, 0.f), sf::Color(0x3E, 0x02, 0x5C)));
    bullet.append(sf::Vertex(sf::Vector2f(13.f, 7.5f), sf::Color(0x3E, 0x02, 0x5C)));
    bullet.append(sf::Vertex(sf::Vector2f(7.5f, 13.f), sf::Color(0x3E, 0x02, 0x5C)));
    bullet.append(sf::Vertex(sf::Vector2f(0.f, 15.f), sf::Color(0x3E, 0x02, 0x5C)));
    bullet.append(sf::Vertex(sf::Vector2f(-7.5f, 13.f), sf::Color(0x3E, 0x02, 0x5C)));
    bullet.append(sf::Vertex(sf::Vector2f(-13.f, 7.5f), sf::Color(0x3E, 0x02, 0x5C)));
    bullet.append(sf::Vertex(sf::Vector2f(-15.f, 0.f), sf::Color(0x3E, 0x02, 0x5C)));
    bullet.append(sf::Vertex(sf::Vector2f(-13.f, -7.5f), sf::Color(0x3E, 0x02, 0x5C)));
    bullet.append(sf::Vertex(sf::Vector2f(-7.5f, -13.f), sf::Color(0x3E, 0x02, 0x5C)));
    bullet.append(sf::Vertex(sf::Vector2f(0.f, -15.f), sf::Color(0x3E, 0x02, 0x5C)));
    bullet.append(sf::Vertex(sf::Vector2f(7.5f, -13.f), sf::Color(0x3E, 0x02, 0x5C)));
    bullet.append(sf::Vertex(sf::Vector2f(13.f, -7.5f), sf::Color(0x3E, 0x02, 0x5C)));
    bullet.append(sf::Vertex(sf::Vector2f(15.f, 0.f), sf::Color(0x3E, 0x02, 0x5C)));
}

sf::FloatRect PurpleBullet::GetBounds()
{
    return getTransform().transformRect(bullet.getBounds());
}

BallEnemy::BallEnemy(float delay)
{
    health = 10;
    isMoving = false;
    isOrange = true;
    shootingDelay = delay;
    timeSinceLastShot = 2.f;
    timeSinceLastStream = 2.f;
    bulletCount = 0;
    isAnimatingHit = false;
    isAnimatingExplode = false;

    constructBallEnemy(enemy);
}

void BallEnemy::AnimateHit()
{
    if (isAnimatingHit)
    {
        currentFrame++;
        if (currentFrame == 12)
        {
            isAnimatingHit = false;
            health--;
        }
    }
}

void BallEnemy::UpdateAllBullets(const float& deltaTime)
{
    for (OrangeBullet& bullet : orangeBullets)
    {
        bullet.position += bullet.velocity * deltaTime;
        bullet.setPosition(bullet.position);
    }

    for (PurpleBullet& bullet : purpleBullets)
    {
        bullet.position += bullet.velocity * deltaTime;
        bullet.setPosition(bullet.position);
    }
}

void BallEnemy::UpdatePurpleBullets(const float& deltaTime)
{
    for (PurpleBullet& bullet : purpleBullets)
    {
        bullet.position += bullet.velocity * deltaTime;
        bullet.setPosition(bullet.position);
    }
}

void BallEnemy::GotHit()
{
    if (!isAnimatingHit)
    {
        if (health > 1)
        {
            enemySounds.hit.play();
            isAnimatingHit = true;
        }
        else
        {
            enemySounds.explode.play();
            isAnimatingExplode = true;
            orangeBullets.clear();
            purpleBullets.clear();
        }
        currentFrame = 0;
    }
}

sf::FloatRect BallEnemy::GetBounds()
{
    return getTransform().transformRect(enemy.getBounds());
}