//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <Widget/Cursor.h>
#include <Widget/Window.h>
#include <Widget/Palette.h>
#include <curses.h>

using namespace nvs;

//===----------------------------------------------------------------------===//
// Cursor
//===----------------------------------------------------------------------===//
Cursor::Cursor(Window& pWindow)
  : m_Window(pWindow), m_Position(), m_Brush(), m_Ground(Color::fg) {
}

Cursor::Cursor(Window& pWindow, const Point& pPosition)
  : m_Window(pWindow), m_Position(pPosition), m_Brush(), m_Ground(Color::fg) {
  this->move(m_Position);
}

Cursor::Cursor(Window& pWindow, int pX, int pY)
  : m_Window(pWindow), m_Position(pX, pY), m_Brush(), m_Ground(Color::fg) {
  this->move(m_Position);
}

bool Cursor::move(int pX, int pY)
{
  return (OK == ::wmove(m_Window.win(), pY, pX));
}

bool Cursor::reset()
{
  m_Ground = Color::fg;
  m_Brush = Color();
  wstandend(m_Window.win());
  return (OK == ::wmove(m_Window.win(), y(), x()));
}

Cursor& Cursor::operator<<(const std::string& pText)
{
  waddstr(m_Window.win(), pText.c_str());
  return *this;
}

Cursor& Cursor::operator<<(Color::Type pColor)
{
  if (Color::Reset == pColor) {
    wstandend(m_Window.win());
    return *this;
  }

  if (Color::Foreground == m_Ground)
    m_Brush.setFore(pColor);
  else
    m_Brush.setBack(pColor);

  wattrset(m_Window.win(), Palette::attr(m_Brush));
  return *this;
}

Cursor& Cursor::operator<<(Color::Playground pGround)
{
  m_Ground = pGround;
  return *this;
}

Cursor& Cursor::operator<<(Color::Attribute pAttr)
{
  m_Brush.add(pAttr);
  wattrset(m_Window.win(), Palette::attr(m_Brush));
  return *this;
}
