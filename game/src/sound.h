#pragma once

#include "headers.h"

class MusicManager
{
public:
    MusicManager();

    void TurnOnMenuMusic();
    void TurnOnNewSong();
    void FadeOut();
    void TracksChanged();
    void TurnDown();
    void TurnUp();
    void StopMusic();

public:
    sf::Sound selectSound;
    sf::Sound pressSound;
    sf::Sound pauseSound;

    std::vector<std::shared_ptr<sf::Music>> songs;

private:
    std::mt19937 rng;
    std::uniform_int_distribution<int> distribution;
    int currentSongNumber;
    int randomNumber;
    float volume;
    float speed;
    sf::SoundBuffer selectBuffer;
    sf::SoundBuffer pressBuffer;
    sf::SoundBuffer pauseBuffer;
    std::shared_ptr<sf::Music> currentSong;
    std::shared_ptr<sf::Music> nextSong;
    std::shared_ptr<sf::Music> mainMenuMusic;
    std::shared_ptr<sf::Music> gameMusic1;
    std::shared_ptr<sf::Music> gameMusic2;
    std::shared_ptr<sf::Music> gameMusic3;
    std::shared_ptr<sf::Music> gameMusic4;
    std::shared_ptr<sf::Music> gameMusic5;
    std::shared_ptr<sf::Music> gameMusic6;
    std::shared_ptr<sf::Music> gameMusic7;
    std::shared_ptr<sf::Music> gameMusic8;
    std::shared_ptr<sf::Music> gameMusic9;
    std::shared_ptr<sf::Music> gameMusic10;
};