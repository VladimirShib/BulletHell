#include "screens.h"

Menu::Menu()
{
    if (!font.loadFromFile("arial.ttf"))
    {
        perror("Couldn't load font \"arial\".");
    }

    title.setFont(font);
    title.setString("YORHA GAME");
    title.setCharacterSize(40);
    title.setPosition(sf::Vector2f(38, 60));
    title.setFillColor(sf::Color(0x50, 0x4E, 0x48));

    titleShadow.setFont(font);
    titleShadow.setString("YORHA GAME");
    titleShadow.setCharacterSize(40);
    titleShadow.setPosition(sf::Vector2f(43, 65));
    titleShadow.setFillColor(sf::Color(0x7C, 0x7B, 0x69, 0x80));

    menuPositions[0] = sf::Vector2f(114, 284);
    menuPositions[1] = sf::Vector2f(114, 336);
    menuPositions[2] = sf::Vector2f(114, 388);

    menuItem[0].setFont(font);
    menuItem[0].setString("Play");
    menuItem[0].setCharacterSize(22);
    menuItem[0].setPosition(menuPositions[0]);
    menuItem[0].setFillColor(sf::Color(0xC6, 0xC2, 0xA5));

    menuItem[1].setFont(font);
    menuItem[1].setString("Select level");
    menuItem[1].setCharacterSize(22);
    menuItem[1].setPosition(menuPositions[1]);
    menuItem[1].setFillColor(sf::Color(0x50, 0x4E, 0x48));

    menuItem[2].setFont(font);
    menuItem[2].setString("Exit game");
    menuItem[2].setCharacterSize(22);
    menuItem[2].setPosition(menuPositions[2]);
    menuItem[2].setFillColor(sf::Color(0x50, 0x4E, 0x48));

    selectedItemIndex = 0;

    background.setPrimitiveType(sf::Quads);
    // menu item bg
    background.append(sf::Vertex(sf::Vector2f(85, 282), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));
    background.append(sf::Vertex(sf::Vector2f(420, 282), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));
    background.append(sf::Vertex(sf::Vector2f(420, 314), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));
    background.append(sf::Vertex(sf::Vector2f(85, 314), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));
    // little square
    background.append(sf::Vertex(sf::Vector2f(93, 290), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(109, 290), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(109, 306), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(93, 306), sf::Color(0x50, 0x4E, 0x48)));
    
    background.append(sf::Vertex(sf::Vector2f(85, 334), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));
    background.append(sf::Vertex(sf::Vector2f(420, 334), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));
    background.append(sf::Vertex(sf::Vector2f(420, 366), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));
    background.append(sf::Vertex(sf::Vector2f(85, 366), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));

    background.append(sf::Vertex(sf::Vector2f(93, 342), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(109, 342), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(109, 358), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(93, 358), sf::Color(0x50, 0x4E, 0x48)));

    background.append(sf::Vertex(sf::Vector2f(85, 386), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));
    background.append(sf::Vertex(sf::Vector2f(420, 386), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));
    background.append(sf::Vertex(sf::Vector2f(420, 418), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));
    background.append(sf::Vertex(sf::Vector2f(85, 418), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));

    background.append(sf::Vertex(sf::Vector2f(93, 394), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(109, 394), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(109, 410), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(93, 410), sf::Color(0x50, 0x4E, 0x48)));
    // lines on the left
    background.append(sf::Vertex(sf::Vector2f(38, 280), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));
    background.append(sf::Vertex(sf::Vector2f(49, 280), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));
    background.append(sf::Vertex(sf::Vector2f(49, 420), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));
    background.append(sf::Vertex(sf::Vector2f(38, 420), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));

    background.append(sf::Vertex(sf::Vector2f(54, 280), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));
    background.append(sf::Vertex(sf::Vector2f(57, 280), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));
    background.append(sf::Vertex(sf::Vector2f(57, 420), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));
    background.append(sf::Vertex(sf::Vector2f(54, 420), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));
    // block shadow
    background.append(sf::Vertex(sf::Vector2f(41, 591), sf::Color(0x7C, 0x7B, 0x69, 0x80)));
    background.append(sf::Vertex(sf::Vector2f(965, 591), sf::Color(0x7C, 0x7B, 0x69, 0x80)));
    background.append(sf::Vertex(sf::Vector2f(965, 643), sf::Color(0x7C, 0x7B, 0x69, 0x80)));
    background.append(sf::Vertex(sf::Vector2f(41, 643), sf::Color(0x7C, 0x7B, 0x69, 0x80)));
    // block at the bottom
    background.append(sf::Vertex(sf::Vector2f(38, 588), sf::Color(0xD9, 0xD5, 0xB3)));
    background.append(sf::Vertex(sf::Vector2f(962, 588), sf::Color(0xD9, 0xD5, 0xB3)));
    background.append(sf::Vertex(sf::Vector2f(962, 640), sf::Color(0xD9, 0xD5, 0xB3)));
    background.append(sf::Vertex(sf::Vector2f(38, 640), sf::Color(0xD9, 0xD5, 0xB3)));
    // lines
    background.append(sf::Vertex(sf::Vector2f(38, 588), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(49, 588), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(49, 640), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(38, 640), sf::Color(0x50, 0x4E, 0x48)));

    background.append(sf::Vertex(sf::Vector2f(54, 588), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(57, 588), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(57, 640), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(54, 640), sf::Color(0x50, 0x4E, 0x48)));
    // select buttons bg
    background.append(sf::Vertex(sf::Vector2f(671, 604), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(691, 604), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(691, 624), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(671, 624), sf::Color(0x50, 0x4E, 0x48)));

    background.append(sf::Vertex(sf::Vector2f(701, 604), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(721, 604), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(721, 624), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(701, 624), sf::Color(0x50, 0x4E, 0x48)));
    // confirm button bg
    background.append(sf::Vertex(sf::Vector2f(813, 604), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(854, 604), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(854, 624), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(813, 624), sf::Color(0x50, 0x4E, 0x48)));

    selectButtons.setFont(font);
    selectButtons.setString("W     S");
    selectButtons.setCharacterSize(13);
    selectButtons.setPosition(sf::Vector2f(675, 605));
    selectButtons.setFillColor(sf::Color(0xD9, 0xD5, 0xB3));

    select.setFont(font);
    select.setString("Select");
    select.setCharacterSize(22);
    select.setPosition(sf::Vector2f(727, 600));
    select.setFillColor(sf::Color(0x50, 0x4E, 0x48));

    confirmButton.setFont(font);
    confirmButton.setString("Space");
    confirmButton.setCharacterSize(13);
    confirmButton.setPosition(sf::Vector2f(814, 605));
    confirmButton.setFillColor(sf::Color(0xD9, 0xD5, 0xB3));

    confirm.setFont(font);
    confirm.setString("Confirm");
    confirm.setCharacterSize(22);
    confirm.setPosition(sf::Vector2f(860, 600));
    confirm.setFillColor(sf::Color(0x50, 0x4E, 0x48));

    menuSelectedItem.setPosition(menuPositions[0]);
}

MenuSelectedItem::MenuSelectedItem()
{
    background.setPrimitiveType(sf::Quads);

    background.append(sf::Vertex(sf::Vector2f(-29, -7), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(306, -7), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(306, -5), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(-29, -5), sf::Color(0x50, 0x4E, 0x48)));
    // shadow
    background.append(sf::Vertex(sf::Vector2f(-27, 0), sf::Color(0x7C, 0x7B, 0x69, 0x80)));
    background.append(sf::Vertex(sf::Vector2f(308, 0), sf::Color(0x7C, 0x7B, 0x69, 0x80)));
    background.append(sf::Vertex(sf::Vector2f(308, 32), sf::Color(0x7C, 0x7B, 0x69, 0x80)));
    background.append(sf::Vertex(sf::Vector2f(-27, 32), sf::Color(0x7C, 0x7B, 0x69, 0x80)));

    background.append(sf::Vertex(sf::Vector2f(-29, -2), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(306, -2), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(306, 30), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(-29, 30), sf::Color(0x50, 0x4E, 0x48)));

    background.append(sf::Vertex(sf::Vector2f(-29, 33), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(306, 33), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(306, 35), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(-29, 35), sf::Color(0x50, 0x4E, 0x48)));
    // little square
    background.append(sf::Vertex(sf::Vector2f(-21, 6), sf::Color(0xD9, 0xD5, 0xB3)));
    background.append(sf::Vertex(sf::Vector2f(-5, 6), sf::Color(0xD9, 0xD5, 0xB3)));
    background.append(sf::Vertex(sf::Vector2f(-5, 22), sf::Color(0xD9, 0xD5, 0xB3)));
    background.append(sf::Vertex(sf::Vector2f(-21, 22), sf::Color(0xD9, 0xD5, 0xB3)));
}

void Menu::PollEvents(sf::RenderWindow& window, sf::Event& event, bool& isTransitioning, int& level)
{
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::KeyPressed:
            switch (event.key.code)
            {
            case sf::Keyboard::Up:
            case sf::Keyboard::W:
                this->MoveUp();
                break;
            case sf::Keyboard::Down:
            case sf::Keyboard::S:
                this->MoveDown();
                break;
            case sf::Keyboard::Return:
            case sf::Keyboard::Space:
                switch (this->GetPressedItem())
                {
                case 0:
                {
                    level = 0;
                    isTransitioning = true;
                }
                    break;
                case 1:
                    // level select
                    std::cout << "Select level button pressed\n";
                    break;
                case 2:
                    window.close();
                    break;
                default:
                    break;
                }
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
}

void Menu::MoveUp()
{
    menuItem[selectedItemIndex].setFillColor(sf::Color(0x50, 0x4E, 0x48));
    if (selectedItemIndex == 0)
    {
        selectedItemIndex = 2;
    }
    else
    {
        selectedItemIndex--;
    }
    menuItem[selectedItemIndex].setFillColor(sf::Color(0xC6, 0xC2, 0xA5));
    menuSelectedItem.setPosition(menuPositions[selectedItemIndex]);
}

void Menu::MoveDown()
{
    menuItem[selectedItemIndex].setFillColor(sf::Color(0x50, 0x4E, 0x48));
    if (selectedItemIndex == 2)
    {
        selectedItemIndex = 0;
    }
    else
    {
        selectedItemIndex++;
    }
    menuItem[selectedItemIndex].setFillColor(sf::Color(0xC6, 0xC2, 0xA5));
    menuSelectedItem.setPosition(menuPositions[selectedItemIndex]);
}

Transition::Transition()
{
    isTransitioning = false;
    screenOff = false;
    alpha = 0;
    transitionSpeed = 9;
    rectangle.setPrimitiveType(sf::TriangleStrip);

    rectangle.append(sf::Vertex(sf::Vector2f(0, 0), sf::Color(0, 0, 0, 0)));
    rectangle.append(sf::Vertex(sf::Vector2f(0, 700), sf::Color(0, 0, 0, 0)));
    rectangle.append(sf::Vertex(sf::Vector2f(1000, 0), sf::Color(0, 0, 0, 0)));
    rectangle.append(sf::Vertex(sf::Vector2f(1000, 700), sf::Color(0, 0, 0, 0)));
}

void Transition::FadingIn()
{
    if (alpha < 255)
    {
        alpha += transitionSpeed;
        if (alpha > 255)
        {
            alpha = 255;
            screenOff = true;
        }
    }

    for (int i = 0; i < 4; ++i)
    {
        rectangle[i].color = sf::Color(0, 0, 0, alpha);
    }
}

void Transition::FadingOut()
{
    if (alpha > 0)
    {
        alpha -= transitionSpeed;
        if (alpha < 0)
        {
            alpha = 0;
            isTransitioning = false;
            screenOff = false;
        }
    }

    for (int i = 0; i < 4; ++i)
    {
        rectangle[i].color = sf::Color(0, 0, 0, alpha);
    }
}

Pause::Pause()
{
    if (!font.loadFromFile("arial.ttf"))
    {
        perror("Couldn't load font \"arial\".");
    }
    background.setPrimitiveType(sf::Quads);

    // 1/10 of screen height
    background.append(sf::Vertex(sf::Vector2f(0, 0), sf::Color(0, 0, 0, 0xAA)));
    background.append(sf::Vertex(sf::Vector2f(1000, 0), sf::Color(0, 0, 0, 0xAA)));
    background.append(sf::Vertex(sf::Vector2f(1000, 70), sf::Color(0, 0, 0, 0xAA)));
    background.append(sf::Vertex(sf::Vector2f(0, 70), sf::Color(0, 0, 0, 0xAA)));

    background.append(sf::Vertex(sf::Vector2f(0, 70), sf::Color(0, 0, 0, 0x40)));
    background.append(sf::Vertex(sf::Vector2f(1000, 70), sf::Color(0, 0, 0, 0x40)));
    background.append(sf::Vertex(sf::Vector2f(1000, 630), sf::Color(0, 0, 0, 0x40)));
    background.append(sf::Vertex(sf::Vector2f(0, 630), sf::Color(0, 0, 0, 0x40)));

    background.append(sf::Vertex(sf::Vector2f(0, 630), sf::Color(0, 0, 0, 0xAA)));
    background.append(sf::Vertex(sf::Vector2f(1000, 630), sf::Color(0, 0, 0, 0xAA)));
    background.append(sf::Vertex(sf::Vector2f(1000, 700), sf::Color(0, 0, 0, 0xAA)));
    background.append(sf::Vertex(sf::Vector2f(0, 700), sf::Color(0, 0, 0, 0xAA)));
    // resume button bg
    background.append(sf::Vertex(sf::Vector2f(739, 650), sf::Color(0xC6, 0xC2, 0xA5)));
    background.append(sf::Vertex(sf::Vector2f(780, 650), sf::Color(0xC6, 0xC2, 0xA5)));
    background.append(sf::Vertex(sf::Vector2f(780, 670), sf::Color(0xC6, 0xC2, 0xA5)));
    background.append(sf::Vertex(sf::Vector2f(739, 670), sf::Color(0xC6, 0xC2, 0xA5)));
    // exit button bg
    background.append(sf::Vertex(sf::Vector2f(893, 650), sf::Color(0xC6, 0xC2, 0xA5)));
    background.append(sf::Vertex(sf::Vector2f(913, 650), sf::Color(0xC6, 0xC2, 0xA5)));
    background.append(sf::Vertex(sf::Vector2f(913, 670), sf::Color(0xC6, 0xC2, 0xA5)));
    background.append(sf::Vertex(sf::Vector2f(893, 670), sf::Color(0xC6, 0xC2, 0xA5)));

    paused.setFont(font);
    paused.setString("PAUSED");
    paused.setCharacterSize(40);
    paused.setPosition(sf::Vector2f(419, 275));
    paused.setFillColor(sf::Color(0xE6, 0xE4, 0xC4));

    resumeButton.setFont(font);
    resumeButton.setString("Esc");
    resumeButton.setCharacterSize(13);
    resumeButton.setPosition(sf::Vector2f(748, 651));
    resumeButton.setFillColor(sf::Color(0, 0, 0, 0xAA)); // same color as dark background
    
    resumeText.setFont(font);
    resumeText.setString("Resume");
    resumeText.setCharacterSize(22);
    resumeText.setPosition(sf::Vector2f(786, 646));
    resumeText.setFillColor(sf::Color(0xC6, 0xC2, 0xA5));

    exitButton.setFont(font);
    exitButton.setString("Q");
    exitButton.setCharacterSize(13);
    exitButton.setPosition(sf::Vector2f(898, 651));
    exitButton.setFillColor(sf::Color(0, 0, 0, 0xAA)); // same color as dark background
    
    exitText.setFont(font);
    exitText.setString("Exit");
    exitText.setCharacterSize(22);
    exitText.setPosition(sf::Vector2f(919, 646));
    exitText.setFillColor(sf::Color(0xC6, 0xC2, 0xA5));
}

Complete::Complete()
{
    isNotVisible = true;
    alphaDark = 0;
    alphaLight = 0;
    transitionSpeedDark = 5;
    transitionSpeedLight = 2;
    if (!font.loadFromFile("arial.ttf"))
    {
        perror("Couldn't load font \"arial\".");
    }
    background.setPrimitiveType(sf::Quads);

    // 1/10 of screen height
    background.append(sf::Vertex(sf::Vector2f(0, 0), sf::Color(0, 0, 0, 0)));
    background.append(sf::Vertex(sf::Vector2f(1000, 0), sf::Color(0, 0, 0, 0)));
    background.append(sf::Vertex(sf::Vector2f(1000, 70), sf::Color(0, 0, 0, 0)));
    background.append(sf::Vertex(sf::Vector2f(0, 70), sf::Color(0, 0, 0, 0)));

    background.append(sf::Vertex(sf::Vector2f(0, 70), sf::Color(0, 0, 0, 0)));
    background.append(sf::Vertex(sf::Vector2f(1000, 70), sf::Color(0, 0, 0, 0)));
    background.append(sf::Vertex(sf::Vector2f(1000, 630), sf::Color(0, 0, 0, 0)));
    background.append(sf::Vertex(sf::Vector2f(0, 630), sf::Color(0, 0, 0, 0)));

    background.append(sf::Vertex(sf::Vector2f(0, 630), sf::Color(0, 0, 0, 0)));
    background.append(sf::Vertex(sf::Vector2f(1000, 630), sf::Color(0, 0, 0, 0)));
    background.append(sf::Vertex(sf::Vector2f(1000, 700), sf::Color(0, 0, 0, 0)));
    background.append(sf::Vertex(sf::Vector2f(0, 700), sf::Color(0, 0, 0, 0)));

    levelComplete.setFont(font);
    levelComplete.setString("LEVEL COMPLETE");
    levelComplete.setCharacterSize(40);
    levelComplete.setPosition(sf::Vector2f(322, 275));
    levelComplete.setFillColor(sf::Color(0xE6, 0xE4, 0xC4));
}

void Complete::FadingIn()
{
    if (alphaDark < 170)
    {
        alphaDark += transitionSpeedDark;
        if (alphaDark >= 170)
        {
            alphaDark = 170;
            isNotVisible = false;
        }
        alphaLight += transitionSpeedLight;
        if (alphaLight >= 64)
        {
            alphaLight = 64;
        }
    }

    for (int i = 0; i < 4; ++i)
    {
        background[i].color = sf::Color(0, 0, 0, alphaDark);
        background[i + 4].color = sf::Color(0, 0, 0, alphaLight);
        background[i + 8].color = sf::Color(0, 0, 0, alphaDark);
    }
}

void Complete::Reset()
{
    isNotVisible = true;
    alphaDark = 0;
    alphaLight = 0;
    for (int i = 0; i < 12; ++i)
    {
        background[i].color = sf::Color(0, 0, 0, 0);
    }
}

Failed::Failed()
{
    isNotVisible = true;
    alphaDark = 0;
    alphaLight = 0;
    transitionSpeedDark = 5;
    transitionSpeedLight = 2;
    if (!font.loadFromFile("arial.ttf"))
    {
        perror("Couldn't load font \"arial\".");
    }
    background.setPrimitiveType(sf::Quads);

    // 1/10 of screen height
    background.append(sf::Vertex(sf::Vector2f(0, 0), sf::Color(0, 0, 0, 0)));
    background.append(sf::Vertex(sf::Vector2f(1000, 0), sf::Color(0, 0, 0, 0)));
    background.append(sf::Vertex(sf::Vector2f(1000, 70), sf::Color(0, 0, 0, 0)));
    background.append(sf::Vertex(sf::Vector2f(0, 70), sf::Color(0, 0, 0, 0)));

    background.append(sf::Vertex(sf::Vector2f(0, 70), sf::Color(0, 0, 0, 0)));
    background.append(sf::Vertex(sf::Vector2f(1000, 70), sf::Color(0, 0, 0, 0)));
    background.append(sf::Vertex(sf::Vector2f(1000, 630), sf::Color(0, 0, 0, 0)));
    background.append(sf::Vertex(sf::Vector2f(0, 630), sf::Color(0, 0, 0, 0)));

    background.append(sf::Vertex(sf::Vector2f(0, 630), sf::Color(0, 0, 0, 0)));
    background.append(sf::Vertex(sf::Vector2f(1000, 630), sf::Color(0, 0, 0, 0)));
    background.append(sf::Vertex(sf::Vector2f(1000, 700), sf::Color(0, 0, 0, 0)));
    background.append(sf::Vertex(sf::Vector2f(0, 700), sf::Color(0, 0, 0, 0)));

    levelFailed.setFont(font);
    levelFailed.setString("LEVEL FAILED");
    levelFailed.setCharacterSize(40);
    levelFailed.setPosition(sf::Vector2f(363, 275));
    levelFailed.setFillColor(sf::Color(0xE6, 0xE4, 0xC4));
}

void Failed::FadingIn()
{
    if (alphaDark < 170)
    {
        alphaDark += transitionSpeedDark;
        if (alphaDark >= 170)
        {
            alphaDark = 170;
            isNotVisible = false;
        }
        alphaLight += transitionSpeedLight;
        if (alphaLight >= 64)
        {
            alphaLight = 64;
        }
    }

    for (int i = 0; i < 4; ++i)
    {
        background[i].color = sf::Color(0, 0, 0, alphaDark);
        background[i + 4].color = sf::Color(0, 0, 0, alphaLight);
        background[i + 8].color = sf::Color(0, 0, 0, alphaDark);
    }
}

void Failed::Reset()
{
    isNotVisible = true;
    alphaDark = 0;
    alphaLight = 0;
    for (int i = 0; i < 12; ++i)
    {
        background[i].color = sf::Color(0, 0, 0, 0);
    }
}