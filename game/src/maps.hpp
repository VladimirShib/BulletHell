#pragma once

#include "headers.hpp"
#include "player.hpp"
#include "enemies.hpp"

class Level0 : public sf::Drawable
{
public:
    Level0();

    void Update(sf::RenderWindow& window, sf::View& view, sf::Clock& clock);
    void CheckCollision();

public:
    Player player;
    BallEnemy enemy;
    float deltaTime;
    float elapsedTime;
    int levelStatus; // 0 - in progress, 1 - complete, 2 - failed, 3 - exited on pause
    sf::Color clearColor;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(map, states);
        if (enemy.health > 0)
        {
            target.draw(enemy, states);
        }
        if (player.health > 0)
        {
            target.draw(player, states);
        }
    }

    sf::VertexArray map;
};

class Level1 : public sf::Drawable
{
public:
    Level1();

    void Update(sf::RenderWindow& window, sf::View& view, sf::Clock& clock);
    void CheckCollision();

public:
    Player player;
    BallEnemy enemy;
    float deltaTime;
    float elapsedTime;
    int levelStatus;
    sf::Color clearColor;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(map, states);
        if (enemy.health > 0)
        {
            target.draw(enemy, states);
        }
        if (player.health > 0)
        {
            target.draw(player, states);
        }
    }

    sf::VertexArray map;
};

class Level2 : public sf::Drawable
{
public:
    Level2();

    void Update(sf::RenderWindow& window, sf::View& view, sf::Clock& clock);
    void CheckCollision();

public:
    Player player;
    BallEnemy enemy;
    float deltaTime;
    float elapsedTime;
    int levelStatus;
    sf::Color clearColor;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(map, states);
        if (enemy.health > 0)
        {
            target.draw(enemy, states);
        }
        if (player.health > 0)
        {
            target.draw(player, states);
        }
    }

    sf::VertexArray map;
};

class Level3 : public sf::Drawable
{
public:
    Level3();

    void Update(sf::RenderWindow& window, sf::View& view, sf::Clock& clock);
    void CheckCollision();

public:
    Player player;
    BallEnemy enemy;
    float deltaTime;
    int levelStatus;
    sf::Color clearColor;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(map, states);
        if (enemy.health > 0)
        {
            target.draw(enemy, states);
        }
        if (player.health > 0)
        {
            target.draw(player, states);
        }
    }

    sf::VertexArray map;
};

class Level4 : public sf::Drawable
{
public:
    Level4();

    void Update(sf::RenderWindow& window, sf::View& view, sf::Clock& clock);
    void CheckCollision();

public:
    Player player;
    BallEnemy enemy;
    float deltaTime;
    int levelStatus;
    sf::Color clearColor;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(map, states);
        if (enemy.health > 0)
        {
            target.draw(enemy, states);
        }
        if (player.health > 0)
        {
            target.draw(player, states);
        }
    }

    sf::VertexArray map;
};

class Level5 : public sf::Drawable
{
public:
    Level5();

    void Update(sf::RenderWindow& window, sf::View& view, sf::Clock& clock);
    void CheckCollision();

public:
    Player player;
    BallEnemy enemy;
    float deltaTime;
    int levelStatus;
    sf::Color clearColor;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(map, states);
        if (enemy.health > 0)
        {
            target.draw(enemy, states);
        }
        if (player.health > 0)
        {
            target.draw(player, states);
        }
    }

    sf::VertexArray map;
};

class Level6 : public sf::Drawable
{
public:
    Level6();

    void Update(sf::RenderWindow& window, sf::View& view, sf::Clock& clock);
    void CheckCollision();

public:
    Player player;
    BallEnemy enemy;
    float deltaTime;
    float elapsedTime;
    int levelStatus;
    sf::Color clearColor;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(map, states);
        if (enemy.health > 0)
        {
            target.draw(enemy, states);
        }
        if (player.health > 0)
        {
            target.draw(player, states);
        }
    }

    sf::VertexArray map;
};

class Level7 : public sf::Drawable
{
public:
    Level7();

    void Update(sf::RenderWindow& window, sf::View& view, sf::Clock& clock);
    void CheckCollision();

public:
    Player player;
    BallEnemy enemy;
    float deltaTime;
    float elapsedTime;
    int levelStatus;
    sf::Color clearColor;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(map, states);
        if (enemy.health > 0)
        {
            target.draw(enemy, states);
        }
        if (player.health > 0)
        {
            target.draw(player, states);
        }
    }

    sf::VertexArray map;
};

class Level8 : public sf::Drawable
{
public:
    Level8();

    void Update(sf::RenderWindow& window, sf::View& view, sf::Clock& clock);
    void CheckCollision();

public:
    Player player;
    BallEnemy enemy;
    float deltaTime;
    int levelStatus;
    sf::Color clearColor;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(map, states);
        if (enemy.health > 0)
        {
            target.draw(enemy, states);
        }
        if (player.health > 0)
        {
            target.draw(player, states);
        }
    }

    sf::VertexArray map;
};

class Level9 : public sf::Drawable
{
public:
    Level9();

    void Update(sf::RenderWindow& window, sf::View& view, sf::Clock& clock);
    void CheckCollision();

public:
    Player player;
    BallEnemy enemy;
    float deltaTime;
    int levelStatus;
    sf::Color clearColor;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(map, states);
        if (enemy.health > 0)
        {
            target.draw(enemy, states);
        }
        if (player.health > 0)
        {
            target.draw(player, states);
        }
    }

    sf::VertexArray map;
};

class Level10 : public sf::Drawable
{
public:
    Level10();

    void Update(sf::RenderWindow& window, sf::View& view, sf::Clock& clock);
    void CheckCollision();

public:
    Player player;
    ShieldedBallWithSmallEnemies enemy;
    float deltaTime;
    int levelStatus;
    sf::Color clearColor;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(map, states);
        target.draw(stars, states);
        if (enemy.health > 0)
        {
            target.draw(enemy, states);
        }
        if (player.health > 0)
        {
            target.draw(player, states);
        }
    }

    sf::VertexArray map;
    sf::VertexArray stars;
};

class Level11 : public sf::Drawable
{
public:
    Level11();

    void Update(sf::RenderWindow& window, sf::View& view, sf::Clock& clock);
    void CheckCollision();

public:
    Player player;
    ShieldedBallWithSmallEnemies enemy;
    float deltaTime;
    int levelStatus;
    sf::Color clearColor;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(map, states);
        target.draw(stars, states);
        if (enemy.health > 0)
        {
            target.draw(enemy, states);
        }
        if (player.health > 0)
        {
            target.draw(player, states);
        }
    }

    sf::VertexArray map;
    sf::VertexArray stars;
};

class Level12 : public sf::Drawable
{
public:
    Level12();

    void Update(sf::RenderWindow& window, sf::View& view, sf::Clock& clock);
    void CheckCollision();

public:
    Player player;
    ShieldedBallWithSmallEnemies enemy;
    AdditionalEnemy secondEnemy;
    std::vector<sf::FloatRect> playerObstacles;
    std::vector<sf::FloatRect> obstacles;
    float deltaTime;
    int levelStatus;
    sf::Color clearColor;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(map, states);
        target.draw(stars, states);
        if (enemy.health > 0)
        {
            target.draw(enemy, states);
        }
        else if (secondEnemy.health > 0)
        {
            for (const OrangeBullet& bullet : enemy.orangeBullets)
            {
                target.draw(bullet);
            }
            for (const PurpleBullet& bullet : enemy.purpleBullets)
            {
                target.draw(bullet);
            }
        }
        if (secondEnemy.health > 0)
        {
            target.draw(secondEnemy, states);
        }
        if (player.health > 0)
        {
            target.draw(player, states);
        }
    }

    sf::VertexArray map;
    sf::VertexArray stars;
};

class Level13 : public sf::Drawable
{
public:
    Level13();

    void Update(sf::RenderWindow& window, sf::View& view, sf::Clock& clock);
    void CheckCollision();

public:
    Player player;
    ShieldedBallWithSmallEnemies enemy;
    float deltaTime;
    int levelStatus;
    sf::Color clearColor;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(map, states);
        target.draw(stars, states);
        if (enemy.health > 0)
        {
            target.draw(enemy, states);
        }
        if (player.health > 0)
        {
            target.draw(player, states);
        }
    }

    sf::VertexArray map;
    sf::VertexArray stars;
};

class Level14 : public sf::Drawable
{
public:
    Level14();

    void Update(sf::RenderWindow& window, sf::View& view, sf::Clock& clock);
    void CheckCollision();

public:
    Player player;
    ShieldedBallWithSmallEnemies enemy;
    std::vector<sf::FloatRect> playerObstacles;
    std::vector<sf::FloatRect> obstacles;
    float deltaTime;
    int levelStatus;
    sf::Color clearColor;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(map, states);
        target.draw(stars, states);
        if (enemy.health > 0)
        {
            target.draw(enemy, states);
        }
        if (player.health > 0)
        {
            target.draw(player, states);
        }
    }

    sf::VertexArray map;
    sf::VertexArray stars;
};

class Level15 : public sf::Drawable
{
public:
    Level15();

    void Update(sf::RenderWindow& window, sf::View& view, sf::Clock& clock);
    void CheckCollision();

public:
    Player player;
    ShieldedBallWithSmallEnemies enemy;
    std::vector<sf::FloatRect> playerObstacles;
    std::vector<sf::FloatRect> obstacles;
    float deltaTime;
    int levelStatus;
    sf::Color clearColor;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(map, states);
        target.draw(stars, states);
        if (enemy.health > 0)
        {
            target.draw(enemy, states);
        }
        if (player.health > 0)
        {
            target.draw(player, states);
        }
    }

    sf::VertexArray map;
    sf::VertexArray stars;
};

class Level16 : public sf::Drawable
{
public:
    Level16();

    void Update(sf::RenderWindow& window, sf::View& view, sf::Clock& clock);
    void CheckCollision();

public:
    Player player;
    ShieldedBallWithSmallEnemies enemy;
    float deltaTime;
    int levelStatus;
    sf::Color clearColor;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(map, states);
        target.draw(stars, states);
        if (enemy.health > 0)
        {
            target.draw(enemy, states);
        }
        if (player.health > 0)
        {
            target.draw(player, states);
        }
    }

    sf::VertexArray map;
    sf::VertexArray stars;
};