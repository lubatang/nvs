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
 *  A Layout object creates a new WINDOW object.
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
  Layout(Orientations pDirection, Widget* pParent = nullptr);

  virtual ~Layout();

  Orientations direction() const { return m_Direction; }

  /// add widget into layout.
  void addWidget(Widget& pWidget);

protected:
  typedef std::vector<Widget*> ComponentList;

  virtual void resizeComponents() = 0;

protected:
  WINDOW* m_pWindow;
  Orientations m_Direction;
  ComponentList m_Components;
};

class HLayout : public Layout
{
public:
  HLayout(Widget* pParent = nullptr);

private:
  void resizeComponents();
};

} // namespace of nvs

#endif
