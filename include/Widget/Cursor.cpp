//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <Widget/Cursor.h>

using namespace nvs;

//===----------------------------------------------------------------------===//
// Cursor
//===----------------------------------------------------------------------===//
Cursor::Cursor(Window& pWindow)
  : m_Window(pWindow) {
}

int Cursor::x() const
{
  return getcurx(m_Window.win());
}

int Cursor::y() const
{
  return getcury(m_Window.win());
}

Point Cursor::pos() const
{
  int x, y;
  getyx(m_Window.win(), y, x);
  return Point(x, y);
}

bool Cursor::move(int pX, int pY)
{
  return (OK == ::wmove(m_Window.win(), pY, pX));
}
