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

/** \class Widget
 *  \brief The Widget class is the base class of all widgets.
 *
 *  Widgets with the same ancestor have handles the same window. Child widget
 *  is visibly above parent widget, and turn on and off at the same time.
 */
class Widget : public Object
{
public:
  /// A widget shares WINDOW with its parents. A orphan widget uses stdscr
  /// WINDOW.
  explicit Widget(Widget* pParent = nullptr);

  virtual ~Widget();

  virtual bool event(Event* pEvent);

  virtual bool keyEvent(KeyEvent* pEvent) { return true; }

  virtual bool paintEvent(PaintEvent* pEvent) { return true; }

  virtual bool moveEvent(MoveEvent* pEvent) { return true; }

  void resize(int pW, int pH);

  void resize(const Point& pSize) { resize(pSize.x(), pSize.y()); }

  int x() const { return m_Geometry.x(); }

  int y() const { return m_Geometry.y(); }

  int width() const { return m_Geometry.width(); }

  int height() const { return m_Geometry.height(); }

  Point pos() const { return Point(x(), y()); }

  Point size() const { return Point(width(), height()); }

  /// This property holds the geometry of the widget relative to its parent.
  const Rect& geometry() const { return m_Geometry; }

  virtual void show();

  virtual void hide();

  virtual void move(int pX, int pY);

  Widget* parent() const { return m_pParent; }

  WINDOW* win() { return m_pWindow; }

  void setVisible(bool pEnable = true) { m_bVisible = pEnable; }

  bool isVisible() const { return m_bVisible; }

protected:
  Rect m_Geometry;
  Widget* m_pParent;
  WINDOW* m_pWindow;
  bool m_bVisible;
};

} // namespace of nvs

#endif
