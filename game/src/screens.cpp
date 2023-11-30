#include "screens.h"

Menu::Menu()
{
    if (!font.loadFromFile("game/fonts/arial.ttf"))
    {
        std::cout << "Couldn't load font \"arial\".";
    }

    title.setFont(font);
    title.setString("YORHA GAME");
    title.setCharacterSize(40);
    title.setPosition(sf::Vector2f(38.f, 60.f));
    title.setFillColor(sf::Color(0x50, 0x4E, 0x48));

    titleShadow.setFont(font);
    titleShadow.setString("YORHA GAME");
    titleShadow.setCharacterSize(40);
    titleShadow.setPosition(sf::Vector2f(43.f, 65.f));
    titleShadow.setFillColor(sf::Color(0x7C, 0x7B, 0x69, 0x80));

    background.setPrimitiveType(sf::Quads);
    
    // block shadow
    background.append(sf::Vertex(sf::Vector2f(41.f, 591.f), sf::Color(0x7C, 0x7B, 0x69, 0x80)));
    background.append(sf::Vertex(sf::Vector2f(965.f, 591.f), sf::Color(0x7C, 0x7B, 0x69, 0x80)));
    background.append(sf::Vertex(sf::Vector2f(965.f, 643.f), sf::Color(0x7C, 0x7B, 0x69, 0x80)));
    background.append(sf::Vertex(sf::Vector2f(41.f, 643.f), sf::Color(0x7C, 0x7B, 0x69, 0x80)));
    // block at the bottom
    background.append(sf::Vertex(sf::Vector2f(38.f, 588.f), sf::Color(0xD9, 0xD5, 0xB3)));
    background.append(sf::Vertex(sf::Vector2f(962.f, 588.f), sf::Color(0xD9, 0xD5, 0xB3)));
    background.append(sf::Vertex(sf::Vector2f(962.f, 640.f), sf::Color(0xD9, 0xD5, 0xB3)));
    background.append(sf::Vertex(sf::Vector2f(38.f, 640.f), sf::Color(0xD9, 0xD5, 0xB3)));

    // lines
    background.append(sf::Vertex(sf::Vector2f(38.f, 588.f), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(49.f, 588.f), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(49.f, 640.f), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(38.f, 640.f), sf::Color(0x50, 0x4E, 0x48)));

    background.append(sf::Vertex(sf::Vector2f(54.f, 588.f), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(57.f, 588.f), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(57.f, 640.f), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(54.f, 640.f), sf::Color(0x50, 0x4E, 0x48)));
    // select buttons bg
    background.append(sf::Vertex(sf::Vector2f(671.f, 604.f), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(691.f, 604.f), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(691.f, 624.f), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(671.f, 624.f), sf::Color(0x50, 0x4E, 0x48)));

    background.append(sf::Vertex(sf::Vector2f(701.f, 604.f), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(721.f, 604.f), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(721.f, 624.f), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(701.f, 624.f), sf::Color(0x50, 0x4E, 0x48)));
    // confirm button bg
    background.append(sf::Vertex(sf::Vector2f(813.f, 604.f), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(854.f, 604.f), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(854.f, 624.f), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(813.f, 624.f), sf::Color(0x50, 0x4E, 0x48)));

    selectButtons.setFont(font);
    selectButtons.setString("W     S");
    selectButtons.setCharacterSize(13);
    selectButtons.setPosition(sf::Vector2f(675.f, 605.f));
    selectButtons.setFillColor(sf::Color(0xD9, 0xD5, 0xB3));

    select.setFont(font);
    select.setString("Select");
    select.setCharacterSize(22);
    select.setPosition(sf::Vector2f(727.f, 600.f));
    select.setFillColor(sf::Color(0x50, 0x4E, 0x48));

    confirmButton.setFont(font);
    confirmButton.setString("Space");
    confirmButton.setCharacterSize(13);
    confirmButton.setPosition(sf::Vector2f(814.f, 605.f));
    confirmButton.setFillColor(sf::Color(0xD9, 0xD5, 0xB3));

    confirm.setFont(font);
    confirm.setString("Confirm");
    confirm.setCharacterSize(22);
    confirm.setPosition(sf::Vector2f(860.f, 600.f));
    confirm.setFillColor(sf::Color(0x50, 0x4E, 0x48));
}

MainMenu::MainMenu()
{
    toSelection = false;

    if (!font.loadFromFile("game/fonts/arial.ttf"))
    {
        std::cout << "Couldn't load font \"arial\".";
    }

    menuPositions[0] = sf::Vector2f(114.f, 284.f);
    menuPositions[1] = sf::Vector2f(114.f, 336.f);
    menuPositions[2] = sf::Vector2f(114.f, 388.f);

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
    selectedItem.setPosition(menuPositions[selectedItemIndex]);

    background.setPrimitiveType(sf::Quads);

    // menu item bg
    background.append(sf::Vertex(sf::Vector2f(85.f, 282.f), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));
    background.append(sf::Vertex(sf::Vector2f(420.f, 282.f), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));
    background.append(sf::Vertex(sf::Vector2f(420.f, 314.f), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));
    background.append(sf::Vertex(sf::Vector2f(85.f, 314.f), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));
    // little square
    background.append(sf::Vertex(sf::Vector2f(93.f, 290.f), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(109.f, 290.f), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(109.f, 306.f), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(93.f, 306.f), sf::Color(0x50, 0x4E, 0x48)));
    
    background.append(sf::Vertex(sf::Vector2f(85.f, 334.f), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));
    background.append(sf::Vertex(sf::Vector2f(420.f, 334.f), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));
    background.append(sf::Vertex(sf::Vector2f(420.f, 366.f), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));
    background.append(sf::Vertex(sf::Vector2f(85.f, 366.f), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));

    background.append(sf::Vertex(sf::Vector2f(93.f, 342.f), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(109.f, 342.f), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(109.f, 358.f), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(93.f, 358.f), sf::Color(0x50, 0x4E, 0x48)));

    background.append(sf::Vertex(sf::Vector2f(85.f, 386.f), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));
    background.append(sf::Vertex(sf::Vector2f(420.f, 386.f), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));
    background.append(sf::Vertex(sf::Vector2f(420.f, 418.f), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));
    background.append(sf::Vertex(sf::Vector2f(85.f, 418.f), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));

    background.append(sf::Vertex(sf::Vector2f(93.f, 394.f), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(109.f, 394.f), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(109.f, 410.f), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(93.f, 410.f), sf::Color(0x50, 0x4E, 0x48)));
    // lines on the left
    background.append(sf::Vertex(sf::Vector2f(38.f, 280.f), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));
    background.append(sf::Vertex(sf::Vector2f(49.f, 280.f), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));
    background.append(sf::Vertex(sf::Vector2f(49.f, 420.f), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));
    background.append(sf::Vertex(sf::Vector2f(38.f, 420.f), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));

    background.append(sf::Vertex(sf::Vector2f(54.f, 280.f), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));
    background.append(sf::Vertex(sf::Vector2f(57.f, 280.f), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));
    background.append(sf::Vertex(sf::Vector2f(57.f, 420.f), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));
    background.append(sf::Vertex(sf::Vector2f(54.f, 420.f), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));
}

MainMenuSelectedItem::MainMenuSelectedItem()
{
    background.setPrimitiveType(sf::Quads);

    background.append(sf::Vertex(sf::Vector2f(-29.f, -7.f), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(306.f, -7.f), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(306.f, -5.f), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(-29.f, -5.f), sf::Color(0x50, 0x4E, 0x48)));
    // shadow
    background.append(sf::Vertex(sf::Vector2f(-27.f, 0.f), sf::Color(0x7C, 0x7B, 0x69, 0x80)));
    background.append(sf::Vertex(sf::Vector2f(308.f, 0.f), sf::Color(0x7C, 0x7B, 0x69, 0x80)));
    background.append(sf::Vertex(sf::Vector2f(308.f, 32.f), sf::Color(0x7C, 0x7B, 0x69, 0x80)));
    background.append(sf::Vertex(sf::Vector2f(-27.f, 32.f), sf::Color(0x7C, 0x7B, 0x69, 0x80)));

    background.append(sf::Vertex(sf::Vector2f(-29.f, -2.f), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(306.f, -2.f), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(306.f, 30.f), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(-29.f, 30.f), sf::Color(0x50, 0x4E, 0x48)));

    background.append(sf::Vertex(sf::Vector2f(-29.f, 33.f), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(306.f, 33.f), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(306.f, 35.f), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(-29.f, 35.f), sf::Color(0x50, 0x4E, 0x48)));
    // little square
    background.append(sf::Vertex(sf::Vector2f(-21.f, 6.f), sf::Color(0xD9, 0xD5, 0xB3)));
    background.append(sf::Vertex(sf::Vector2f(-5.f, 6.f), sf::Color(0xD9, 0xD5, 0xB3)));
    background.append(sf::Vertex(sf::Vector2f(-5.f, 22.f), sf::Color(0xD9, 0xD5, 0xB3)));
    background.append(sf::Vertex(sf::Vector2f(-21.f, 22.f), sf::Color(0xD9, 0xD5, 0xB3)));
}

void MainMenu::PollEvents(sf::RenderWindow& window, sf::Event& event, bool& isTransitioning, int& level, MusicManager& sounds)
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
                this->MoveUp(sounds);
                break;
            case sf::Keyboard::Down:
            case sf::Keyboard::S:
                this->MoveDown(sounds);
                break;
            case sf::Keyboard::Return:
            case sf::Keyboard::Space:
                switch (this->GetPressedItem())
                {
                case 0:
                {
                    level = 0;
                    isTransitioning = true;
                    sounds.pressSound.play();
                }
                    break;
                case 1:
                {
                    sounds.pressSound.play();
                    toSelection = true;
                }
                    break;
                case 2:
                {
                    sounds.StopMusic();
                    window.close();
                }
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

void MainMenu::MoveUp(MusicManager& sounds)
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
    selectedItem.setPosition(menuPositions[selectedItemIndex]);
    sounds.selectSound.play();
}

void MainMenu::MoveDown(MusicManager& sounds)
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
    selectedItem.setPosition(menuPositions[selectedItemIndex]);
    sounds.selectSound.play();
}

Selection::Selection()
{
    toMainMenu = false;

    if (!font.loadFromFile("game/fonts/arial.ttf"))
    {
        std::cout << "Couldn't load font \"arial\".";
    }

    menuPositions[0] = sf::Vector2f(114.f, 128.f);
    menuPositions[1] = sf::Vector2f(114.f, 180.f);
    menuPositions[2] = sf::Vector2f(114.f, 232.f);
    menuPositions[3] = sf::Vector2f(114.f, 284.f);
    menuPositions[4] = sf::Vector2f(114.f, 336.f);
    menuPositions[5] = sf::Vector2f(114.f, 388.f);
    menuPositions[6] = sf::Vector2f(114.f, 440.f);
    menuPositions[7] = sf::Vector2f(114.f, 492.f);

    menuItem[0].setFont(font);
    menuItem[0].setString("Level 1");
    menuItem[0].setCharacterSize(22);
    menuItem[0].setPosition(menuPositions[0]);
    menuItem[0].setFillColor(sf::Color(0xC6, 0xC2, 0xA5));

    for (int i = 1; i < MAX_SELECTION_MENU_ITEMS; ++i)
    {
        menuItem[i].setFont(font);
        menuItem[i].setString("Level " + std::to_string(i + 1));
        menuItem[i].setCharacterSize(22);
        menuItem[i].setPosition(menuPositions[i]);
        menuItem[i].setFillColor(sf::Color(0x50, 0x4E, 0x48));
    }

    selectedItemIndex = 0;
    selectedItem.setPosition(menuPositions[selectedItemIndex]);

    background.setPrimitiveType(sf::Quads);

    // menu items bg
    const std::vector<sf::Vector2f> itemPoints = {
        {85.f, 126.f}, {245.f, 126.f}, {245.f, 158.f}, {85.f, 158.f}, // first
        {85.f, 178.f}, {245.f, 178.f}, {245.f, 210.f}, {85.f, 210.f}, // second...
        {85.f, 230.f}, {245.f, 230.f}, {245.f, 262.f}, {85.f, 262.f},
        {85.f, 282.f}, {245.f, 282.f}, {245.f, 314.f}, {85.f, 314.f},
        {85.f, 334.f}, {245.f, 334.f}, {245.f, 366.f}, {85.f, 366.f},
        {85.f, 386.f}, {245.f, 386.f}, {245.f, 418.f}, {85.f, 418.f},
        {85.f, 438.f}, {245.f, 438.f}, {245.f, 470.f}, {85.f, 470.f},
        {85.f, 490.f}, {245.f, 490.f}, {245.f, 522.f}, {85.f, 522.f}
    };
    for (auto& point : itemPoints)
    {
        background.append(sf::Vertex(point, sf::Color(0xA9, 0xA3, 0x89, 0xC0)));
    }

    // little squares
    const std::vector<sf::Vector2f> squarePoints = {
        {93.f, 134.f}, {109.f, 134.f}, {109.f, 150.f}, {93.f, 150.f}, // first
        {93.f, 186.f}, {109.f, 186.f}, {109.f, 202.f}, {93.f, 202.f}, // second...
        {93.f, 238.f}, {109.f, 238.f}, {109.f, 254.f}, {93.f, 254.f},
        {93.f, 290.f}, {109.f, 290.f}, {109.f, 306.f}, {93.f, 306.f},
        {93.f, 342.f}, {109.f, 342.f}, {109.f, 358.f}, {93.f, 358.f},
        {93.f, 394.f}, {109.f, 394.f}, {109.f, 410.f}, {93.f, 410.f},
        {93.f, 446.f}, {109.f, 446.f}, {109.f, 462.f}, {93.f, 462.f},
        {93.f, 498.f}, {109.f, 498.f}, {109.f, 514.f}, {93.f, 514.f}
    };
    for (auto& point : squarePoints)
    {
        background.append(sf::Vertex(point, sf::Color(0x50, 0x4E, 0x48)));
    }

    // lines on the left
    background.append(sf::Vertex(sf::Vector2f(38.f, 124.f), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));
    background.append(sf::Vertex(sf::Vector2f(49.f, 124.f), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));
    background.append(sf::Vertex(sf::Vector2f(49.f, 524.f), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));
    background.append(sf::Vertex(sf::Vector2f(38.f, 524.f), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));

    background.append(sf::Vertex(sf::Vector2f(54.f, 124.f), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));
    background.append(sf::Vertex(sf::Vector2f(57.f, 124.f), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));
    background.append(sf::Vertex(sf::Vector2f(57.f, 524.f), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));
    background.append(sf::Vertex(sf::Vector2f(54.f, 524.f), sf::Color(0xA9, 0xA3, 0x89, 0xC0)));

    // back button bg
    background.append(sf::Vertex(sf::Vector2f(551.f, 604.f), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(592.f, 604.f), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(592.f, 624.f), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(551.f, 624.f), sf::Color(0x50, 0x4E, 0x48)));

    hintText.setFont(font);
    hintText.setString("Select a stage to play");
    hintText.setCharacterSize(22);
    hintText.setPosition(sf::Vector2f(81.f, 600.f));
    hintText.setFillColor(sf::Color(0x50, 0x4E, 0x48));

    backButton.setFont(font);
    backButton.setString("Esc");
    backButton.setCharacterSize(13);
    backButton.setPosition(sf::Vector2f(560.f, 605.f));
    backButton.setFillColor(sf::Color(0xD9, 0xD5, 0xB3));
    
    backText.setFont(font);
    backText.setString("Back");
    backText.setCharacterSize(22);
    backText.setPosition(sf::Vector2f(597.f, 600.f));
    backText.setFillColor(sf::Color(0x50, 0x4E, 0x48));
}

SelectionMenuSelectedItem::SelectionMenuSelectedItem()
{
    background.setPrimitiveType(sf::Quads);

    background.append(sf::Vertex(sf::Vector2f(-29.f, -7.f), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(131.f, -7.f), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(131.f, -5.f), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(-29.f, -5.f), sf::Color(0x50, 0x4E, 0x48)));
    // shadow
    background.append(sf::Vertex(sf::Vector2f(-27.f, 0.f), sf::Color(0x7C, 0x7B, 0x69, 0x80)));
    background.append(sf::Vertex(sf::Vector2f(133.f, 0.f), sf::Color(0x7C, 0x7B, 0x69, 0x80)));
    background.append(sf::Vertex(sf::Vector2f(133.f, 32.f), sf::Color(0x7C, 0x7B, 0x69, 0x80)));
    background.append(sf::Vertex(sf::Vector2f(-27.f, 32.f), sf::Color(0x7C, 0x7B, 0x69, 0x80)));

    background.append(sf::Vertex(sf::Vector2f(-29.f, -2.f), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(131.f, -2.f), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(131.f, 30.f), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(-29.f, 30.f), sf::Color(0x50, 0x4E, 0x48)));

    background.append(sf::Vertex(sf::Vector2f(-29.f, 33.f), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(131.f, 33.f), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(131.f, 35.f), sf::Color(0x50, 0x4E, 0x48)));
    background.append(sf::Vertex(sf::Vector2f(-29.f, 35.f), sf::Color(0x50, 0x4E, 0x48)));
    // little square
    background.append(sf::Vertex(sf::Vector2f(-21.f, 6.f), sf::Color(0xD9, 0xD5, 0xB3)));
    background.append(sf::Vertex(sf::Vector2f(-5.f, 6.f), sf::Color(0xD9, 0xD5, 0xB3)));
    background.append(sf::Vertex(sf::Vector2f(-5.f, 22.f), sf::Color(0xD9, 0xD5, 0xB3)));
    background.append(sf::Vertex(sf::Vector2f(-21.f, 22.f), sf::Color(0xD9, 0xD5, 0xB3)));
}

void Selection::PollEvents(sf::RenderWindow& window, sf::Event& event, bool& isTransitioning, int& level, MusicManager& sounds)
{
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::KeyPressed:
            switch (event.key.code)
            {
            case sf::Keyboard::Escape:
            {
                sounds.pressSound.play();
                toMainMenu = true;
            }
                break;
            case sf::Keyboard::Up:
            case sf::Keyboard::W:
                this->MoveUp(sounds);
                break;
            case sf::Keyboard::Down:
            case sf::Keyboard::S:
                this->MoveDown(sounds);
                break;
            case sf::Keyboard::Return:
            case sf::Keyboard::Space:
                switch (this->GetPressedItem())
                {
                case 0:
                {
                    level = 0;
                    isTransitioning = true;
                    sounds.pressSound.play();
                }
                    break;
                case 1:
                {
                    level = 1;
                    isTransitioning = true;
                    sounds.pressSound.play();
                }
                    break;
                case 2:
                {
                    level = 2;
                    isTransitioning = true;
                    sounds.pressSound.play();
                }
                    break;
                case 3:
                {
                    level = 3;
                    isTransitioning = true;
                    sounds.pressSound.play();
                }
                    break;
                case 4:
                {
                    std::cout << "Level 5\n";
                    sounds.pressSound.play();
                }
                    break;
                case 5:
                {
                    std::cout << "Level 6\n";
                    sounds.pressSound.play();
                }
                    break;
                case 6:
                {
                    std::cout << "Level 7\n";
                    sounds.pressSound.play();
                }
                    break;
                case 7:
                {
                    std::cout << "Level 8\n";
                    sounds.pressSound.play();
                }
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

void Selection::MoveUp(MusicManager& sounds)
{
    menuItem[selectedItemIndex].setFillColor(sf::Color(0x50, 0x4E, 0x48));
    if (selectedItemIndex == 0)
    {
        selectedItemIndex = 7;
    }
    else
    {
        selectedItemIndex--;
    }
    menuItem[selectedItemIndex].setFillColor(sf::Color(0xC6, 0xC2, 0xA5));
    selectedItem.setPosition(menuPositions[selectedItemIndex]);
    sounds.selectSound.play();
}

void Selection::MoveDown(MusicManager& sounds)
{
    menuItem[selectedItemIndex].setFillColor(sf::Color(0x50, 0x4E, 0x48));
    if (selectedItemIndex == 7)
    {
        selectedItemIndex = 0;
    }
    else
    {
        selectedItemIndex++;
    }
    menuItem[selectedItemIndex].setFillColor(sf::Color(0xC6, 0xC2, 0xA5));
    selectedItem.setPosition(menuPositions[selectedItemIndex]);
    sounds.selectSound.play();
}

Transition::Transition()
{
    isTransitioning = false;
    screenOff = false;
    alpha = 0;
    transitionSpeed = 9;
    rectangle.setPrimitiveType(sf::TriangleStrip);

    rectangle.append(sf::Vertex(sf::Vector2f(0.f, 0.f), sf::Color(0, 0, 0, 0)));
    rectangle.append(sf::Vertex(sf::Vector2f(0.f, 700.f), sf::Color(0, 0, 0, 0)));
    rectangle.append(sf::Vertex(sf::Vector2f(1000.f, 0.f), sf::Color(0, 0, 0, 0)));
    rectangle.append(sf::Vertex(sf::Vector2f(1000.f, 700.f), sf::Color(0, 0, 0, 0)));
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
    if (!font.loadFromFile("game/fonts/arial.ttf"))
    {
        std::cout << "Couldn't load font \"arial\".";
    }
    background.setPrimitiveType(sf::Quads);

    // 1/10 of screen height
    background.append(sf::Vertex(sf::Vector2f(0.f, 0.f), sf::Color(0, 0, 0, 0xAA)));
    background.append(sf::Vertex(sf::Vector2f(1000.f, 0.f), sf::Color(0, 0, 0, 0xAA)));
    background.append(sf::Vertex(sf::Vector2f(1000.f, 70.f), sf::Color(0, 0, 0, 0xAA)));
    background.append(sf::Vertex(sf::Vector2f(0.f, 70.f), sf::Color(0, 0, 0, 0xAA)));

    background.append(sf::Vertex(sf::Vector2f(0.f, 70.f), sf::Color(0, 0, 0, 0x40)));
    background.append(sf::Vertex(sf::Vector2f(1000.f, 70.f), sf::Color(0, 0, 0, 0x40)));
    background.append(sf::Vertex(sf::Vector2f(1000.f, 630.f), sf::Color(0, 0, 0, 0x40)));
    background.append(sf::Vertex(sf::Vector2f(0.f, 630.f), sf::Color(0, 0, 0, 0x40)));

    background.append(sf::Vertex(sf::Vector2f(0.f, 630.f), sf::Color(0, 0, 0, 0xAA)));
    background.append(sf::Vertex(sf::Vector2f(1000.f, 630.f), sf::Color(0, 0, 0, 0xAA)));
    background.append(sf::Vertex(sf::Vector2f(1000.f, 700.f), sf::Color(0, 0, 0, 0xAA)));
    background.append(sf::Vertex(sf::Vector2f(0.f, 700.f), sf::Color(0, 0, 0, 0xAA)));
    // resume button bg
    background.append(sf::Vertex(sf::Vector2f(739.f, 650.f), sf::Color(0xC6, 0xC2, 0xA5)));
    background.append(sf::Vertex(sf::Vector2f(780.f, 650.f), sf::Color(0xC6, 0xC2, 0xA5)));
    background.append(sf::Vertex(sf::Vector2f(780.f, 670.f), sf::Color(0xC6, 0xC2, 0xA5)));
    background.append(sf::Vertex(sf::Vector2f(739.f, 670.f), sf::Color(0xC6, 0xC2, 0xA5)));
    // exit button bg
    background.append(sf::Vertex(sf::Vector2f(893.f, 650.f), sf::Color(0xC6, 0xC2, 0xA5)));
    background.append(sf::Vertex(sf::Vector2f(913.f, 650.f), sf::Color(0xC6, 0xC2, 0xA5)));
    background.append(sf::Vertex(sf::Vector2f(913.f, 670.f), sf::Color(0xC6, 0xC2, 0xA5)));
    background.append(sf::Vertex(sf::Vector2f(893.f, 670.f), sf::Color(0xC6, 0xC2, 0xA5)));

    paused.setFont(font);
    paused.setString("PAUSED");
    paused.setCharacterSize(40);
    paused.setPosition(sf::Vector2f(419.f, 275.f));
    paused.setFillColor(sf::Color(0xE6, 0xE4, 0xC4));

    resumeButton.setFont(font);
    resumeButton.setString("Esc");
    resumeButton.setCharacterSize(13);
    resumeButton.setPosition(sf::Vector2f(748.f, 651.f));
    resumeButton.setFillColor(sf::Color(0, 0, 0, 0xAA)); // same color as dark background
    
    resumeText.setFont(font);
    resumeText.setString("Resume");
    resumeText.setCharacterSize(22);
    resumeText.setPosition(sf::Vector2f(786.f, 646.f));
    resumeText.setFillColor(sf::Color(0xC6, 0xC2, 0xA5));

    exitButton.setFont(font);
    exitButton.setString("Q");
    exitButton.setCharacterSize(13);
    exitButton.setPosition(sf::Vector2f(898.f, 651.f));
    exitButton.setFillColor(sf::Color(0, 0, 0, 0xAA)); // same color as dark background
    
    exitText.setFont(font);
    exitText.setString("Exit");
    exitText.setCharacterSize(22);
    exitText.setPosition(sf::Vector2f(919.f, 646.f));
    exitText.setFillColor(sf::Color(0xC6, 0xC2, 0xA5));
}

Complete::Complete()
{
    isNotVisible = true;
    alphaDark = 0;
    alphaLight = 0;
    transitionSpeedDark = 5;
    transitionSpeedLight = 2;
    if (!font.loadFromFile("game/fonts/arial.ttf"))
    {
        std::cout << "Couldn't load font \"arial\".";
    }
    background.setPrimitiveType(sf::Quads);

    // 1/10 of screen height
    background.append(sf::Vertex(sf::Vector2f(0.f, 0.f), sf::Color(0, 0, 0, 0)));
    background.append(sf::Vertex(sf::Vector2f(1000.f, 0.f), sf::Color(0, 0, 0, 0)));
    background.append(sf::Vertex(sf::Vector2f(1000.f, 70.f), sf::Color(0, 0, 0, 0)));
    background.append(sf::Vertex(sf::Vector2f(0.f, 70.f), sf::Color(0, 0, 0, 0)));

    background.append(sf::Vertex(sf::Vector2f(0.f, 70.f), sf::Color(0, 0, 0, 0)));
    background.append(sf::Vertex(sf::Vector2f(1000.f, 70.f), sf::Color(0, 0, 0, 0)));
    background.append(sf::Vertex(sf::Vector2f(1000.f, 630.f), sf::Color(0, 0, 0, 0)));
    background.append(sf::Vertex(sf::Vector2f(0.f, 630.f), sf::Color(0, 0, 0, 0)));

    background.append(sf::Vertex(sf::Vector2f(0.f, 630.f), sf::Color(0, 0, 0, 0)));
    background.append(sf::Vertex(sf::Vector2f(1000.f, 630.f), sf::Color(0, 0, 0, 0)));
    background.append(sf::Vertex(sf::Vector2f(1000.f, 700.f), sf::Color(0, 0, 0, 0)));
    background.append(sf::Vertex(sf::Vector2f(0.f, 700.f), sf::Color(0, 0, 0, 0)));

    levelComplete.setFont(font);
    levelComplete.setString("LEVEL COMPLETE");
    levelComplete.setCharacterSize(40);
    levelComplete.setPosition(sf::Vector2f(322.f, 275.f));
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
    if (!font.loadFromFile("game/fonts/arial.ttf"))
    {
        std::cout << "Couldn't load font \"arial\".";
    }
    background.setPrimitiveType(sf::Quads);

    // 1/10 of screen height
    background.append(sf::Vertex(sf::Vector2f(0.f, 0.f), sf::Color(0, 0, 0, 0)));
    background.append(sf::Vertex(sf::Vector2f(1000.f, 0.f), sf::Color(0, 0, 0, 0)));
    background.append(sf::Vertex(sf::Vector2f(1000.f, 70.f), sf::Color(0, 0, 0, 0)));
    background.append(sf::Vertex(sf::Vector2f(0.f, 70.f), sf::Color(0, 0, 0, 0)));

    background.append(sf::Vertex(sf::Vector2f(0.f, 70.f), sf::Color(0, 0, 0, 0)));
    background.append(sf::Vertex(sf::Vector2f(1000.f, 70.f), sf::Color(0, 0, 0, 0)));
    background.append(sf::Vertex(sf::Vector2f(1000.f, 630.f), sf::Color(0, 0, 0, 0)));
    background.append(sf::Vertex(sf::Vector2f(0.f, 630.f), sf::Color(0, 0, 0, 0)));

    background.append(sf::Vertex(sf::Vector2f(0.f, 630.f), sf::Color(0, 0, 0, 0)));
    background.append(sf::Vertex(sf::Vector2f(1000.f, 630.f), sf::Color(0, 0, 0, 0)));
    background.append(sf::Vertex(sf::Vector2f(1000.f, 700.f), sf::Color(0, 0, 0, 0)));
    background.append(sf::Vertex(sf::Vector2f(0.f, 700.f), sf::Color(0, 0, 0, 0)));

    levelFailed.setFont(font);
    levelFailed.setString("LEVEL FAILED");
    levelFailed.setCharacterSize(40);
    levelFailed.setPosition(sf::Vector2f(363.f, 275.f));
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