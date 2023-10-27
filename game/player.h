#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class PlayerBullet : public sf::Drawable, public sf::Transformable
{
public:
    float speed = 700.f;
    sf::Vector2f position;
    sf::Vector2f velocity;

    PlayerBullet()
	{
        playerBullet.setPrimitiveType(sf::Triangles);

        playerBullet.append(sf::Vertex(sf::Vector2f(-15.f, -5.f), sf::Color(0xFF, 0xF9, 0xEE)));
        playerBullet.append(sf::Vertex(sf::Vector2f(-15.f, 5.f), sf::Color(0xFF, 0xF9, 0xEE)));
        playerBullet.append(sf::Vertex(sf::Vector2f(15.f, 5.f), sf::Color(0xFF, 0xF9, 0xEE)));
        playerBullet.append(sf::Vertex(sf::Vector2f(-15.f, -5.f), sf::Color(0xFF, 0xF9, 0xEE)));
        playerBullet.append(sf::Vertex(sf::Vector2f(15.f, -5.f), sf::Color(0xFF, 0xF9, 0xEE)));
        playerBullet.append(sf::Vertex(sf::Vector2f(15.f, 5.f), sf::Color(0xFF, 0xF9, 0xEE)));
    }

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
        states.transform *= getTransform();
        target.draw(playerBullet, states);
    }

    sf::VertexArray playerBullet;
};

class Player : public sf::Drawable, public sf::Transformable
{
public:
    // Define the shapes for the player
    Player()
    {
        ship.setPrimitiveType(sf::Triangles);

        // left shield
        ship.append(sf::Vertex(sf::Vector2f(0.f, -1.f), sf::Color(0xF7, 0xF3, 0xCA)));
        ship.append(sf::Vertex(sf::Vector2f(6.f, -11.5f), sf::Color(0xF7, 0xF3, 0xCA)));
        ship.append(sf::Vertex(sf::Vector2f(-16.f, -1.f), sf::Color(0xF7, 0xF3, 0xCA)));
        ship.append(sf::Vertex(sf::Vector2f(-16.f, -1.f), sf::Color(0xF7, 0xF3, 0xCA)));
        ship.append(sf::Vertex(sf::Vector2f(2.f, -13.f), sf::Color(0xF7, 0xF3, 0xCA)));
        ship.append(sf::Vertex(sf::Vector2f(6.f, -11.5f), sf::Color(0xF7, 0xF3, 0xCA)));

        // right shield
        ship.append(sf::Vertex(sf::Vector2f(0.f, 1.f), sf::Color(0xF7, 0xF3, 0xCA)));
        ship.append(sf::Vertex(sf::Vector2f(6.f, 11.5f), sf::Color(0xF7, 0xF3, 0xCA)));
        ship.append(sf::Vertex(sf::Vector2f(-16.f, 1.f), sf::Color(0xF7, 0xF3, 0xCA)));
        ship.append(sf::Vertex(sf::Vector2f(-16.f, 1.f), sf::Color(0xF7, 0xF3, 0xCA)));
        ship.append(sf::Vertex(sf::Vector2f(2.f, 13.f), sf::Color(0xF7, 0xF3, 0xCA)));
        ship.append(sf::Vertex(sf::Vector2f(6.f, 11.5f), sf::Color(0xF7, 0xF3, 0xCA)));

        // ship
        ship.append(sf::Vertex(sf::Vector2f(2.f, 0.f), sf::Color(0xF7, 0xF3, 0xCA)));
        ship.append(sf::Vertex(sf::Vector2f(8.f, -11.f), sf::Color(0xF7, 0xF3, 0xCA)));
        ship.append(sf::Vertex(sf::Vector2f(37.f, 0.f), sf::Color(0xF7, 0xF3, 0xCA)));
        ship.append(sf::Vertex(sf::Vector2f(2.f, 0.f), sf::Color(0xF7, 0xF3, 0xCA)));
        ship.append(sf::Vertex(sf::Vector2f(8.f, 11.f), sf::Color(0xF7, 0xF3, 0xCA)));
        ship.append(sf::Vertex(sf::Vector2f(37.f, 0.f), sf::Color(0xF7, 0xF3, 0xCA)));

        // core
        ship.append(sf::Vertex(sf::Vector2f(0.f, 0.f), sf::Color(0x50, 0x4E, 0x48)));
        ship.append(sf::Vertex(sf::Vector2f(5.f, 0.f), sf::Color(0x50, 0x4E, 0x48)));
        ship.append(sf::Vertex(sf::Vector2f(3.5f, 3.5f), sf::Color(0x50, 0x4E, 0x48)));
        ship.append(sf::Vertex(sf::Vector2f(0.f, 0.f), sf::Color(0x50, 0x4E, 0x48)));
        ship.append(sf::Vertex(sf::Vector2f(3.5f, 3.5f), sf::Color(0x50, 0x4E, 0x48)));
        ship.append(sf::Vertex(sf::Vector2f(0.f, 5.f), sf::Color(0x50, 0x4E, 0x48)));
        ship.append(sf::Vertex(sf::Vector2f(0.f, 0.f), sf::Color(0x50, 0x4E, 0x48)));
        ship.append(sf::Vertex(sf::Vector2f(0.f, 5.f), sf::Color(0x50, 0x4E, 0x48)));
        ship.append(sf::Vertex(sf::Vector2f(-3.5f, 3.5f), sf::Color(0x50, 0x4E, 0x48)));
        ship.append(sf::Vertex(sf::Vector2f(0.f, 0.f), sf::Color(0x50, 0x4E, 0x48)));
        ship.append(sf::Vertex(sf::Vector2f(-3.5f, 3.5f), sf::Color(0x50, 0x4E, 0x48)));
        ship.append(sf::Vertex(sf::Vector2f(-5.f, 0.f), sf::Color(0x50, 0x4E, 0x48)));
        ship.append(sf::Vertex(sf::Vector2f(0.f, 0.f), sf::Color(0x50, 0x4E, 0x48)));
        ship.append(sf::Vertex(sf::Vector2f(-5.f, 0.f), sf::Color(0x50, 0x4E, 0x48)));
        ship.append(sf::Vertex(sf::Vector2f(-3.5f, -3.5f), sf::Color(0x50, 0x4E, 0x48)));
        ship.append(sf::Vertex(sf::Vector2f(0.f, 0.f), sf::Color(0x50, 0x4E, 0x48)));
        ship.append(sf::Vertex(sf::Vector2f(-3.5f, -3.5f), sf::Color(0x50, 0x4E, 0x48)));
        ship.append(sf::Vertex(sf::Vector2f(0.f, -5.f), sf::Color(0x50, 0x4E, 0x48)));
        ship.append(sf::Vertex(sf::Vector2f(0.f, 0.f), sf::Color(0x50, 0x4E, 0x48)));
        ship.append(sf::Vertex(sf::Vector2f(0.f, -5.f), sf::Color(0x50, 0x4E, 0x48)));
        ship.append(sf::Vertex(sf::Vector2f(3.5f, -3.5f), sf::Color(0x50, 0x4E, 0x48)));
        ship.append(sf::Vertex(sf::Vector2f(0.f, 0.f), sf::Color(0x50, 0x4E, 0x48)));
        ship.append(sf::Vertex(sf::Vector2f(3.5f, -3.5f), sf::Color(0x50, 0x4E, 0x48)));
        ship.append(sf::Vertex(sf::Vector2f(5.f, 0.f), sf::Color(0x50, 0x4E, 0x48)));
    }

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // Apply the transform
        states.transform *= getTransform();

        // Draw the vertex array
        target.draw(ship, states);
    }

    sf::VertexArray ship;
};

struct Data
{
    sf::Vector2f playerPosition;
    sf::Vector2f mousePosition;
    sf::Vector2f delta;
    float angleRad;
    float angleDeg;
};

struct Bullets
{
    sf::Clock clock;
    const float shootingDelay = 0.1f;
    std::vector<PlayerBullet> playerBullets;
};

void updatePlayer(sf::RenderWindow& window, Player& player, Data& data);
void updateBullets(Data& data, Bullets& bullets, const float& deltaTime);