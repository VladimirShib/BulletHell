#include "enemies.h"

namespace
{
    struct EnemySounds
    {
        EnemySounds()
        {
            if (!shootBuffer.loadFromFile("game/sounds/sfx/enemy_shoot.wav"))
            {
                std::cout << "Couldn't load sound \"enemy_shoot\".";
            }
            shoot.setBuffer(shootBuffer);

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

        sf::SoundBuffer shootBuffer;
        sf::Sound shoot;
        sf::SoundBuffer hitBuffer;
        sf::Sound hit;
        sf::SoundBuffer explodeBuffer;
        sf::Sound explode;
    };

    EnemySounds enemySounds;
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

Level0Enemy::Level0Enemy()
{
    health = 10;
    elapsedTime = 0.f;
    amplitude = 5.f;
    period = 3.f;
    isOrange = true;
    shootingDelay = 0.5f;
    timeSinceLastShot = 0.f;
    isAnimatingHit = false;
    isAnimatingExplode = false;
    enemy.setPrimitiveType(sf::TriangleFan);

    enemy.append(sf::Vertex(sf::Vector2f(0.f, 0.f), sf::Color(0x50, 0x4E, 0x48)));
    enemy.append(sf::Vertex(sf::Vector2f(25.f, 0.f), sf::Color(0x50, 0x4E, 0x48)));
    enemy.append(sf::Vertex(sf::Vector2f(21.6f, 12.5f), sf::Color(0x50, 0x4E, 0x48)));
    enemy.append(sf::Vertex(sf::Vector2f(12.5f, 21.6f), sf::Color(0x50, 0x4E, 0x48)));
    enemy.append(sf::Vertex(sf::Vector2f(0.f, 25.0f), sf::Color(0x50, 0x4E, 0x48)));
    enemy.append(sf::Vertex(sf::Vector2f(-12.5f, 21.6f), sf::Color(0x50, 0x4E, 0x48)));
    enemy.append(sf::Vertex(sf::Vector2f(-21.6f, 12.5f), sf::Color(0x50, 0x4E, 0x48)));
    enemy.append(sf::Vertex(sf::Vector2f(-25.f, 0.f), sf::Color(0x50, 0x4E, 0x48)));
    enemy.append(sf::Vertex(sf::Vector2f(-21.6f, -12.5f), sf::Color(0x50, 0x4E, 0x48)));
    enemy.append(sf::Vertex(sf::Vector2f(-12.5f, -21.6f), sf::Color(0x50, 0x4E, 0x48)));
    enemy.append(sf::Vertex(sf::Vector2f(0.f, -25.0f), sf::Color(0x50, 0x4E, 0x48)));
    enemy.append(sf::Vertex(sf::Vector2f(12.5f, -21.6f), sf::Color(0x50, 0x4E, 0x48)));
    enemy.append(sf::Vertex(sf::Vector2f(21.6f, -12.5f), sf::Color(0x50, 0x4E, 0x48)));
    enemy.append(sf::Vertex(sf::Vector2f(25.f, 0.f), sf::Color(0x50, 0x4E, 0x48)));
}

void Level0Enemy::Update(const float& deltaTime, const sf::Vector2f& playerPosition)
{
    if (isAnimatingExplode)
    {
        currentFrame++;
        if (currentFrame == 30)
        {
            health--;
        }
        return;
    }
    elapsedTime += deltaTime;
    wavePhase = elapsedTime * (1.5f * M_PI);
    enemyPosition.x += amplitude * std::cos(wavePhase / period);
    this->setPosition(enemyPosition);

    if (isAnimatingHit)
    {
        currentFrame++;
        if (currentFrame == 12)
        {
            isAnimatingHit = false;
            health--;
        }
    }
    UpdateBullets(deltaTime, playerPosition);
}

void Level0Enemy::UpdateBullets(const float& deltaTime, const sf::Vector2f& playerPosition)
{
    timeSinceLastShot += deltaTime;
    if (timeSinceLastShot > shootingDelay)
    {
        delta = playerPosition - enemyPosition;
        angleRad = atan2(delta.y, delta.x);
        if (isOrange)
        {
            OrangeBullet bullet;
            bullet.position = enemyPosition;
            bullet.velocity = {
                std::cos(angleRad) * bullet.speed,
                std::sin(angleRad) * bullet.speed
            };
            bullet.setPosition(bullet.position);
            orangeBullets.push_back(bullet);
        }
        else
        {
            PurpleBullet bullet;
            bullet.position = enemyPosition;
            bullet.velocity = {
                std::cos(angleRad) * bullet.speed,
                std::sin(angleRad) * bullet.speed
            };
            bullet.setPosition(bullet.position);
            purpleBullets.push_back(bullet);
        }
        timeSinceLastShot = 0.f;
        isOrange = !isOrange;

        enemySounds.shoot.play();
    }

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

void Level0Enemy::GotHit()
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

sf::FloatRect Level0Enemy::GetBounds()
{
    return getTransform().transformRect(enemy.getBounds());
}

Level1Enemy::Level1Enemy()
{
    health = 10;
    elapsedTime = 0.f;
    speedX = 7.f;
    speedY = 3.5f;
    shootingDelay = 1.f;
    timeSinceLastShot = 0.f;
    isAnimatingHit = false;
    isAnimatingExplode = false;
    enemy.setPrimitiveType(sf::TriangleFan);

    enemy.append(sf::Vertex(sf::Vector2f(0.f, 0.f), sf::Color(0x50, 0x4E, 0x48)));
    enemy.append(sf::Vertex(sf::Vector2f(25.f, 0.f), sf::Color(0x50, 0x4E, 0x48)));
    enemy.append(sf::Vertex(sf::Vector2f(21.6f, 12.5f), sf::Color(0x50, 0x4E, 0x48)));
    enemy.append(sf::Vertex(sf::Vector2f(12.5f, 21.6f), sf::Color(0x50, 0x4E, 0x48)));
    enemy.append(sf::Vertex(sf::Vector2f(0.f, 25.0f), sf::Color(0x50, 0x4E, 0x48)));
    enemy.append(sf::Vertex(sf::Vector2f(-12.5f, 21.6f), sf::Color(0x50, 0x4E, 0x48)));
    enemy.append(sf::Vertex(sf::Vector2f(-21.6f, 12.5f), sf::Color(0x50, 0x4E, 0x48)));
    enemy.append(sf::Vertex(sf::Vector2f(-25.f, 0.f), sf::Color(0x50, 0x4E, 0x48)));
    enemy.append(sf::Vertex(sf::Vector2f(-21.6f, -12.5f), sf::Color(0x50, 0x4E, 0x48)));
    enemy.append(sf::Vertex(sf::Vector2f(-12.5f, -21.6f), sf::Color(0x50, 0x4E, 0x48)));
    enemy.append(sf::Vertex(sf::Vector2f(0.f, -25.0f), sf::Color(0x50, 0x4E, 0x48)));
    enemy.append(sf::Vertex(sf::Vector2f(12.5f, -21.6f), sf::Color(0x50, 0x4E, 0x48)));
    enemy.append(sf::Vertex(sf::Vector2f(21.6f, -12.5f), sf::Color(0x50, 0x4E, 0x48)));
    enemy.append(sf::Vertex(sf::Vector2f(25.f, 0.f), sf::Color(0x50, 0x4E, 0x48)));
}

void Level1Enemy::Update(const float& deltaTime, const sf::Vector2f& playerPosition)
{
    if (isAnimatingExplode)
    {
        currentFrame++;
        if (currentFrame == 30)
        {
            health--;
        }
        return;
    }
    elapsedTime += deltaTime;
    wavePhase = elapsedTime * (5.f * M_PI);
    enemyPosition.x += speedX * std::cos(wavePhase / speedX);
    enemyPosition.y += speedY * std::cos(wavePhase / speedY);
    this->setPosition(enemyPosition);

    if (isAnimatingHit)
    {
        currentFrame++;
        if (currentFrame == 12)
        {
            isAnimatingHit = false;
            health--;
        }
    }
    UpdateBullets(deltaTime, playerPosition);
}

void Level1Enemy::UpdateBullets(const float& deltaTime, const sf::Vector2f& playerPosition)
{
    timeSinceLastShot += deltaTime;
    if (timeSinceLastShot > shootingDelay)
    {
        delta = playerPosition - enemyPosition;
        angleRad = atan2(delta.y, delta.x);
        leftOffsetAngle = angleRad - (M_PI / 4.0f);
        rightOffsetAngle = angleRad + (M_PI / 4.0f);

        PurpleBullet bullet1;
        bullet1.position = enemyPosition;
        bullet1.velocity = {
            std::cos(angleRad) * bullet1.speed,
            std::sin(angleRad) * bullet1.speed
        };
        bullet1.setPosition(bullet1.position);

        PurpleBullet bullet2;
        bullet2.position = enemyPosition;
        bullet2.velocity = {
            std::cos(leftOffsetAngle) * bullet2.speed,
            std::sin(leftOffsetAngle) * bullet2.speed
        };
        bullet2.setPosition(bullet2.position);
        
        PurpleBullet bullet3;
        bullet3.position = enemyPosition;
        bullet3.velocity = {
            std::cos(rightOffsetAngle) * bullet3.speed,
            std::sin(rightOffsetAngle) * bullet3.speed
        };
        bullet3.setPosition(bullet3.position);

        purpleBullets.push_back(bullet1);
        purpleBullets.push_back(bullet2);
        purpleBullets.push_back(bullet3);

        timeSinceLastShot = 0.f;

        enemySounds.shoot.play();
    }

    for (PurpleBullet& bullet : purpleBullets)
    {
        bullet.position += bullet.velocity * deltaTime;
        bullet.setPosition(bullet.position);
    }
}

void Level1Enemy::GotHit()
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
            purpleBullets.clear();
        }
        currentFrame = 0;
    }
}

sf::FloatRect Level1Enemy::GetBounds()
{
    return getTransform().transformRect(enemy.getBounds());
}