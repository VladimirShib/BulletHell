#include "maps.hpp"

namespace
{
    struct Sounds
    {
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
        }

        sf::SoundBuffer playerBulletWallBuffer;
        sf::Sound playerBulletWall;
        sf::SoundBuffer enemyBulletWallBuffer;
        sf::Sound enemyBulletWall;
    };

    Sounds sounds;

    sf::FloatRect n_playerBounds;
    sf::FloatRect n_playerBulletBounds;
    sf::FloatRect n_enemyBounds;
    sf::FloatRect n_smallEnemyBounds;
    sf::FloatRect n_smallEnemyFrontBounds;
    sf::FloatRect n_enemyBulletBounds;
}

template <typename EnemyType>
void checkPlayerBulletsWithOrange(Player& player, EnemyType& enemy)
{
    n_enemyBounds = enemy.GetBounds();

    for (auto& playerBullet : player.bullets)
    {
        if (!player.playingField.contains(playerBullet.position))
        {
            playerBullet.hit = true;
            sounds.playerBulletWall.play();
        }
        else
        {
            n_playerBulletBounds = playerBullet.GetBounds();

            if (n_playerBulletBounds.intersects(n_enemyBounds) && !enemy.isAnimatingExplode)
            {
                playerBullet.hit = true;
                enemy.GotHit();
            }
            else
            {
                for (auto& orangeBullet : enemy.orangeBullets)
                {
                    n_enemyBulletBounds = orangeBullet.GetBounds();

                    if (n_playerBulletBounds.intersects(n_enemyBulletBounds))
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
void checkPlayerBulletsWithOrangeAndSmall(Player& player, EnemyType& enemy)
{
    n_enemyBounds = enemy.GetBounds();

    for (auto& playerBullet : player.bullets)
    {
        if (!player.playingField.contains(playerBullet.position))
        {
            playerBullet.hit = true;
            sounds.playerBulletWall.play();
        }
        else
        {
            n_playerBulletBounds = playerBullet.GetBounds();

            if (n_playerBulletBounds.intersects(n_enemyBounds) && !enemy.isAnimatingExplode)
            {
                playerBullet.hit = true;
                enemy.GotHit();
            }
            else
            {
                for (auto& orangeBullet : enemy.orangeBullets)
                {
                    n_enemyBulletBounds = orangeBullet.GetBounds();

                    if (n_playerBulletBounds.intersects(n_enemyBulletBounds))
                    {
                        playerBullet.hit = true;
                        orangeBullet.hit = true;
                        return;
                    }
                }
                for (auto& smallEnemy : enemy.smallEnemies)
                {
                    n_smallEnemyBounds = smallEnemy.GetBounds();

                    if (n_playerBulletBounds.intersects(n_smallEnemyBounds) && !smallEnemy.isAnimatingExplode)
                    {
                        playerBullet.hit = true;
                        smallEnemy.GotHit(enemy.shootingDelay);
                    }
                }
            }
        }
    }
}

template <typename EnemyType>
void checkPlayerBulletsWithOrangeAndSmallShielded(Player& player, EnemyType& enemy)
{
    n_enemyBounds = enemy.GetBounds();

    for (auto& playerBullet : player.bullets)
    {
        if (!player.playingField.contains(playerBullet.position))
        {
            playerBullet.hit = true;
            sounds.playerBulletWall.play();
        }
        else
        {
            n_playerBulletBounds = playerBullet.GetBounds();

            if (n_playerBulletBounds.intersects(n_enemyBounds) && !enemy.isAnimatingExplode)
            {
                playerBullet.hit = true;
                enemy.GotHit();
            }
            else
            {
                for (auto& orangeBullet : enemy.orangeBullets)
                {
                    n_enemyBulletBounds = orangeBullet.GetBounds();

                    if (n_playerBulletBounds.intersects(n_enemyBulletBounds))
                    {
                        playerBullet.hit = true;
                        orangeBullet.hit = true;
                        return;
                    }
                }
                for (auto& smallEnemy : enemy.smallEnemies)
                {
                    n_smallEnemyBounds = smallEnemy.GetBounds();

                    if (n_playerBulletBounds.intersects(n_smallEnemyBounds) && !smallEnemy.isAnimatingExplode)
                    {
                        playerBullet.hit = true;
                        n_smallEnemyFrontBounds = smallEnemy.GetFrontBounds();
                        if (n_playerBulletBounds.intersects(n_smallEnemyFrontBounds))
                        {
                            smallEnemy.GotHitInShield();
                        }
                        else
                        {
                            smallEnemy.GotHit(enemy.shootingDelay);
                        }
                    }
                }
            }
        }
    }
}

template <typename EnemyType>
void checkPlayerBullets(Player& player, EnemyType& enemy)
{
    n_enemyBounds = enemy.GetBounds();

    for (auto& playerBullet : player.bullets)
    {
        if (!player.playingField.contains(playerBullet.position))
        {
            playerBullet.hit = true;
            sounds.playerBulletWall.play();
        }
        else
        {
            n_playerBulletBounds = playerBullet.GetBounds();

            if (n_playerBulletBounds.intersects(n_enemyBounds) && !enemy.isAnimatingExplode)
            {
                playerBullet.hit = true;
                enemy.GotHit();
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

template <typename EnemyType>
void checkPlayerBulletsWithAdd(Player& player, EnemyType& enemy)
{
    n_enemyBounds = enemy.GetBounds();
    for (auto& playerBullet : player.bullets)
    {
        if (!playerBullet.hit)
        {
            n_playerBulletBounds = playerBullet.GetBounds();
            if (n_playerBulletBounds.intersects(n_enemyBounds) && !enemy.isAnimatingExplode)
            {
                playerBullet.hit = true;
                enemy.GotHit();
            }
        }
    }
}

template <typename EnemyType>
void checkAllBulletsWithObstacles(Player& player, EnemyType& enemy, const std::vector<sf::FloatRect>& obstacles)
{
    for (const auto& obstacle : obstacles)
    {
        for (auto& playerBullet : player.bullets)
        {
            if (!playerBullet.hit && obstacle.contains(playerBullet.position))
            {
                playerBullet.hit = true;
                sounds.playerBulletWall.play();
            }
        }
        for (auto& orangeBullet : enemy.orangeBullets)
        {
            if (!orangeBullet.hit && obstacle.contains(orangeBullet.position))
            {
                orangeBullet.hit = true;
                sounds.enemyBulletWall.play();
            }
        }
        for (auto& purpleBullet : enemy.purpleBullets)
        {
            if (!purpleBullet.hit && obstacle.contains(purpleBullet.position))
            {
                purpleBullet.hit = true;
                sounds.enemyBulletWall.play();
            }
        }
    }
}

template <typename EntityType>
bool isToBeRemoved(const EntityType& entity)
{
    return entity.hit;
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

template <typename EnemyType>
void eraseSmallEnemies(EnemyType& enemy)
{
    auto newEndEnemies = std::remove_if(enemy.smallEnemies.begin(), enemy.smallEnemies.end(), [&](const SmallEnemy& smallEnemy)
    {
        return isToBeRemoved(smallEnemy);
    });
    enemy.smallEnemies.erase(newEndEnemies, enemy.smallEnemies.end());
}

void Level0::CheckCollision()
{
    n_playerBounds = player.GetBounds();
    checkPlayerBulletsWithOrange(player, enemy);
    checkOrangeBullets(player, n_playerBounds, enemy);
    checkPurpleBullets(player, n_playerBounds, enemy);

    erasePlayerAndPurpleBullets(player, enemy);
    eraseOrangeBullets(enemy);
}

void Level1::CheckCollision()
{
    n_playerBounds = player.GetBounds();
    checkPlayerBullets(player, enemy);
    checkPurpleBullets(player, n_playerBounds, enemy);

    erasePlayerAndPurpleBullets(player, enemy);
}

void Level2::CheckCollision()
{
    n_playerBounds = player.GetBounds();
    checkPlayerBullets(player, enemy);
    checkPurpleBullets(player, n_playerBounds, enemy);

    erasePlayerAndPurpleBullets(player, enemy);
}

void Level3::CheckCollision()
{
    n_playerBounds = player.GetBounds();
    checkPlayerBulletsWithOrange(player, enemy);
    checkOrangeBullets(player, n_playerBounds, enemy);
    checkPurpleBullets(player, n_playerBounds, enemy);

    erasePlayerAndPurpleBullets(player, enemy);
    eraseOrangeBullets(enemy);
}

void Level4::CheckCollision()
{
    n_playerBounds = player.GetBounds();
    checkPlayerBulletsWithOrange(player, enemy);
    checkOrangeBullets(player, n_playerBounds, enemy);
    checkPurpleBullets(player, n_playerBounds, enemy);

    erasePlayerAndPurpleBullets(player, enemy);
    eraseOrangeBullets(enemy);
}

void Level5::CheckCollision()
{
    n_playerBounds = player.GetBounds();
    checkPlayerBulletsWithOrange(player, enemy);
    checkOrangeBullets(player, n_playerBounds, enemy);
    checkPurpleBullets(player, n_playerBounds, enemy);

    erasePlayerAndPurpleBullets(player, enemy);
    eraseOrangeBullets(enemy);
}

void Level6::CheckCollision()
{
    n_playerBounds = player.GetBounds();
    checkPlayerBulletsWithOrange(player, enemy);
    checkOrangeBullets(player, n_playerBounds, enemy);
    checkPurpleBullets(player, n_playerBounds, enemy);

    erasePlayerAndPurpleBullets(player, enemy);
    eraseOrangeBullets(enemy);
}

void Level7::CheckCollision()
{
    n_playerBounds = player.GetBounds();
    checkPlayerBullets(player, enemy);
    checkPurpleBullets(player, n_playerBounds, enemy);

    erasePlayerAndPurpleBullets(player, enemy);
}

void Level8::CheckCollision()
{
    n_playerBounds = player.GetBounds();
    checkPlayerBulletsWithOrange(player, enemy);
    checkOrangeBullets(player, n_playerBounds, enemy);
    checkPurpleBullets(player, n_playerBounds, enemy);

    erasePlayerAndPurpleBullets(player, enemy);
    eraseOrangeBullets(enemy);
}

void Level9::CheckCollision()
{
    n_playerBounds = player.GetBounds();
    checkPlayerBulletsWithOrange(player, enemy);
    checkOrangeBullets(player, n_playerBounds, enemy);
    checkPurpleBullets(player, n_playerBounds, enemy);

    erasePlayerAndPurpleBullets(player, enemy);
    eraseOrangeBullets(enemy);
}

void Level10::CheckCollision()
{
    n_playerBounds = player.GetBounds();
    checkPlayerBulletsWithOrangeAndSmall(player, enemy);
    checkOrangeBullets(player, n_playerBounds, enemy);
    checkPurpleBullets(player, n_playerBounds, enemy);

    eraseSmallEnemies(enemy);
    erasePlayerAndPurpleBullets(player, enemy);
    eraseOrangeBullets(enemy);
}

void Level11::CheckCollision()
{
    n_playerBounds = player.GetBounds();
    checkPlayerBulletsWithOrangeAndSmall(player, enemy);
    checkOrangeBullets(player, n_playerBounds, enemy);
    checkPurpleBullets(player, n_playerBounds, enemy);

    eraseSmallEnemies(enemy);
    erasePlayerAndPurpleBullets(player, enemy);
    eraseOrangeBullets(enemy);
}

void Level12::CheckCollision()
{
    n_playerBounds = player.GetBounds();
    checkPlayerBulletsWithOrangeAndSmall(player, enemy);
    checkOrangeBullets(player, n_playerBounds, enemy);
    checkPurpleBullets(player, n_playerBounds, enemy);

    checkPlayerBulletsWithAdd(player, secondEnemy);
    checkAllBulletsWithObstacles(player, enemy, obstacles);

    eraseSmallEnemies(enemy);
    erasePlayerAndPurpleBullets(player, enemy);
    eraseOrangeBullets(enemy);
}

void Level13::CheckCollision()
{
    n_playerBounds = player.GetBounds();
    checkPlayerBulletsWithOrangeAndSmall(player, enemy);
    checkOrangeBullets(player, n_playerBounds, enemy);
    checkPurpleBullets(player, n_playerBounds, enemy);

    eraseSmallEnemies(enemy);
    erasePlayerAndPurpleBullets(player, enemy);
    eraseOrangeBullets(enemy);
}

void Level14::CheckCollision()
{
    n_playerBounds = player.GetBounds();
    checkPlayerBulletsWithOrangeAndSmall(player, enemy);
    checkOrangeBullets(player, n_playerBounds, enemy);
    checkPurpleBullets(player, n_playerBounds, enemy);

    checkAllBulletsWithObstacles(player, enemy, obstacles);

    eraseSmallEnemies(enemy);
    erasePlayerAndPurpleBullets(player, enemy);
    eraseOrangeBullets(enemy);
}

void Level15::CheckCollision()
{
    n_playerBounds = player.GetBounds();
    checkPlayerBulletsWithOrangeAndSmallShielded(player, enemy);
    checkOrangeBullets(player, n_playerBounds, enemy);
    checkPurpleBullets(player, n_playerBounds, enemy);

    checkAllBulletsWithObstacles(player, enemy, obstacles);

    eraseSmallEnemies(enemy);
    erasePlayerAndPurpleBullets(player, enemy);
    eraseOrangeBullets(enemy);
}

void Level16::CheckCollision()
{
    n_playerBounds = player.GetBounds();
    checkPlayerBulletsWithOrangeAndSmall(player, enemy);
    checkOrangeBullets(player, n_playerBounds, enemy);
    checkPurpleBullets(player, n_playerBounds, enemy);

    eraseSmallEnemies(enemy);
    erasePlayerAndPurpleBullets(player, enemy);
    eraseOrangeBullets(enemy);
}