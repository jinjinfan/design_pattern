#include "IBuffer.h"
#include "Viewport.h"
#include "Window.h"
#include <iostream>
void Window::ResizeFunction(int w, int h)
{
  self->width = w;
  self->height = h;
}

Window::Window(std::string title, int width, int height):
  width{width}, height{height}
{
  self = this; // wow, it's 2016 and we're doing this!
}

void Window::DrawEverything()
{
}

void Window::Show()
{
    std::cout << "windows with height = " << self->height << " and width = " << self->width << std::endl;
}

std::pair<int, int> Window::size() const
{
}

Window::~Window()
{
}

Window* Window::self;