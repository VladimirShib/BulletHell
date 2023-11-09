#include "maps.h"

// ====== common ======
void playerBulletsHitWall(Player& player)
{
    for (auto& bullet : player.bullets)
    {
        if (bullet.position.y <= player.walls.top || bullet.position.x >= player.walls.right ||
            bullet.position.y >= player.walls.bottom || bullet.position.x <= player.walls.left)
        {
            bullet.hit = true;
        }
    }
}

template <typename EnemyType>
void enemyBulletsHitWall(EnemyType& enemy, Player& player)
{
    for (auto& bullet : enemy.orangeBullets)
    {
        if (bullet.position.y <= player.walls.top || bullet.position.x >= player.walls.right ||
            bullet.position.y >= player.walls.bottom || bullet.position.x <= player.walls.left)
        {
            bullet.hit = true;
        }
    }
    for (auto& bullet : enemy.purpleBullets)
    {
        if (bullet.position.y <= player.walls.top || bullet.position.x >= player.walls.right ||
            bullet.position.y >= player.walls.bottom || bullet.position.x <= player.walls.left)
        {
            bullet.hit = true;
        }
    }
}

template <typename EnemyType>
void twoBulletsCollide(Player& player, EnemyType& enemy)
{
    for (auto& bullet1 : player.bullets)
    {
        sf::FloatRect bounds1 = bullet1.GetBounds();
        for (auto& bullet2 : enemy.orangeBullets)
        {
            sf::FloatRect bounds2 = bullet2.GetBounds();
            if (bounds1.intersects(bounds2))
            {
                bullet1.hit = true;
                bullet2.hit = true;
            }
        }
    }
}

template <typename BulletType>
bool isToBeRemoved(const BulletType& bullet)
{
    return bullet.hit;
}

template <typename EnemyType>
void eraseBullets(Player& player, EnemyType& enemy)
{
    auto newEndPlayer = std::remove_if(player.bullets.begin(), player.bullets.end(), [&](const Bullet& bullet)
    {
        return isToBeRemoved(bullet);
    });
    player.bullets.erase(newEndPlayer, player.bullets.end());

    auto newEndOrange = std::remove_if(enemy.orangeBullets.begin(), enemy.orangeBullets.end(), [&](const OrangeBullet& bullet)
    {
        return isToBeRemoved(bullet);
    });
    enemy.orangeBullets.erase(newEndOrange, enemy.orangeBullets.end());

    auto newEndPurple = std::remove_if(enemy.purpleBullets.begin(), enemy.purpleBullets.end(), [&](const PurpleBullet& bullet)
    {
        return isToBeRemoved(bullet);
    });
    enemy.purpleBullets.erase(newEndPurple, enemy.purpleBullets.end());
}
// ====== common/ =====

void Level0::CheckCollision()
{
    playerBulletsHitWall(player);
    enemyBulletsHitWall(enemy, player);
    twoBulletsCollide(player, enemy);

    eraseBullets(player, enemy);
}