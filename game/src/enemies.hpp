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
        }

    public:
        std::vector<sf::Sprite> hitSprites;
        std::vector<sf::Sprite> explodeSprites;

    private:
        sf::Texture hitTexture;
        sf::Texture explodeTexture;
        std::vector<sf::IntRect> hitFrames;
        std::vector<sf::IntRect> explodeFrames;
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