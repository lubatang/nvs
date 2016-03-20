//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#ifndef NVS_WIDGET_CURSOR_H
#define NVS_WIDGET_CURSOR_H
#include <string>
#include <Widget/Point.h>
#include <Widget/Window.h>

namespace nvs {

/** \class Cursor
 *  \brief The Cursor class represents a cursor of a Window.
 *
 *  Different with WinCursor, moving a Cursor object doesn't affect 
 *  Window's current cursor immediately. Current cursor doesn't move until
 *  Cursor::print.
 */
class Cursor
{
public:
  Cursor(Window& pWindow);

  Cursor(WinCursor& pWinCursor);

  int x() const { return m_Position.x(); }

  int y() const { return m_Position.y(); }

  Point pos() const { return m_Position; }

  void move(int pX, int pY) { m_Position = Point(pX, pY); }

  void move(const Point& pPos) { m_Position = pPos; }

  bool print(const std::string& pText);

protected:
  Window& m_Window;
  Point m_Position;
};

inline Cursor& operator<<(Cursor& pCursor, const std::string& pText)
{
  pCursor.print(pText);
  return pCursor;
}

} // namespace of nvs

#endif
