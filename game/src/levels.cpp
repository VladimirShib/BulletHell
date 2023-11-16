#include "levels.h"

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
                        window.clear(sf::Color(0xC6, 0xC2, 0xA5));
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
        window.clear(sf::Color(0xC6, 0xC2, 0xA5));
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
        window.clear(sf::Color(0xC6, 0xC2, 0xA5));
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

int playLevel0(sf::RenderWindow& window, sf::View& view, sf::Event& event, sf::Clock& clock, Screens& screens, MusicManager& sounds)
{
    Level0 level;
    bool isPaused = false;

    sounds.TurnOnNewSong();
    view.setCenter(level.player.playerPosition);
    while (screens.transition.isTransitioning)
    {
        screens.transition.FadingOut();
        window.clear(sf::Color(0xC6, 0xC2, 0xA5));
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
        window.clear(sf::Color(0xC6, 0xC2, 0xA5));
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

    return level.levelStatus;
}

int playLevel1(sf::RenderWindow& window, sf::View& view, sf::Event& event, sf::Clock& clock, Screens& screens, MusicManager& sounds)
{
    Level1 level;
    bool isPaused = false;

    sounds.TurnOnNewSong();
    view.setCenter(level.player.playerPosition);
    while (screens.transition.isTransitioning)
    {
        screens.transition.FadingOut();
        window.clear(sf::Color(0xC6, 0xC2, 0xA5));
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
        window.clear(sf::Color(0xC6, 0xC2, 0xA5));
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

    return level.levelStatus;
}