#pragma once

#include "headers.h"

enum struct GameWindow
{
    MENU,
    SELECTION,
    FADING_FROM_MENU,
    FADING_TO_GAME,
    GAME,
    PAUSE,
    FADING_FROM_GAME,
    FADING_TO_MENU
};

struct GameState
{
    GameWindow state;
    int level;
};