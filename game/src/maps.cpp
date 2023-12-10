#include "maps.hpp"

namespace
{
    const sf::Color LIGHT_COLOR(0xC6, 0xC2, 0xA5);
    const sf::Color DARK_COLOR(0x50, 0x4E, 0x48);

    void constructSmallLevelMap(sf::VertexArray& vertices)
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

    void constructLargeLevelMap(sf::VertexArray& vertices, sf::VertexArray& stars)
    {
        vertices.setPrimitiveType(sf::Quads);
        vertices.append(sf::Vertex(sf::Vector2f(50.f, -100.f), sf::Color(0xC6, 0xC2, 0xA5)));
        vertices.append(sf::Vertex(sf::Vector2f(950.f, -100.f), sf::Color(0xC6, 0xC2, 0xA5)));
        vertices.append(sf::Vertex(sf::Vector2f(950.f, 800.f), sf::Color(0xC6, 0xC2, 0xA5)));
        vertices.append(sf::Vertex(sf::Vector2f(50.f, 800.f), sf::Color(0xC6, 0xC2, 0xA5)));

        stars.setPrimitiveType(sf::Triangles);
        const std::vector<sf::Vector2f> small = {
            {-330.f, -344.f}, {4.f, -182.f}, {-260.f, -46.f}, {-60.f, 130.f},
            {-334.f, 228.f}, {174.f, -370.f}, {434.f, -336.f}, {360.f, -120.f}
            // {.f, .f}, {.f, .f}, {.f, .f}, {.f, .f}
        };
        for (auto& point : small)
        {
            stars.append(sf::Vertex(point, sf::Color(0xFF, 0xFF, 0xFF)));
            stars.append(sf::Vertex(point + sf::Vector2f(1.f, -2.f), sf::Color(0xFF, 0xFF, 0xFF)));
            stars.append(sf::Vertex(point + sf::Vector2f(2.f, 0.f), sf::Color(0xFF, 0xFF, 0xFF)));
        }

        const std::vector<sf::Vector2f> medium = {
            {-32.f, -322.f}, {-236.f, -194.f}, {-125.f, 56.f}, {510.f, -190.f}
            // {.f, .f}, {.f, .f}, {.f, .f}, {.f, .f}
        };
        for (auto& point : medium)
        {
            stars.append(sf::Vertex(point, sf::Color(0xFF, 0xFF, 0xFF)));
            stars.append(sf::Vertex(point + sf::Vector2f(1.f, -3.f), sf::Color(0xFF, 0xFF, 0xFF)));
            stars.append(sf::Vertex(point + sf::Vector2f(4.f, -1.f), sf::Color(0xFF, 0xFF, 0xFF)));
        }

        const std::vector<sf::Vector2f> large = {
            {-104.f, -412.f}, {-350.f, 124.f}, {270.f, -248.f}
            // {.f, .f}, {.f, .f}, {.f, .f}, {.f, .f}
        };
        for (auto& point : large)
        {
            stars.append(sf::Vertex(point, sf::Color(0xFF, 0xFF, 0xFF)));
            stars.append(sf::Vertex(point + sf::Vector2f(6.f, -2.f), sf::Color(0xFF, 0xFF, 0xFF)));
            stars.append(sf::Vertex(point + sf::Vector2f(4.f, 4.f), sf::Color(0xFF, 0xFF, 0xFF)));
        }
    }
}

Level0::Level0() : player(275.f, 125.f, 450.f), enemy(0.5f)
// passing playing field parameters to player constructor and shooting delay to enemy constructor
{
    player.playerPosition = sf::Vector2f(500.f, 515.f);
    player.setPosition(player.playerPosition);
    player.setRotation(-90);
    enemy.enemyPosition = sf::Vector2f(500.f, 250.f);
    enemy.setPosition(enemy.enemyPosition);
    elapsedTime = 0.f;
    levelStatus = 0;
    clearColor = LIGHT_COLOR;

    constructSmallLevelMap(map);
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
    player.setRotation(-90);
    enemy.enemyPosition = sf::Vector2f(500.f, 250.f);
    enemy.setPosition(enemy.enemyPosition);
    elapsedTime = 45.f * (M_PI / 180.f);
    levelStatus = 0;
    clearColor = LIGHT_COLOR;

    constructSmallLevelMap(map);
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
    player.setRotation(-90);
    enemy.enemyPosition = sf::Vector2f(500.f, 200.f);
    enemy.setPosition(enemy.enemyPosition);
    elapsedTime = 90.0f * (M_PI / 180.f);
    levelStatus = 0;
    clearColor = LIGHT_COLOR;
    
    constructSmallLevelMap(map);
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
    player.setRotation(-90);
    enemy.enemyPosition = sf::Vector2f(500.f, 250.f);
    enemy.setPosition(enemy.enemyPosition);
    levelStatus = 0;
    clearColor = LIGHT_COLOR;
    
    constructSmallLevelMap(map);
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
    player.setRotation(-90);
    enemy.enemyPosition = sf::Vector2f(500.f, 250.f);
    enemy.setPosition(enemy.enemyPosition);
    levelStatus = 0;
    clearColor = LIGHT_COLOR;
    
    constructSmallLevelMap(map);
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
    player.setRotation(-90);
    enemy.enemyPosition = sf::Vector2f(500.f, 250.f);
    enemy.setPosition(enemy.enemyPosition);
    levelStatus = 0;
    clearColor = LIGHT_COLOR;
    
    constructSmallLevelMap(map);
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
    player.setRotation(-90);
    enemy.enemyPosition = sf::Vector2f(425.f, 250.f);
    enemy.setPosition(enemy.enemyPosition);
    elapsedTime = 0.f;
    levelStatus = 0;
    clearColor = LIGHT_COLOR;
    
    constructSmallLevelMap(map);
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
    player.setRotation(-90);
    enemy.enemyPosition = sf::Vector2f(500.f, 350.f);
    enemy.setPosition(enemy.enemyPosition);
    elapsedTime = 45.f * (M_PI / 180.f);
    levelStatus = 0;
    clearColor = LIGHT_COLOR;
    
    constructSmallLevelMap(map);
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
    player.setRotation(-90);
    enemy.enemyPosition = sf::Vector2f(500.f, 250.f);
    enemy.setPosition(enemy.enemyPosition);
    levelStatus = 0;
    clearColor = LIGHT_COLOR;
    
    constructSmallLevelMap(map);
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
    player.setRotation(-90);
    enemy.enemyPosition = sf::Vector2f(500.f, 250.f);
    enemy.setPosition(enemy.enemyPosition);
    levelStatus = 0;
    clearColor = LIGHT_COLOR;
    
    constructSmallLevelMap(map);
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

Level10::Level10() : player(50.f, -100.f, 900.f), enemy(0.5f)
{
    player.playerPosition = sf::Vector2f(500.f, 100.f);
    player.setPosition(player.playerPosition);
    player.setRotation(90);
    enemy.enemyPosition = sf::Vector2f(500.f, 420.f);
    enemy.setPosition(enemy.enemyPosition);
    levelStatus = 0;
    clearColor = DARK_COLOR;

    constructLargeLevelMap(map, stars);
}

void Level10::Update(sf::RenderWindow& window, sf::View& view, sf::Clock& clock)
{
    deltaTime = clock.restart().asSeconds();
    player.Update(window, view, deltaTime);
    enemy.FollowSlowly(deltaTime, player.playerPosition);
    if (!enemy.isAnimatingExplode)
    {
        enemy.AnimateHit();
        // enemy.ShootEightBulletsBothColors(deltaTime);
        // enemy.UpdateAllBullets(deltaTime);
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