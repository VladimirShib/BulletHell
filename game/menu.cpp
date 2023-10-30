#include "menu.h"

Menu::Menu()
{
    if (!font.loadFromFile("arial.ttf"))
    {
        perror("Couldn't load font \"arial\".");
    }

    menuPositions[0] = sf::Vector2f(200, 100);
    menuPositions[1] = sf::Vector2f(200, 200);
    menuPositions[2] = sf::Vector2f(200, 300);

    menu[0].setFont(font);
    menu[0].setString("Play");
    menu[0].setCharacterSize(40);
    menu[0].setPosition(menuPositions[0]);
    menu[0].setFillColor(sf::Color(0xC7, 0xC3, 0x9B));

    menu[1].setFont(font);
    menu[1].setString("Select level");
    menu[1].setCharacterSize(40);
    menu[1].setPosition(menuPositions[1]);
    menu[1].setFillColor(sf::Color(0x50, 0x4E, 0x48));

    menu[2].setFont(font);
    menu[2].setString("Exit game");
    menu[2].setCharacterSize(40);
    menu[2].setPosition(menuPositions[2]);
    menu[2].setFillColor(sf::Color(0x50, 0x4E, 0x48));

    selectedItemIndex = 0;

    menuAllBg.setPrimitiveType(sf::Triangles);

    menuAllBg.append(sf::Vertex(sf::Vector2f(180, 95), sf::Color(0xA9, 0xA3, 0x89)));
    menuAllBg.append(sf::Vertex(sf::Vector2f(180, 155), sf::Color(0xA9, 0xA3, 0x89)));
    menuAllBg.append(sf::Vertex(sf::Vector2f(600, 95), sf::Color(0xA9, 0xA3, 0x89)));
    menuAllBg.append(sf::Vertex(sf::Vector2f(600, 95), sf::Color(0xA9, 0xA3, 0x89)));
    menuAllBg.append(sf::Vertex(sf::Vector2f(600, 155), sf::Color(0xA9, 0xA3, 0x89)));
    menuAllBg.append(sf::Vertex(sf::Vector2f(180, 155), sf::Color(0xA9, 0xA3, 0x89)));
    
    menuAllBg.append(sf::Vertex(sf::Vector2f(180, 195), sf::Color(0xA9, 0xA3, 0x89)));
    menuAllBg.append(sf::Vertex(sf::Vector2f(180, 255), sf::Color(0xA9, 0xA3, 0x89)));
    menuAllBg.append(sf::Vertex(sf::Vector2f(600, 195), sf::Color(0xA9, 0xA3, 0x89)));
    menuAllBg.append(sf::Vertex(sf::Vector2f(600, 195), sf::Color(0xA9, 0xA3, 0x89)));
    menuAllBg.append(sf::Vertex(sf::Vector2f(600, 255), sf::Color(0xA9, 0xA3, 0x89)));
    menuAllBg.append(sf::Vertex(sf::Vector2f(180, 255), sf::Color(0xA9, 0xA3, 0x89)));

    menuAllBg.append(sf::Vertex(sf::Vector2f(180, 295), sf::Color(0xA9, 0xA3, 0x89)));
    menuAllBg.append(sf::Vertex(sf::Vector2f(180, 355), sf::Color(0xA9, 0xA3, 0x89)));
    menuAllBg.append(sf::Vertex(sf::Vector2f(600, 295), sf::Color(0xA9, 0xA3, 0x89)));
    menuAllBg.append(sf::Vertex(sf::Vector2f(600, 295), sf::Color(0xA9, 0xA3, 0x89)));
    menuAllBg.append(sf::Vertex(sf::Vector2f(600, 355), sf::Color(0xA9, 0xA3, 0x89)));
    menuAllBg.append(sf::Vertex(sf::Vector2f(180, 355), sf::Color(0xA9, 0xA3, 0x89)));

    menuSelectedBg.setPosition(menuPositions[0]);
}

MenuSelectedBg::MenuSelectedBg()
{
    background.setPrimitiveType(sf::Triangles);

    background.append(sf::Vertex(sf::Vector2f(-20, -12), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(-20, -10), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(400, -12), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(400, -12), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(400, -10), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(-20, -10), sf::Color(0x50, 0x4E, 0x48)));

    background.append(sf::Vertex(sf::Vector2f(-20, -5), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(-20, 55), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(400, -5), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(400, -5), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(400, 55), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(-20, 55), sf::Color(0x50, 0x4E, 0x48)));

    background.append(sf::Vertex(sf::Vector2f(-20, 60), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(-20, 62), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(400, 60), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(400, 60), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(400, 62), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(-20, 62), sf::Color(0x50, 0x4E, 0x48)));
}

void Menu::MoveUp()
{
    menu[selectedItemIndex].setFillColor(sf::Color(0x50, 0x4E, 0x48));
    if (selectedItemIndex == 0)
    {
        selectedItemIndex = 2;
    }
    else
    {
        selectedItemIndex--;
    }
    menu[selectedItemIndex].setFillColor(sf::Color(0xC7, 0xC3, 0x9B));
    menuSelectedBg.setPosition(menuPositions[selectedItemIndex]);
}

void Menu::MoveDown()
{
    menu[selectedItemIndex].setFillColor(sf::Color(0x50, 0x4E, 0x48));
    if (selectedItemIndex == 2)
    {
        selectedItemIndex = 0;
    }
    else
    {
        selectedItemIndex++;
    }
    menu[selectedItemIndex].setFillColor(sf::Color(0xC7, 0xC3, 0x9B));
    menuSelectedBg.setPosition(menuPositions[selectedItemIndex]);
}