#ifndef PLAYER_H
#define PLAYER_H

#include "SFML/Graphics.hpp"
#include "world.h"

using namespace sf;

enum class Direction {Up,Down,Left,Right,RightTop,LeftTop};
enum class State {Stay,Walk,Jump,Duck,Shoot};

class Player
{
public:
    Player();
    ~Player();

    void SetDirection(Direction l_dir);
    void SetState (State l_state);
    Direction GetDirection();
    State GetState();
    int GetSpeed();
    int GetLives();

    void Tick();
    void Render(RenderWindow &l_window);

    void Flip();

    void Move();

    bool HasLost();

    void Lose();

    void Accelerate();

    bool OnGround();

    void SetView();

    IntRect GetRect();

    void PlayerSize();

    void Reset();

private:
    void CheckCollision(float Dy);

    Texture m_playerTexture;
    Sprite m_playerSprite;
    Direction m_dir;
    State m_state;
    int m_speed;
    bool m_lost;
    int m_lives;
    float m_currentFrame;
    bool m_flip;
    float x,y,w,h;
    bool m_onGround;
    float dx,dy;
    World m_player;
    World m_solid;
    World m_water;
    View view;
};

#endif // PLAYER_H
