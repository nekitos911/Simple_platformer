#include "player.h"
#include <iostream>

Player::Player () : m_speed(80),m_lives(3),m_onGround(false),m_state(State::Stay),m_dir(Direction::Right) {
    m_view.reset(FloatRect(0, 0, 640, 480));
    m_playerTexture.loadFromFile("Media/Images/fang.png");
    anim.loadFromXML("Media/playerAnim.xml",m_playerTexture);
    y = m_player.GetPlayerObject().rect.top;
    x = m_player.GetPlayerObject().rect.left;
    dx = dy = 0;
    anim.set("stay");
}
Player::~Player() {}

void Player::SetDirection(Direction l_dir) { m_dir = l_dir; }
void Player::SetState(State l_state) { m_state = l_state; }
State Player::GetState() { return m_state; }
Direction Player::GetDirection() { return m_dir; }

int Player::GetLives() { return m_lives; }
int Player::GetSpeed() { return m_speed; }

bool Player::HasLost() { return m_lost; }
bool Player::OnGround() { return m_onGround; }

void Player::Lose() { m_lost = true; }

void Player::Accelerate() {
    switch (m_state) {
    case State::Stay:
        dx = dy = 0;
        anim.set("stay");
        break;
    case State::Walk:
        anim.set("walk");
        if(!m_flip) dx = 1.5;
        else dx = -1.5;
        break;
    case State::Jump:
        anim.set("jump");
        if (m_onGround) dy = -12;
        break;
    case State::Shoot:
        anim.set("shoot");
        break;
    }
}

void Player::Tick() {
    Flip();
    Accelerate();
    Move();
    anim.tick();
    SetView();
}

void Player::Move() {
    x += dx;
    if (!m_onGround) dy += 0.5;
    y += dy;
    m_onGround = false;
    CheckCollision(dy);

}

void Player::Flip() {
    switch (m_dir) {
    case Direction::Left:
        anim.flip(1);
        m_flip = true;
        break;
    case Direction::Right:
        anim.flip(0);
        m_flip = false;
        break;
    }
}

void Player::CheckCollision(float Dy) {
    for (int i = 0;i < m_solid.GetSolidObjects().size();i ++) {
        if (GetRect().intersects(m_solid.GetSolidObjects()[i].rect))
        if (Dy > 0) { y = m_solid.GetSolidObjects()[i].rect.top; dy = 0; m_onGround = true; }
    }
}
void Player::SetView() {
    float tempX = x; float tempY = y;

    if (x < 320) tempX = 320;
    tempY = 240;

    m_view.setCenter(tempX,tempY);
}

IntRect Player::GetRect() { return IntRect(x,y,anim.getW() / 2,anim.getH()); }

void Player::Render(RenderWindow &l_window) {
    l_window.setView(m_view);
    anim.draw(l_window,x,y);
}
