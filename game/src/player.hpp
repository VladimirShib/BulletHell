#pragma once

#include "headers.hpp"

namespace
{
    struct PlayerAnimations
    {
    public:
        PlayerAnimations()
        {
            if (!hitTexture.loadFromFile("game/spritesheets/player_hit.png"))
            {
                std::cout << "Failed to load player_hit spritesheet!\n";
            }
            if (!explodeTexture.loadFromFile("game/spritesheets/player_explode.png"))
            {
                std::cout << "Failed to load player_explode spritesheet!\n";
            }

            for (int i = 0; i < 6; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    hitFrames.push_back(sf::IntRect(j * 256, i * 256, 256, 256));
                }
            }
            for (int i = 0; i < 18; ++i)
            {
                sf::Sprite sprite;
                sprite.setTexture(hitTexture);
                sprite.setTextureRect(hitFrames[i]);
                sprite.setOrigin(sf::Vector2f(128.f, 128.f));
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

    PlayerAnimations playerAnimations;
}

class Bullet : public sf::Drawable, public sf::Transformable
{
public:
    Bullet();

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

class Player : public sf::Drawable, public sf::Transformable
{
public:
    // Define the shapes for the player
    Player(float left, float top, float size);

    void Update(sf::RenderWindow& window, sf::View& view, const float& deltaTime);
    void UpdateBullets(const float& deltaTime);
    void Fire();
    void GotHit();
    void GotHitOnce();
    void GotHitTwice();
    sf::FloatRect GetBounds();

public:
    int health;
    float lastGotHit;
    sf::Vector2f playerPosition;
    sf::Vector2i mousePositionWindow;
    sf::Vector2f mousePositionView;
    sf::Vector2f delta; // distance between mouse cursor and player
    float angleRad;
    float angleDeg;
    std::vector<Bullet> bullets;
    sf::FloatRect playingField;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // Apply the transform
        states.transform *= getTransform();

        for (const Bullet& bullet : bullets)
        {
            target.draw(bullet);
        }

        // Draw the vertex array
        if (!isAnimatingExplode)
        {
            target.draw(ship, states);
        }
        else
        {
            playerAnimations.explodeSprites[currentFrame].setPosition(playerPosition);
            target.draw(playerAnimations.explodeSprites[currentFrame]);
        }

        if (isAnimatingHit)
        {
            playerAnimations.hitSprites[currentFrame].setPosition(playerPosition);
            target.draw(playerAnimations.hitSprites[currentFrame]);
        }
    }

    sf::Vertex vertices[20];
    sf::VertexArray ship;
    float shootingDelay;
    float timeSinceLastShot;
    float invulnerable;
    int currentFrame;
    bool isAnimatingHit;
    bool isAnimatingExplode;
};