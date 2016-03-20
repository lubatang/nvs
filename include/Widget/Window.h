//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#ifndef NVS_WIDGET_WINDOW_H
#define NVS_WIDGET_WINDOW_H
#include <Widget/Rect.h>
#include <Widget/Point.h>
#include <Widget/WinCursor.h>
#include <curses.h>

namespace nvs {

/** \class Window
 *  \brief The Window class controls a WINDOW on the screen
 */
class Window
{
public:
  Window();

  explicit Window(const Rect& pRect);

  virtual ~Window();

  bool isTopLevel() const { return (stdscr == m_pWindow); }

  bool move(int pX, int pY);

  bool move(const Point& pPos) { return this->move(pPos.x(), pPos.y()); }

  bool resize(int pWidth, int pHeight);

  bool resize(const Point& pSize) { return this->resize(pSize.x(), pSize.y()); }

  int x() const;

  int y() const;

  int height() const;

  int width() const;

  Point pos() const;

  Point size() const;

  Rect geometry() const;

  /// return current cursor.
  WinCursor cursor();

  bool refresh();

protected:
  friend class WinCursor;
  friend class Cursor;

  WINDOW* win() { return m_pWindow; }

  const WINDOW* win() const { return m_pWindow; }

protected:
  WINDOW* m_pWindow;
};

} // namespace of nvs

#endif
