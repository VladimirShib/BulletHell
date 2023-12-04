#pragma once

#include "headers.h"

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

class Level0Enemy : public sf::Drawable, public sf::Transformable
{
public:
    Level0Enemy();

    void Update(const float& deltaTime, const sf::Vector2f& playerPosition);
    void UpdateBullets(const float& deltaTime, const sf::Vector2f& playerPosition);
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
    float elapsedTime;
    float wavePhase;
    float amplitude;
    float period;
    bool isOrange;
    float shootingDelay;
    float timeSinceLastShot;
    sf::Vector2f delta;
    float angleRad;
    int currentFrame;
    bool isAnimatingHit;
};

class Level1Enemy : public sf::Drawable, public sf::Transformable
{
public:
    Level1Enemy();

    void Update(const float& deltaTime, const sf::Vector2f& playerPosition);
    void UpdateBullets(const float& deltaTime, const sf::Vector2f& playerPosition);
    void GotHit();
    sf::FloatRect GetBounds();

public:
    int health;
    sf::Vector2f enemyPosition;
    std::vector<PurpleBullet> purpleBullets;
    bool isAnimatingExplode;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
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
    float elapsedTime;
    sf::Vector2f center;
    sf::Vector2f offset;
    float radius;
    float speed;
    float shootingDelay;
    float timeSinceLastShot;
    sf::Vector2f delta;
    float angleRad;
    float leftOffsetAngle;
    float rightOffsetAngle;
    int currentFrame;
    bool isAnimatingHit;
};

class Level2Enemy : public sf::Drawable, public sf::Transformable
{
public:
    Level2Enemy();

    void Update(const float& deltaTime, const sf::Vector2f& playerPosition);
    void UpdateBullets(const float& deltaTime, const sf::Vector2f& playerPosition);
    void GotHit();
    sf::FloatRect GetBounds();

public:
    int health;
    sf::Vector2f enemyPosition;
    std::vector<PurpleBullet> purpleBullets;
    bool isAnimatingExplode;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
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
    float elapsedTime;
    sf::Vector2f center;
    sf::Vector2f offset;
    float radius;
    float speed;
    float shootingDelay;
    float timeSinceLastShot;
    sf::Vector2f delta;
    float angleRad;
    float leftOffsetAngle;
    float rightOffsetAngle;
    float backOffsetAngle;
    int currentFrame;
    bool isAnimatingHit;
};

class Level3Enemy : public sf::Drawable, public sf::Transformable
{
public:
    Level3Enemy();

    void Update(const float& deltaTime, const sf::Vector2f& playerPosition);
    void UpdateBullets(const float& deltaTime, const sf::Vector2f& playerPosition);
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
    sf::Vector2f speed;
    float shootingDelay;
    float timeSinceLastShot;
    bool isOrange;
    sf::Vector2f delta;
    float angleRad;
    float left1OffsetAngle;
    float left2OffsetAngle;
    float right1OffsetAngle;
    float right2OffsetAngle;
    int currentFrame;
    bool isAnimatingHit;
};

class Level4Enemy : public sf::Drawable, public sf::Transformable
{
public:
    Level4Enemy();

    void Update(const float& deltaTime, const sf::Vector2f& playerPosition);
    void UpdateBullets(const float& deltaTime);
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
    float speed;
    float shootingDelay;
    float timeSinceLastShot;
    sf::Vector2f delta;
    float vectorLength;
    sf::Vector2f direction;
    float distance;
    float angleRad;
    float left1OffsetAngle;
    float left2OffsetAngle;
    float left3OffsetAngle;
    float backOffsetAngle;
    float right1OffsetAngle;
    float right2OffsetAngle;
    float right3OffsetAngle;
    int currentFrame;
    bool isAnimatingHit;
};

class Level5Enemy : public sf::Drawable, public sf::Transformable
{
public:
    Level5Enemy();

    void Update(const float& deltaTime, const sf::Vector2f& playerPosition);
    void UpdateBullets(const float& deltaTime);
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
    float speed;
    bool isOrange;
    float shootingDelay;
    float timeSinceLastStream;
    float timeSinceLastShot;
    int bulletCount;
    sf::Vector2f delta;
    float vectorLength;
    sf::Vector2f direction;
    float distance;
    float angleRad;
    int currentFrame;
    bool isAnimatingHit;
};