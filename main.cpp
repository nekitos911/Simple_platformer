#include <iostream>
#include "game.h"

int main()
{
    //Entry point
    Game game;

    while (!game.GetWindow() ->IsDone()) {
        //Game loop
        game.HandleInput();
        game.Update();
        game.Render();
        game.RestartClock();
    }

    return 0;
}
