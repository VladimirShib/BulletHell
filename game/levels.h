#pragma once

enum struct GameWindow
{
    MENU,
    SELECTION,
    GAME,
    PAUSE
};

struct GameState {
    GameWindow state;
    int level;
};