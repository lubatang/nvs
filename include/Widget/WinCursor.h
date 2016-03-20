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

  bool print(const std::string& pText);

protected:
  friend class Cursor;

protected:
  Window& m_Window;
};

inline WinCursor& operator<<(WinCursor& pWinCursor, const std::string& pText)
{
  pWinCursor.print(pText);
  return pWinCursor;
}

} // namespace of nvs

#endif
