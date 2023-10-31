#include "headers.h"
#include "player.h"

PlayerBullet::PlayerBullet()
{
    playerBullet.setPrimitiveType(sf::TriangleStrip);

    playerBullet.append(sf::Vertex(sf::Vector2f(-15.f, 5.f), sf::Color(0xFF, 0xF9, 0xEE)));
    playerBullet.append(sf::Vertex(sf::Vector2f(-15.f, -5.f), sf::Color(0xFF, 0xF9, 0xEE)));
    playerBullet.append(sf::Vertex(sf::Vector2f(15.f, 5.f), sf::Color(0xFF, 0xF9, 0xEE)));
    playerBullet.append(sf::Vertex(sf::Vector2f(15.f, -5.f), sf::Color(0xFF, 0xF9, 0xEE)));
}

Player::Player()
{
    ship.setPrimitiveType(sf::Quads);

    // left shield
    ship.append(sf::Vertex(sf::Vector2f(-16.f, -1.f), sf::Color(0xF7, 0xF3, 0xCA)));
    ship.append(sf::Vertex(sf::Vector2f(2.f, -13.f), sf::Color(0xF7, 0xF3, 0xCA)));
    ship.append(sf::Vertex(sf::Vector2f(6.f, -11.5f), sf::Color(0xF7, 0xF3, 0xCA)));
    ship.append(sf::Vertex(sf::Vector2f(0.f, -1.f), sf::Color(0xF7, 0xF3, 0xCA)));

    // right shield
    ship.append(sf::Vertex(sf::Vector2f(-16.f, 1.f), sf::Color(0xF7, 0xF3, 0xCA)));
    ship.append(sf::Vertex(sf::Vector2f(0.f, 1.f), sf::Color(0xF7, 0xF3, 0xCA)));
    ship.append(sf::Vertex(sf::Vector2f(6.f, 11.5f), sf::Color(0xF7, 0xF3, 0xCA)));
    ship.append(sf::Vertex(sf::Vector2f(2.f, 13.f), sf::Color(0xF7, 0xF3, 0xCA)));

    // ship
    ship.append(sf::Vertex(sf::Vector2f(2.f, 0.f), sf::Color(0xF7, 0xF3, 0xCA)));
    ship.append(sf::Vertex(sf::Vector2f(8.f, -11.f), sf::Color(0xF7, 0xF3, 0xCA)));
    ship.append(sf::Vertex(sf::Vector2f(37.f, 0.f), sf::Color(0xF7, 0xF3, 0xCA)));
    ship.append(sf::Vertex(sf::Vector2f(8.f, 11.f), sf::Color(0xF7, 0xF3, 0xCA)));

    // core
    ship.append(sf::Vertex(sf::Vector2f(0.f, -5.f), sf::Color(0x50, 0x4E, 0x48)));
    ship.append(sf::Vertex(sf::Vector2f(5.f, 0.f), sf::Color(0x50, 0x4E, 0x48)));
    ship.append(sf::Vertex(sf::Vector2f(0.f, 5.f), sf::Color(0x50, 0x4E, 0x48)));
    ship.append(sf::Vertex(sf::Vector2f(-5.f, 0.f), sf::Color(0x50, 0x4E, 0x48)));
    ship.append(sf::Vertex(sf::Vector2f(3.5f, -3.5f), sf::Color(0x50, 0x4E, 0x48)));
    ship.append(sf::Vertex(sf::Vector2f(3.5f, 3.5f), sf::Color(0x50, 0x4E, 0x48)));
    ship.append(sf::Vertex(sf::Vector2f(-3.5f, 3.5f), sf::Color(0x50, 0x4E, 0x48)));
    ship.append(sf::Vertex(sf::Vector2f(-3.5f, -3.5f), sf::Color(0x50, 0x4E, 0x48)));
}

float toDegrees(float radians)
{
    return float(double(radians) * 180.0 / M_PI);
}

void updatePlayer(sf::RenderWindow& window, Player& player)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        player.move(0.f, -5.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        player.move(-5.f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        player.move(0.f, 5.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        player.move(5.f, 0.f);
    }
    
    player.data.playerPosition = player.getPosition();
    player.data.mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
    player.data.delta = player.data.mousePosition - player.data.playerPosition;
    player.data.angleRad = atan2(player.data.delta.y, player.data.delta.x);
    player.data.angleDeg = toDegrees(player.data.angleRad);
    player.setRotation(player.data.angleDeg);
}

void fire(Player& player, Bullets& bullets)
{
    PlayerBullet bullet;
    bullet.position = player.data.playerPosition;
    bullet.velocity = {
        std::cos(player.data.angleRad) * bullet.speed,
        std::sin(player.data.angleRad) * bullet.speed
    };
    bullet.setPosition(bullet.position);
    bullet.setRotation(player.data.angleDeg);
    bullets.playerBullets.push_back(bullet);
}

bool isToBeRemoved(const PlayerBullet& bullet)
{
    return (bullet.position.x >= 800 || bullet.position.x <= 0 || bullet.position.y >= 600 || bullet.position.y <= 0);
}

void eraseBullets(std::vector<PlayerBullet>& bullets)
{
    auto newEnd = std::remove_if(bullets.begin(), bullets.end(), isToBeRemoved);
    bullets.erase(newEnd, bullets.end());
}

void updateBullets(Player& player, Bullets& bullets, const float& deltaTime)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        const float delay = bullets.clock.getElapsedTime().asSeconds();
        if (delay > bullets.shootingDelay)
        {
            fire(player, bullets);
            bullets.clock.restart();
        }
    }

    for (auto& bullet : bullets.playerBullets)
    {
        bullet.position += bullet.velocity * deltaTime;
        bullet.setPosition(bullet.position);
    }
    eraseBullets(bullets.playerBullets);
}