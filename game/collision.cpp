#include "maps.h"

bool playerBulletHitWall(const Bullet& bullet, const Walls& walls)
{
    return (bullet.position.y <= walls.top || bullet.position.x >= walls.right || bullet.position.y >= walls.bottom || bullet.position.x <= walls.left);
}

void removePlayerBulletsOnWallHit(Player& player)
{
    auto newEnd = std::remove_if(player.bullets.begin(), player.bullets.end(), [&player](const Bullet& bullet)
    {
        return playerBulletHitWall(bullet, player.walls);
    });
    player.bullets.erase(newEnd, player.bullets.end());
}

bool orangeBulletHitWall(const OrangeBullet& bullet, const Walls& walls)
{
    return (bullet.position.y <= walls.top || bullet.position.x >= walls.right || bullet.position.y >= walls.bottom || bullet.position.x <= walls.left);
}

bool purpleBulletHitWall(const PurpleBullet& bullet, const Walls& walls)
{
    return (bullet.position.y <= walls.top || bullet.position.x >= walls.right || bullet.position.y >= walls.bottom || bullet.position.x <= walls.left);
}

removeEnemyBulletsOnWallHit(const Player& player, Level0Enemy& enemy)
{
    auto newEndOrange = std::remove_if(enemy.orangeBullets.begin(), enemy.orangeBullets.end(), [&player](const OrangeBullet& bullet)
    {
        return orangeBulletHitWall(bullet, player.walls);
    });
    enemy.orangeBullets.erase(newEndOrange, enemy.orangeBullets.end());

    auto newEndPurple = std::remove_if(enemy.purpleBullets.begin(), enemy.purpleBullets.end(), [&player](const PurpleBullet& bullet)
    {
        return purpleBulletHitWall(bullet, player.walls);
    });
    enemy.purpleBullets.erase(newEndPurple, enemy.purpleBullets.end());
}

void Level0::CheckCollision()
{
    removePlayerBulletsOnWallHit(player);
    removeEnemyBulletsOnWallHit(player, enemy);
}