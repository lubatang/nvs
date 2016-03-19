//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#ifndef NVS_WIDGET_LAYOUT_H
#define NVS_WIDGET_LAYOUT_H
#include <vector>
#include <curses.h>

namespace nvs {

class Widget;

/** \class Layout
 *  \brief The Layout class is the base class of geometry managers
 *
 *  Layout objects manage curses WINDOW objects. A layout object without
 *  parent Widget is a top-level layout. The top-level layout manages stdscr
 *  WINDOW. A system has only one top-level layout. Every non-top-level layout
 *  creates a WINDOW object.
 *
 *  When a widget object get a resize event, it requests a new geometry from its
 *  Layout object.
 */
class Layout
{
public:
  enum Orientations {
    Horizontal,
    Vertical
  };

public:
  /// @param[in,out] pParent The parent widget. If the parent widget is null,
  /// then this is a top-level layout.
  /// construct a new top-level layout
  Layout(Orientations pDirection, Widget& pParent);

  virtual ~Layout();

  Orientations direction() const { return m_Direction; }

  /// add widget into layout.
  void addWidget(Widget& pWidget);

  /// update the geometry of components.
  void move(int pX, int pY);

  /// update the geometry of components.
  void resize(int pW, int pH);

  /// refresh the WINDOW object
  void refresh();

  bool isTopLevel() const;

protected:
  typedef std::vector<Widget*> ComponentList;

  virtual void doMove(int pX, int pY) = 0;

  virtual void doResize(int pW, int pH) = 0;

protected:
  Widget& m_Parent;
  WINDOW* m_pWindow;
  Orientations m_Direction;
  ComponentList m_Components;
};

class HLayout : public Layout
{
public:
  HLayout(Widget& pParent);

protected:
  void doMove(int pX, int pY);

  void doResize(int pW, int pH);
};

class VLayout : public Layout
{
public:
  VLayout(Widget& pParent);

protected:
  void doMove(int pX, int pY);

  void doResize(int pW, int pH);
};

} // namespace of nvs

#endif
