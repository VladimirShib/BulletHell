#pragma once

class Field
{
public:
    bool contains(const sf::Vector2f& pos) const
    {
        return (pos.x > this->left && pos.x < this->right &&
                pos.y > this->top && pos.y < this->bottom);
    }
    
public:
    float left;
    float right;
    float top;
    float bottom;
};

class Obstacle
{
public:
    Obstacle(float x, float y, float width, float height, char t)
    {
        left = x;
        right = x + width;
        top = y;
        bottom = y + height;
        type = t;
    }

    bool contains(const float& posX, const float& posY) const
    {
        return (posX > this->left && posX < this->right &&
                posY > this->top && posY < this->bottom);
    }
    bool contains(const sf::Vector2f& pos) const
    {
        return (pos.x > this->left && pos.x < this->right &&
                pos.y > this->top && pos.y < this->bottom);
    }

public:
    float left;
    float right;
    float top;
    float bottom;
    char type;
};