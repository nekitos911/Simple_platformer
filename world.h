#ifndef WORLD_H
#define WORLD_H

#include "SFML/Graphics.hpp"

#include "level.h"

using namespace sf;

class World
{
public:
    World();
    void Render(RenderWindow &l_window);
    Object GetPlayerObject();
    std::vector<Object> GetSolidObjects();
    std::vector<Object> GetWaterObjects();
private:
    Level m_lvl;
    Object m_player;
    std::vector<Object> m_solid;
    std::vector<Object> m_water;
};

#endif // WORLD_H
