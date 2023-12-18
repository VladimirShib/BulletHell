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
        {1.6f}, {1.4f}, {1.2f}, {1.f}, {0.8f}, {0.6f}, {0.4f}, {0.2f}, {0.f},
        {1.5f}, {1.3f}, {1.1f}, {0.9f}, {0.7f}, {0.5f}, {0.3f}, {0.1f}
    };
    struct EnemyLevelData
    {
        sf::Vector2f position;
        float rotation;
    };
    const std::vector<std::vector<EnemyLevelData>> n_enemyLevelData = {
        {
            {{500.f, 270.f}, -90.f}, {{430.f, 270.f}, -70.f}, {{570.f, 270.f}, -110.f}, {{390.f, 340.f}, -65.f},
            {{610.f, 340.f}, -115.f}, {{320.f, 400.f}, -60.f}, {{680.f, 400.f}, -120.f}
        },
        {
            {{500.f, 370.f}, 90.f}, {{430.f, 300.f}, 80.f}, {{570.f, 300.f}, 100.f}, {{360.f, 370.f}, 60.f},
            {{640.f, 370.f}, 120.f}, {{280.f, 410.f}, 45.f}, {{720.f, 410.f}, 135.f}, {{230.f, 490.f}, 30.f},
            {{770.f, 490.f}, 150.f}, {{160.f, 580.f}, 10.f}, {{840.f, 580.f}, 170.f}
        },
        {
            {{500.f, 240.f}, 90.f}, {{400.f, 190.f}, 70.f}, {{600.f, 190.f}, 110.f}, {{320.f, 235.f}, 50.f},
            {{680.f, 235.f}, 130.f}, {{230.f, 185.f}, 45.f}, {{770.f, 185.f}, 135.f}
        },
        {
            {{385.f, 250.f}, -55.f}, {{615.f, 250.f}, -125.f}, {{285.f, 250.f}, -40.f}, {{715.f, 250.f}, -140.f},
            {{335.f, 345.f}, -50.f}, {{665.f, 345.f}, -130.f}, {{165.f, 345.f}, -40.f}, {{835.f, 345.f}, -140.f},
            {{440.f, 425.f}, -80.f}, {{560.f, 425.f}, -100.f}, {{205.f, 425.f}, -45.f}, {{795.f, 425.f}, -135.f},
            {{335.f, 495.f}, -85.f}, {{665.f, 495.f}, -95.f}
        },
        {
            {{500.f, 675.f}, -90.f}, {{125.f, 400.f}, 30.f}, {{875.f, 400.f}, 150.f}, {{325.f, 290.f}, 60.f},
            {{675.f, 290.f}, 120.f}, {{355.f, 240.f}, 70.f}, {{645.f, 240.f}, 110.f}, {{450.f, 150.f}, 90.f},
            {{550.f, 150.f}, 90.f}
        }
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

ShieldedBallWithSmallEnemies::ShieldedBallWithSmallEnemies(float delay, int level, int number)
{
    health = 10;
    numberOfSmallEnemies = number;
    isOrange = true;
    shootingDelay = delay;
    timeSinceLastShot = 2.f;
    isShielded = true;
    otherEnemy = false;
    shieldFrame = 0;
    isAnimatingHit = false;
    isAnimatingExplode = false;
    isAnimatingShieldExplode = false;

    constructBallEnemy(enemy);

    for (int i = 0; i < number; ++i)
    {
        SmallEnemy smallEnemy(i, n_lastShot[i]);
        smallEnemy.position = n_enemyLevelData[level][i].position;
        smallEnemy.setPosition(smallEnemy.position);
        smallEnemy.setRotation(n_enemyLevelData[level][i].rotation);
        smallEnemies.push_back(smallEnemy);
    }
}

void ShieldedBallWithSmallEnemies::UpdateSmallEnemies(const float& deltaTime, const sf::Vector2f& playerPosition)
{
    for (SmallEnemy& enemy : smallEnemies)
    {
        enemy.Move(smallEnemies, deltaTime, playerPosition, orangeBullets, numberOfSmallEnemies);
    }
}

void ShieldedBallWithSmallEnemies::UpdateSmallEnemiesWithObstacles(const float& deltaTime, const sf::Vector2f& playerPosition,
                                                                   const std::vector<sf::FloatRect>& obstacles)
{
    for (SmallEnemy& enemy : smallEnemies)
    {
        enemy.MoveWithObstacles(smallEnemies, deltaTime, playerPosition, orangeBullets, numberOfSmallEnemies, obstacles);
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
            if (!otherEnemy)
            {
                orangeBullets.clear();
                purpleBullets.clear();
            }
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
            shieldFrame = 0;
            return;
        }        
    }
    if (isAnimatingShieldExplode)
    {
        shieldFrame++;
        {
            if (shieldFrame == 30)
            {
                isAnimatingShieldExplode = false;
            }
        }
    }
}

void ShieldedBallWithSmallEnemies::CheckOtherEnemy(const bool& isAlive)
{
    if (!isAlive)
    {
        otherEnemy = false;
    }
}

sf::FloatRect ShieldedBallWithSmallEnemies::GetBounds()
{
    return getTransform().transformRect(enemy.getBounds());
}

AdditionalEnemy::AdditionalEnemy(float delay)
{
    health = 10;
    isOrange = true;
    shootingDelay = delay;
    timeSinceLastShot = 2.f;
    isShielded = true;
    isAlive = true;
    shieldFrame = 0;
    isAnimatingHit = false;
    isAnimatingExplode = false;
    isAnimatingShieldExplode = false;

    constructBallEnemy(enemy);
}

void AdditionalEnemy::AnimateHit()
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

void AdditionalEnemy::GotHit()
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
            isAlive = false;
        }
        currentFrame = 0;
    }
}

void AdditionalEnemy::UpdateShield(const int& numberOfSmallEnemies)
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
            shieldFrame = 0;
            return;
        }        
    }
    if (isAnimatingShieldExplode)
    {
        shieldFrame++;
        {
            if (shieldFrame == 30)
            {
                isAnimatingShieldExplode = false;
            }
        }
    }
}

sf::FloatRect AdditionalEnemy::GetBounds()
{
    return getTransform().transformRect(enemy.getBounds());
}

SmallEnemy::SmallEnemy(int num, float lastShot)
{
    health = 3;
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
    if (health > 1)
    {
        enemySounds.hit.play();
        health--;
    }
    else
    {
        enemySounds.weakExplode.play();
        isAnimatingExplode = true;
        currentFrame = 0;
        if (delay > 0.12f)
        {
            delay -= 0.08f; // reducing delay after each destroyed enemy
            if (delay < 0.12f)
            {
                delay = 0.12f;
            }
        }
    }
}