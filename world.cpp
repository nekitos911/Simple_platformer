#include "world.h"

World::World()
{
    m_lvl.LoadFromFile("Media/Level1.tmx");
    m_player = m_lvl.GetObject("player");
    m_solid = m_lvl.GetObjects("solid");
    m_water = m_lvl.GetObjects("water");
}

void World::Render(RenderWindow &l_window) {
    m_lvl.Draw(l_window);
}

Object World::GetPlayerObject() {
    return m_player;
}

std::vector<Object> World::GetSolidObjects() {
    return m_solid;
}

std::vector<Object> World::GetWaterObjects() {
    return m_water;
}
