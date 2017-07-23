#ifndef MYWINDOW_H
#define MYWINDOW_H

#include "SFML/Graphics.hpp"

using namespace sf;

class MyWindow
{
public:
    MyWindow();
    MyWindow(const std::string &l_title,const Vector2u &l_size);
    ~MyWindow();

    void BeginDraw(); // Clear the window
    void EndDraw(); // Display changes

    void Update();

    bool IsDone();
    bool IsFullScreen();
    Vector2u GetWindowSize();
    RenderWindow* GetRenderWindow();

    void ToggleFullScreen();

    void Draw(Drawable &l_drawable);

private:
    void Setup(const std::string &l_title,const Vector2u &l_size);
    void Destroy();
    void Create();

    RenderWindow m_window;
    Vector2u m_windowSize;
    std::string m_windowTitle;
    bool m_isDone,m_isFullScreen;
};


#endif // MYWINDOW_H
