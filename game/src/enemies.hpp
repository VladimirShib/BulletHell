#pragma once

#include "headers.hpp"

namespace
{
    struct EnemyAnimations
    {
    public:
        EnemyAnimations()
        {
            if (!hitTexture.loadFromFile("game/spritesheets/enemy_hit.png"))
            {
                std::cout << "Failed to load enemy_hit spritesheet!\n";
            }
            if (!explodeTexture.loadFromFile("game/spritesheets/enemy_explode.png"))
            {
                std::cout << "Failed to load enemy_explode spritesheet!\n";
            }
            if (!shieldTexture.loadFromFile("game/spritesheets/shield.png"))
            {
                std::cout << "Failed to load shield spritesheet!\n";
            }
            if (!weakExplodeTexture.loadFromFile("game/spritesheets/enemy_explode_weak.png"))
            {
                std::cout << "Failed to load enemy_explode_weak spritesheet!\n";
            }
            if (!shieldExplodeTexture.loadFromFile("game/spritesheets/shield_explode.png"))
            {
                std::cout << "Failed to load shield_explode spritesheet!\n";
            }
            if (!spawnTexture.loadFromFile("game/spritesheets/enemy_spawn.png"))
            {
                std::cout << "Failed to load enemy_spawn spritesheet!\n";
            }

            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    hitFrames.push_back(sf::IntRect(j * 128, i * 128, 128, 128));
                }
            }
            for (int i = 0; i < 12; ++i)
            {
                sf::Sprite sprite;
                sprite.setTexture(hitTexture);
                sprite.setTextureRect(hitFrames[i]);
                sprite.setOrigin(sf::Vector2f(64.f, 64.f));
                hitSprites.push_back(sprite);
            }

            for (int i = 0; i < 6; ++i)
            {
                for (int j = 0; j < 5; ++j)
                {
                    explodeFrames.push_back(sf::IntRect(j * 256, i * 256, 256, 256));
                }
            }
            for (int i = 0; i < 30; ++i)
            {
                sf::Sprite sprite;
                sprite.setTexture(explodeTexture);
                sprite.setTextureRect(explodeFrames[i]);
                sprite.setOrigin(sf::Vector2f(128.f, 128.f));
                explodeSprites.push_back(sprite);
            }

            for (int i = 0; i < 5; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    shieldFrames.push_back(sf::IntRect(j * 128, i * 128, 128, 128));
                }
            }
            for (int i = 0; i < 20; ++i)
            {
                sf::Sprite sprite;
                sprite.setTexture(shieldTexture);
                sprite.setTextureRect(shieldFrames[i]);
                sprite.setOrigin(sf::Vector2f(64.f, 64.f));
                shieldSprites.push_back(sprite);
            }

            for (int i = 0; i < 6; ++i)
            {
                for (int j = 0; j < 5; ++j)
                {
                    weakExplodeFrames.push_back(sf::IntRect(j * 256, i * 256, 256, 256));
                }
            }
            for (int i = 0; i < 30; ++i)
            {
                sf::Sprite sprite;
                sprite.setTexture(weakExplodeTexture);
                sprite.setTextureRect(weakExplodeFrames[i]);
                sprite.setOrigin(sf::Vector2f(128.f, 128.f));
                weakExplodeSprites.push_back(sprite);
            }

            for (int i = 0; i < 6; ++i)
            {
                for (int j = 0; j < 5; ++j)
                {
                    shieldExplodeFrames.push_back(sf::IntRect(j * 256, i * 256, 256, 256));
                }
            }
            for (int i = 0; i < 30; ++i)
            {
                sf::Sprite sprite;
                sprite.setTexture(shieldExplodeTexture);
                sprite.setTextureRect(shieldExplodeFrames[i]);
                sprite.setOrigin(sf::Vector2f(128.f, 128.f));
                shieldExplodeSprites.push_back(sprite);
            }

            for (int i = 0; i < 6; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    spawnFrames.push_back(sf::IntRect(j * 128, i * 128, 128, 128));
                }
            }
            for (int i = 0; i < 18; ++i)
            {
                sf::Sprite sprite;
                sprite.setTexture(spawnTexture);
                sprite.setTextureRect(spawnFrames[i]);
                sprite.setOrigin(sf::Vector2f(64.f, 64.f));
                spawnSprites.push_back(sprite);
            }
        }

    public:
        std::vector<sf::Sprite> hitSprites;
        std::vector<sf::Sprite> explodeSprites;
        std::vector<sf::Sprite> shieldSprites;
        std::vector<sf::Sprite> weakExplodeSprites;
        std::vector<sf::Sprite> shieldExplodeSprites;
        std::vector<sf::Sprite> spawnSprites;

    private:
        sf::Texture hitTexture;
        sf::Texture explodeTexture;
        sf::Texture shieldTexture;
        sf::Texture weakExplodeTexture;
        sf::Texture shieldExplodeTexture;
        sf::Texture spawnTexture;
        std::vector<sf::IntRect> hitFrames;
        std::vector<sf::IntRect> explodeFrames;
        std::vector<sf::IntRect> shieldFrames;
        std::vector<sf::IntRect> weakExplodeFrames;
        std::vector<sf::IntRect> shieldExplodeFrames;
        std::vector<sf::IntRect> spawnFrames;
    };

    EnemyAnimations enemyAnimations;
}

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

class BallEnemy : public sf::Drawable, public sf::Transformable
{
public:
    BallEnemy(float delay);

    void MoveHorizontal(const float& elapsedTime);
    void MoveHorizontalRotated(const float& elapsedTime);
    void MoveLemniscate(const float& elapsedTime);
    void MoveLemniscateRotated(const float& elapsedTime);
    void MoveCircular(const float& elapsedTime);
    void MoveWithCollision(const float& deltaTime);
    void FollowSlowly(const float& deltaTime, const sf::Vector2f& playerPosition);
    void FollowFast(const float& deltaTime, const sf::Vector2f& playerPosition);
    void MoveInPlayerDirWithDelay(const float& deltaTime, const sf::Vector2f& playerPosition);
    void AnimateHit();
    void ShootOneBulletBothColors(const float& deltaTime, const sf::Vector2f& playerPosition);
    void ShootOneBulletInStreamsBothColors(const float& deltaTime);
    void ShootThreePurpleBullets(const float& deltaTime, const sf::Vector2f& playerPosition);
    void ShootThreeBulletsInStreamsBothColors(const float& deltaTime, const sf::Vector2f& playerPosition);
    void ShootFourPurpleBullets(const float& deltaTime, const sf::Vector2f& playerPosition);
    void ShootFourBulletsBothColors(const float& deltaTime, const sf::Vector2f& playerPosition);
    void ShootFiveBulletsBothColors(const float& deltaTime, const sf::Vector2f& playerPosition);
    void ShootEightBulletsBothColors(const float& deltaTime);
    void UpdateAllBullets(const float& deltaTime);
    void UpdatePurpleBullets(const float& deltaTime);
    void GotHit();
    sf::FloatRect GetBounds();

public:
    int health;
    sf::Vector2f enemyPosition;
    std::vector<OrangeBullet> orangeBullets;
    std::vector<PurpleBullet> purpleBullets;
    bool isAnimatingExplode;

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

        if (!isAnimatingExplode)
        {
            target.draw(enemy, states);
        }
        else
        {
            enemyAnimations.explodeSprites[currentFrame].setPosition(enemyPosition);
            target.draw(enemyAnimations.explodeSprites[currentFrame]);
        }

        if (isAnimatingHit)
        {
            enemyAnimations.hitSprites[currentFrame].setPosition(enemyPosition);
            target.draw(enemyAnimations.hitSprites[currentFrame]);
        }
    }

    sf::VertexArray enemy;
    bool isMoving;
    bool isOrange;
    float shootingDelay;
    float timeSinceLastShot;
    float timeSinceLastStream;
    int bulletCount;
    sf::Vector2f delta;
    float angleRad;
    int currentFrame;
    bool isAnimatingHit;
};

class SmallEnemy : public sf::Drawable, public sf::Transformable
{
public:
    SmallEnemy(int num, float lastShot, char shield);

    void Move(std::vector<SmallEnemy>& enemies, const float& deltaTime, const sf::Vector2f& playerPosition,
              std::vector<OrangeBullet>& bullets, int& number);
    void MoveWithObstacles(std::vector<SmallEnemy>& enemies, const float& deltaTime, const sf::Vector2f& playerPosition,
                           std::vector<OrangeBullet>& bullets, int& number, const std::vector<sf::FloatRect>& obstacles);
    void Shoot(std::vector<OrangeBullet>& orangeBullets, const float& deltaTime);
    void GotHit(float& delay);
    void GotHitInShield();
    sf::FloatRect GetBounds();
    sf::FloatRect GetFrontBounds();

public:
    int id;
    sf::Vector2f position;
    bool hit;
    bool isAnimatingExplode;
    bool spawned;
    bool shielded;
    int currentFrame;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        if (!isAnimatingExplode)
        {
            target.draw(enemy, states);
            if (shielded)
            {
                target.draw(enemyFront, states);
            }
        }
        else
        {
            enemyAnimations.weakExplodeSprites[currentFrame].setPosition(position);
            target.draw(enemyAnimations.weakExplodeSprites[currentFrame]);
        }
        if (spawned)
        {
            enemyAnimations.spawnSprites[currentFrame].setPosition(position);
            target.draw(enemyAnimations.spawnSprites[currentFrame]);
        }
    }

    sf::VertexArray enemy;
    sf::VertexArray enemyFront;
    int health;
    sf::Vector2f delta;
    float angleRad;
    float angleDeg;
    float newAngleDeg;
    float deltaAngle;
    float direction;
    sf::Vector2f possiblePos;
    sf::Vector2f velocity;
    float shootingDelay;
    float timeSinceLastShot;
};

class ShieldedBallWithSmallEnemies : public sf::Drawable, public sf::Transformable
{
public:
    ShieldedBallWithSmallEnemies(float delay, int number);

    void FollowSlowly(const float& deltaTime, const sf::Vector2f& playerPosition);
    void FollowSlowlyWithObstacles(const float& deltaTime, const sf::Vector2f& playerPosition,
                                   const std::vector<sf::FloatRect>& obstacles);
    void FollowSlowlyWithObstaclesAndAdd(const float& deltaTime, const sf::Vector2f& playerPosition,
                                         const std::vector<sf::FloatRect>& obstacles, const sf::Vector2f& secondEnemyPos);
    void UpdateSmallEnemies(const float& deltaTime, const sf::Vector2f& playerPosition);
    void UpdateSmallEnemiesWithObstacles(const float& deltaTime, const sf::Vector2f& playerPosition,
                                         const std::vector<sf::FloatRect>& obstacles);
    void AnimateHit();
    void ShootOneBulletBothColors(const float& deltaTime);
    void ShootThreePurpleBullets(const float& deltaTime);
    void ShootFiveBulletsBothColors(const float& deltaTime);
    void RotatingShootingTypeOne(const float& deltaTime);
    void RotatingShootingTypeTwo(const float& deltaTime);
    void RotatingShootingTypeThree(const float& deltaTime);
    void ConstantAngleShooting(const float& deltaTime);
    void UpdateAllBullets(const float& deltaTime);
    void GotHit();
    void UpdateShield();
    void CheckOtherEnemy(const bool& isAlive);
    sf::FloatRect GetBounds();

public:
    int health;
    sf::Vector2f enemyPosition;
    std::vector<OrangeBullet> orangeBullets;
    std::vector<PurpleBullet> purpleBullets;
    std::vector<SmallEnemy> smallEnemies;
    int numberOfSmallEnemies;
    float shootingDelay;
    float shootingAngle;
    bool isAnimatingExplode;
    bool otherEnemy;

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

        for (const SmallEnemy& smallEnemy : smallEnemies)
        {
            target.draw(smallEnemy);
        }

        if (!isAnimatingExplode)
        {
            target.draw(enemy, states);
        }
        else
        {
            enemyAnimations.explodeSprites[currentFrame].setPosition(enemyPosition);
            target.draw(enemyAnimations.explodeSprites[currentFrame]);
        }

        if (isAnimatingHit)
        {
            enemyAnimations.hitSprites[currentFrame].setPosition(enemyPosition);
            target.draw(enemyAnimations.hitSprites[currentFrame]);
        }

        if (isShielded)
        {
            enemyAnimations.shieldSprites[shieldFrame].setPosition(enemyPosition);
            target.draw(enemyAnimations.shieldSprites[shieldFrame]);
        }

        if (isAnimatingShieldExplode)
        {
            enemyAnimations.shieldExplodeSprites[shieldFrame].setPosition(enemyPosition);
            target.draw(enemyAnimations.shieldExplodeSprites[shieldFrame]);
        }
    }

    sf::VertexArray enemy;
    bool isOrange;
    float timeSinceLastShot;
    sf::Vector2f delta;
    float angleRad;
    sf::Vector2f possiblePos;
    bool isShielded;
    int shieldFrame;
    int currentFrame;
    bool isAnimatingHit;
    bool isAnimatingShieldExplode;
};

class AdditionalEnemy : public sf::Drawable, public sf::Transformable
{
public:
    AdditionalEnemy(float delay);

    void FollowSlowlyWithObstacles(const float& deltaTime, const sf::Vector2f& playerPosition, const std::vector<sf::FloatRect>& obstacles,
                                   const sf::Vector2f& firstEnemyPos, std::vector<SmallEnemy>& smallEnemies);
    void RotatingShootingTypeOne(const float& deltaTime, const float& delay, std::vector<OrangeBullet>& orangeBullets,
                                 std::vector<PurpleBullet>& purpleBullets);
    void AnimateHit();
    void GotHit();
    void UpdateShield(const int& numberOfSmallEnemies);
    sf::FloatRect GetBounds();

public:
    int health;
    sf::Vector2f enemyPosition;
    float shootingDelay;
    float shootingAngle;
    bool isAnimatingExplode;
    bool isAlive;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();

        if (!isAnimatingExplode)
        {
            target.draw(enemy, states);
        }
        else
        {
            enemyAnimations.explodeSprites[currentFrame].setPosition(enemyPosition);
            target.draw(enemyAnimations.explodeSprites[currentFrame]);
        }

        if (isAnimatingHit)
        {
            enemyAnimations.hitSprites[currentFrame].setPosition(enemyPosition);
            target.draw(enemyAnimations.hitSprites[currentFrame]);
        }

        if (isShielded)
        {
            enemyAnimations.shieldSprites[shieldFrame].setPosition(enemyPosition);
            target.draw(enemyAnimations.shieldSprites[shieldFrame]);
        }

        if (isAnimatingShieldExplode)
        {
            enemyAnimations.shieldExplodeSprites[shieldFrame].setPosition(enemyPosition);
            target.draw(enemyAnimations.shieldExplodeSprites[shieldFrame]);
        }
    }

    sf::VertexArray enemy;
    bool isOrange;
    float timeSinceLastShot;
    sf::Vector2f delta;
    float angleRad;
    sf::Vector2f possiblePos;
    bool isShielded;
    int shieldFrame;
    int currentFrame;
    bool isAnimatingHit;
    bool isAnimatingShieldExplode;
};