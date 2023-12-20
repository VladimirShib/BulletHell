#include "enemies.hpp"

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
        }

        sf::SoundBuffer shootBuffer;
        sf::Sound shoot;
    };

    EnemySounds enemySounds;

    // moving variables
    sf::Vector2f n_vectorOffset;
    float n_linearOffset;
    sf::Vector2f n_vectorSpeed(-400.f, 300.f);
    sf::Vector2f n_velocity;
    float n_vectorLength;
    sf::Vector2f n_direction;
    float n_distance;
    float n_originalX;
    float n_originalY;
    float n_movementOffsetCos = std::cos(float(M_PI) / 4.f);
    float n_movementOffsetSin = std::sin(float(M_PI) / 4.f);

    // shooting variables
    float n_left1OffsetAngle;
    float n_left2OffsetAngle;
    float n_left3OffsetAngle;
    float n_right1OffsetAngle;
    float n_right2OffsetAngle;
    float n_right3OffsetAngle;
    float n_backOffsetAngle;
}

float toDegrees(float radians)
{
    return radians * 180.f / float(M_PI);
}

float toRadians(float degrees)
{
    return degrees * float(M_PI) / 180.f;
}

bool boxesOverlap(const sf::Vector2f& first, const sf::Vector2f& second, const float& bounds)
{
    return (first.x + bounds > second.x &&
            first.x - bounds < second.x &&
            first.y + bounds > second.y &&
            first.y - bounds < second.y);
}

void handleOverlapping(sf::Vector2f& possiblePos, const sf::Vector2f& currentPos,
                       const float& bounds, const sf::Vector2f& otherEnemyPos)
{
    if (possiblePos.x + bounds > otherEnemyPos.x &&
        possiblePos.x - bounds < otherEnemyPos.x &&
        possiblePos.y + bounds > otherEnemyPos.y &&
        possiblePos.y - bounds < otherEnemyPos.y)
    {
        if (possiblePos.x + bounds > otherEnemyPos.x &&
            possiblePos.x - bounds < otherEnemyPos.x &&
            currentPos.y + bounds > otherEnemyPos.y &&
            currentPos.y - bounds < otherEnemyPos.y)
        {
            possiblePos.x = currentPos.x;
        }
        else
        {
            possiblePos.y = currentPos.y;
        }
    }
}

void handleObstacle(sf::Vector2f& possiblePos, const sf::Vector2f& currentPos,
                    const float& bounds, const sf::FloatRect& obstacle)
{
    if (possiblePos.x + bounds > obstacle.left &&
        possiblePos.x - bounds < obstacle.left + obstacle.width &&
        possiblePos.y + bounds > obstacle.top &&
        possiblePos.y - bounds < obstacle.top + obstacle.height)
    {
        if (possiblePos.x + bounds > obstacle.left &&
            possiblePos.x - bounds < obstacle.left + obstacle.width &&
            currentPos.y + bounds > obstacle.top &&
            currentPos.y - bounds < obstacle.top + obstacle.height)
        {
            possiblePos.x = currentPos.x;
        }
        else
        {
            possiblePos.y = currentPos.y;
        }
    }
}

void handleTwoBalls(sf::Vector2f& possiblePos, const sf::Vector2f& currentPos,
                    const sf::Vector2f& otherEnemyPos)
{
    if (possiblePos.x + 70.f > otherEnemyPos.x &&
        possiblePos.x - 70.f < otherEnemyPos.x &&
        currentPos.y + 70.f > otherEnemyPos.y &&
        currentPos.y - 70.f < otherEnemyPos.y)
    {
        possiblePos.x = currentPos.x;
    }
    else
    {
        possiblePos.y = currentPos.y;
    }
}

void BallEnemy::MoveHorizontal(const float& elapsedTime)
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

    enemyPosition.x += 6.5f * std::cos(elapsedTime * 2.f); // maxDistance and speed
    this->setPosition(enemyPosition);
}

void BallEnemy::MoveHorizontalRotated(const float& elapsedTime)
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

    n_linearOffset = 5.f * std::cos(elapsedTime * 3.f); // maxDistance and speed
    enemyPosition.x -= n_linearOffset;
    enemyPosition.y += n_linearOffset;
    this->setPosition(enemyPosition);
}

void BallEnemy::MoveLemniscate(const float& elapsedTime)
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

    n_vectorOffset.x = 200.f * std::cos(elapsedTime * 2.f); // radius and speed
    n_vectorOffset.y = 200.f * std::sin(elapsedTime * 4.f) / 2.f;
    enemyPosition.x = 500.f + n_vectorOffset.x; // center
    enemyPosition.y = 250.f + n_vectorOffset.y;
    this->setPosition(enemyPosition);
}

void BallEnemy::MoveLemniscateRotated(const float& elapsedTime)
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

    n_originalX = 200.f * std::cos(elapsedTime * 2.f); // radius and speed
    n_originalY = 200.f * std::sin(elapsedTime * 4.f) / 2.f;
    n_vectorOffset.x = n_originalX * n_movementOffsetCos - n_originalY * n_movementOffsetSin;
    n_vectorOffset.y = n_originalX * n_movementOffsetSin + n_originalY * n_movementOffsetCos;
    enemyPosition.x = 500.f + n_vectorOffset.x; // center
    enemyPosition.y = 350.f + n_vectorOffset.y;
    this->setPosition(enemyPosition);
}

void BallEnemy::MoveCircular(const float& elapsedTime)
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

    n_vectorOffset.x = 150.f * std::cos(elapsedTime * 3.f); // radius and speed
    n_vectorOffset.y = 150.f * std::sin(elapsedTime * 3.f);
    enemyPosition.x = 500.f + n_vectorOffset.x; // center
    enemyPosition.y = 350.f + n_vectorOffset.y;
    this->setPosition(enemyPosition);
}

void BallEnemy::MoveWithCollision(const float& deltaTime)
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

    enemyPosition += n_vectorSpeed * deltaTime;
    if ((enemyPosition.x >= 700.f) && (n_vectorSpeed.x > 0))
    {
        n_vectorSpeed.x = -n_vectorSpeed.x;
    }
    if ((enemyPosition.x <= 300.f) && (n_vectorSpeed.x < 0))
    {
        n_vectorSpeed.x = -n_vectorSpeed.x;
    }
    if ((enemyPosition.y >= 550.f) && (n_vectorSpeed.y > 0))
    {
        n_vectorSpeed.y = -n_vectorSpeed.y;
    }
    if ((enemyPosition.y <= 150.f) && (n_vectorSpeed.y < 0))
    {
        n_vectorSpeed.y = -n_vectorSpeed.y;
    }
    this->setPosition(enemyPosition);
}

void BallEnemy::FollowSlowly(const float& deltaTime, const sf::Vector2f& playerPosition)
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
    n_vectorLength = std::sqrt(delta.x * delta.x + delta.y * delta.y);
    if (n_vectorLength > 45.f)
    {
        n_direction.x = delta.x / n_vectorLength;
        n_direction.y = delta.y / n_vectorLength;
        n_distance = 70.f * deltaTime; // speed
        enemyPosition += n_direction * n_distance;
        this->setPosition(enemyPosition);
    }
}

void BallEnemy::FollowFast(const float& deltaTime, const sf::Vector2f& playerPosition)
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
    n_vectorLength = std::sqrt(delta.x * delta.x + delta.y * delta.y);
    if (n_vectorLength > 45.f)
    {
        n_direction.x = delta.x / n_vectorLength;
        n_direction.y = delta.y / n_vectorLength;
        n_distance = 250.f * deltaTime; // speed
        enemyPosition += n_direction * n_distance;
        this->setPosition(enemyPosition);
    }
}

void BallEnemy::MoveInPlayerDirWithDelay(const float& deltaTime, const sf::Vector2f& playerPosition)
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
    if (isMoving)
    {
        enemyPosition += n_velocity * deltaTime;
        this->setPosition(enemyPosition);
        
        if ((enemyPosition.x >= 700.f) && (n_velocity.x > 0)
        || (enemyPosition.x <= 300.f) && (n_velocity.x < 0)
        || (enemyPosition.y >= 550.f) && (n_velocity.y > 0)
        || (enemyPosition.y <= 150.f) && (n_velocity.y < 0))
        {
            isMoving = false;
            timeSinceLastStream = 0.f;
        }
    }
    else
    {
        timeSinceLastStream += deltaTime;
        if (timeSinceLastStream > 1.f)
        {
            delta = playerPosition - enemyPosition;
            angleRad = atan2(delta.y, delta.x);
            n_velocity.x = std::cos(angleRad) * 250.f; // speed
            n_velocity.y = std::sin(angleRad) * 250.f;
            isMoving = true;
        }
    }
}

void BallEnemy::ShootOneBulletBothColors(const float& deltaTime, const sf::Vector2f& playerPosition)
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
            bullet.velocity.x = std::cos(angleRad) * bullet.speed;
            bullet.velocity.y = std::sin(angleRad) * bullet.speed;
            bullet.setPosition(bullet.position);
            orangeBullets.push_back(bullet);
        }
        else
        {
            PurpleBullet bullet;
            bullet.position = enemyPosition;
            bullet.velocity.x = std::cos(angleRad) * bullet.speed;
            bullet.velocity.y = std::sin(angleRad) * bullet.speed;
            bullet.setPosition(bullet.position);
            purpleBullets.push_back(bullet);
        }
        timeSinceLastShot = 0.f;
        isOrange = !isOrange;

        enemySounds.shoot.play();
    }
}

void BallEnemy::ShootOneBulletInStreamsBothColors(const float& deltaTime)
{
    timeSinceLastStream += deltaTime;
    if (timeSinceLastStream > 1.f)
    {
        timeSinceLastShot += deltaTime;
        if (timeSinceLastShot > shootingDelay)
        {
            angleRad = atan2(delta.y, delta.x);
            if (isOrange)
            {
                OrangeBullet bullet;
                bullet.position = enemyPosition;
                bullet.velocity.x = std::cos(angleRad) * bullet.speed;
                bullet.velocity.y = std::sin(angleRad) * bullet.speed;
                bullet.setPosition(bullet.position);
                orangeBullets.push_back(bullet);
            }
            else
            {
                PurpleBullet bullet;
                bullet.position = enemyPosition;
                bullet.velocity.x = std::cos(angleRad) * bullet.speed;
                bullet.velocity.y = std::sin(angleRad) * bullet.speed;
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
}

void BallEnemy::ShootThreePurpleBullets(const float& deltaTime, const sf::Vector2f& playerPosition)
{
    timeSinceLastShot += deltaTime;
    if (timeSinceLastShot > shootingDelay)
    {
        delta = playerPosition - enemyPosition;
        angleRad = atan2(delta.y, delta.x);
        n_left1OffsetAngle = angleRad - (float(M_PI) / 4.0f);
        n_right1OffsetAngle = angleRad + (float(M_PI) / 4.0f);

        PurpleBullet bullet1;
        bullet1.position = enemyPosition;
        bullet1.velocity.x = std::cos(angleRad) * bullet1.speed;
        bullet1.velocity.y = std::sin(angleRad) * bullet1.speed;
        bullet1.setPosition(bullet1.position);

        PurpleBullet bullet2;
        bullet2.position = enemyPosition;
        bullet2.velocity.x = std::cos(n_left1OffsetAngle) * bullet2.speed;
        bullet2.velocity.y = std::sin(n_left1OffsetAngle) * bullet2.speed;
        bullet2.setPosition(bullet2.position);
        
        PurpleBullet bullet3;
        bullet3.position = enemyPosition;
        bullet3.velocity.x = std::cos(n_right1OffsetAngle) * bullet3.speed;
        bullet3.velocity.y = std::sin(n_right1OffsetAngle) * bullet3.speed;
        bullet3.setPosition(bullet3.position);

        purpleBullets.push_back(bullet1);
        purpleBullets.push_back(bullet2);
        purpleBullets.push_back(bullet3);

        timeSinceLastShot = 0.f;

        enemySounds.shoot.play();
    }
}

void BallEnemy::ShootThreeBulletsInStreamsBothColors(const float& deltaTime, const sf::Vector2f& playerPosition)
{
    timeSinceLastStream += deltaTime;
    if (timeSinceLastStream > 1.f)
    {
        timeSinceLastShot += deltaTime;
        if (timeSinceLastShot > shootingDelay)
        {
            delta = playerPosition - enemyPosition;
            angleRad = atan2(delta.y, delta.x);
            n_left1OffsetAngle = angleRad - (float(M_PI) / 4.0f);
            n_right1OffsetAngle = angleRad + (float(M_PI) / 4.0f);
            if (isOrange)
            {
                OrangeBullet bullet1;
                bullet1.position = enemyPosition;
                bullet1.velocity.x = std::cos(angleRad) * bullet1.speed;
                bullet1.velocity.y = std::sin(angleRad) * bullet1.speed;
                bullet1.setPosition(bullet1.position);

                OrangeBullet bullet2;
                bullet2.position = enemyPosition;
                bullet2.velocity.x = std::cos(n_left1OffsetAngle) * bullet2.speed;
                bullet2.velocity.y = std::sin(n_left1OffsetAngle) * bullet2.speed;
                bullet2.setPosition(bullet2.position);

                OrangeBullet bullet3;
                bullet3.position = enemyPosition;
                bullet3.velocity.x = std::cos(n_right1OffsetAngle) * bullet3.speed;
                bullet3.velocity.y = std::sin(n_right1OffsetAngle) * bullet3.speed;
                bullet3.setPosition(bullet3.position);

                orangeBullets.push_back(bullet1);
                orangeBullets.push_back(bullet2);
                orangeBullets.push_back(bullet3);
            }
            else
            {
                PurpleBullet bullet1;
                bullet1.position = enemyPosition;
                bullet1.velocity.x = std::cos(angleRad) * bullet1.speed;
                bullet1.velocity.y = std::sin(angleRad) * bullet1.speed;
                bullet1.setPosition(bullet1.position);

                PurpleBullet bullet2;
                bullet2.position = enemyPosition;
                bullet2.velocity.x = std::cos(n_left1OffsetAngle) * bullet2.speed;
                bullet2.velocity.y = std::sin(n_left1OffsetAngle) * bullet2.speed;
                bullet2.setPosition(bullet2.position);

                PurpleBullet bullet3;
                bullet3.position = enemyPosition;
                bullet3.velocity.x = std::cos(n_right1OffsetAngle) * bullet3.speed;
                bullet3.velocity.y = std::sin(n_right1OffsetAngle) * bullet3.speed;
                bullet3.setPosition(bullet3.position);

                purpleBullets.push_back(bullet1);
                purpleBullets.push_back(bullet2);
                purpleBullets.push_back(bullet3);
            }
            timeSinceLastShot = 0.f;
            isOrange = !isOrange;
            bulletCount++;

            enemySounds.shoot.play();
        }
        if (bulletCount == 3)
        {
            timeSinceLastStream = 0.f;
            bulletCount = 0;
        }
    }
}

void BallEnemy::ShootFourPurpleBullets(const float& deltaTime, const sf::Vector2f& playerPosition)
{
    timeSinceLastShot += deltaTime;
    if (timeSinceLastShot > shootingDelay)
    {
        delta = playerPosition - enemyPosition;
        angleRad = atan2(delta.y, delta.x);
        n_left1OffsetAngle = angleRad - (float(M_PI) / 2.0f);
        n_right1OffsetAngle = angleRad + (float(M_PI) / 2.0f);
        n_backOffsetAngle = angleRad + float(M_PI);

        PurpleBullet bullet1;
        bullet1.position = enemyPosition;
        bullet1.velocity.x = std::cos(angleRad) * bullet1.speed;
        bullet1.velocity.y = std::sin(angleRad) * bullet1.speed;
        bullet1.setPosition(bullet1.position);

        PurpleBullet bullet2;
        bullet2.position = enemyPosition;
        bullet2.velocity.x = std::cos(n_left1OffsetAngle) * bullet2.speed;
        bullet2.velocity.y = std::sin(n_left1OffsetAngle) * bullet2.speed;
        bullet2.setPosition(bullet2.position);
        
        PurpleBullet bullet3;
        bullet3.position = enemyPosition;
        bullet3.velocity.x = std::cos(n_right1OffsetAngle) * bullet3.speed;
        bullet3.velocity.y = std::sin(n_right1OffsetAngle) * bullet3.speed;
        bullet3.setPosition(bullet3.position);

        PurpleBullet bullet4;
        bullet4.position = enemyPosition;
        bullet4.velocity.x = std::cos(n_backOffsetAngle) * bullet4.speed;
        bullet4.velocity.y = std::sin(n_backOffsetAngle) * bullet4.speed;
        bullet4.setPosition(bullet4.position);

        purpleBullets.push_back(bullet1);
        purpleBullets.push_back(bullet2);
        purpleBullets.push_back(bullet3);
        purpleBullets.push_back(bullet4);

        timeSinceLastShot = 0.f;

        enemySounds.shoot.play();
    }
}

void BallEnemy::ShootFourBulletsBothColors(const float& deltaTime, const sf::Vector2f& playerPosition)
{
    timeSinceLastShot += deltaTime;
    if (timeSinceLastShot > shootingDelay)
    {
        delta = playerPosition - enemyPosition;
        angleRad = atan2(delta.y, delta.x);
        n_left1OffsetAngle = angleRad - (float(M_PI) / 2.0f);
        n_right1OffsetAngle = angleRad + (float(M_PI) / 2.0f);
        n_backOffsetAngle = angleRad + float(M_PI);
        if (isOrange)
        {
            OrangeBullet bullet1;
            bullet1.position = enemyPosition;
            bullet1.velocity.x = std::cos(angleRad) * bullet1.speed;
            bullet1.velocity.y = std::sin(angleRad) * bullet1.speed;
            bullet1.setPosition(bullet1.position);

            OrangeBullet bullet2;
            bullet2.position = enemyPosition;
            bullet2.velocity.x = std::cos(n_left1OffsetAngle) * bullet2.speed;
            bullet2.velocity.y = std::sin(n_left1OffsetAngle) * bullet2.speed;
            bullet2.setPosition(bullet2.position);
            
            OrangeBullet bullet3;
            bullet3.position = enemyPosition;
            bullet3.velocity.x = std::cos(n_right1OffsetAngle) * bullet3.speed;
            bullet3.velocity.y = std::sin(n_right1OffsetAngle) * bullet3.speed;
            bullet3.setPosition(bullet3.position);

            OrangeBullet bullet4;
            bullet4.position = enemyPosition;
            bullet4.velocity.x = std::cos(n_backOffsetAngle) * bullet4.speed;
            bullet4.velocity.y = std::sin(n_backOffsetAngle) * bullet4.speed;
            bullet4.setPosition(bullet4.position);

            orangeBullets.push_back(bullet1);
            orangeBullets.push_back(bullet2);
            orangeBullets.push_back(bullet3);
            orangeBullets.push_back(bullet4);
        }
        else
        {
            PurpleBullet bullet1;
            bullet1.position = enemyPosition;
            bullet1.velocity.x = std::cos(angleRad) * bullet1.speed;
            bullet1.velocity.y = std::sin(angleRad) * bullet1.speed;
            bullet1.setPosition(bullet1.position);

            PurpleBullet bullet2;
            bullet2.position = enemyPosition;
            bullet2.velocity.x = std::cos(n_left1OffsetAngle) * bullet2.speed;
            bullet2.velocity.y = std::sin(n_left1OffsetAngle) * bullet2.speed;
            bullet2.setPosition(bullet2.position);
            
            PurpleBullet bullet3;
            bullet3.position = enemyPosition;
            bullet3.velocity.x = std::cos(n_right1OffsetAngle) * bullet3.speed;
            bullet3.velocity.y = std::sin(n_right1OffsetAngle) * bullet3.speed;
            bullet3.setPosition(bullet3.position);

            PurpleBullet bullet4;
            bullet4.position = enemyPosition;
            bullet4.velocity.x = std::cos(n_backOffsetAngle) * bullet4.speed;
            bullet4.velocity.y = std::sin(n_backOffsetAngle) * bullet4.speed;
            bullet4.setPosition(bullet4.position);

            purpleBullets.push_back(bullet1);
            purpleBullets.push_back(bullet2);
            purpleBullets.push_back(bullet3);
            purpleBullets.push_back(bullet4);
        }
        timeSinceLastShot = 0.f;
        isOrange = !isOrange;

        enemySounds.shoot.play();
    }
}

void BallEnemy::ShootFiveBulletsBothColors(const float& deltaTime, const sf::Vector2f& playerPosition)
{
    timeSinceLastShot += deltaTime;
    if (timeSinceLastShot > shootingDelay)
    {
        delta = playerPosition - enemyPosition;
        angleRad = atan2(delta.y, delta.x);
        n_left1OffsetAngle = angleRad - (float(M_PI) / 4.0f);
        n_left2OffsetAngle = angleRad - (float(M_PI) / 2.0f);
        n_right1OffsetAngle = angleRad + (float(M_PI) / 4.0f);
        n_right2OffsetAngle = angleRad + (float(M_PI) / 2.0f);
        if (isOrange)
        {
            OrangeBullet bullet1;
            bullet1.position = enemyPosition;
            bullet1.velocity.x = std::cos(angleRad) * bullet1.speed;
            bullet1.velocity.y = std::sin(angleRad) * bullet1.speed;
            bullet1.setPosition(bullet1.position);

            OrangeBullet bullet2;
            bullet2.position = enemyPosition;
            bullet2.velocity.x = std::cos(n_left1OffsetAngle) * bullet2.speed;
            bullet2.velocity.y = std::sin(n_left1OffsetAngle) * bullet2.speed;
            bullet2.setPosition(bullet2.position);

            OrangeBullet bullet3;
            bullet3.position = enemyPosition;
            bullet3.velocity.x = std::cos(n_left2OffsetAngle) * bullet3.speed;
            bullet3.velocity.y = std::sin(n_left2OffsetAngle) * bullet3.speed;
            bullet3.setPosition(bullet3.position);

            OrangeBullet bullet4;
            bullet4.position = enemyPosition;
            bullet4.velocity.x = std::cos(n_right1OffsetAngle) * bullet4.speed;
            bullet4.velocity.y = std::sin(n_right1OffsetAngle) * bullet4.speed;
            bullet4.setPosition(bullet4.position);

            OrangeBullet bullet5;
            bullet5.position = enemyPosition;
            bullet5.velocity.x = std::cos(n_right2OffsetAngle) * bullet5.speed;
            bullet5.velocity.y = std::sin(n_right2OffsetAngle) * bullet5.speed;
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
            bullet1.velocity.x = std::cos(angleRad) * bullet1.speed;
            bullet1.velocity.y = std::sin(angleRad) * bullet1.speed;
            bullet1.setPosition(bullet1.position);

            PurpleBullet bullet2;
            bullet2.position = enemyPosition;
            bullet2.velocity.x = std::cos(n_left1OffsetAngle) * bullet2.speed;
            bullet2.velocity.y = std::sin(n_left1OffsetAngle) * bullet2.speed;
            bullet2.setPosition(bullet2.position);

            PurpleBullet bullet3;
            bullet3.position = enemyPosition;
            bullet3.velocity.x = std::cos(n_left2OffsetAngle) * bullet3.speed;
            bullet3.velocity.y = std::sin(n_left2OffsetAngle) * bullet3.speed;
            bullet3.setPosition(bullet3.position);

            PurpleBullet bullet4;
            bullet4.position = enemyPosition;
            bullet4.velocity.x = std::cos(n_right1OffsetAngle) * bullet4.speed;
            bullet4.velocity.y = std::sin(n_right1OffsetAngle) * bullet4.speed;
            bullet4.setPosition(bullet4.position);

            PurpleBullet bullet5;
            bullet5.position = enemyPosition;
            bullet5.velocity.x = std::cos(n_right2OffsetAngle) * bullet5.speed;
            bullet5.velocity.y = std::sin(n_right2OffsetAngle) * bullet5.speed;
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
}

void BallEnemy::ShootEightBulletsBothColors(const float& deltaTime)
{
    timeSinceLastShot += deltaTime;
    if (timeSinceLastShot > shootingDelay)
    {
        angleRad = atan2(delta.y, delta.x);
        n_backOffsetAngle = angleRad + float(M_PI);
        n_left1OffsetAngle = angleRad - (float(M_PI) / 4.0f);
        n_left2OffsetAngle = angleRad - (float(M_PI) / 2.0f);
        n_left3OffsetAngle = n_backOffsetAngle - (float(M_PI) / 4.0f);
        n_right1OffsetAngle = angleRad + (float(M_PI) / 4.0f);
        n_right2OffsetAngle = angleRad + (float(M_PI) / 2.0f);
        n_right3OffsetAngle = n_backOffsetAngle + (float(M_PI) / 4.0f);

        PurpleBullet bullet1;
        bullet1.position = enemyPosition;
        bullet1.velocity.x = std::cos(angleRad) * bullet1.speed;
        bullet1.velocity.y = std::sin(angleRad) * bullet1.speed;
        bullet1.setPosition(bullet1.position);

        PurpleBullet bullet2;
        bullet2.position = enemyPosition;
        bullet2.velocity.x = std::cos(n_left2OffsetAngle) * bullet2.speed;
        bullet2.velocity.y = std::sin(n_left2OffsetAngle) * bullet2.speed;
        bullet2.setPosition(bullet2.position);

        PurpleBullet bullet3;
        bullet3.position = enemyPosition;
        bullet3.velocity.x = std::cos(n_right2OffsetAngle) * bullet3.speed;
        bullet3.velocity.y = std::sin(n_right2OffsetAngle) * bullet3.speed;
        bullet3.setPosition(bullet3.position);

        PurpleBullet bullet4;
        bullet4.position = enemyPosition;
        bullet4.velocity.x = std::cos(n_backOffsetAngle) * bullet4.speed;
        bullet4.velocity.y = std::sin(n_backOffsetAngle) * bullet4.speed;
        bullet4.setPosition(bullet4.position);

        OrangeBullet bullet5;
        bullet5.position = enemyPosition;
        bullet5.velocity.x = std::cos(n_left1OffsetAngle) * bullet5.speed;
        bullet5.velocity.y = std::sin(n_left1OffsetAngle) * bullet5.speed;
        bullet5.setPosition(bullet5.position);

        OrangeBullet bullet6;
        bullet6.position = enemyPosition;
        bullet6.velocity.x = std::cos(n_left3OffsetAngle) * bullet6.speed;
        bullet6.velocity.y = std::sin(n_left3OffsetAngle) * bullet6.speed;
        bullet6.setPosition(bullet6.position);

        OrangeBullet bullet7;
        bullet7.position = enemyPosition;
        bullet7.velocity.x = std::cos(n_right1OffsetAngle) * bullet7.speed;
        bullet7.velocity.y = std::sin(n_right1OffsetAngle) * bullet7.speed;
        bullet7.setPosition(bullet7.position);

        OrangeBullet bullet8;
        bullet8.position = enemyPosition;
        bullet8.velocity.x = std::cos(n_right3OffsetAngle) * bullet8.speed;
        bullet8.velocity.y = std::sin(n_right3OffsetAngle) * bullet8.speed;
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
}

void ShieldedBallWithSmallEnemies::FollowSlowly(const float& deltaTime, const sf::Vector2f& playerPosition)
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
    n_vectorLength = std::sqrt(delta.x * delta.x + delta.y * delta.y);
    if (n_vectorLength > 45.f)
    {
        n_direction.x = delta.x / n_vectorLength;
        n_direction.y = delta.y / n_vectorLength;
        n_distance = 50.f * deltaTime; // speed
        possiblePos = enemyPosition;
        possiblePos += n_direction * n_distance;
        for (SmallEnemy& enemy : smallEnemies) // axis-aligned bounding boxes (AABB) algorithm
        {
            if (boxesOverlap(possiblePos, enemy.position, 60.f))
            {
                enemy.position -= (enemyPosition - enemy.position) * 0.05f; // push distance
                enemy.setPosition(enemy.position);
            }
        }
        enemyPosition = possiblePos;
        this->setPosition(enemyPosition);
    }
}

void ShieldedBallWithSmallEnemies::FollowSlowlyWithObstacles(const float& deltaTime, const sf::Vector2f& playerPosition,
                                                             const std::vector<sf::FloatRect>& obstacles)
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
    n_vectorLength = std::sqrt(delta.x * delta.x + delta.y * delta.y);
    if (n_vectorLength > 45.f)
    {
        n_direction.x = delta.x / n_vectorLength;
        n_direction.y = delta.y / n_vectorLength;
        n_distance = 50.f * deltaTime; // speed
        possiblePos = enemyPosition;
        possiblePos += n_direction * n_distance;
        for (const auto& obstacle : obstacles)
        {
            handleObstacle(possiblePos, enemyPosition, 35.f, obstacle); // point + bounds
        }
        for (SmallEnemy& enemy : smallEnemies) // axis-aligned bounding boxes (AABB) algorithm
        {
            handleOverlapping(possiblePos, enemyPosition, 60.f, enemy.position);
        }
        enemyPosition = possiblePos;
        this->setPosition(enemyPosition);
    }
}

void ShieldedBallWithSmallEnemies::FollowSlowlyWithObstaclesAndAdd(const float& deltaTime, const sf::Vector2f& playerPosition,
                                                                   const std::vector<sf::FloatRect>& obstacles, const sf::Vector2f& secondEnemyPos)
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
    n_vectorLength = std::sqrt(delta.x * delta.x + delta.y * delta.y);
    if (n_vectorLength > 45.f)
    {
        n_direction.x = delta.x / n_vectorLength;
        n_direction.y = delta.y / n_vectorLength;
        n_distance = 50.f * deltaTime; // speed
        possiblePos = enemyPosition;
        possiblePos += n_direction * n_distance;
        for (const auto& obstacle : obstacles)
        {
            handleObstacle(possiblePos, enemyPosition, 35.f, obstacle); // point + bounds
        }
        if (boxesOverlap(possiblePos, secondEnemyPos, 70.f))
        {
            handleTwoBalls(possiblePos, enemyPosition, secondEnemyPos);
        }
        for (SmallEnemy& enemy : smallEnemies) // axis-aligned bounding boxes (AABB) algorithm
        {
            handleOverlapping(possiblePos, enemyPosition, 60.f, enemy.position);
        }
        enemyPosition = possiblePos;
        this->setPosition(enemyPosition);
    }
}

void ShieldedBallWithSmallEnemies::ShootOneBulletBothColors(const float& deltaTime)
{
    timeSinceLastShot += deltaTime;
    if (timeSinceLastShot > shootingDelay)
    {
        angleRad = atan2(delta.y, delta.x);
        if (isOrange)
        {
            OrangeBullet bullet;
            bullet.position = enemyPosition;
            bullet.velocity.x = std::cos(angleRad) * bullet.speed;
            bullet.velocity.y = std::sin(angleRad) * bullet.speed;
            bullet.setPosition(bullet.position);
            orangeBullets.push_back(bullet);
        }
        else
        {
            PurpleBullet bullet;
            bullet.position = enemyPosition;
            bullet.velocity.x = std::cos(angleRad) * bullet.speed;
            bullet.velocity.y = std::sin(angleRad) * bullet.speed;
            bullet.setPosition(bullet.position);
            purpleBullets.push_back(bullet);
        }
        timeSinceLastShot = 0.f;
        isOrange = !isOrange;

        enemySounds.shoot.play();
    }
}

void ShieldedBallWithSmallEnemies::ShootThreePurpleBullets(const float& deltaTime)
{
    timeSinceLastShot += deltaTime;
    if (timeSinceLastShot > shootingDelay)
    {
        angleRad = atan2(delta.y, delta.x);
        n_left1OffsetAngle = angleRad - (float(M_PI) / 4.0f);
        n_right1OffsetAngle = angleRad + (float(M_PI) / 4.0f);

        PurpleBullet bullet1;
        bullet1.position = enemyPosition;
        bullet1.velocity.x = std::cos(angleRad) * bullet1.speed;
        bullet1.velocity.y = std::sin(angleRad) * bullet1.speed;
        bullet1.setPosition(bullet1.position);

        PurpleBullet bullet2;
        bullet2.position = enemyPosition;
        bullet2.velocity.x = std::cos(n_left1OffsetAngle) * bullet2.speed;
        bullet2.velocity.y = std::sin(n_left1OffsetAngle) * bullet2.speed;
        bullet2.setPosition(bullet2.position);
        
        PurpleBullet bullet3;
        bullet3.position = enemyPosition;
        bullet3.velocity.x = std::cos(n_right1OffsetAngle) * bullet3.speed;
        bullet3.velocity.y = std::sin(n_right1OffsetAngle) * bullet3.speed;
        bullet3.setPosition(bullet3.position);

        purpleBullets.push_back(bullet1);
        purpleBullets.push_back(bullet2);
        purpleBullets.push_back(bullet3);

        timeSinceLastShot = 0.f;

        enemySounds.shoot.play();
    }
}

void ShieldedBallWithSmallEnemies::ShootFiveBulletsBothColors(const float& deltaTime)
{
    timeSinceLastShot += deltaTime;
    if (timeSinceLastShot > shootingDelay)
    {
        angleRad = atan2(delta.y, delta.x);
        n_left1OffsetAngle = angleRad - (float(M_PI) / 4.0f);
        n_left2OffsetAngle = angleRad - (float(M_PI) / 2.0f);
        n_right1OffsetAngle = angleRad + (float(M_PI) / 4.0f);
        n_right2OffsetAngle = angleRad + (float(M_PI) / 2.0f);
        if (isOrange)
        {
            OrangeBullet bullet1;
            bullet1.position = enemyPosition;
            bullet1.velocity.x = std::cos(angleRad) * bullet1.speed;
            bullet1.velocity.y = std::sin(angleRad) * bullet1.speed;
            bullet1.setPosition(bullet1.position);

            OrangeBullet bullet2;
            bullet2.position = enemyPosition;
            bullet2.velocity.x = std::cos(n_left1OffsetAngle) * bullet2.speed;
            bullet2.velocity.y = std::sin(n_left1OffsetAngle) * bullet2.speed;
            bullet2.setPosition(bullet2.position);

            OrangeBullet bullet3;
            bullet3.position = enemyPosition;
            bullet3.velocity.x = std::cos(n_left2OffsetAngle) * bullet3.speed;
            bullet3.velocity.y = std::sin(n_left2OffsetAngle) * bullet3.speed;
            bullet3.setPosition(bullet3.position);

            OrangeBullet bullet4;
            bullet4.position = enemyPosition;
            bullet4.velocity.x = std::cos(n_right1OffsetAngle) * bullet4.speed;
            bullet4.velocity.y = std::sin(n_right1OffsetAngle) * bullet4.speed;
            bullet4.setPosition(bullet4.position);

            OrangeBullet bullet5;
            bullet5.position = enemyPosition;
            bullet5.velocity.x = std::cos(n_right2OffsetAngle) * bullet5.speed;
            bullet5.velocity.y = std::sin(n_right2OffsetAngle) * bullet5.speed;
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
            bullet1.velocity.x = std::cos(angleRad) * bullet1.speed;
            bullet1.velocity.y = std::sin(angleRad) * bullet1.speed;
            bullet1.setPosition(bullet1.position);

            PurpleBullet bullet2;
            bullet2.position = enemyPosition;
            bullet2.velocity.x = std::cos(n_left1OffsetAngle) * bullet2.speed;
            bullet2.velocity.y = std::sin(n_left1OffsetAngle) * bullet2.speed;
            bullet2.setPosition(bullet2.position);

            PurpleBullet bullet3;
            bullet3.position = enemyPosition;
            bullet3.velocity.x = std::cos(n_left2OffsetAngle) * bullet3.speed;
            bullet3.velocity.y = std::sin(n_left2OffsetAngle) * bullet3.speed;
            bullet3.setPosition(bullet3.position);

            PurpleBullet bullet4;
            bullet4.position = enemyPosition;
            bullet4.velocity.x = std::cos(n_right1OffsetAngle) * bullet4.speed;
            bullet4.velocity.y = std::sin(n_right1OffsetAngle) * bullet4.speed;
            bullet4.setPosition(bullet4.position);

            PurpleBullet bullet5;
            bullet5.position = enemyPosition;
            bullet5.velocity.x = std::cos(n_right2OffsetAngle) * bullet5.speed;
            bullet5.velocity.y = std::sin(n_right2OffsetAngle) * bullet5.speed;
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
}

void ShieldedBallWithSmallEnemies::RotatingShootingTypeOne(const float& deltaTime) // two orange two purple
{
    timeSinceLastShot += deltaTime;
    if (timeSinceLastShot > shootingDelay)
    {
        OrangeBullet bullet1;
        bullet1.position = enemyPosition;
        bullet1.velocity.x = std::cos(shootingAngle) * bullet1.speed;
        bullet1.velocity.y = std::sin(shootingAngle) * bullet1.speed;
        bullet1.setPosition(bullet1.position);
        shootingAngle += float(M_PI) / 2.f;

        OrangeBullet bullet2;
        bullet2.position = enemyPosition;
        bullet2.velocity.x = std::cos(shootingAngle) * bullet2.speed;
        bullet2.velocity.y = std::sin(shootingAngle) * bullet2.speed;
        bullet2.setPosition(bullet2.position);
        shootingAngle += float(M_PI) / 2.f;

        PurpleBullet bullet3;
        bullet3.position = enemyPosition;
        bullet3.velocity.x = std::cos(shootingAngle) * bullet3.speed;
        bullet3.velocity.y = std::sin(shootingAngle) * bullet3.speed;
        bullet3.setPosition(bullet3.position);
        shootingAngle += float(M_PI) / 2.f;

        PurpleBullet bullet4;
        bullet4.position = enemyPosition;
        bullet4.velocity.x = std::cos(shootingAngle) * bullet4.speed;
        bullet4.velocity.y = std::sin(shootingAngle) * bullet4.speed;
        bullet4.setPosition(bullet4.position);
        shootingAngle += float(M_PI) / 2.f;

        orangeBullets.push_back(bullet1);
        orangeBullets.push_back(bullet2);
        purpleBullets.push_back(bullet3);
        purpleBullets.push_back(bullet4);

        timeSinceLastShot = 0.f;

        enemySounds.shoot.play();
    }

    shootingAngle += 0.5f * float(M_PI) / 180.f;
}

void ShieldedBallWithSmallEnemies::RotatingShootingTypeTwo(const float& deltaTime) // orange-two purple-three orange-two purple
{
    timeSinceLastShot += deltaTime;
    if (timeSinceLastShot > shootingDelay)
    {
        OrangeBullet bullet1;
        bullet1.position = enemyPosition;
        bullet1.velocity.x = std::cos(shootingAngle) * bullet1.speed;
        bullet1.velocity.y = std::sin(shootingAngle) * bullet1.speed;
        bullet1.setPosition(bullet1.position);
        shootingAngle += float(M_PI) / 4.f;

        PurpleBullet bullet2;
        bullet2.position = enemyPosition;
        bullet2.velocity.x = std::cos(shootingAngle) * bullet2.speed;
        bullet2.velocity.y = std::sin(shootingAngle) * bullet2.speed;
        bullet2.setPosition(bullet2.position);
        shootingAngle += float(M_PI) / 4.f;

        PurpleBullet bullet3;
        bullet3.position = enemyPosition;
        bullet3.velocity.x = std::cos(shootingAngle) * bullet3.speed;
        bullet3.velocity.y = std::sin(shootingAngle) * bullet3.speed;
        bullet3.setPosition(bullet3.position);
        shootingAngle += float(M_PI) / 4.f;

        OrangeBullet bullet4;
        bullet4.position = enemyPosition;
        bullet4.velocity.x = std::cos(shootingAngle) * bullet4.speed;
        bullet4.velocity.y = std::sin(shootingAngle) * bullet4.speed;
        bullet4.setPosition(bullet4.position);
        shootingAngle += float(M_PI) / 4.f;

        OrangeBullet bullet5;
        bullet5.position = enemyPosition;
        bullet5.velocity.x = std::cos(shootingAngle) * bullet5.speed;
        bullet5.velocity.y = std::sin(shootingAngle) * bullet5.speed;
        bullet5.setPosition(bullet5.position);
        shootingAngle += float(M_PI) / 4.f;

        OrangeBullet bullet6;
        bullet6.position = enemyPosition;
        bullet6.velocity.x = std::cos(shootingAngle) * bullet6.speed;
        bullet6.velocity.y = std::sin(shootingAngle) * bullet6.speed;
        bullet6.setPosition(bullet6.position);
        shootingAngle += float(M_PI) / 4.f;

        PurpleBullet bullet7;
        bullet7.position = enemyPosition;
        bullet7.velocity.x = std::cos(shootingAngle) * bullet7.speed;
        bullet7.velocity.y = std::sin(shootingAngle) * bullet7.speed;
        bullet7.setPosition(bullet7.position);
        shootingAngle += float(M_PI) / 4.f;

        PurpleBullet bullet8;
        bullet8.position = enemyPosition;
        bullet8.velocity.x = std::cos(shootingAngle) * bullet8.speed;
        bullet8.velocity.y = std::sin(shootingAngle) * bullet8.speed;
        bullet8.setPosition(bullet8.position);
        shootingAngle += float(M_PI) / 4.f;

        orangeBullets.push_back(bullet1);
        orangeBullets.push_back(bullet4);
        orangeBullets.push_back(bullet5);
        orangeBullets.push_back(bullet6);
        purpleBullets.push_back(bullet2);
        purpleBullets.push_back(bullet3);
        purpleBullets.push_back(bullet7);
        purpleBullets.push_back(bullet8);

        timeSinceLastShot = 0.f;

        enemySounds.shoot.play();
    }

    shootingAngle += 0.5f * float(M_PI) / 180.f;
}

void ShieldedBallWithSmallEnemies::RotatingShootingTypeThree(const float& deltaTime) // eight purple
{
    timeSinceLastShot += deltaTime;
    if (timeSinceLastShot > shootingDelay)
    {
        PurpleBullet bullet1;
        bullet1.position = enemyPosition;
        bullet1.velocity.x = std::cos(shootingAngle) * bullet1.speed;
        bullet1.velocity.y = std::sin(shootingAngle) * bullet1.speed;
        bullet1.setPosition(bullet1.position);
        shootingAngle += float(M_PI) / 4.f;

        PurpleBullet bullet2;
        bullet2.position = enemyPosition;
        bullet2.velocity.x = std::cos(shootingAngle) * bullet2.speed;
        bullet2.velocity.y = std::sin(shootingAngle) * bullet2.speed;
        bullet2.setPosition(bullet2.position);
        shootingAngle += float(M_PI) / 4.f;

        PurpleBullet bullet3;
        bullet3.position = enemyPosition;
        bullet3.velocity.x = std::cos(shootingAngle) * bullet3.speed;
        bullet3.velocity.y = std::sin(shootingAngle) * bullet3.speed;
        bullet3.setPosition(bullet3.position);
        shootingAngle += float(M_PI) / 4.f;

        PurpleBullet bullet4;
        bullet4.position = enemyPosition;
        bullet4.velocity.x = std::cos(shootingAngle) * bullet4.speed;
        bullet4.velocity.y = std::sin(shootingAngle) * bullet4.speed;
        bullet4.setPosition(bullet4.position);
        shootingAngle += float(M_PI) / 4.f;

        PurpleBullet bullet5;
        bullet5.position = enemyPosition;
        bullet5.velocity.x = std::cos(shootingAngle) * bullet5.speed;
        bullet5.velocity.y = std::sin(shootingAngle) * bullet5.speed;
        bullet5.setPosition(bullet5.position);
        shootingAngle += float(M_PI) / 4.f;

        PurpleBullet bullet6;
        bullet6.position = enemyPosition;
        bullet6.velocity.x = std::cos(shootingAngle) * bullet6.speed;
        bullet6.velocity.y = std::sin(shootingAngle) * bullet6.speed;
        bullet6.setPosition(bullet6.position);
        shootingAngle += float(M_PI) / 4.f;

        PurpleBullet bullet7;
        bullet7.position = enemyPosition;
        bullet7.velocity.x = std::cos(shootingAngle) * bullet7.speed;
        bullet7.velocity.y = std::sin(shootingAngle) * bullet7.speed;
        bullet7.setPosition(bullet7.position);
        shootingAngle += float(M_PI) / 4.f;

        PurpleBullet bullet8;
        bullet8.position = enemyPosition;
        bullet8.velocity.x = std::cos(shootingAngle) * bullet8.speed;
        bullet8.velocity.y = std::sin(shootingAngle) * bullet8.speed;
        bullet8.setPosition(bullet8.position);
        shootingAngle += float(M_PI) / 4.f;

        purpleBullets.push_back(bullet1);
        purpleBullets.push_back(bullet4);
        purpleBullets.push_back(bullet5);
        purpleBullets.push_back(bullet6);
        purpleBullets.push_back(bullet2);
        purpleBullets.push_back(bullet3);
        purpleBullets.push_back(bullet7);
        purpleBullets.push_back(bullet8);

        timeSinceLastShot = 0.f;

        enemySounds.shoot.play();
    }

    shootingAngle += 0.5f * float(M_PI) / 180.f;
}

void ShieldedBallWithSmallEnemies::ConstantAngleShooting(const float& deltaTime)
{
    timeSinceLastShot += deltaTime;
    if (timeSinceLastShot > shootingDelay)
    {
        n_left1OffsetAngle = shootingAngle - (float(M_PI) / 2.0f);
        n_right1OffsetAngle = shootingAngle + (float(M_PI) / 2.0f);
        n_backOffsetAngle = shootingAngle + float(M_PI);
        if (isOrange)
        {
            OrangeBullet bullet1;
            bullet1.position = enemyPosition;
            bullet1.velocity.x = std::cos(shootingAngle) * bullet1.speed;
            bullet1.velocity.y = std::sin(shootingAngle) * bullet1.speed;
            bullet1.setPosition(bullet1.position);

            OrangeBullet bullet2;
            bullet2.position = enemyPosition;
            bullet2.velocity.x = std::cos(n_left1OffsetAngle) * bullet2.speed;
            bullet2.velocity.y = std::sin(n_left1OffsetAngle) * bullet2.speed;
            bullet2.setPosition(bullet2.position);

            OrangeBullet bullet3;
            bullet3.position = enemyPosition;
            bullet3.velocity.x = std::cos(n_right1OffsetAngle) * bullet3.speed;
            bullet3.velocity.y = std::sin(n_right1OffsetAngle) * bullet3.speed;
            bullet3.setPosition(bullet3.position);

            OrangeBullet bullet4;
            bullet4.position = enemyPosition;
            bullet4.velocity.x = std::cos(n_backOffsetAngle) * bullet4.speed;
            bullet4.velocity.y = std::sin(n_backOffsetAngle) * bullet4.speed;
            bullet4.setPosition(bullet4.position);

            orangeBullets.push_back(bullet1);
            orangeBullets.push_back(bullet2);
            orangeBullets.push_back(bullet3);
            orangeBullets.push_back(bullet4);
        }
        else
        {
            PurpleBullet bullet1;
            bullet1.position = enemyPosition;
            bullet1.velocity.x = std::cos(shootingAngle) * bullet1.speed;
            bullet1.velocity.y = std::sin(shootingAngle) * bullet1.speed;
            bullet1.setPosition(bullet1.position);

            PurpleBullet bullet2;
            bullet2.position = enemyPosition;
            bullet2.velocity.x = std::cos(n_left1OffsetAngle) * bullet2.speed;
            bullet2.velocity.y = std::sin(n_left1OffsetAngle) * bullet2.speed;
            bullet2.setPosition(bullet2.position);

            PurpleBullet bullet3;
            bullet3.position = enemyPosition;
            bullet3.velocity.x = std::cos(n_right1OffsetAngle) * bullet3.speed;
            bullet3.velocity.y = std::sin(n_right1OffsetAngle) * bullet3.speed;
            bullet3.setPosition(bullet3.position);

            PurpleBullet bullet4;
            bullet4.position = enemyPosition;
            bullet4.velocity.x = std::cos(n_backOffsetAngle) * bullet4.speed;
            bullet4.velocity.y = std::sin(n_backOffsetAngle) * bullet4.speed;
            bullet4.setPosition(bullet4.position);

            purpleBullets.push_back(bullet1);
            purpleBullets.push_back(bullet2);
            purpleBullets.push_back(bullet3);
            purpleBullets.push_back(bullet4);
        }
        timeSinceLastShot = 0.f;
        isOrange = !isOrange;

        enemySounds.shoot.play();
    }
}

void AdditionalEnemy::FollowSlowlyWithObstacles(const float& deltaTime, const sf::Vector2f& playerPosition, const std::vector<sf::FloatRect>& obstacles,
                                                const sf::Vector2f& firstEnemyPos, std::vector<SmallEnemy>& smallEnemies)
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
    n_vectorLength = std::sqrt(delta.x * delta.x + delta.y * delta.y);
    if (n_vectorLength > 45.f)
    {
        n_direction.x = delta.x / n_vectorLength;
        n_direction.y = delta.y / n_vectorLength;
        n_distance = 50.f * deltaTime; // speed
        possiblePos = enemyPosition;
        possiblePos += n_direction * n_distance;
        for (const auto& obstacle : obstacles)
        {
            handleObstacle(possiblePos, enemyPosition, 35.f, obstacle); // point + bounds
        }
        if (boxesOverlap(possiblePos, firstEnemyPos, 70.f))
        {
            handleTwoBalls(possiblePos, enemyPosition, firstEnemyPos);
        }
        for (SmallEnemy& enemy : smallEnemies) // axis-aligned bounding boxes (AABB) algorithm
        {
            handleOverlapping(possiblePos, enemyPosition, 60.f, enemy.position);
        }
        enemyPosition = possiblePos;
        this->setPosition(enemyPosition);
    }
}

void AdditionalEnemy::RotatingShootingTypeOne(const float& deltaTime, const float& delay, std::vector<OrangeBullet>& orangeBullets,
                                              std::vector<PurpleBullet>& purpleBullets)
{
    if (shootingDelay != delay)
    {
        shootingDelay = delay;
    }
    timeSinceLastShot += deltaTime;
    if (timeSinceLastShot > shootingDelay)
    {
        OrangeBullet bullet1;
        bullet1.position = enemyPosition;
        bullet1.velocity.x = std::cos(shootingAngle) * bullet1.speed;
        bullet1.velocity.y = std::sin(shootingAngle) * bullet1.speed;
        bullet1.setPosition(bullet1.position);
        shootingAngle += float(M_PI) / 2.f;

        OrangeBullet bullet2;
        bullet2.position = enemyPosition;
        bullet2.velocity.x = std::cos(shootingAngle) * bullet2.speed;
        bullet2.velocity.y = std::sin(shootingAngle) * bullet2.speed;
        bullet2.setPosition(bullet2.position);
        shootingAngle += float(M_PI) / 2.f;

        PurpleBullet bullet3;
        bullet3.position = enemyPosition;
        bullet3.velocity.x = std::cos(shootingAngle) * bullet3.speed;
        bullet3.velocity.y = std::sin(shootingAngle) * bullet3.speed;
        bullet3.setPosition(bullet3.position);
        shootingAngle += float(M_PI) / 2.f;

        PurpleBullet bullet4;
        bullet4.position = enemyPosition;
        bullet4.velocity.x = std::cos(shootingAngle) * bullet4.speed;
        bullet4.velocity.y = std::sin(shootingAngle) * bullet4.speed;
        bullet4.setPosition(bullet4.position);
        shootingAngle += float(M_PI) / 2.f;

        orangeBullets.push_back(bullet1);
        orangeBullets.push_back(bullet2);
        purpleBullets.push_back(bullet3);
        purpleBullets.push_back(bullet4);

        timeSinceLastShot = 0.f;
    }

    shootingAngle += 0.5f * float(M_PI) / 180.f;
}

void SmallEnemy::Move(std::vector<SmallEnemy>& enemies, const float& deltaTime, const sf::Vector2f& playerPosition,
                      std::vector<OrangeBullet>& bullets, int& number)
{
    if (isAnimatingExplode)
    {
        currentFrame++;
        if (currentFrame == 30)
        {
            hit = true;
            number--; // remaining small enemies
        }
        return;
    }
    if (spawned)
    {
        currentFrame++;
        if (currentFrame == 18)
        {
            spawned = false;
        }
    }

    delta = playerPosition - position;
    angleRad = atan2(delta.y, delta.x);
    newAngleDeg = toDegrees(angleRad);
    if (newAngleDeg < 0.f)
    {
        newAngleDeg += 360.f;
    }
    angleDeg = this->getRotation();
    deltaAngle = newAngleDeg - angleDeg;
    if (deltaAngle > 0.f && deltaAngle < 180.f || deltaAngle < -180.f)
    {
        angleDeg += 0.7f; // rotational speed
    }
    else
    {
        angleDeg -= 0.7f;
    }
    this->setRotation(angleDeg);

    Shoot(bullets, deltaTime);

    direction = toRadians(angleDeg);
    velocity.x = std::cos(direction) * 70.f; // speed
    velocity.y = std::sin(direction) * 70.f;
    possiblePos = position;
    possiblePos += velocity * deltaTime;
    if (!boxesOverlap(possiblePos, playerPosition, 40.f)) // axis-aligned bounding boxes (AABB) algorithm
    {
        for (SmallEnemy& otherEnemy : enemies)
        {
            if (id != otherEnemy.id)
            {
                if (boxesOverlap(possiblePos, otherEnemy.position, 35.f))
                {
                    position -= (otherEnemy.position - position) * 0.05f; // push distance
                    this->setPosition(position);
                    return;
                }
            }
        }
        if (possiblePos.x > 65.f && possiblePos.x < 935.f
            && possiblePos.y > -85.f && possiblePos.y < 785.f)
        {
            position = possiblePos;
            this->setPosition(position);
        }
    }
}

void SmallEnemy::MoveWithObstacles(std::vector<SmallEnemy>& enemies, const float& deltaTime, const sf::Vector2f& playerPosition,
                                   std::vector<OrangeBullet>& bullets, int& number, const std::vector<sf::FloatRect>& obstacles)
{
    if (isAnimatingExplode)
    {
        currentFrame++;
        if (currentFrame == 30)
        {
            hit = true;
            number--;
        }
        return;
    }
    if (spawned)
    {
        currentFrame++;
        if (currentFrame == 18)
        {
            spawned = false;
        }
    }

    delta = playerPosition - position;
    angleRad = atan2(delta.y, delta.x);
    newAngleDeg = toDegrees(angleRad);
    if (newAngleDeg < 0.f)
    {
        newAngleDeg += 360.f;
    }
    angleDeg = this->getRotation();
    deltaAngle = newAngleDeg - angleDeg;
    if (deltaAngle > 0.f && deltaAngle < 180.f || deltaAngle < -180.f)
    {
        angleDeg += 0.7f; // rotational speed
    }
    else
    {
        angleDeg -= 0.7f;
    }
    this->setRotation(angleDeg);

    Shoot(bullets, deltaTime);

    direction = toRadians(angleDeg);
    velocity.x = std::cos(direction) * 70.f; // speed
    velocity.y = std::sin(direction) * 70.f;
    possiblePos = position;
    possiblePos += velocity * deltaTime;
    if (!boxesOverlap(possiblePos, playerPosition, 40.f)) // axis-aligned bounding boxes (AABB) algorithm
    {
        for (const auto& obstacle : obstacles)
        {
            handleObstacle(possiblePos, position, 20.f, obstacle);
        }
        for (SmallEnemy& otherEnemy : enemies)
        {
            if (id != otherEnemy.id)
            {
                handleOverlapping(possiblePos, position, 35.f, otherEnemy.position);
            }
        }
        if (possiblePos.x > 65.f && possiblePos.x < 935.f
            && possiblePos.y > -85.f && possiblePos.y < 785.f)
        {
            position = possiblePos;
            this->setPosition(position);
        }
    }
}

void SmallEnemy::Shoot(std::vector<OrangeBullet>& bullets, const float& deltaTime)
{
    timeSinceLastShot += deltaTime;
    if (timeSinceLastShot > shootingDelay)
    {
        OrangeBullet bullet;
        bullet.position = position;
        bullet.velocity.x = std::cos(angleRad) * bullet.speed;
        bullet.velocity.y = std::sin(angleRad) * bullet.speed;
        bullet.setPosition(bullet.position);
        bullets.push_back(bullet);

        timeSinceLastShot = 0.f;

        enemySounds.shoot.play();
    }
}