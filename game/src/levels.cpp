#include "levels.hpp"

void checkForEscPress(sf::RenderWindow& window, sf::Event& event, sf::Clock& clock, bool& isPaused, MusicManager& sounds)
{
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Escape)
            {
                isPaused = true;
                sounds.pauseSound.play();
                sounds.TurnDown();
            }
        }
    }
}

template <typename Level>
void handlePause(sf::RenderWindow& window, sf::View& view, sf::Event& event, sf::Clock& clock, Screens& screens, Level& level, bool& isPaused, MusicManager& sounds)
{
    window.setView(window.getDefaultView());
    window.draw(screens.pause);
    window.display();
    while (isPaused)
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    isPaused = false;
                    sounds.pressSound.play();
                    sounds.TurnUp();
                    clock.restart();
                    return;
                }
                else if (event.key.code == sf::Keyboard::Q)
                {
                    screens.transition.isTransitioning = true;
                    sounds.pressSound.play();
                    while (screens.transition.isTransitioning)
                    {
                        screens.transition.FadingIn();
                        window.clear(level.clearColor);
                        window.setView(view);
                        window.draw(level);
                        window.setView(window.getDefaultView());
                        window.draw(screens.pause);
                        window.draw(screens.transition);
                        if (screens.transition.screenOff)
                        {
                            level.levelStatus = 3;
                            return;
                        }
                        window.display();
                    }
                }
            }
        }
    }
}

template <typename Level>
void showCompleteScreen(sf::RenderWindow& window, sf::View& view, sf::Clock& clock, Screens& screens, Level& level, MusicManager& sounds)
{
    float waitTime = 0.f;
    while (window.isOpen())
    {
        waitTime = clock.getElapsedTime().asSeconds();
        window.clear(level.clearColor);
        window.draw(level);
        if (screens.complete.isNotVisible)
        {
            screens.complete.FadingIn();
        }
        window.setView(window.getDefaultView());
        window.draw(screens.complete);
        if (waitTime > 2.f)
        {
            screens.transition.FadingIn();
            window.draw(screens.transition);
            sounds.FadeOut();
            if (screens.transition.screenOff)
            {
                screens.complete.Reset();
                screens.transition.isTransitioning = true;
                return;
            }
        }
        window.display();
        window.setView(view);
    }
}

template <typename Level>
void showFailedScreen(sf::RenderWindow& window, sf::View& view, sf::Clock& clock, Screens& screens, Level& level, MusicManager& sounds)
{
    float waitTime = 0.f;
    while (window.isOpen())
    {
        waitTime = clock.getElapsedTime().asSeconds();
        window.clear(level.clearColor);
        window.draw(level);
        if (screens.failed.isNotVisible)
        {
            screens.failed.FadingIn();
        }
        window.setView(window.getDefaultView());
        window.draw(screens.failed);
        if (waitTime > 2.f)
        {
            screens.transition.FadingIn();
            window.draw(screens.transition);
            sounds.FadeOut();
            if (screens.transition.screenOff)
            {
                screens.failed.Reset();
                screens.transition.isTransitioning = true;
                return;
            }
        }
        window.display();
        window.setView(view);
    }
}

int loadLevel(sf::RenderWindow& window, sf::View& view, sf::Event& event, sf::Clock& clock, Screens& screens, MusicManager& sounds, const int& levelNumber)
{
    switch (levelNumber)
    {
    case 0:
    {
        Level0 level0;
        playLevel(level0, window, view, event, clock, screens, sounds);
        return level0.levelStatus;
    }
    case 1:
    {
        Level1 level1;
        playLevel(level1, window, view, event, clock, screens, sounds);
        return level1.levelStatus;
    }
    case 2:
    {
        Level2 level2;
        playLevel(level2, window, view, event, clock, screens, sounds);
        return level2.levelStatus;
    }
    case 3:
    {
        Level3 level3;
        playLevel(level3, window, view, event, clock, screens, sounds);
        return level3.levelStatus;
    }
    case 4:
    {
        Level4 level4;
        playLevel(level4, window, view, event, clock, screens, sounds);
        return level4.levelStatus;
    }
    case 5:
    {
        Level5 level5;
        playLevel(level5, window, view, event, clock, screens, sounds);
        return level5.levelStatus;
    }
    case 6:
    {
        Level6 level6;
        playLevel(level6, window, view, event, clock, screens, sounds);
        return level6.levelStatus;
    }
    case 7:
    {
        Level7 level7;
        playLevel(level7, window, view, event, clock, screens, sounds);
        return level7.levelStatus;
    }
    case 8:
    {
        Level8 level8;
        playLevel(level8, window, view, event, clock, screens, sounds);
        return level8.levelStatus;
    }
    case 9:
    {
        Level9 level9;
        playLevel(level9, window, view, event, clock, screens, sounds);
        return level9.levelStatus;
    }
    case 10:
    {
        Level10 level10;
        playLevel(level10, window, view, event, clock, screens, sounds);
        return level10.levelStatus;
    }
    case 11:
    {
        Level11 level11;
        playLevel(level11, window, view, event, clock, screens, sounds);
        return level11.levelStatus;
    }
    case 12:
    {
        Level12 level12;
        playLevel(level12, window, view, event, clock, screens, sounds);
        return level12.levelStatus;
    }
    case 13:
    {
        Level13 level13;
        playLevel(level13, window, view, event, clock, screens, sounds);
        return level13.levelStatus;
    }
    case 14:
    {
        Level14 level14;
        playLevel(level14, window, view, event, clock, screens, sounds);
        return level14.levelStatus;
    }
    default:
        std::cout << "Couldn't load level\n";
        return 3;
    }
}

template <typename Level>
int playLevel(Level& level, sf::RenderWindow& window, sf::View& view, sf::Event& event, sf::Clock& clock, Screens& screens, MusicManager& sounds)
{
    bool isPaused = false;

    sounds.TurnOnNewSong();
    view.setCenter(level.player.playerPosition);
    while (screens.transition.isTransitioning)
    {
        screens.transition.FadingOut();
        window.clear(level.clearColor);
        window.setView(view);
        window.draw(level);
        window.setView(window.getDefaultView());
        window.draw(screens.transition);
        window.display();
        sounds.FadeOut();
    }
    sounds.TracksChanged();
    clock.restart();
    while (window.isOpen() && level.levelStatus == 0)
    {
        level.Update(window, view, clock);
        window.clear(level.clearColor);
        window.setView(view);
        window.draw(level);
        window.display();
        checkForEscPress(window, event, clock, isPaused, sounds);
        if (isPaused)
        {
            handlePause(window, view, event, clock, screens, level, isPaused, sounds);
        }
    }

    switch (level.levelStatus)
    {
    case 1:
        showCompleteScreen(window, view, clock, screens, level, sounds);
        break;
    case 2:
        showFailedScreen(window, view, clock, screens, level, sounds);
        break;
    default:
        break;
    }
}