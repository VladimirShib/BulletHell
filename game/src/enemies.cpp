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

Level0Enemy::Level0Enemy()
{
    health = 10;
    elapsedTime = 0.f;
    amplitude = 5.f;
    period = 3.f;
    isOrange = true;
    shootingDelay = 0.5f;
    timeSinceLastShot = 2.f;
    isAnimatingHit = false;
    isAnimatingExplode = false;

    constructBallEnemy(enemy);
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
    elapsedTime = 45.f * (M_PI / 180.f);
    center = sf::Vector2f(500.f, 250.f);
    radius = 200.f;
    speed = 2.f;
    shootingDelay = 1.f;
    timeSinceLastShot = 2.f;
    isAnimatingHit = false;
    isAnimatingExplode = false;

    constructBallEnemy(enemy);
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

    offset.x = radius * std::cos(elapsedTime * speed);
    offset.y = radius * std::sin(2.f * elapsedTime * speed) / 2.f;
    enemyPosition = center + offset;
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

Level2Enemy::Level2Enemy()
{
    health = 10;
    elapsedTime = 90.0f * (M_PI / 180.f);
    center = sf::Vector2f(500.f, 350.f);
    radius = 100.f;
    speed = 3.f;
    shootingDelay = 0.6f;
    timeSinceLastShot = 2.f;
    isAnimatingHit = false;
    isAnimatingExplode = false;

    constructBallEnemy(enemy);
}

void Level2Enemy::Update(const float& deltaTime, const sf::Vector2f& playerPosition)
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
    offset.x = radius * std::cos(elapsedTime * speed);
    offset.y = radius * std::sin(elapsedTime * speed);
    enemyPosition = center + offset;
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

void Level2Enemy::UpdateBullets(const float& deltaTime, const sf::Vector2f& playerPosition)
{
    timeSinceLastShot += deltaTime;
    if (timeSinceLastShot > shootingDelay)
    {
        delta = playerPosition - enemyPosition;
        angleRad = atan2(delta.y, delta.x);
        leftOffsetAngle = angleRad - (M_PI / 2.0f);
        rightOffsetAngle = angleRad + (M_PI / 2.0f);
        backOffsetAngle = angleRad + M_PI;

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

        PurpleBullet bullet4;
        bullet4.position = enemyPosition;
        bullet4.velocity = {
            std::cos(backOffsetAngle) * bullet4.speed,
            std::sin(backOffsetAngle) * bullet4.speed
        };
        bullet4.setPosition(bullet4.position);

        purpleBullets.push_back(bullet1);
        purpleBullets.push_back(bullet2);
        purpleBullets.push_back(bullet3);
        purpleBullets.push_back(bullet4);

        timeSinceLastShot = 0.f;

        enemySounds.shoot.play();
    }

    for (PurpleBullet& bullet : purpleBullets)
    {
        bullet.position += bullet.velocity * deltaTime;
        bullet.setPosition(bullet.position);
    }
}

void Level2Enemy::GotHit()
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

sf::FloatRect Level2Enemy::GetBounds()
{
    return getTransform().transformRect(enemy.getBounds());
}

Level3Enemy::Level3Enemy()
{
    health = 10;
    speed = sf::Vector2f(-400.f, 300.f);
    shootingDelay = 1.f;
    timeSinceLastShot = 2.f;
    isOrange = true;
    isAnimatingHit = false;
    isAnimatingExplode = false;

    constructBallEnemy(enemy);
}

void Level3Enemy::Update(const float& deltaTime, const sf::Vector2f& playerPosition)
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
    enemyPosition += speed * deltaTime;
    if ((enemyPosition.x >= 700.f) && (speed.x > 0))
    {
        speed.x = -speed.x;
    }
    if ((enemyPosition.x <= 300.f) && (speed.x < 0))
    {
        speed.x = -speed.x;
    }
    if ((enemyPosition.y >= 550.f) && (speed.y > 0))
    {
        speed.y = -speed.y;
    }
    if ((enemyPosition.y <= 150.f) && (speed.y < 0))
    {
        speed.y = -speed.y;
    }
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

void Level3Enemy::UpdateBullets(const float& deltaTime, const sf::Vector2f& playerPosition)
{
    timeSinceLastShot += deltaTime;
    if (timeSinceLastShot > shootingDelay)
    {
        delta = playerPosition - enemyPosition;
        angleRad = atan2(delta.y, delta.x);
        left1OffsetAngle = angleRad - (M_PI / 4.0f);
        left2OffsetAngle = angleRad - (M_PI / 2.0f);
        right1OffsetAngle = angleRad + (M_PI / 4.0f);
        right2OffsetAngle = angleRad + (M_PI / 2.0f);

        if (isOrange)
        {
            OrangeBullet bullet1;
            bullet1.position = enemyPosition;
            bullet1.velocity = {
                std::cos(angleRad) * bullet1.speed,
                std::sin(angleRad) * bullet1.speed
            };
            bullet1.setPosition(bullet1.position);

            OrangeBullet bullet2;
            bullet2.position = enemyPosition;
            bullet2.velocity = {
                std::cos(left1OffsetAngle) * bullet2.speed,
                std::sin(left1OffsetAngle) * bullet2.speed
            };
            bullet2.setPosition(bullet2.position);

            OrangeBullet bullet3;
            bullet3.position = enemyPosition;
            bullet3.velocity = {
                std::cos(left2OffsetAngle) * bullet3.speed,
                std::sin(left2OffsetAngle) * bullet3.speed
            };
            bullet3.setPosition(bullet3.position);

            OrangeBullet bullet4;
            bullet4.position = enemyPosition;
            bullet4.velocity = {
                std::cos(right1OffsetAngle) * bullet4.speed,
                std::sin(right1OffsetAngle) * bullet4.speed
            };
            bullet4.setPosition(bullet4.position);

            OrangeBullet bullet5;
            bullet5.position = enemyPosition;
            bullet5.velocity = {
                std::cos(right2OffsetAngle) * bullet5.speed,
                std::sin(right2OffsetAngle) * bullet5.speed
            };
            bullet5.setPosition(bullet5.position);

            orangeBullets.push_back(bullet1);
            orangeBullets.push_back(bullet2);
            orangeBullets.push_back(bullet3);
            orangeBullets.push_back(bullet4);
            orangeBullets.push_back(bullet5);
        }
        else
        {
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
                std::cos(left1OffsetAngle) * bullet2.speed,
                std::sin(left1OffsetAngle) * bullet2.speed
            };
            bullet2.setPosition(bullet2.position);

            PurpleBullet bullet3;
            bullet3.position = enemyPosition;
            bullet3.velocity = {
                std::cos(left2OffsetAngle) * bullet3.speed,
                std::sin(left2OffsetAngle) * bullet3.speed
            };
            bullet3.setPosition(bullet3.position);

            PurpleBullet bullet4;
            bullet4.position = enemyPosition;
            bullet4.velocity = {
                std::cos(right1OffsetAngle) * bullet4.speed,
                std::sin(right1OffsetAngle) * bullet4.speed
            };
            bullet4.setPosition(bullet4.position);

            PurpleBullet bullet5;
            bullet5.position = enemyPosition;
            bullet5.velocity = {
                std::cos(right2OffsetAngle) * bullet5.speed,
                std::sin(right2OffsetAngle) * bullet5.speed
            };
            bullet5.setPosition(bullet5.position);

            purpleBullets.push_back(bullet1);
            purpleBullets.push_back(bullet2);
            purpleBullets.push_back(bullet3);
            purpleBullets.push_back(bullet4);
            purpleBullets.push_back(bullet5);
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

void Level3Enemy::GotHit()
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

sf::FloatRect Level3Enemy::GetBounds()
{
    return getTransform().transformRect(enemy.getBounds());
}

Level4Enemy::Level4Enemy()
{
    health = 10;
    speed = 70.f;
    shootingDelay = 1.f;
    timeSinceLastShot = 2.f;
    isAnimatingHit = false;
    isAnimatingExplode = false;

    constructBallEnemy(enemy);
}

void Level4Enemy::Update(const float& deltaTime, const sf::Vector2f& playerPosition)
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
    delta = playerPosition - enemyPosition;
    vectorLength = std::sqrt(delta.x * delta.x + delta.y * delta.y);
    direction = sf::Vector2f(delta.x / vectorLength, delta.y / vectorLength);
    distance = speed * deltaTime;
    enemyPosition += direction * distance;
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
    UpdateBullets(deltaTime);
}

void Level4Enemy::UpdateBullets(const float& deltaTime)
{
    timeSinceLastShot += deltaTime;
    if (timeSinceLastShot > shootingDelay)
    {
        angleRad = atan2(delta.y, delta.x);
        backOffsetAngle = angleRad + M_PI;
        left1OffsetAngle = angleRad - (M_PI / 4.0f);
        left2OffsetAngle = angleRad - (M_PI / 2.0f);
        left3OffsetAngle = backOffsetAngle - (M_PI / 4.0f);
        right1OffsetAngle = angleRad + (M_PI / 4.0f);
        right2OffsetAngle = angleRad + (M_PI / 2.0f);
        right3OffsetAngle = backOffsetAngle + (M_PI / 4.0f);

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
            std::cos(left2OffsetAngle) * bullet2.speed,
            std::sin(left2OffsetAngle) * bullet2.speed
        };
        bullet2.setPosition(bullet2.position);

        PurpleBullet bullet3;
        bullet3.position = enemyPosition;
        bullet3.velocity = {
            std::cos(right2OffsetAngle) * bullet3.speed,
            std::sin(right2OffsetAngle) * bullet3.speed
        };
        bullet3.setPosition(bullet3.position);

        PurpleBullet bullet4;
        bullet4.position = enemyPosition;
        bullet4.velocity = {
            std::cos(backOffsetAngle) * bullet4.speed,
            std::sin(backOffsetAngle) * bullet4.speed
        };
        bullet4.setPosition(bullet4.position);

        OrangeBullet bullet5;
        bullet5.position = enemyPosition;
        bullet5.velocity = {
            std::cos(left1OffsetAngle) * bullet5.speed,
            std::sin(left1OffsetAngle) * bullet5.speed
        };
        bullet5.setPosition(bullet5.position);

        OrangeBullet bullet6;
        bullet6.position = enemyPosition;
        bullet6.velocity = {
            std::cos(left3OffsetAngle) * bullet6.speed,
            std::sin(left3OffsetAngle) * bullet6.speed
        };
        bullet6.setPosition(bullet6.position);

        OrangeBullet bullet7;
        bullet7.position = enemyPosition;
        bullet7.velocity = {
            std::cos(right1OffsetAngle) * bullet7.speed,
            std::sin(right1OffsetAngle) * bullet7.speed
        };
        bullet7.setPosition(bullet7.position);

        OrangeBullet bullet8;
        bullet8.position = enemyPosition;
        bullet8.velocity = {
            std::cos(right3OffsetAngle) * bullet8.speed,
            std::sin(right3OffsetAngle) * bullet8.speed
        };
        bullet8.setPosition(bullet8.position);

        purpleBullets.push_back(bullet1);
        purpleBullets.push_back(bullet2);
        purpleBullets.push_back(bullet3);
        purpleBullets.push_back(bullet4);
        orangeBullets.push_back(bullet5);
        orangeBullets.push_back(bullet6);
        orangeBullets.push_back(bullet7);
        orangeBullets.push_back(bullet8);

        timeSinceLastShot = 0.f;

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

void Level4Enemy::GotHit()
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

sf::FloatRect Level4Enemy::GetBounds()
{
    return getTransform().transformRect(enemy.getBounds());
}

Level5Enemy::Level5Enemy()
{
    health = 10;
    speed = 70.f;
    isOrange = true;
    shootingDelay = 0.1f;
    timeSinceLastStream = 2.f;
    timeSinceLastShot = 2.f;
    bulletCount = 0;
    isAnimatingHit = false;
    isAnimatingExplode = false;

    constructBallEnemy(enemy);
}

void Level5Enemy::Update(const float& deltaTime, const sf::Vector2f& playerPosition)
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
    delta = playerPosition - enemyPosition;
    vectorLength = std::sqrt(delta.x * delta.x + delta.y * delta.y);
    direction = sf::Vector2f(delta.x / vectorLength, delta.y / vectorLength);
    distance = speed * deltaTime;
    enemyPosition += direction * distance;
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
    UpdateBullets(deltaTime);
}

void Level5Enemy::UpdateBullets(const float& deltaTime)
{
    timeSinceLastStream += deltaTime;
    timeSinceLastShot += deltaTime;
    if (timeSinceLastStream > 1.f)
    {
        if (timeSinceLastShot > shootingDelay)
        {
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
            bulletCount++;

            enemySounds.shoot.play();
        }
        if (bulletCount == 10)
        {
            timeSinceLastStream = 0.f;
            bulletCount = 0;
        }
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

void Level5Enemy::GotHit()
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

sf::FloatRect Level5Enemy::GetBounds()
{
    return getTransform().transformRect(enemy.getBounds());
}