#include "maps.hpp"

namespace
{
    const sf::Color LIGHT_COLOR(0xC6, 0xC2, 0xA5);
    const sf::Color DARK_COLOR(0x50, 0x4E, 0x48);

    void initSmallLevelMap(sf::VertexArray& vertices)
    {
        vertices.setPrimitiveType(sf::Quads);
        
        vertices.append(sf::Vertex(sf::Vector2f(-205.f, 95.f), sf::Color(0xE6, 0xE4, 0xC4)));
        vertices.append(sf::Vertex(sf::Vector2f(1205.f, 95.f), sf::Color(0xE6, 0xE4, 0xC4)));
        vertices.append(sf::Vertex(sf::Vector2f(1205.f, 125.f), sf::Color(0xE6, 0xE4, 0xC4)));
        vertices.append(sf::Vertex(sf::Vector2f(-205.f, 125.f), sf::Color(0xE6, 0xE4, 0xC4)));
        vertices.append(sf::Vertex(sf::Vector2f(-205.f, 575.f), sf::Color(0xE6, 0xE4, 0xC4)));
        vertices.append(sf::Vertex(sf::Vector2f(1205.f, 575.f), sf::Color(0xE6, 0xE4, 0xC4)));
        vertices.append(sf::Vertex(sf::Vector2f(1205.f, 605.f), sf::Color(0xE6, 0xE4, 0xC4)));
        vertices.append(sf::Vertex(sf::Vector2f(-205.f, 605.f), sf::Color(0xE6, 0xE4, 0xC4)));
        vertices.append(sf::Vertex(sf::Vector2f(245.f, -205.f), sf::Color(0xE6, 0xE4, 0xC4)));
        vertices.append(sf::Vertex(sf::Vector2f(275.f, -205.f), sf::Color(0xE6, 0xE4, 0xC4)));
        vertices.append(sf::Vertex(sf::Vector2f(275.f, 905.f), sf::Color(0xE6, 0xE4, 0xC4)));
        vertices.append(sf::Vertex(sf::Vector2f(245.f, 905.f), sf::Color(0xE6, 0xE4, 0xC4)));
        vertices.append(sf::Vertex(sf::Vector2f(725.f, -205.f), sf::Color(0xE6, 0xE4, 0xC4)));
        vertices.append(sf::Vertex(sf::Vector2f(755.f, -205.f), sf::Color(0xE6, 0xE4, 0xC4)));
        vertices.append(sf::Vertex(sf::Vector2f(755.f, 905.f), sf::Color(0xE6, 0xE4, 0xC4)));
        vertices.append(sf::Vertex(sf::Vector2f(725.f, 905.f), sf::Color(0xE6, 0xE4, 0xC4)));
    }

    void initLargeLevelMap(sf::VertexArray& vertices, sf::VertexArray& stars)
    {
        vertices.setPrimitiveType(sf::Quads);
        vertices.append(sf::Vertex(sf::Vector2f(50.f, -100.f), sf::Color(0xC6, 0xC2, 0xA5)));
        vertices.append(sf::Vertex(sf::Vector2f(950.f, -100.f), sf::Color(0xC6, 0xC2, 0xA5)));
        vertices.append(sf::Vertex(sf::Vector2f(950.f, 800.f), sf::Color(0xC6, 0xC2, 0xA5)));
        vertices.append(sf::Vertex(sf::Vector2f(50.f, 800.f), sf::Color(0xC6, 0xC2, 0xA5)));

        stars.setPrimitiveType(sf::Triangles);
        const std::vector<sf::Vector2f> small = {
            {-330.f, -344.f}, {4.f, -182.f}, {174.f, -370.f}, {434.f, -336.f},
            {360.f, -120.f}, {-190.f, 284.f}, {-116.f, 612.f}, {-44.f, 866.f},
            {-154.f, 1080.f}, {453.f, 1076.f}, {862.f, 1034.f}, {700.f, -350.f},
            {922.f, -242.f}, {1158.f, -330.f}, {1124.f, -58.f}, {1422.f, 184.f},
            {1038.f, 300.f}, {1128.f, 566.f}, {998.f, 766.f}, {1252.f, 890.f}
        };
        for (auto& point : small)
        {
            stars.append(sf::Vertex(point, sf::Color(0xFF, 0xFF, 0xFF)));
            stars.append(sf::Vertex(point + sf::Vector2f(1.f, -2.f), sf::Color(0xFF, 0xFF, 0xFF)));
            stars.append(sf::Vertex(point + sf::Vector2f(2.f, 0.f), sf::Color(0xFF, 0xFF, 0xFF)));
        }

        const std::vector<sf::Vector2f> medium = {
            {-104.f, -412.f}, {-272.f, -174.f}, {-125.f, 56.f}, {558.f, -220.f},
            {-314.f, 474.f}, {-268.f, 710.f}, {105.f, 990.f}, {326.f, 826.f},
            {762.f, -124.f}, {1300.f, -164.f}, {1270.f, 396.f}, {1156.f, 1074.f}
        };
        for (auto& point : medium)
        {
            stars.append(sf::Vertex(point, sf::Color(0xFF, 0xFF, 0xFF)));
            stars.append(sf::Vertex(point + sf::Vector2f(1.f, -3.f), sf::Color(0xFF, 0xFF, 0xFF)));
            stars.append(sf::Vertex(point + sf::Vector2f(4.f, -1.f), sf::Color(0xFF, 0xFF, 0xFF)));
        }

        const std::vector<sf::Vector2f> large = {
            {-350.f, 124.f}, {270.f, -248.f}, {-70.f, 400.f}, {-282.f, 988.f},
            {666.f, 922.f}, {886.f, -388.f}, {1190.f, 120.f}, {1384.f, 716.f}
        };
        for (auto& point : large)
        {
            stars.append(sf::Vertex(point, sf::Color(0xFF, 0xFF, 0xFF)));
            stars.append(sf::Vertex(point + sf::Vector2f(6.f, -2.f), sf::Color(0xFF, 0xFF, 0xFF)));
            stars.append(sf::Vertex(point + sf::Vector2f(4.f, 4.f), sf::Color(0xFF, 0xFF, 0xFF)));
        }
    }

    const std::vector<float> n_lastShot = {
        {1.6f}, {1.4f}, {1.2f}, {1.f}, {0.8f}, {0.6f}, {0.4f}, {0.2f}, {0.f},
        {1.5f}, {1.3f}, {1.1f}, {0.9f}, {0.7f}, {0.5f}, {0.3f}, {0.1f}
    };
    struct EnemyLevelData
    {
        sf::Vector2f position;
        float rotation;
    };
}

Level0::Level0() : player(275.f, 125.f, 450.f), enemy(0.5f)
// passing playing field parameters to player constructor and shooting delay to enemy constructor
{
    player.playerPosition = sf::Vector2f(500.f, 515.f);
    player.setPosition(player.playerPosition);
    player.setRotation(-90.f);
    enemy.enemyPosition = sf::Vector2f(500.f, 250.f);
    enemy.setPosition(enemy.enemyPosition);
    elapsedTime = 0.f;
    levelStatus = 0;
    clearColor = LIGHT_COLOR;

    initSmallLevelMap(map);
}

void Level0::Update(sf::RenderWindow& window, sf::View& view, sf::Clock& clock)
{
    deltaTime = clock.restart().asSeconds();
    elapsedTime += deltaTime;
    player.Update(window, view, deltaTime);
    enemy.MoveHorizontal(elapsedTime);
    if (!enemy.isAnimatingExplode)
    {
        enemy.AnimateHit();
        enemy.ShootOneBulletBothColors(deltaTime, player.playerPosition);
        enemy.UpdateAllBullets(deltaTime);
    }
    CheckCollision();

    if (player.health <= 0)
    {
        levelStatus = 2;
    }
    if (enemy.health <= 0)
    {
        levelStatus = 1;
    }
}

Level1::Level1() : player(275.f, 125.f, 450.f), enemy(1.f)
{
    player.playerPosition = sf::Vector2f(500.f, 515.f);
    player.setPosition(player.playerPosition);
    player.setRotation(-90.f);
    enemy.enemyPosition = sf::Vector2f(500.f, 250.f);
    enemy.setPosition(enemy.enemyPosition);
    elapsedTime = 45.f * float(M_PI) / 180.f;
    levelStatus = 0;
    clearColor = LIGHT_COLOR;

    initSmallLevelMap(map);
}

void Level1::Update(sf::RenderWindow& window, sf::View& view, sf::Clock& clock)
{
    deltaTime = clock.restart().asSeconds();
    elapsedTime += deltaTime;
    player.Update(window, view, deltaTime);
    enemy.MoveLemniscate(elapsedTime);
    if (!enemy.isAnimatingExplode)
    {
        enemy.AnimateHit();
        enemy.ShootThreePurpleBullets(deltaTime, player.playerPosition);
        enemy.UpdatePurpleBullets(deltaTime);
    }
    CheckCollision();

    if (player.health <= 0)
    {
        levelStatus = 2;
    }
    if (enemy.health <= 0)
    {
        levelStatus = 1;
    }
}

Level2::Level2() : player(275.f, 125.f, 450.f), enemy(0.6f)
{
    player.playerPosition = sf::Vector2f(500.f, 515.f);
    player.setPosition(player.playerPosition);
    player.setRotation(-90.f);
    enemy.enemyPosition = sf::Vector2f(500.f, 200.f);
    enemy.setPosition(enemy.enemyPosition);
    elapsedTime = 90.0f * float(M_PI) / 180.f;
    levelStatus = 0;
    clearColor = LIGHT_COLOR;
    
    initSmallLevelMap(map);
}

void Level2::Update(sf::RenderWindow& window, sf::View& view, sf::Clock& clock)
{
    deltaTime = clock.restart().asSeconds();
    elapsedTime += deltaTime;
    player.Update(window, view, deltaTime);
    enemy.MoveCircular(elapsedTime);
    if (!enemy.isAnimatingExplode)
    {
        enemy.AnimateHit();
        enemy.ShootFourPurpleBullets(deltaTime, player.playerPosition);
        enemy.UpdatePurpleBullets(deltaTime);
    }
    CheckCollision();

    if (player.health <= 0)
    {
        levelStatus = 2;
    }
    if (enemy.health <= 0)
    {
        levelStatus = 1;
    }
}

Level3::Level3() : player(275.f, 125.f, 450.f), enemy(1.f)
{
    player.playerPosition = sf::Vector2f(500.f, 515.f);
    player.setPosition(player.playerPosition);
    player.setRotation(-90.f);
    enemy.enemyPosition = sf::Vector2f(500.f, 250.f);
    enemy.setPosition(enemy.enemyPosition);
    levelStatus = 0;
    clearColor = LIGHT_COLOR;
    
    initSmallLevelMap(map);
}

void Level3::Update(sf::RenderWindow& window, sf::View& view, sf::Clock& clock)
{
    deltaTime = clock.restart().asSeconds();
    player.Update(window, view, deltaTime);
    enemy.MoveWithCollision(deltaTime);
    if (!enemy.isAnimatingExplode)
    {
        enemy.AnimateHit();
        enemy.ShootFiveBulletsBothColors(deltaTime, player.playerPosition);
        enemy.UpdateAllBullets(deltaTime);
    }
    CheckCollision();

    if (player.health <= 0)
    {
        levelStatus = 2;
    }
    if (enemy.health <= 0)
    {
        levelStatus = 1;
    }
}

Level4::Level4() : player(275.f, 125.f, 450.f), enemy(1.f)
{
    player.playerPosition = sf::Vector2f(500.f, 515.f);
    player.setPosition(player.playerPosition);
    player.setRotation(-90.f);
    enemy.enemyPosition = sf::Vector2f(500.f, 250.f);
    enemy.setPosition(enemy.enemyPosition);
    levelStatus = 0;
    clearColor = LIGHT_COLOR;
    
    initSmallLevelMap(map);
}

void Level4::Update(sf::RenderWindow& window, sf::View& view, sf::Clock& clock)
{
    deltaTime = clock.restart().asSeconds();
    player.Update(window, view, deltaTime);
    enemy.FollowSlowly(deltaTime, player.playerPosition);
    if (!enemy.isAnimatingExplode)
    {
        enemy.AnimateHit();
        enemy.ShootEightBulletsBothColors(deltaTime);
        enemy.UpdateAllBullets(deltaTime);
    }
    CheckCollision();

    if (player.health <= 0)
    {
        levelStatus = 2;
    }
    if (enemy.health <= 0)
    {
        levelStatus = 1;
    }
}

Level5::Level5() : player(275.f, 125.f, 450.f), enemy(0.1f)
{
    player.playerPosition = sf::Vector2f(500.f, 515.f);
    player.setPosition(player.playerPosition);
    player.setRotation(-90.f);
    enemy.enemyPosition = sf::Vector2f(500.f, 250.f);
    enemy.setPosition(enemy.enemyPosition);
    levelStatus = 0;
    clearColor = LIGHT_COLOR;
    
    initSmallLevelMap(map);
}

void Level5::Update(sf::RenderWindow& window, sf::View& view, sf::Clock& clock)
{
    deltaTime = clock.restart().asSeconds();
    player.Update(window, view, deltaTime);
    enemy.FollowSlowly(deltaTime, player.playerPosition);
    if (!enemy.isAnimatingExplode)
    {
        enemy.AnimateHit();
        enemy.ShootOneBulletInStreamsBothColors(deltaTime);
        enemy.UpdateAllBullets(deltaTime);
    }
    CheckCollision();

    if (player.health <= 0)
    {
        levelStatus = 2;
    }
    if (enemy.health <= 0)
    {
        levelStatus = 1;
    }
}

Level6::Level6() : player(275.f, 125.f, 450.f), enemy(0.1f)
{
    player.playerPosition = sf::Vector2f(500.f, 515.f);
    player.setPosition(player.playerPosition);
    player.setRotation(-90.f);
    enemy.enemyPosition = sf::Vector2f(425.f, 250.f);
    enemy.setPosition(enemy.enemyPosition);
    elapsedTime = 0.f;
    levelStatus = 0;
    clearColor = LIGHT_COLOR;
    
    initSmallLevelMap(map);
}

void Level6::Update(sf::RenderWindow& window, sf::View& view, sf::Clock& clock)
{
    deltaTime = clock.restart().asSeconds();
    elapsedTime += deltaTime;
    player.Update(window, view, deltaTime);
    enemy.MoveHorizontalRotated(elapsedTime);
    if (!enemy.isAnimatingExplode)
    {
        enemy.AnimateHit();
        enemy.ShootThreeBulletsInStreamsBothColors(deltaTime, player.playerPosition);
        enemy.UpdateAllBullets(deltaTime);
    }
    CheckCollision();

    if (player.health <= 0)
    {
        levelStatus = 2;
    }
    if (enemy.health <= 0)
    {
        levelStatus = 1;
    }
}

Level7::Level7() : player(275.f, 125.f, 450.f), enemy(1.f)
{
    player.playerPosition = sf::Vector2f(500.f, 515.f);
    player.setPosition(player.playerPosition);
    player.setRotation(-90.f);
    enemy.enemyPosition = sf::Vector2f(500.f, 350.f);
    enemy.setPosition(enemy.enemyPosition);
    elapsedTime = 45.f * float(M_PI) / 180.f;
    levelStatus = 0;
    clearColor = LIGHT_COLOR;
    
    initSmallLevelMap(map);
}

void Level7::Update(sf::RenderWindow& window, sf::View& view, sf::Clock& clock)
{
    deltaTime = clock.restart().asSeconds();
    elapsedTime += deltaTime;
    player.Update(window, view, deltaTime);
    enemy.MoveLemniscateRotated(elapsedTime);
    if (!enemy.isAnimatingExplode)
    {
        enemy.AnimateHit();
        enemy.ShootFourPurpleBullets(deltaTime, player.playerPosition);
        enemy.UpdatePurpleBullets(deltaTime);
    }
    CheckCollision();

    if (player.health <= 0)
    {
        levelStatus = 2;
    }
    if (enemy.health <= 0)
    {
        levelStatus = 1;
    }
}

Level8::Level8() : player(275.f, 125.f, 450.f), enemy(1.f)
{
    player.playerPosition = sf::Vector2f(500.f, 515.f);
    player.setPosition(player.playerPosition);
    player.setRotation(-90.f);
    enemy.enemyPosition = sf::Vector2f(500.f, 250.f);
    enemy.setPosition(enemy.enemyPosition);
    levelStatus = 0;
    clearColor = LIGHT_COLOR;
    
    initSmallLevelMap(map);
}

void Level8::Update(sf::RenderWindow& window, sf::View& view, sf::Clock& clock)
{
    deltaTime = clock.restart().asSeconds();
    player.Update(window, view, deltaTime);
    enemy.MoveInPlayerDirWithDelay(deltaTime, player.playerPosition);
    if (!enemy.isAnimatingExplode)
    {
        enemy.AnimateHit();
        enemy.ShootFourBulletsBothColors(deltaTime, player.playerPosition);
        enemy.UpdateAllBullets(deltaTime);
    }
    CheckCollision();

    if (player.health <= 0)
    {
        levelStatus = 2;
    }
    if (enemy.health <= 0)
    {
        levelStatus = 1;
    }
}

Level9::Level9() : player(275.f, 125.f, 450.f), enemy(1.f)
{
    player.playerPosition = sf::Vector2f(500.f, 515.f);
    player.setPosition(player.playerPosition);
    player.setRotation(-90.f);
    enemy.enemyPosition = sf::Vector2f(500.f, 250.f);
    enemy.setPosition(enemy.enemyPosition);
    levelStatus = 0;
    clearColor = LIGHT_COLOR;
    
    initSmallLevelMap(map);
}

void Level9::Update(sf::RenderWindow& window, sf::View& view, sf::Clock& clock)
{
    deltaTime = clock.restart().asSeconds();
    player.Update(window, view, deltaTime);
    enemy.FollowFast(deltaTime, player.playerPosition);
    if (!enemy.isAnimatingExplode)
    {
        enemy.AnimateHit();
        enemy.ShootEightBulletsBothColors(deltaTime);
        enemy.UpdateAllBullets(deltaTime);
    }
    CheckCollision();

    if (player.health <= 0)
    {
        levelStatus = 2;
    }
    if (enemy.health <= 0)
    {
        levelStatus = 1;
    }
}

Level10::Level10() : player(50.f, -100.f, 900.f), enemy(0.5f, 7) // shooting delay and number of small enemies
{
    player.playerPosition = sf::Vector2f(500.f, 100.f);
    player.setPosition(player.playerPosition);
    player.setRotation(90.f);
    enemy.enemyPosition = sf::Vector2f(500.f, 420.f);
    enemy.setPosition(enemy.enemyPosition);
    levelStatus = 0;
    clearColor = DARK_COLOR;

    const std::vector<EnemyLevelData> enemyLevelData = {
        {{500.f, 270.f}, -90.f}, {{430.f, 270.f}, -70.f}, {{570.f, 270.f}, -110.f}, {{390.f, 340.f}, -65.f},
        {{610.f, 340.f}, -115.f}, {{320.f, 400.f}, -60.f}, {{680.f, 400.f}, -120.f}
    };
    for (int i = 0; i < 7; ++i)
    {
        SmallEnemy smallEnemy(i, n_lastShot[i], 'f');
        smallEnemy.position = enemyLevelData[i].position;
        smallEnemy.setPosition(smallEnemy.position);
        smallEnemy.setRotation(enemyLevelData[i].rotation);
        enemy.smallEnemies.push_back(smallEnemy);
    }

    initLargeLevelMap(map, stars);
}

void Level10::Update(sf::RenderWindow& window, sf::View& view, sf::Clock& clock)
{
    deltaTime = clock.restart().asSeconds();
    player.Update(window, view, deltaTime);
    enemy.FollowSlowly(deltaTime, player.playerPosition);
    if (enemy.numberOfSmallEnemies > 0)
    {
        enemy.UpdateSmallEnemies(deltaTime, player.playerPosition);
    }
    if (!enemy.isAnimatingExplode)
    {
        enemy.AnimateHit();
        enemy.ShootOneBulletBothColors(deltaTime);
        enemy.UpdateAllBullets(deltaTime);
    }
    CheckCollision();
    enemy.UpdateShield();

    if (player.health <= 0)
    {
        levelStatus = 2;
    }
    if (enemy.health <= 0)
    {
        levelStatus = 1;
    }
}

Level11::Level11() : player(50.f, -100.f, 900.f), enemy(1.f, 11)
{
    player.playerPosition = sf::Vector2f(500.f, 600.f);
    player.setPosition(player.playerPosition);
    player.setRotation(-90.f);
    enemy.enemyPosition = sf::Vector2f(500.f, 200.f);
    enemy.setPosition(enemy.enemyPosition);
    levelStatus = 0;
    clearColor = DARK_COLOR;

    const std::vector<EnemyLevelData> enemyLevelData = {
        {{500.f, 370.f}, 90.f}, {{430.f, 300.f}, 80.f}, {{570.f, 300.f}, 100.f}, {{360.f, 370.f}, 60.f},
        {{640.f, 370.f}, 120.f}, {{280.f, 410.f}, 45.f}, {{720.f, 410.f}, 135.f}, {{230.f, 490.f}, 30.f},
        {{770.f, 490.f}, 150.f}, {{160.f, 580.f}, 10.f}, {{840.f, 580.f}, 170.f}
    };
    for (int i = 0; i < 11; ++i)
    {
        SmallEnemy smallEnemy(i, n_lastShot[i], 'f');
        smallEnemy.position = enemyLevelData[i].position;
        smallEnemy.setPosition(smallEnemy.position);
        smallEnemy.setRotation(enemyLevelData[i].rotation);
        enemy.smallEnemies.push_back(smallEnemy);
    }

    initLargeLevelMap(map, stars);
}

void Level11::Update(sf::RenderWindow& window, sf::View& view, sf::Clock& clock)
{
    deltaTime = clock.restart().asSeconds();
    player.Update(window, view, deltaTime);
    enemy.FollowSlowly(deltaTime, player.playerPosition);
    if (enemy.numberOfSmallEnemies > 0)
    {
        enemy.UpdateSmallEnemies(deltaTime, player.playerPosition);
    }
    if (!enemy.isAnimatingExplode)
    {
        enemy.AnimateHit();
        enemy.ShootThreePurpleBullets(deltaTime);
        enemy.UpdateAllBullets(deltaTime);
    }
    CheckCollision();
    enemy.UpdateShield();

    if (player.health <= 0)
    {
        levelStatus = 2;
    }
    if (enemy.health <= 0)
    {
        levelStatus = 1;
    }
}

Level12::Level12() : player(50.f, -100.f, 900.f), enemy(0.68f, 7), secondEnemy(0.68f)
{
    player.playerPosition = sf::Vector2f(500.f, 450.f);
    player.setPosition(player.playerPosition);
    player.setRotation(-90.f);
    enemy.enemyPosition = sf::Vector2f(270.f, 100.f);
    enemy.setPosition(enemy.enemyPosition);
    enemy.shootingAngle = 5.f * float(M_PI) / 6.f;
    secondEnemy.enemyPosition = sf::Vector2f(730.f, 100.f);
    secondEnemy.setPosition(secondEnemy.enemyPosition);
    secondEnemy.shootingAngle = 5.f * float(M_PI) / 6.f;
    levelStatus = 0;
    enemy.otherEnemy = true;
    clearColor = DARK_COLOR;

    const std::vector<EnemyLevelData> enemyLevelData = {
        {{500.f, 240.f}, 90.f}, {{400.f, 190.f}, 70.f}, {{600.f, 190.f}, 110.f}, {{320.f, 235.f}, 50.f},
        {{680.f, 235.f}, 130.f}, {{230.f, 185.f}, 45.f}, {{770.f, 185.f}, 135.f}
    };
    for (int i = 0; i < 7; ++i)
    {
        SmallEnemy smallEnemy(i, n_lastShot[i], 'f');
        smallEnemy.position = enemyLevelData[i].position;
        smallEnemy.setPosition(smallEnemy.position);
        smallEnemy.setRotation(enemyLevelData[i].rotation);
        enemy.smallEnemies.push_back(smallEnemy);
    }

    initLargeLevelMap(map, stars);
    const std::vector<sf::Vector2f> points = {
        {50.f, 325.f}, {100.f, 325.f}, {100.f, 375.f}, {50.f, 375.f},
        {200.f, 325.f}, {250.f, 325.f}, {250.f, 375.f}, {200.f, 375.f},
        {350.f, 325.f}, {400.f, 325.f}, {400.f, 375.f}, {350.f, 375.f},
        {600.f, 325.f}, {650.f, 325.f}, {650.f, 375.f}, {600.f, 375.f},
        {750.f, 325.f}, {800.f, 325.f}, {800.f, 375.f}, {750.f, 375.f},
        {900.f, 325.f}, {950.f, 325.f}, {950.f, 375.f}, {900.f, 375.f}
    }; // obstacles
    for (auto& point : points)
    {
        map.append(sf::Vertex(point, sf::Color(0xEC, 0xE8, 0xE1)));
    }

    playerObstacles.push_back(sf::FloatRect(50.f, 305.f, 70.f, 90.f));
    playerObstacles.push_back(sf::FloatRect(180.f, 305.f, 90.f, 90.f));
    playerObstacles.push_back(sf::FloatRect(330.f, 305.f, 90.f, 90.f));
    playerObstacles.push_back(sf::FloatRect(580.f, 305.f, 90.f, 90.f));
    playerObstacles.push_back(sf::FloatRect(730.f, 305.f, 90.f, 90.f));
    playerObstacles.push_back(sf::FloatRect(880.f, 305.f, 70.f, 90.f));

    obstacles.push_back(sf::FloatRect(50.f, 325.f, 50.f, 50.f));
    obstacles.push_back(sf::FloatRect(200.f, 325.f, 50.f, 50.f));
    obstacles.push_back(sf::FloatRect(350.f, 325.f, 50.f, 50.f));
    obstacles.push_back(sf::FloatRect(600.f, 325.f, 50.f, 50.f));
    obstacles.push_back(sf::FloatRect(750.f, 325.f, 50.f, 50.f));
    obstacles.push_back(sf::FloatRect(900.f, 325.f, 50.f, 50.f));
}

void Level12::Update(sf::RenderWindow& window, sf::View& view, sf::Clock& clock)
{
    deltaTime = clock.restart().asSeconds();
    player.UpdateWithObstacles(window, view, deltaTime, playerObstacles);
    enemy.FollowSlowlyWithObstaclesAndAdd(deltaTime, player.playerPosition, obstacles, secondEnemy.enemyPosition);
    if (enemy.numberOfSmallEnemies > 0)
    {
        enemy.UpdateSmallEnemiesWithObstacles(deltaTime, player.playerPosition, obstacles);
    }
    secondEnemy.FollowSlowlyWithObstacles(deltaTime, player.playerPosition, obstacles, enemy.enemyPosition, enemy.smallEnemies);
    if (!secondEnemy.isAnimatingExplode)
    {
        secondEnemy.AnimateHit();
        secondEnemy.RotatingShootingTypeOne(deltaTime, enemy.shootingDelay, enemy.orangeBullets, enemy.purpleBullets);
    }
    if (!enemy.isAnimatingExplode)
    {
        enemy.AnimateHit();
        enemy.RotatingShootingTypeOne(deltaTime);
    }
    if (!enemy.isAnimatingExplode || !secondEnemy.isAnimatingExplode)
    {
        enemy.UpdateAllBullets(deltaTime);
    }
    else
    {
        enemy.orangeBullets.clear();
        enemy.purpleBullets.clear();
    }
    CheckCollision();
    enemy.UpdateShield();
    secondEnemy.UpdateShield(enemy.numberOfSmallEnemies);
    enemy.CheckOtherEnemy(secondEnemy.isAlive);

    if (player.health <= 0)
    {
        levelStatus = 2;
    }
    if (enemy.health <= 0 && secondEnemy.health <= 0)
    {
        levelStatus = 1;
    }
}

Level13::Level13() : player(50.f, -100.f, 900.f), enemy(1.1f, 14)
{
    player.playerPosition = sf::Vector2f(500.f, 100.f);
    player.setPosition(player.playerPosition);
    player.setRotation(90.f);
    enemy.enemyPosition = sf::Vector2f(500.f, 350.f);
    enemy.setPosition(enemy.enemyPosition);
    levelStatus = 0;
    clearColor = DARK_COLOR;

    const std::vector<EnemyLevelData> enemyLevelData = {
        {{385.f, 250.f}, -55.f}, {{615.f, 250.f}, -125.f}, {{285.f, 250.f}, -40.f}, {{715.f, 250.f}, -140.f},
        {{335.f, 345.f}, -50.f}, {{665.f, 345.f}, -130.f}, {{165.f, 345.f}, -40.f}, {{835.f, 345.f}, -140.f},
        {{440.f, 425.f}, -80.f}, {{560.f, 425.f}, -100.f}, {{205.f, 425.f}, -45.f}, {{795.f, 425.f}, -135.f},
        {{335.f, 495.f}, -85.f}, {{665.f, 495.f}, -95.f}
    };
    for (int i = 0; i < 14; ++i)
    {
        SmallEnemy smallEnemy(i, n_lastShot[i], 'f');
        smallEnemy.position = enemyLevelData[i].position;
        smallEnemy.setPosition(smallEnemy.position);
        smallEnemy.setRotation(enemyLevelData[i].rotation);
        enemy.smallEnemies.push_back(smallEnemy);
    }

    initLargeLevelMap(map, stars);
}

void Level13::Update(sf::RenderWindow& window, sf::View& view, sf::Clock& clock)
{
    deltaTime = clock.restart().asSeconds();
    player.Update(window, view, deltaTime);
    enemy.FollowSlowly(deltaTime, player.playerPosition);
    if (enemy.numberOfSmallEnemies > 0)
    {
        enemy.UpdateSmallEnemies(deltaTime, player.playerPosition);
    }
    if (!enemy.isAnimatingExplode)
    {
        enemy.AnimateHit();
        enemy.ShootFiveBulletsBothColors(deltaTime);
        enemy.UpdateAllBullets(deltaTime);
    }
    CheckCollision();
    enemy.UpdateShield();

    if (player.health <= 0)
    {
        levelStatus = 2;
    }
    if (enemy.health <= 0)
    {
        levelStatus = 1;
    }
}

Level14::Level14() : player(50.f, -100.f, 900.f), enemy(0.8f, 9)
{
    player.playerPosition = sf::Vector2f(500.f, 575.f);
    player.setPosition(player.playerPosition);
    player.setRotation(-90.f);
    enemy.enemyPosition = sf::Vector2f(500.f, 200.f);
    enemy.setPosition(enemy.enemyPosition);
    enemy.shootingAngle = 0.f;
    levelStatus = 0;
    clearColor = DARK_COLOR;

    const std::vector<EnemyLevelData> enemyLevelData = {
        {{500.f, 675.f}, -90.f}, {{125.f, 400.f}, 30.f}, {{875.f, 400.f}, 150.f}, {{325.f, 290.f}, 60.f},
        {{675.f, 290.f}, 120.f}, {{355.f, 240.f}, 70.f}, {{645.f, 240.f}, 110.f}, {{450.f, 150.f}, 90.f},
        {{550.f, 150.f}, 90.f}
    };
    for (int i = 0; i < 9; ++i)
    {
        SmallEnemy smallEnemy(i, n_lastShot[i], 'f');
        smallEnemy.position = enemyLevelData[i].position;
        smallEnemy.setPosition(smallEnemy.position);
        smallEnemy.setRotation(enemyLevelData[i].rotation);
        enemy.smallEnemies.push_back(smallEnemy);
    }

    initLargeLevelMap(map, stars);
    const std::vector<sf::Vector2f> points = {
        {418.4f, 600.f}, {468.4f, 600.f}, {468.4f, 650.f}, {418.4f, 650.f},
        {475.f, 600.f}, {525.f, 600.f}, {525.f, 650.f}, {475.f, 650.f},
        {531.6f, 600.f}, {581.6f, 600.f}, {581.6f, 650.f}, {531.6f, 650.f},
        {200.f, 318.4f}, {250.f, 318.4f}, {250.f, 368.4f}, {200.f, 368.4f},
        {200.f, 375.f}, {250.f, 375.f}, {250.f, 425.f}, {200.f, 425.f},
        {200.f, 431.6f}, {250.f, 431.6f}, {250.f, 481.6f}, {200.f, 481.6f},
        {750.f, 318.4f}, {800.f, 318.4f}, {800.f, 368.4f}, {750.f, 368.4f},
        {750.f, 375.f}, {800.f, 375.f}, {800.f, 425.f}, {750.f, 425.f},
        {750.f, 431.6f}, {800.f, 431.6f}, {800.f, 481.6f}, {750.f, 481.6f}
    };
    for (auto& point : points)
    {
        map.append(sf::Vertex(point, sf::Color(0xEC, 0xE8, 0xE1)));
    }

    playerObstacles.push_back(sf::FloatRect(398.4f, 580.f, 203.2f, 90.f));
    playerObstacles.push_back(sf::FloatRect(180.f, 298.4f, 90.f, 203.2f));
    playerObstacles.push_back(sf::FloatRect(730.f, 298.4f, 90.f, 203.2f));

    obstacles.push_back(sf::FloatRect(418.4f, 600.f, 163.2f, 50.f));
    obstacles.push_back(sf::FloatRect(200.f, 318.4f, 50.f, 163.2f));
    obstacles.push_back(sf::FloatRect(750.f, 318.4f, 50.f, 163.2f));
}

void Level14::Update(sf::RenderWindow& window, sf::View& view, sf::Clock& clock)
{
    deltaTime = clock.restart().asSeconds();
    player.UpdateWithObstacles(window, view, deltaTime, playerObstacles);
    enemy.FollowSlowlyWithObstacles(deltaTime, player.playerPosition, obstacles);
    if (enemy.numberOfSmallEnemies > 0)
    {
        enemy.UpdateSmallEnemiesWithObstacles(deltaTime, player.playerPosition, obstacles);
    }
    if (!enemy.isAnimatingExplode)
    {
        enemy.AnimateHit();
        enemy.RotatingShootingTypeTwo(deltaTime);
        enemy.UpdateAllBullets(deltaTime);
    }
    CheckCollision();
    enemy.UpdateShield();

    if (player.health <= 0)
    {
        levelStatus = 2;
    }
    if (enemy.health <= 0)
    {
        levelStatus = 1;
    }
}

Level15::Level15() : player(50.f, -100.f, 900.f), enemy(0.76f, 8)
{
    player.playerPosition = sf::Vector2f(500.f, 445.f);
    player.setPosition(player.playerPosition);
    player.setRotation(-90.f);
    enemy.enemyPosition = sf::Vector2f(500.f, 185.f);
    enemy.setPosition(enemy.enemyPosition);
    levelStatus = 0;
    clearColor = DARK_COLOR;

    const std::vector<EnemyLevelData> enemyLevelData = {
        {{144.f, 350.f}, 25.f}, {{856.f, 350.f}, 155.f}, {{262.f, 231.f}, 45.f}, {{738.f, 231.f}, 135.f},
        {{105.f, 40.f}, 60.f}, {{895.f, 40.f}, 120.f}, {{380.f, 30.f}, 80.f}, {{620.f, 30.f}, 100.f}
    };
    for (int i = 0; i < 2; ++i)
    {
        SmallEnemy smallEnemy(i, n_lastShot[i], 't');
        smallEnemy.position = enemyLevelData[i].position;
        smallEnemy.setPosition(smallEnemy.position);
        smallEnemy.setRotation(enemyLevelData[i].rotation);
        enemy.smallEnemies.push_back(smallEnemy);
    }
    for (int i = 2; i < 8; ++i)
    {
        SmallEnemy smallEnemy(i, n_lastShot[i], 'f');
        smallEnemy.position = enemyLevelData[i].position;
        smallEnemy.setPosition(smallEnemy.position);
        smallEnemy.setRotation(enemyLevelData[i].rotation);
        enemy.smallEnemies.push_back(smallEnemy);
    }

    initLargeLevelMap(map, stars);
    const std::vector<sf::Vector2f> points = {
        {237.5f, 87.5f}, {287.5f, 87.5f}, {287.5f, 137.5f}, {237.5f, 137.5f},
        {475.f, 87.5f}, {525.f, 87.5f}, {525.f, 137.5f}, {475.f, 137.5f},
        {712.5f, 87.5f}, {762.5f, 87.5f}, {762.5f, 137.5f}, {712.5f, 137.5f},
        {237.5f, 325.f}, {287.5f, 325.f}, {287.5f, 375.f}, {237.5f, 375.f},
        {712.5f, 325.f}, {762.5f, 325.f}, {762.5f, 375.f}, {712.5f, 375.f},
        {237.5f, 562.5f}, {287.5f, 562.5f}, {287.5f, 612.5f}, {237.5f, 612.5f},
        {712.5f, 562.5f}, {762.5f, 562.5f}, {762.5f, 612.5f}, {712.5f, 612.5f}
    };
    for (auto& point : points)
    {
        map.append(sf::Vertex(point, sf::Color(0xEC, 0xE8, 0xE1)));
    }

    playerObstacles.push_back(sf::FloatRect(217.5f, 37.5f, 90.f, 90.f));
    playerObstacles.push_back(sf::FloatRect(455.f, 37.5f, 90.f, 90.f));
    playerObstacles.push_back(sf::FloatRect(692.5f, 37.5f, 90.f, 90.f));
    playerObstacles.push_back(sf::FloatRect(217.5f, 305.f, 90.f, 90.f));
    playerObstacles.push_back(sf::FloatRect(692.5f, 305.f, 90.f, 90.f));
    playerObstacles.push_back(sf::FloatRect(217.5f, 542.5f, 90.f, 90.f));
    playerObstacles.push_back(sf::FloatRect(692.5f, 542.5f, 90.f, 90.f));

    obstacles.push_back(sf::FloatRect(237.5f, 87.5f, 50.f, 50.f));
    obstacles.push_back(sf::FloatRect(475.f, 87.5f, 50.f, 50.f));
    obstacles.push_back(sf::FloatRect(712.5f, 87.5f, 50.f, 50.f));
    obstacles.push_back(sf::FloatRect(237.5f, 325.f, 50.f, 50.f));
    obstacles.push_back(sf::FloatRect(712.5f, 325.f, 50.f, 50.f));
    obstacles.push_back(sf::FloatRect(237.5f, 562.5f, 50.f, 50.f));
    obstacles.push_back(sf::FloatRect(712.5f, 562.5f, 50.f, 50.f));
}

void Level15::Update(sf::RenderWindow& window, sf::View& view, sf::Clock& clock)
{
    deltaTime = clock.restart().asSeconds();
    player.UpdateWithObstacles(window, view, deltaTime, playerObstacles);
    enemy.FollowSlowlyWithObstacles(deltaTime, player.playerPosition, obstacles);
    if (enemy.numberOfSmallEnemies > 0)
    {
        enemy.UpdateSmallEnemiesWithObstacles(deltaTime, player.playerPosition, obstacles);
    }
    if (!enemy.isAnimatingExplode)
    {
        enemy.AnimateHit();
        enemy.ShootOneBulletBothColors(deltaTime);
        enemy.UpdateAllBullets(deltaTime);
    }
    CheckCollision();
    enemy.UpdateShield();

    if (player.health <= 0)
    {
        levelStatus = 2;
    }
    if (enemy.health <= 0)
    {
        levelStatus = 1;
    }
}

Level16::Level16() : player(50.f, -100.f, 900.f), enemy(1.f, 11)
{
    player.playerPosition = sf::Vector2f(500.f, 100.f);
    player.setPosition(player.playerPosition);
    player.setRotation(90.f);
    enemy.enemyPosition = sf::Vector2f(500.f, 470.f);
    enemy.setPosition(enemy.enemyPosition);
    enemy.shootingAngle = float(M_PI) / 6.f;
    levelStatus = 0;
    clearColor = DARK_COLOR;

    const std::vector<EnemyLevelData> enemyLevelData = {
        {{400.f, -50.f}, 55.f}, {{600.f, -50.f}, 125.f}, {{300.f, 0.f}, 30.f}, {{700.f, 0.f}, 150.f},
        {{300.f, 330.f}, -50.f}, {{500.f, 330.f}, -90.f}, {{700.f, 330.f}, -130.f}, {{200.f, 460.f}, -45.f},
        {{400.f, 460.f}, -80.f}, {{600.f, 460.f}, -100.f}, {{800.f, 460.f}, -135.f}
    };
    for (int i = 0; i < 11; ++i)
    {
        SmallEnemy smallEnemy(i, n_lastShot[i], 'f');
        smallEnemy.position = enemyLevelData[i].position;
        smallEnemy.setPosition(smallEnemy.position);
        smallEnemy.setRotation(enemyLevelData[i].rotation);
        enemy.smallEnemies.push_back(smallEnemy);
    }

    initLargeLevelMap(map, stars);
}

void Level16::Update(sf::RenderWindow& window, sf::View& view, sf::Clock& clock)
{
    deltaTime = clock.restart().asSeconds();
    player.Update(window, view, deltaTime);
    enemy.FollowSlowly(deltaTime, player.playerPosition);
    if (enemy.numberOfSmallEnemies > 0)
    {
        enemy.UpdateSmallEnemies(deltaTime, player.playerPosition);
    }
    if (!enemy.isAnimatingExplode)
    {
        enemy.AnimateHit();
        enemy.ConstantAngleShooting(deltaTime);
        enemy.UpdateAllBullets(deltaTime);
    }
    CheckCollision();
    enemy.UpdateShield();

    if (player.health <= 0)
    {
        levelStatus = 2;
    }
    if (enemy.health <= 0)
    {
        levelStatus = 1;
    }
}