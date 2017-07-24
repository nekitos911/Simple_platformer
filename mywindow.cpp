#include "mywindow.h"

MyWindow::MyWindow()
{
    Setup("Window",Vector2u(640,480));
}
MyWindow::MyWindow (const std::string &l_title, const Vector2u &l_size) {
    Setup(l_title,l_size);
}
MyWindow::~MyWindow() { Destroy(); }

RenderWindow* MyWindow::GetRenderWindow(){ return &m_window; }

void MyWindow::Setup(const std::string &l_title, const Vector2u &l_size) {
    m_windowTitle = l_title;
    m_windowSize = l_size;
    m_isFullScreen = false;
    m_isDone = false;
    Create();
}


void MyWindow::Create() {
    auto style = (m_isFullScreen ? Style::Fullscreen : Style::Default);
    m_window.create({m_windowSize.x,m_windowSize.y,32},m_windowTitle,style);
}

void MyWindow::Destroy() {
    m_window.close();
}

void MyWindow::BeginDraw() {  m_window.clear(Color::Black); }
void MyWindow::EndDraw() { m_window.display(); }

bool MyWindow::IsDone() { return m_isDone; }
bool MyWindow::IsFullScreen() { return m_isFullScreen; }

void MyWindow::Draw(Drawable &l_drawable) { m_window.draw(l_drawable); }

Vector2u MyWindow::GetWindowSize() { return m_windowSize; }

void MyWindow::ToggleFullScreen() {
    m_isFullScreen = !m_isFullScreen;
    Destroy();
    Create();
}

void MyWindow::Update() {
        Event event;
        while (m_window.pollEvent(event)) {
            if (event.type == Event::Closed)
                m_isDone = true;
            else if (event.type == Event::KeyPressed && event.key.code == Keyboard::F5)
                ToggleFullScreen();
        }
}

