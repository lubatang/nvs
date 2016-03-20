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

/** \class WinCursor
 *  \brief The WinCursor class represents current cursor of a Window.
 */
class WinCursor
{
public:
  WinCursor(Window& pWindow);

  int x() const;

  int y() const;

  Point pos() const;

  bool move(int pX, int pY);

  bool move(const Point& pPos) { return this->move(pPos.x(), pPos.y()); }

  WinCursor& operator<<(const std::string& pText);

  WinCursor& operator<<(Color::Type pColor);

  WinCursor& operator<<(Color::Playground pGround);

  WinCursor& operator<<(Color::Attribute pAttr);

protected:
  friend class Cursor;

  Window& win() { return m_Window; }

protected:
  Window& m_Window;
  Color m_Brush;
  Color::Playground m_Ground;
};

} // namespace of nvs

#endif
