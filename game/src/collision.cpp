#include "maps.h"

namespace
{
    struct Sounds
    {
        sf::SoundBuffer playerBulletWallBuffer;
        sf::Sound playerBulletWall;
        sf::SoundBuffer enemyBulletWallBuffer;
        sf::Sound enemyBulletWall;
        sf::SoundBuffer enemyHitBuffer;
        sf::Sound enemyHit;
        sf::SoundBuffer enemyExplodeBuffer;
        sf::Sound enemyExplode;

        Sounds()
        {
            if (!playerBulletWallBuffer.loadFromFile("game/sounds/sfx/player_bullet_hit_wall.wav"))
            {
                std::cout << "Couldn't load sound \"player_bullet_hit_wall\".";
            }
            playerBulletWall.setBuffer(playerBulletWallBuffer);

            if (!enemyBulletWallBuffer.loadFromFile("game/sounds/sfx/enemy_bullet_hit_wall.wav"))
            {
                std::cout << "Couldn't load sound \"enemy_bullet_hit_wall\".";
            }
            enemyBulletWall.setBuffer(enemyBulletWallBuffer);

            if (!enemyHitBuffer.loadFromFile("game/sounds/sfx/enemy_hit.wav"))
            {
                std::cout << "Couldn't load sound \"enemy_hit\".";
            }
            enemyHit.setBuffer(enemyHitBuffer);

            if (!enemyExplodeBuffer.loadFromFile("game/sounds/sfx/enemy_explode.wav"))
            {
                std::cout << "Couldn't load sound \"enemy_explode\".";
            }
            enemyExplode.setBuffer(enemyExplodeBuffer);
        }
    };

    Sounds sounds;
}

template <typename EnemyType>
void checkPlayerBulletsWithOrange(Player& player, EnemyType& enemy)
{
    sf::FloatRect enemyBounds = enemy.GetBounds();

    for (auto& playerBullet : player.bullets)
    {
        if (!player.playingField.contains(playerBullet.position))
        {
            playerBullet.hit = true;
            sounds.playerBulletWall.play();
        }
        else
        {
            sf::FloatRect playerBulletBounds = playerBullet.GetBounds();

            if (playerBulletBounds.intersects(enemyBounds))
            {
                playerBullet.hit = true;
                enemy.health--;
                if (enemy.health > 0)
                {
                    sounds.enemyHit.play();
                }
                else
                {
                    sounds.enemyExplode.play();
                }
            }
            else
            {
                for (auto& orangeBullet : enemy.orangeBullets)
                {
                    sf::FloatRect orangeBulletBounds = orangeBullet.GetBounds();

                    if (playerBulletBounds.intersects(orangeBulletBounds))
                    {
                        playerBullet.hit = true;
                        orangeBullet.hit = true;
                    }
                }
            }
        }
    }
}

template <typename EnemyType>
void checkPlayerBullets(Player& player, EnemyType& enemy)
{
    sf::FloatRect enemyBounds = enemy.GetBounds();

    for (auto& playerBullet : player.bullets)
    {
        if (!player.playingField.contains(playerBullet.position))
        {
            playerBullet.hit = true;
            sounds.playerBulletWall.play();
        }
        else
        {
            sf::FloatRect playerBulletBounds = playerBullet.GetBounds();

            if (playerBulletBounds.intersects(enemyBounds))
            {
                playerBullet.hit = true;
                enemy.health--;
                if (enemy.health > 0)
                {
                    sounds.enemyHit.play();
                }
                else
                {
                    sounds.enemyExplode.play();
                }
            }
        }
    }
}

template <typename EnemyType>
void checkOrangeBullets(Player& player, sf::FloatRect& playerBounds, EnemyType& enemy)
{
    for (auto& orangeBullet : enemy.orangeBullets)
    {
        if (!player.playingField.contains(orangeBullet.position))
        {
            orangeBullet.hit = true;
            sounds.enemyBulletWall.play();
        }
        else if (playerBounds.contains(orangeBullet.position))
        {
            orangeBullet.hit = true;
            player.GotHit();
        }
    }
}

template <typename EnemyType>
void checkPurpleBullets(Player& player, sf::FloatRect& playerBounds, EnemyType& enemy)
{
    for (auto& purpleBullet : enemy.purpleBullets)
    {
        if (!player.playingField.contains(purpleBullet.position))
        {
            purpleBullet.hit = true;
            sounds.enemyBulletWall.play();
        }
        else if (playerBounds.contains(purpleBullet.position))
        {
            purpleBullet.hit = true;
            player.GotHit();
        }
    }
}

template <typename BulletType>
bool isToBeRemoved(const BulletType& bullet)
{
    return bullet.hit;
}

template <typename EnemyType>
void erasePlayerAndPurpleBullets(Player& player, EnemyType& enemy)
{
    auto newEndPlayer = std::remove_if(player.bullets.begin(), player.bullets.end(), [&](const Bullet& bullet)
    {
        return isToBeRemoved(bullet);
    });
    player.bullets.erase(newEndPlayer, player.bullets.end());

    auto newEndPurple = std::remove_if(enemy.purpleBullets.begin(), enemy.purpleBullets.end(), [&](const PurpleBullet& bullet)
    {
        return isToBeRemoved(bullet);
    });
    enemy.purpleBullets.erase(newEndPurple, enemy.purpleBullets.end());
}

template <typename EnemyType>
void eraseOrangeBullets(EnemyType& enemy)
{
    auto newEndOrange = std::remove_if(enemy.orangeBullets.begin(), enemy.orangeBullets.end(), [&](const OrangeBullet& bullet)
    {
        return isToBeRemoved(bullet);
    });
    enemy.orangeBullets.erase(newEndOrange, enemy.orangeBullets.end());
}

void Level0::CheckCollision()
{
    sf::FloatRect playerBounds = player.GetBounds();
    checkPlayerBulletsWithOrange(player, enemy);
    checkOrangeBullets(player, playerBounds, enemy);
    checkPurpleBullets(player, playerBounds, enemy);

    erasePlayerAndPurpleBullets(player, enemy);
    eraseOrangeBullets(enemy);
}

void Level1::CheckCollision()
{
    sf::FloatRect playerBounds = player.GetBounds();
    checkPlayerBullets(player, enemy);
    checkPurpleBullets(player, playerBounds, enemy);

    erasePlayerAndPurpleBullets(player, enemy);
}