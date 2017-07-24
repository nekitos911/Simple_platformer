#include "game.h"

Game::Game() : m_window("New",Vector2u(640,480))
{
    RestartClock();
    srand(time(nullptr));
}
Game::~Game() {}

Time Game::GetElapsed() { return m_clock.getElapsedTime(); }
void Game::RestartClock() { m_elapsed += m_clock.restart().asSeconds(); }
MyWindow *Game::GetWindow() { return &m_window; }

void Game::HandleInput() {
    if (m_player.OnGround())  m_player.SetState(State::Stay);
    if (Keyboard::isKeyPressed(Keyboard::Up))
        m_player.SetDirection(Direction::Up);
    else if (Keyboard::isKeyPressed(Keyboard::Down))
        m_player.SetDirection(Direction::Down);
    if (Keyboard::isKeyPressed(Keyboard::Z) && m_player.OnGround()) {
        m_player.SetState(State::Jump);

    }
    else if (Keyboard::isKeyPressed(Keyboard::Left)) {
        m_player.SetDirection(Direction::Left);
        if (m_player.OnGround())m_player.SetState(State::Walk);
    }
    else if (Keyboard::isKeyPressed(Keyboard::Right)) {
        m_player.SetDirection(Direction::Right);
        if (m_player.OnGround())m_player.SetState(State::Walk);
    }
    if (Keyboard::isKeyPressed(Keyboard::X)) {
        m_player.SetState(State::Shoot);

    }
}

void Game::Update() {
    m_window.Update(); // update window

    float timestep = 1.0f / m_player.GetSpeed();

    if (m_elapsed >= timestep) {
        m_player.Tick();
        //m_world.Update(m_snake);
        m_elapsed -= timestep;
        if (m_player.HasLost()) {
            // Something when losing
        }
    }
}

void Game::Render() {
    m_window.BeginDraw(); // Clear
    m_world.Render(*m_window.GetRenderWindow());
    m_player.Render(*m_window.GetRenderWindow());
    m_window.EndDraw(); // Display
}


