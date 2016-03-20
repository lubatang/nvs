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
#include <Widget/Window.h>

namespace nvs {

class Cursor
{
public:
  Cursor(Window& pWindow);

  int x() const;

  int y() const;

  Point pos() const;

  bool move(int pX, int pY);

  bool move(const Point& pPos) { return this->move(pPos.x(), pPos.y()); }

protected:
  Window& m_Window;
};

} // namespace of nvs

#endif
