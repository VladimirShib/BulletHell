#include "sound.h"

MusicManager::MusicManager()
{
    volume = 100.f;
    speed = 2.f;
    inProcess = true;

    if (!selectBuffer.loadFromFile("game/sounds/sfx/button_select.wav"))
    {
        std::cout << "Couldn't load sound \"button_select\".";
    }
    selectSound.setBuffer(selectBuffer);
    
    if (!pressBuffer.loadFromFile("game/sounds/sfx/button_press.wav"))
    {
        std::cout << "Couldn't load sound \"button_press\".";
    }
    pressSound.setBuffer(pressBuffer);

    mainMenuMusic = std::make_unique<sf::Music>();
    if (!mainMenuMusic->openFromFile("game/sounds/bgm/Blissful_Death.ogg"))
    {
        std::cout << "Couldn't load \"Blissful_Death\" song.";
    }
    mainMenuMusic->setLoop(true);
    songs.push_back(std::move(mainMenuMusic));

    gameMusic1 = std::make_unique<sf::Music>();
    if (!gameMusic1->openFromFile("game/sounds/bgm/A_Beautiful_Song.ogg"))
    {
        std::cout << "Couldn't load \"A_Beautiful_Song\" song.";
    }
    songs.push_back(std::move(gameMusic1));

    gameMusic2 = std::make_unique<sf::Music>();
    if (!gameMusic2->openFromFile("game/sounds/bgm/Amusement_Park.ogg"))
    {
        std::cout << "Couldn't load \"Amusement_Park\" song.";
    }
    songs.push_back(std::move(gameMusic2));

    // if (!gameMusic3.openFromFile("game/sounds/bgm/Birth_Of_A_Wish.ogg"))
    // {
    //     std::cout << "Couldn't load \"Birth_Of_A_Wish\" song.";
    // }

    // if (!gameMusic4.openFromFile("game/sounds/bgm/City_Ruins.ogg"))
    // {
    //     std::cout << "Couldn't load \"City_Ruins\" song.";
    // }

    // if (!gameMusic5.openFromFile("game/sounds/bgm/Dark_Colossus_Kaiju.ogg"))
    // {
    //     std::cout << "Couldn't load \"Dark_Colossus_Kaiju\" song.";
    // }

    // if (!gameMusic6.openFromFile("game/sounds/bgm/Dependent_Weakling.ogg"))
    // {
    //     std::cout << "Couldn't load \"Dependent_Weakling\" song.";
    // }

    // if (!gameMusic7.openFromFile("game/sounds/bgm/Memories_Of_Dust.ogg"))
    // {
    //     std::cout << "Couldn't load \"Memories_Of_Dust\" song.";
    // }

    // if (!gameMusic8.openFromFile("game/sounds/bgm/Song_Of_The_Ancients.ogg"))
    // {
    //     std::cout << "Couldn't load \"Song_Of_The_Ancients\" song.";
    // }

    // if (!gameMusic9.openFromFile("game/sounds/bgm/War_To_War.ogg"))
    // {
    //     std::cout << "Couldn't load \"War_To_War\" song.";
    // }

    // if (!gameMusic10.openFromFile("game/sounds/bgm/Wretched_Weaponry.ogg"))
    // {
    //     std::cout << "Couldn't load \"Wretched_Weaponry\" song.";
    // }
}

void MusicManager::TurnOnMenuMusic()
{
    songs[0]->play();
}

// void MusicManager::FadeOut()

void MusicManager::StopMusic()
{
    songs[0]->stop();
}