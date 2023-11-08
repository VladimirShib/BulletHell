#include "maps.h"

bool playerBulletHitWall(const Bullet& bullet)

void removePlayerBulletsOnWallHit(std::vector<Bullet>& bullets)
{
    auto newEnd = std::remove_if(bullets.begin(), bullets.end(), playerBulletHitWall);
    bullets.erase(newEnd, bullets.end());
}

void Level0::CheckCollision()
{
    removePlayerBulletsOnWallHit(player.bullets);
}