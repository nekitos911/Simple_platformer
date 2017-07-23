#include "player.h"

Player::Player () : m_speed(80),m_lives(3),m_onGround(false),m_state(State::Jump),m_dir(Direction::Right) {
    m_playerTexture.loadFromFile("Media/Images/fang.png");
    m_playerSprite.setTexture(m_playerTexture);
    y = m_player.GetPlayerObject().rect.top;
    x = m_player.GetPlayerObject().rect.left;
    w = 40;
    h = 50;
    m_playerSprite.setTextureRect(IntRect(0,244,40,50));
    m_playerSprite.setOrigin(w / 2,h / 2);
}
Player::~Player() {}

void Player::SetDirection(Direction l_dir) { m_dir = l_dir; }
Direction Player::GetDirection() { return m_dir; }

int Player::GetLives() { return m_lives; }
int Player::GetSpeed() { return m_speed; }

bool Player::HasLost() { return m_lost; }

void Player::Tick() {
    Move();
    CheckCollision(dy);
}

void Player::Move() {

}

void Player::CheckCollision(float Dy) {
    for (int i = 0;i < m_solid.GetSolidObjects().size();i ++) {
        if (Dy > 0) { y = m_solid.GetSolidObjects()[i].rect + h; dy = 0; m_onGround = true; }
    }
}

void Player::SetView() {

}

IntRect Player::GetRect() { return IntRect(x,y,w,h); }

void Player::Render(RenderWindow &l_window) {
    l_window.draw(m_playerSprite);

}
