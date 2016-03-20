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
#include <Widget/Palette.h>
#include <curses.h>

using namespace nvs;

//===----------------------------------------------------------------------===//
// WinCursor
//===----------------------------------------------------------------------===//
WinCursor::WinCursor(Window& pWindow)
  : m_Window(pWindow), m_Brush(), m_Ground(Color::fg) {
  if (Palette::hasColors()) {
    short color_pair, fore, back;
    attr_t attr; 
    wattr_get(m_Window.win(), &attr, &color_pair, 0);
    pair_content(color_pair, &fore, &back);
    m_Brush = Color(fore, back, attr);
  }
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

WinCursor& WinCursor::operator<<(const std::string& pText)
{
  waddstr(m_Window.win(), pText.c_str());
  return *this;
}

WinCursor& WinCursor::operator<<(Color::Type pColor)
{
  if (Color::Foreground == m_Ground)
    m_Brush.setFore(pColor);
  else
    m_Brush.setBack(pColor);

  wattrset(m_Window.win(), Palette::attr(m_Brush));
  return *this;
}

WinCursor& WinCursor::operator<<(Color::Playground pGround)
{
  m_Ground = pGround;
  return *this;
}

WinCursor& WinCursor::operator<<(Color::Attribute pAttr)
{
  if (Color::Reset == pAttr) {
    short fore, back;
    pair_content(-1, &fore, &back);
    m_Brush = Color(fore, back, 0);
  }
  else
    m_Brush.add(pAttr);

  wattrset(m_Window.win(), Palette::attr(m_Brush));
  return *this;
}
