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

  virtual ~Widget();

  bool event(Event* pEvent);

  virtual bool keyEvent(KeyEvent* pEvent) { return true; }

  virtual bool paintEvent(PaintEvent* pEvent) { return true; }

  void resize(int pW, int pH);

  void resize(const Point& pSize) { resize(pSize.x(), pSize.y()); }

  int x() const { return m_Geometry.x(); }

  int y() const { return m_Geometry.y(); }

  int width() const { return m_Geometry.width(); }

  int height() const { return m_Geometry.height(); }

  Point size() const { return Point(width(), height()); }

  /// This property holds the geometry of the widget relative to its parent.
  const Rect& geometry() const { return m_Geometry; }

  virtual void show();

  Widget* parent() const { return m_pParent; }

  WINDOW* win() { return m_pWindow; }

protected:
  Rect m_Geometry;
  Widget* m_pParent;
  WINDOW* m_pWindow;
};

} // namespace of nvs

#endif
