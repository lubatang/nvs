//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <Widget/Cursor.h>
#include <curses.h>

using namespace nvs;

//===----------------------------------------------------------------------===//
// nvs::Cursor
//===----------------------------------------------------------------------===//
Cursor::Cursor(Window& pWindow)
  : m_Window(pWindow) {
  int x, y;
  getyx(m_Window.win(), y, x);
  m_Position.setX(x);
  m_Position.setY(y);
}

Cursor::Cursor(WinCursor& pWinCursor)
  : m_Window(pWinCursor.m_Window), m_Position(pWinCursor.pos()) {
}

bool Cursor::print(const std::string& pText)
{
  bool rst = (OK == mvwaddstr(m_Window.win(), y(), x(), pText.c_str()));
  m_Position = m_Window.cursor().pos();
  return rst;
}
