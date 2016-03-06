//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#ifndef NVS_WIDGET_H
#define NVS_WIDGET_H
#include <Widget/Object.h>
#include <Widget/Point.h>

namespace nvs {

class Widget : public Object
{
public:
  explicit Widget(Widget* pParent = nullptr);

  bool event(Event* pEvent);

  virtual bool keyEvent(KeyEvent* pEvent) { return true; }

  virtual bool paintEvent(PaintEvent* pEvent) { return true; }

  void resize(int pW, int pH) { m_Size = Point(pW, pH); }

  void resize(const Point& pSize) { m_Size = pSize; }

  int width() const { return m_Size.x(); }

  int height() const { return m_Size.y(); }

  Rect rect() const { return Rect(0, 0, width(), height()); }

  Point size() const { return m_Size; }

protected:
  Point m_Size;
};

} // namespace of nvs

#endif
