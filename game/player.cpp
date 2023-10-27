#include <SFML/Window.hpp>
#include <cmath>
#include <algorithm>
#include "player.h"

float toDegrees(float radians)
{
    return float(double(radians) * 180.0 / M_PI);
}

void updatePlayer(sf::RenderWindow& window, Player& player, Data& data)
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
    
    data.playerPosition = player.getPosition();
    data.mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
    data.delta = data.mousePosition - data.playerPosition;
    data.angleRad = atan2(data.delta.y, data.delta.x);
    data.angleDeg = toDegrees(data.angleRad);
    player.setRotation(data.angleDeg);
}

void fire(Data& data, Bullets& bullets)
{
    PlayerBullet bullet;
    bullet.position = data.playerPosition;
    bullet.velocity = {
        std::cos(data.angleRad) * bullet.speed,
        std::sin(data.angleRad) * bullet.speed
    };
    bullet.setPosition(bullet.position);
    bullet.setRotation(data.angleDeg);
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

void updateBullets(Data& data, Bullets& bullets, const float& deltaTime)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        const float delay = bullets.clock.getElapsedTime().asSeconds();
        if (delay > bullets.shootingDelay)
        {
            fire(data, bullets);
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