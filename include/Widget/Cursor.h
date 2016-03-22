//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#ifndef NVS_WIDGET_WINDOW_CURSOR_H
#define NVS_WIDGET_WINDOW_CURSOR_H
#include <string>
#include <Widget/Point.h>
#include <Widget/Color.h>

namespace nvs {

class Window;

/** \class Cursor
 *  \brief The Cursor class represents current cursor of a Window.
 */
class Cursor
{
public:
  Cursor(Window& pWindow);

  Cursor(Window& pWindow, const Point& pPosition);

  Cursor(Window& pWindow, int pX, int pY);

  int x() const { return m_Position.x(); }

  int y() const { return m_Position.y(); }

  Point pos() const { return m_Position; }

  bool move(int pX, int pY);

  bool move(const Point& pPos) { return this->move(pPos.x(), pPos.y()); }

  bool reset();

  Cursor& operator<<(const std::string& pText);

  Cursor& operator<<(Color::Type pColor);

  Cursor& operator<<(Color::Playground pGround);

  Cursor& operator<<(Color::Attribute pAttr);

protected:
  friend class Cursor;

  Window& win() { return m_Window; }

protected:
  Window& m_Window;
  Point m_Position;
  Color m_Brush;
  Color::Playground m_Ground;
};

} // namespace of nvs

#endif
