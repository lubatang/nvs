//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <Widget/Widget.h>
#include <Widget/Layout.h>
#include <curses.h>
#include <iostream>

using namespace nvs;

extern WINDOW* stdscr;
static Layout* g_Layout = nullptr;

//===----------------------------------------------------------------------===//
// Widget
//===----------------------------------------------------------------------===//
Widget::Widget(Widget* pParent)
  : m_pParent(pParent), m_Geometry(), m_pWindow(nullptr),
    m_bVisible(false) {
  if (nullptr == pParent)
    m_pWindow = stdscr;
  else {
    m_pWindow = pParent->win();
    pParent->addChild(this);
  }
}

Widget::~Widget()
{
  // The derived widget who calls newwin() is responsible for calling delwin().
}

bool Widget::doEvent(Event* pEvent)
{
  // by pass all events to the children.
  bool result = event(pEvent);
  Children::iterator child, cEnd = m_Children.end();
  for (child = m_Children.begin(); child != cEnd; ++child)
    result |= (*child)->doEvent(pEvent);
  return result;
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

Layout* Widget::layout()
{
  return g_Layout;
}

void Widget::setLayout(Layout* pLayout)
{
  g_Layout = pLayout;
}
