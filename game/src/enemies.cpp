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

            if (!weakExplodeBuffer.loadFromFile("game/sounds/sfx/enemy_explode_weak.wav"))
            {
                std::cout << "Couldn't load sound \"enemy_explode_weak\".";
            }
            weakExplode.setBuffer(weakExplodeBuffer);

            if (!shieldHitBuffer.loadFromFile("game/sounds/sfx/shield_hit.wav"))
            {
                std::cout << "Couldn't load sound \"shield_hit\".";
            }
            shieldHit.setBuffer(shieldHitBuffer);

            if (!shieldExplodeBuffer.loadFromFile("game/sounds/sfx/shield_explode.wav"))
            {
                std::cout << "Couldn't load sound \"shield_explode\".";
            }
            shieldExplode.setBuffer(shieldExplodeBuffer);
        }

        sf::SoundBuffer hitBuffer;
        sf::Sound hit;
        sf::SoundBuffer explodeBuffer;
        sf::Sound explode;
        sf::SoundBuffer weakExplodeBuffer;
        sf::Sound weakExplode;
        sf::SoundBuffer shieldHitBuffer;
        sf::Sound shieldHit;
        sf::SoundBuffer shieldExplodeBuffer;
        sf::Sound shieldExplode;
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

    const std::vector<float> n_lastShot = {
        {0.f}, {0.2f}, {0.4f}, {0.6f}, {0.8f}, {1.f}, {1.2f}, {1.4f}, {1.6f}
    };
    const std::vector<sf::Vector2f> n_level10Positions = {
        {500.f, 270.f}, {430.f, 270.f}, {570.f, 270.f}, {390.f, 340.f},
        {610.f, 340.f}, {320.f, 400.f}, {680.f, 400.f}
    };
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

SmallEnemy::SmallEnemy(int num, float lastShot)
{
    id = num;
    hit = false;
    shootingDelay = 1.5f;
    timeSinceLastShot = lastShot;
    isAnimatingExplode = false;

    enemy.setPrimitiveType(sf::TriangleStrip);
    enemy.append(sf::Vertex(sf::Vector2f(-15.f, 15.f), sf::Color(0x75, 0x6C, 0x5C)));
    enemy.append(sf::Vertex(sf::Vector2f(-15.f, -15.f), sf::Color(0x75, 0x6C, 0x5C)));
    enemy.append(sf::Vertex(sf::Vector2f(15.f, 15.f), sf::Color(0x75, 0x6C, 0x5C)));
    enemy.append(sf::Vertex(sf::Vector2f(15.f, -15.f), sf::Color(0x75, 0x6C, 0x5C)));
    enemy.append(sf::Vertex(sf::Vector2f(30.f, 0.f), sf::Color(0x75, 0x6C, 0x5C)));
}

sf::FloatRect SmallEnemy::GetBounds()
{
    return getTransform().transformRect(enemy.getBounds());
}

void SmallEnemy::GotHit(float& delay)
{
    enemySounds.weakExplode.play();
    isAnimatingExplode = true;
    currentFrame = 0;
    if (delay > 0.1f)
    {
        delay -= 0.06f; // from 0.5 to 0.1 after 7 destroyed enemies
        if (delay < 0.1f)
        {
            delay = 0.1f;
        }
    }
}

ShieldedBallWithSmallEnemies::ShieldedBallWithSmallEnemies(float delay, int number)
{
    health = 10;
    numberOfSmallEnemies = number;
    isOrange = true;
    shootingDelay = delay;
    timeSinceLastShot = 2.f;
    isShielded = true;
    shieldFrame = 0;
    isAnimatingHit = false;
    isAnimatingExplode = false;
    isAnimatingShieldExplode = false;

    constructBallEnemy(enemy);

    for (int i = 0; i < number; ++i)
    {
        SmallEnemy smallEnemy(i, n_lastShot[i]);
        smallEnemy.position = n_level10Positions[i];
        smallEnemy.setPosition(smallEnemy.position);
        smallEnemy.setRotation(-90.f);
        smallEnemies.push_back(smallEnemy);
    }
}

void ShieldedBallWithSmallEnemies::UpdateSmallEnemies(const float& deltaTime, const sf::Vector2f& playerPosition)
{
    for (SmallEnemy& enemy : smallEnemies)
    {
        enemy.Update(smallEnemies, deltaTime, playerPosition, enemyPosition, orangeBullets, numberOfSmallEnemies);
    }
}

void ShieldedBallWithSmallEnemies::AnimateHit()
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

void ShieldedBallWithSmallEnemies::UpdateAllBullets(const float& deltaTime)
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

void ShieldedBallWithSmallEnemies::GotHit()
{
    if (isShielded)
    {
        enemySounds.shieldHit.play();
        return;
    }
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

void ShieldedBallWithSmallEnemies::UpdateShield()
{
    if (isShielded)
    {
        shieldFrame++;
        if (shieldFrame == 20)
        {
            shieldFrame = 0;
        }
        if (numberOfSmallEnemies == 0)
        {
            enemySounds.shieldExplode.play();
            isShielded = false;
            isAnimatingShieldExplode = true;
            currentFrame = 0;
            return;
        }        
    }
    if (isAnimatingShieldExplode)
    {
        currentFrame++;
        {
            if (currentFrame == 30)
            {
                isAnimatingShieldExplode = false;
            }
        }
    }
}

sf::FloatRect ShieldedBallWithSmallEnemies::GetBounds()
{
    return getTransform().transformRect(enemy.getBounds());
}