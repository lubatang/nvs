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
  : m_pParent(pParent), m_Geometry(), m_bVisible(false), m_pLayout(nullptr) {
  if (nullptr == pParent)
    RegisterTopLevel(this);
  else
    pParent->addChild(this);
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

  return result;
}

void Widget::resize(int pW, int pH)
{
  m_Geometry.setWidth(pW);
  m_Geometry.setHeight(pH);

  // update geometry
  if (hasLayout())
    layout()->resize(pW, pH);

  // reflesh
  if (isVisible() && hasLayout())
    layout()->refresh();
}

void Widget::move(int pX, int pY)
{
  // update geometry
  if (hasLayout())
    layout()->move(pX, pY);

  m_Geometry.setX(pX);
  m_Geometry.setY(pY);

  // reflesh
  if (isVisible() && hasLayout())
    layout()->refresh();
}

void Widget::show()
{
  setVisible(true);
  Children::iterator child, cEnd = m_Children.end();
  for (child = m_Children.begin(); child != cEnd; ++child)
    (*child)->show();

  
}

void Widget::hide()
{
  setVisible(false);
  // clean up
}
