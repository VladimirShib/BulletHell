#pragma once

#include "headers.h"

class MusicManager
{
public:
    MusicManager();

    void TurnOnMenuMusic();
    // void FadeOut();
    void StopMusic();

public:
    sf::Sound selectSound;
    sf::Sound pressSound;

    std::vector<std::unique_ptr<sf::Music>> songs;

private:
    float volume;
    float speed;
    bool inProcess;
    sf::SoundBuffer selectBuffer;
    sf::SoundBuffer pressBuffer;
    std::unique_ptr<sf::Music> mainMenuMusic;
    std::unique_ptr<sf::Music> gameMusic1;
    std::unique_ptr<sf::Music> gameMusic2;
};