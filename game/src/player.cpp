#include "player.h"

namespace
{
    struct PlayerSounds
    {
        PlayerSounds()
        {
            if (!shootBuffer.loadFromFile("game/sounds/sfx/player_shoot.wav"))
            {
                std::cout << "Couldn't load sound \"player_shoot\".";
            }
            shoot.setBuffer(shootBuffer);

            if (!hitBuffer.loadFromFile("game/sounds/sfx/player_hit.wav"))
            {
                std::cout << "Couldn't load sound \"player_hit\".";
            }
            hit.setBuffer(hitBuffer);

            if (!explodeBuffer.loadFromFile("game/sounds/sfx/player_explode.wav"))
            {
                std::cout << "Couldn't load sound \"player_explode\".";
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

    PlayerSounds playerSounds;
}

Bullet::Bullet()
{
    speed = 550.f;
    hit = false;
    bullet.setPrimitiveType(sf::TriangleStrip);

    bullet.append(sf::Vertex(sf::Vector2f(-15.f, 5.f), sf::Color(0xFF, 0xFC, 0xF9)));
    bullet.append(sf::Vertex(sf::Vector2f(-15.f, -5.f), sf::Color(0xFF, 0xFC, 0xF9)));
    bullet.append(sf::Vertex(sf::Vector2f(15.f, 5.f), sf::Color(0xFF, 0xFC, 0xF9)));
    bullet.append(sf::Vertex(sf::Vector2f(15.f, -5.f), sf::Color(0xFF, 0xFC, 0xF9)));
}

sf::FloatRect Bullet::GetBounds()
{
    return getTransform().transformRect(bullet.getBounds());
}

Player::Player(float left, float top, float size)
{
    health = 3;
    lastGotHit = 1.f;
    shootingDelay = 0.1f;
    timeSinceLastShot = 1.f;
    invulnerable = 1.f;
    isAnimatingHit = false;
    isAnimatingExplode = false;

    playingField.left = left;
    playingField.top = top;
    playingField.width = size;
    playingField.height = size;

    vertices[0].position = sf::Vector2f(-16.f, -1.f);
    vertices[0].color = sf::Color(0xFF, 0xFC, 0xD9);
    vertices[1].position = sf::Vector2f(2.f, -13.f);
    vertices[1].color = sf::Color(0xFF, 0xFC, 0xD9);
    vertices[2].position = sf::Vector2f(6.f, -11.5f);
    vertices[2].color = sf::Color(0xFF, 0xFC, 0xD9);
    vertices[3].position = sf::Vector2f(0.f, -1.f);
    vertices[3].color = sf::Color(0xFF, 0xFC, 0xD9);
    vertices[4].position = sf::Vector2f(-16.f, 1.f);
    vertices[4].color = sf::Color(0xFF, 0xFC, 0xD9);
    vertices[5].position = sf::Vector2f(0.f, 1.f);
    vertices[5].color = sf::Color(0xFF, 0xFC, 0xD9);
    vertices[6].position = sf::Vector2f(6.f, 11.5f);
    vertices[6].color = sf::Color(0xFF, 0xFC, 0xD9);
    vertices[7].position = sf::Vector2f(2.f, 13.f);
    vertices[7].color = sf::Color(0xFF, 0xFC, 0xD9);
    vertices[8].position = sf::Vector2f(2.f, 0.f);
    vertices[8].color = sf::Color(0xFF, 0xFC, 0xD9);
    vertices[9].position = sf::Vector2f(8.f, -11.f);
    vertices[9].color = sf::Color(0xFF, 0xFC, 0xD9);
    vertices[10].position = sf::Vector2f(37.f, 0.f);
    vertices[10].color = sf::Color(0xFF, 0xFC, 0xD9);
    vertices[11].position = sf::Vector2f(8.f, 11.f);
    vertices[11].color = sf::Color(0xFF, 0xFC, 0xD9);
    vertices[12].position = sf::Vector2f(0.f, -5.f);
    vertices[12].color = sf::Color(0x50, 0x4E, 0x48);
    vertices[13].position = sf::Vector2f(5.f, 0.f);
    vertices[13].color = sf::Color(0x50, 0x4E, 0x48);
    vertices[14].position = sf::Vector2f(0.f, 5.f);
    vertices[14].color = sf::Color(0x50, 0x4E, 0x48);
    vertices[15].position = sf::Vector2f(-5.f, 0.f);
    vertices[15].color = sf::Color(0x50, 0x4E, 0x48);
    vertices[16].position = sf::Vector2f(3.5f, -3.5f);
    vertices[16].color = sf::Color(0x50, 0x4E, 0x48);
    vertices[17].position = sf::Vector2f(3.5f, 3.5f);
    vertices[17].color = sf::Color(0x50, 0x4E, 0x48);
    vertices[18].position = sf::Vector2f(-3.5f, 3.5f);
    vertices[18].color = sf::Color(0x50, 0x4E, 0x48);
    vertices[19].position = sf::Vector2f(-3.5f, -3.5f);
    vertices[19].color = sf::Color(0x50, 0x4E, 0x48);

    ship.setPrimitiveType(sf::Quads);

    for (int i = 0; i < 20; ++i)
    {
        ship.append(vertices[i]);
    }
}

float toDegrees(float radians)
{
    return float(double(radians) * 180.0 / M_PI);
}

void Player::Update(sf::RenderWindow& window, sf::View& view, const float& deltaTime)
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

    sf::Vector2f movement;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
		if (playerPosition.y - 20.f > playingField.top)
		{
			movement.y = -5.f;
		}
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        if (playerPosition.x - 20.f > playingField.left)
        {
            movement.x = -5.f;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        if (playerPosition.y + 20.f < playingField.top + playingField.height)
        {
            movement.y = 5.f;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        if (playerPosition.x + 20.f < playingField.left + playingField.width)
        {
            movement.x = 5.f;
        }
    }

    playerPosition = playerPosition + movement;
    this->setPosition(playerPosition);
    view.setCenter(playerPosition);
    mousePositionWindow = sf::Vector2i(sf::Mouse::getPosition(window));
    mousePositionView = window.mapPixelToCoords(mousePositionWindow);
    delta = mousePositionView - playerPosition;
    angleRad = atan2(delta.y, delta.x);
    angleDeg = toDegrees(angleRad);
    this->setRotation(angleDeg);

    lastGotHit += deltaTime;
    if (isAnimatingHit)
    {
        currentFrame++;
        if (currentFrame == 18)
        {
            isAnimatingHit = false;
            health--;
        }
    }
    UpdateBullets(deltaTime);
}

void Player::UpdateBullets(const float& deltaTime)
{
    timeSinceLastShot += deltaTime;
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && timeSinceLastShot > shootingDelay)
    {
        Fire();
        timeSinceLastShot = 0.f;
    }

    for (Bullet& bullet : bullets)
    {
        bullet.position += bullet.velocity * deltaTime;
        bullet.setPosition(bullet.position);
    }
}

void Player::Fire()
{
    Bullet bullet;
    bullet.position = playerPosition;
    bullet.velocity = {
        std::cos(angleRad) * bullet.speed,
        std::sin(angleRad) * bullet.speed
    };
    bullet.setPosition(bullet.position);
    bullet.setRotation(angleDeg);
    bullets.push_back(bullet);

    playerSounds.shoot.play();
}

void Player::GotHit()
{
    if (lastGotHit > invulnerable)
    {
        switch (health)
        {
        case 3:
            GotHitOnce();
            break;
        case 2:
            GotHitTwice();
            break;
        case 1:
        {
            playerSounds.explode.play();
            isAnimatingExplode = true;
            bullets.clear();
        }
            break;
        default:
            break;
        }
        
        lastGotHit = 0.f;
        currentFrame = 0;
    }
}

void Player::GotHitOnce()
{
    ship.clear();
    playerSounds.hit.play();
    isAnimatingHit = true;

    for (int i = 4; i < 20; ++i)
    {
        ship.append(vertices[i]);
    }
}

void Player::GotHitTwice()
{
    ship.clear();
    playerSounds.hit.play();
    isAnimatingHit = true;

    for (int i = 8; i < 20; ++i)
    {
        ship.append(vertices[i]);
    }
}

sf::FloatRect Player::GetBounds()
{
    return getTransform().transformRect(ship.getBounds());
}