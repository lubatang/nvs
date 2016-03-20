//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <Widget/WinCursor.h>
#include <Widget/Window.h>
#include <curses.h>

using namespace nvs;

//===----------------------------------------------------------------------===//
// WinCursor
//===----------------------------------------------------------------------===//
WinCursor::WinCursor(Window& pWindow)
  : m_Window(pWindow) {
}

int WinCursor::x() const
{
  return getcurx(m_Window.win());
}

int WinCursor::y() const
{
  return getcury(m_Window.win());
}

Point WinCursor::pos() const
{
  int x, y;
  getyx(m_Window.win(), y, x);
  return Point(x, y);
}

bool WinCursor::move(int pX, int pY)
{
  return (OK == ::wmove(m_Window.win(), pY, pX));
}

bool WinCursor::print(const std::string& pText)
{
  return (OK == waddstr(m_Window.win(), pText.c_str()));
}
