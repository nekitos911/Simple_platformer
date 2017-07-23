#ifndef GAME_H
#define GAME_H

#include "mywindow.h"
#include "player.h"
#include "world.h"

using namespace sf;

class Game
{
public:
    Game();
    ~Game();

    void HandleInput();
    void Update();
    void Render();

    MyWindow *GetWindow();

    Time GetElapsed();
    void RestartClock();
private:
    MyWindow m_window;

    Clock m_clock;
    float m_elapsed;

    Player m_player;
    World m_world;

};

#endif // GAME_H
