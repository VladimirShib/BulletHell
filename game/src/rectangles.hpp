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

class Obstacle : public sf::Drawable, public sf::Transformable
{
public:
    Obstacle(float x, float y, float width, float height, char t)
    {
        left = x;
        right = x + width;
        top = y;
        bottom = y + height;
        type = t;
        hit = false;

        if (t == 'b') // black
        {
            health = 5;
            vertices.setPrimitiveType(sf::Quads);
            vertices.append(sf::Vertex(sf::Vector2f(0.f, 0.f), sf::Color(0x50, 0x4E, 0x48)));
            vertices.append(sf::Vertex(sf::Vector2f(50.f, 0.f), sf::Color(0x50, 0x4E, 0x48)));
            vertices.append(sf::Vertex(sf::Vector2f(50.f, 50.f), sf::Color(0x50, 0x4E, 0x48)));
            vertices.append(sf::Vertex(sf::Vector2f(0.f, 50.f), sf::Color(0x50, 0x4E, 0x48)));

            this->setPosition(x, y);
        }
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
    void GotHit()
    {
        if (health > 1)
        {
            health--;
        }
        else
        {
            hit = true;
        }
    }

public:
    float left;
    float right;
    float top;
    float bottom;
    char type;
    int health;
    bool hit;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        target.draw(vertices, states);
    }

    sf::VertexArray vertices;
};