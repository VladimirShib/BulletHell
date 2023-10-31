#include "headers.h"
#include "screens.h"

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

    menuAllBg.setPrimitiveType(sf::Quads);

    menuAllBg.append(sf::Vertex(sf::Vector2f(180, 95), sf::Color(0xA9, 0xA3, 0x89)));
    menuAllBg.append(sf::Vertex(sf::Vector2f(600, 95), sf::Color(0xA9, 0xA3, 0x89)));
    menuAllBg.append(sf::Vertex(sf::Vector2f(600, 155), sf::Color(0xA9, 0xA3, 0x89)));
    menuAllBg.append(sf::Vertex(sf::Vector2f(180, 155), sf::Color(0xA9, 0xA3, 0x89)));
    
    menuAllBg.append(sf::Vertex(sf::Vector2f(180, 195), sf::Color(0xA9, 0xA3, 0x89)));
    menuAllBg.append(sf::Vertex(sf::Vector2f(600, 195), sf::Color(0xA9, 0xA3, 0x89)));
    menuAllBg.append(sf::Vertex(sf::Vector2f(600, 255), sf::Color(0xA9, 0xA3, 0x89)));
    menuAllBg.append(sf::Vertex(sf::Vector2f(180, 255), sf::Color(0xA9, 0xA3, 0x89)));

    menuAllBg.append(sf::Vertex(sf::Vector2f(180, 295), sf::Color(0xA9, 0xA3, 0x89)));
    menuAllBg.append(sf::Vertex(sf::Vector2f(600, 295), sf::Color(0xA9, 0xA3, 0x89)));
    menuAllBg.append(sf::Vertex(sf::Vector2f(600, 355), sf::Color(0xA9, 0xA3, 0x89)));
    menuAllBg.append(sf::Vertex(sf::Vector2f(180, 355), sf::Color(0xA9, 0xA3, 0x89)));

    menuSelectedBg.setPosition(menuPositions[0]);
}

MenuSelectedBg::MenuSelectedBg()
{
    background.setPrimitiveType(sf::Quads);

    background.append(sf::Vertex(sf::Vector2f(-20, -12), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(400, -12), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(400, -10), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(-20, -10), sf::Color(0x50, 0x4E, 0x48)));

    background.append(sf::Vertex(sf::Vector2f(-20, -5), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(400, -5), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(400, 55), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(-20, 55), sf::Color(0x50, 0x4E, 0x48)));

    background.append(sf::Vertex(sf::Vector2f(-20, 60), sf::Color(0x50, 0x4E, 0x48)));
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

Transition::Transition()
{
    rectangle.setPrimitiveType(sf::TriangleStrip);

    rectangle.append(sf::Vertex(sf::Vector2f(0, 0), sf::Color(0, 0, 0, 0)));
    rectangle.append(sf::Vertex(sf::Vector2f(0, 600), sf::Color(0, 0, 0, 0)));
    rectangle.append(sf::Vertex(sf::Vector2f(800, 0), sf::Color(0, 0, 0, 0)));
    rectangle.append(sf::Vertex(sf::Vector2f(800, 600), sf::Color(0, 0, 0, 0)));
}

void Transition::ToGame(GameState& gameState, sf::Clock& clock)
{
    if (fading)
    {
        alpha += 7;
        if (alpha >= 255)
        {
            alpha = 255;
            gameState.state = GameWindow::FADING_TO_GAME;
            fading = false;
        }
    }
    else
    {
        alpha -= 7;
        if (alpha <= 0)
        {
            alpha = 0;
            gameState.state = GameWindow::GAME;
            clock.restart();
        }
    }

    for (int i = 0; i < 4; ++i)
    {
        rectangle[i].color = sf::Color(0, 0, 0, alpha);
    }
}

Pause::Pause()
{
    background.setPrimitiveType(sf::Quads);

    // 1/10 of screen height
    background.append(sf::Vertex(sf::Vector2f(0, 0), sf::Color(0, 0, 0, 0xAA)));
    background.append(sf::Vertex(sf::Vector2f(800, 0), sf::Color(0, 0, 0, 0xAA)));
    background.append(sf::Vertex(sf::Vector2f(800, 60), sf::Color(0, 0, 0, 0xAA)));
    background.append(sf::Vertex(sf::Vector2f(0, 60), sf::Color(0, 0, 0, 0xAA)));

    background.append(sf::Vertex(sf::Vector2f(0, 60), sf::Color(0, 0, 0, 0x40)));
    background.append(sf::Vertex(sf::Vector2f(800, 60), sf::Color(0, 0, 0, 0x40)));
    background.append(sf::Vertex(sf::Vector2f(800, 540), sf::Color(0, 0, 0, 0x40)));
    background.append(sf::Vertex(sf::Vector2f(0, 540), sf::Color(0, 0, 0, 0x40)));

    background.append(sf::Vertex(sf::Vector2f(0, 540), sf::Color(0, 0, 0, 0xAA)));
    background.append(sf::Vertex(sf::Vector2f(800, 540), sf::Color(0, 0, 0, 0xAA)));
    background.append(sf::Vertex(sf::Vector2f(800, 600), sf::Color(0, 0, 0, 0xAA)));
    background.append(sf::Vertex(sf::Vector2f(0, 600), sf::Color(0, 0, 0, 0xAA)));

    // for buttons
    background.append(sf::Vertex(sf::Vector2f(601, 555), sf::Color(0xC7, 0xC3, 0x9B)));
    background.append(sf::Vertex(sf::Vector2f(645, 555), sf::Color(0xC7, 0xC3, 0x9B)));
    background.append(sf::Vertex(sf::Vector2f(645, 577), sf::Color(0xC7, 0xC3, 0x9B)));
    background.append(sf::Vertex(sf::Vector2f(601, 577), sf::Color(0xC7, 0xC3, 0x9B)));

    background.append(sf::Vertex(sf::Vector2f(705, 555), sf::Color(0xC7, 0xC3, 0x9B)));
    background.append(sf::Vertex(sf::Vector2f(749, 555), sf::Color(0xC7, 0xC3, 0x9B)));
    background.append(sf::Vertex(sf::Vector2f(749, 577), sf::Color(0xC7, 0xC3, 0x9B)));
    background.append(sf::Vertex(sf::Vector2f(705, 577), sf::Color(0xC7, 0xC3, 0x9B)));

    if (!font.loadFromFile("arial.ttf"))
    {
        perror("Couldn't load font \"arial\".");
    }

    textCenter.setFont(font);
    textCenter.setString("Paused");
    textCenter.setCharacterSize(40);
    textCenter.setPosition({300, 300});
    textCenter.setFillColor(sf::Color(0xD4, 0xCD, 0xB1));
    //textCenter.setOutlineColor(sf::Color(0, 0, 0, 0xAA));
    //textCenter.setOutlineThickness(2);
    
    buttons.setFont(font);
    buttons.setString("Esc                  Q");
    buttons.setCharacterSize(15);
    buttons.setPosition({620, 558});
    buttons.setFillColor(sf::Color(0, 0, 0, 0xAA)); // same color as dark background
    
    actions.setFont(font);
    actions.setString("Back         Exit");
    actions.setCharacterSize(20);
    actions.setPosition({650, 555});
    actions.setFillColor(sf::Color(0xC7, 0xC3, 0x9B));
}