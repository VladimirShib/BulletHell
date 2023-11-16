#include "sound.h"

MusicManager::MusicManager()
{
    const unsigned seed = unsigned(std::time(nullptr));
    rng.seed(seed);
    distribution = std::uniform_int_distribution(1, 10);

    volume = 100.f;
    speed = 2.f;
    inProcess = true;
    currentSong = nullptr;

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
    
    if (!pauseBuffer.loadFromFile("game/sounds/sfx/pause.wav"))
    {
        std::cout << "Couldn't load sound \"pause\".";
    }
    pauseSound.setBuffer(pauseBuffer);

    mainMenuMusic = std::make_shared<sf::Music>();
    if (!mainMenuMusic->openFromFile("game/sounds/bgm/Blissful_Death.ogg"))
    {
        std::cout << "Couldn't load \"Blissful_Death\" song.";
    }
    mainMenuMusic->setLoop(true);
    songs.push_back(std::move(mainMenuMusic));

    gameMusic1 = std::make_shared<sf::Music>();
    if (!gameMusic1->openFromFile("game/sounds/bgm/A_Beautiful_Song.ogg"))
    {
        std::cout << "Couldn't load \"A_Beautiful_Song\" song.";
    }
    songs.push_back(std::move(gameMusic1));

    gameMusic2 = std::make_shared<sf::Music>();
    if (!gameMusic2->openFromFile("game/sounds/bgm/Amusement_Park.ogg"))
    {
        std::cout << "Couldn't load \"Amusement_Park\" song.";
    }
    songs.push_back(std::move(gameMusic2));

    gameMusic3 = std::make_shared<sf::Music>();
    if (!gameMusic3->openFromFile("game/sounds/bgm/Birth_Of_A_Wish.ogg"))
    {
        std::cout << "Couldn't load \"Birth_Of_A_Wish\" song.";
    }
    songs.push_back(std::move(gameMusic3));

    gameMusic4 = std::make_shared<sf::Music>();
    if (!gameMusic4->openFromFile("game/sounds/bgm/City_Ruins.ogg"))
    {
        std::cout << "Couldn't load \"City_Ruins\" song.";
    }
    songs.push_back(std::move(gameMusic4));

    gameMusic5 = std::make_shared<sf::Music>();
    if (!gameMusic5->openFromFile("game/sounds/bgm/Dark_Colossus_Kaiju.ogg"))
    {
        std::cout << "Couldn't load \"Dark_Colossus_Kaiju\" song.";
    }
    songs.push_back(std::move(gameMusic5));

    gameMusic6 = std::make_shared<sf::Music>();
    if (!gameMusic6->openFromFile("game/sounds/bgm/Dependent_Weakling.ogg"))
    {
        std::cout << "Couldn't load \"Dependent_Weakling\" song.";
    }
    songs.push_back(std::move(gameMusic6));

    gameMusic7 = std::make_shared<sf::Music>();
    if (!gameMusic7->openFromFile("game/sounds/bgm/Memories_Of_Dust.ogg"))
    {
        std::cout << "Couldn't load \"Memories_Of_Dust\" song.";
    }
    songs.push_back(std::move(gameMusic7));

    gameMusic8 = std::make_shared<sf::Music>();
    if (!gameMusic8->openFromFile("game/sounds/bgm/Song_Of_The_Ancients.ogg"))
    {
        std::cout << "Couldn't load \"Song_Of_The_Ancients\" song.";
    }
    songs.push_back(std::move(gameMusic8));

    gameMusic9 = std::make_shared<sf::Music>();
    if (!gameMusic9->openFromFile("game/sounds/bgm/War_To_War.ogg"))
    {
        std::cout << "Couldn't load \"War_To_War\" song.";
    }
    songs.push_back(std::move(gameMusic9));

    gameMusic10 = std::make_shared<sf::Music>();
    if (!gameMusic10->openFromFile("game/sounds/bgm/Wretched_Weaponry.ogg"))
    {
        std::cout << "Couldn't load \"Wretched_Weaponry\" song.";
    }
    songs.push_back(std::move(gameMusic10));
}

void MusicManager::TurnOnMenuMusic()
{
    if (currentSong != nullptr)
    {
        currentSong->stop();
        volume = 100.f;
        currentSong->setVolume(volume);
    }
    currentSong = songs[0];
    currentSong->play();
}

void MusicManager::TurnOnNewSong()
{
    randomNumber = distribution(rng);
    if (randomNumber < songs.size())
    {
        nextSong = songs[randomNumber];
        nextSong->play();
    }
}

void MusicManager::FadeOut()
{
    volume -= speed;
    currentSong->setVolume(volume);
}

void MusicManager::TracksChanged()
{
    currentSong->stop();
    volume = 100.f;
    currentSong->setVolume(volume);
    currentSong = nextSong;
    nextSong = nullptr;
}

void MusicManager::TurnDown()
{
    volume = 50.f;
    currentSong->setVolume(volume);
}

void MusicManager::TurnUp()
{
    volume = 100.f;
    currentSong->setVolume(volume);
}

void MusicManager::StopMusic()
{
    currentSong->stop();
}