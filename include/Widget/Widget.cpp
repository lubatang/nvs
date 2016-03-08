//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <Widget/Widget.h>
#include <curses.h>
#include <iostream>

using namespace nvs;

extern WINDOW* stdscr;

//===----------------------------------------------------------------------===//
// Widget
//===----------------------------------------------------------------------===//
Widget::Widget(Widget* pParent)
  : Object(pParent), m_pParent(pParent), m_Geometry(), m_pWindow(nullptr),
    m_bVisible(false) {
  if (nullptr == pParent)
    m_pWindow = stdscr;
  else
    m_pWindow = pParent->win();
}

Widget::~Widget()
{
  // The derived widget who calls newwin() is responsible for calling delwin().
}

bool Widget::event(Event* pEvent)
{
  bool result = true;
  if (KeyEvent::classof(*pEvent))
    result |= this->keyEvent(dynamic_cast<KeyEvent*>(pEvent));

  // since the parent is visibly behind the children, it paints first.
  if (PaintEvent::classof(*pEvent))
    result |= this->paintEvent(dynamic_cast<PaintEvent*>(pEvent));

  if (MoveEvent::classof(*pEvent))
    result |= this->moveEvent(dynamic_cast<MoveEvent*>(pEvent));
  return result;
}

void Widget::resize(int pW, int pH)
{
  // TODO: emit resizeEvent to parents
  m_Geometry.setWidth(pW);
  m_Geometry.setHeight(pH);
}

void Widget::move(int pX, int pY)
{
  Point new_pos(x() + pX, y() + pY);
  Point old_pos(x(), y());

  m_Geometry.setX(new_pos.x());
  m_Geometry.setY(new_pos.y());

  MoveEvent event(new_pos, old_pos);
  this->doEvent(&event);
}

void Widget::show()
{
  setVisible(true);
  // redraw
}

void Widget::hide()
{
  setVisible(false);
  // clean up
}
