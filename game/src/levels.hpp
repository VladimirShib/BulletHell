#pragma once

#include "headers.hpp"
#include "screens.hpp"
#include "maps.hpp"

template <typename Level>
int playLevel(Level& level, sf::RenderWindow& window, sf::View& view, sf::Event& event, sf::Clock& clock, Screens& screens, MusicManager& sounds);
int loadLevel(sf::RenderWindow& window, sf::View& view, sf::Event& event, sf::Clock& clock, Screens& screens, MusicManager& sounds, const int& levelNumber);