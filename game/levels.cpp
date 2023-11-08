#include "levels.h"

void pollEvents(sf::RenderWindow& window, sf::Event& event, sf::Clock& clock, Transition& transition, bool& isPaused)
{
    if (transition.isTransitioning)
    {
        return;
    }
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Escape)
            {
                isPaused = !isPaused;
                clock.restart();
            }
            else if (isPaused && event.key.code == sf::Keyboard::Q)
            {
                transition.isTransitioning = true;
            }
        }
    }
}

int playLevel0(sf::RenderWindow& window, sf::Event& event, sf::Clock& clock, Transition& transition, const Pause& pause)
{
    Level0 level;
    bool isPaused = false;

    while (transition.isTransitioning)
    {
        transition.FadingOut();
        window.clear(sf::Color(0xC6, 0xC2, 0xA5));
        window.draw(level);
        window.draw(transition);
        window.display();
    }

    clock.restart();

    while (window.isOpen() && level.levelStatus == 0)
    {
        pollEvents(window, event, clock, transition, isPaused);
        if (!isPaused)
        {
            level.Update(window, clock);
        }
        window.clear(sf::Color(0xC6, 0xC2, 0xA5));
        window.draw(level);
        if (isPaused)
        {
            window.draw(pause);
            if (transition.isTransitioning)
            {
                transition.FadingIn();
                window.draw(transition);
                if (transition.screenOff)
                {
                    return 2;
                }
            }
        }
        window.display();
    }
}