//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <Widget/Window.h>

using namespace nvs;

//===----------------------------------------------------------------------===//
// Window
//===----------------------------------------------------------------------===//
Window::Window()
  : m_pWindow(stdscr) {
}

Window::Window(const Rect& pRect)
  : m_pWindow(nullptr) {
  m_pWindow = newwin(pRect.height(), pRect.width(), pRect.y(), pRect.x());
}

Window::~Window()
{
  if (!isTopLevel())
    delwin(m_pWindow);
}

bool Window::move(int pX, int pY)
{
  return (OK == mvwin(m_pWindow, pY, pX));
}

bool Window::resize(int pW, int pH)
{
  return (OK == wresize(m_pWindow, pH, pW));
}

int Window::x() const
{
  return getbegx(m_pWindow);
}

int Window::y() const
{
  return getbegy(m_pWindow);
}

int Window::width() const
{
  return getmaxx(m_pWindow);
}

int Window::height() const
{
  return getmaxy(m_pWindow);
}

Point Window::pos() const
{
  int x, y;
  getbegyx(m_pWindow, y, x);
  return Point(x, y);
}

Point Window::size() const
{
  int x, y;
  getmaxyx(m_pWindow, y, x);
  return Point(x, y);
}

Rect Window::geometry() const
{
  int x, y, h, w;
  getbegyx(m_pWindow, y, x);
  getmaxyx(m_pWindow, h, w);
  return Rect(x, y, w, h);
}

bool Window::refresh()
{
  return (OK == wnoutrefresh(m_pWindow));
}
