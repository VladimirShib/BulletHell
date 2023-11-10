#include "maps.h"

template <typename EnemyType>
void checkPlayerBulletsWithOrange(Player& player, EnemyType& enemy)
{
    sf::FloatRect enemyBounds = enemy.GetBounds();

    for (auto& playerBullet : player.bullets)
    {
        if (!player.playingField.contains(playerBullet.position))
        {
            playerBullet.hit = true;
        }
        else
        {
            sf::FloatRect playerBulletBounds = playerBullet.GetBounds();

            if (playerBulletBounds.intersects(enemyBounds))
            {
                playerBullet.hit = true;
                enemy.health--;
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
        }
        else
        {
            sf::FloatRect playerBulletBounds = playerBullet.GetBounds();

            if (playerBulletBounds.intersects(enemyBounds))
            {
                playerBullet.hit = true;
                enemy.health--;
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