//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <Widget/Layout.h>
#include <Widget/Widget.h>
#include <curses.h>
#include <assert.h>

using namespace nvs;

extern WINDOW* stdscr;

//===----------------------------------------------------------------------===//
// Layout
//===----------------------------------------------------------------------===//
Layout::Layout(Orientations pDirection, Widget* pParent)
  : m_pWindow(nullptr), m_Direction(pDirection) {
  if (nullptr == pParent) { //< top-level layout
    Widget::setLayout(this);
    m_pWindow = stdscr;
  }
  else { //< get the size from the parent
    m_pWindow = newwin(pParent->height(), pParent->width(),
                       pParent->y(), pParent->x());
  }
}

Layout::~Layout()
{
  if (stdscr != m_pWindow)
    delwin(m_pWindow);
}

// re-calculate the size of the layout and all widgets.
void Layout::addWidget(Widget& pWidget)
{
  m_Components.push_back(&pWidget);
  this->resizeComponents();
}

//===----------------------------------------------------------------------===//
// HLayout
//===----------------------------------------------------------------------===//
HLayout::HLayout(Widget* pParent)
  : Layout(Layout::Horizontal, pParent) {
}

void HLayout::resizeComponents()
{
  int x, y, width, height;
  getmaxyx(m_pWindow, height, width);
  getbegyx(m_pWindow, y, x);

  int tile = width / m_Components.size();
  int c = 0;
  ComponentList::iterator widget, wEnd = m_Components.end();
  for (widget = m_Components.begin(); widget != wEnd; ++widget, ++c) {
    // widget->updateWindow(m_pWindow, x + tile*c, y, tile*c, height)
  }
}
