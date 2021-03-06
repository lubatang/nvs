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
#include <Widget/Point.h>
#include <Widget/Rect.h>
#include <Widget/Event.h>
#include <Widget/Layout.h>
#include <curses.h>
#include <vector>

namespace nvs {

/** \class Widget
 *  \brief The Widget class is the base class of all widgets.
 *
 *  Widgets with the same ancestor have handles the same window. Child widget
 *  is visibly above parent widget, and turn on and off at the same time.
 *
 *  A widget that is not embedded in a parent widget is called a window. In NVS,
 *  MainWindow and various subclasses of Dialog are the most common window type.
 */
class Widget
{
public:
  typedef std::vector<Widget*> Children;

public:
  /// A widget shares WINDOW with its parents. A orphan widget uses stdscr
  /// WINDOW.
  explicit Widget(Widget* pParent = nullptr);

  virtual ~Widget();

  virtual bool event(Event* pEvent);

  virtual bool keyEvent(KeyEvent* pEvent) { return true; }

  virtual bool paintEvent(PaintEvent* pEvent) { return true; }

  virtual bool moveEvent(MoveEvent* pEvent) { return true; }

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

  void resize(int pW, int pH);

  void resize(const Point& pSize) { resize(pSize.x(), pSize.y()); }

  void move(int pX, int pY);

  void move(const Point& pPosition) { move(pPosition.x(), pPosition.y()); }

  Widget* parent() const { return m_pParent; }

  bool isTopLevel() const { return (nullptr == m_pParent); }

  void setVisible(bool pEnable = true) { m_bVisible = pEnable; }

  bool isVisible() const { return m_bVisible; }

  const Children& children() const { return m_Children; }

  void addChild(Widget* pC) { m_Children.push_back(pC); }

  Layout* layout() const { return m_pLayout; }

  /// @retval true Layout has been installed.
  bool hasLayout() const { return (nullptr != m_pLayout); }

protected:
  friend class Application;
  friend class Layout;

  virtual bool doEvent(Event* pEvent);

  /// Install layout manager
  void setLayout(Layout& pLayout) { m_pLayout = &pLayout; }

protected:
  Widget* m_pParent;
  Children m_Children;
  Rect m_Geometry;
  bool m_bVisible;
  Layout* m_pLayout;
};

/// Register an object to Application
void RegisterTopLevel(Widget* pWidget);

} // namespace of nvs

#endif
