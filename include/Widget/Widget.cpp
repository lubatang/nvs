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

using namespace nvs;

extern WINDOW* stdscr;

//===----------------------------------------------------------------------===//
// Widget
//===----------------------------------------------------------------------===//
Widget::Widget(Widget* pParent)
  : Object(pParent), m_pParent(pParent), m_Geometry() {
}

Widget::~Widget()
{
  if (nullptr != parent() && nullptr != win())
    delwin(m_pWindow);
}

bool Widget::event(Event* pEvent)
{
  bool result = Object::event(pEvent);

  if (KeyEvent::classof(*pEvent))
    result |= this->keyEvent(dynamic_cast<KeyEvent*>(pEvent));

  if (PaintEvent::classof(*pEvent))
    result |= this->paintEvent(dynamic_cast<PaintEvent*>(pEvent));

  return result;
}

void Widget::resize(int pW, int pH)
{
  // TODO: emit resizeEvent to parents
  m_Geometry.setWidth(pW);
  m_Geometry.setHeight(pH);
}

void Widget::show()
{
  if (nullptr == parent())
    m_pWindow = stdscr;
  else
    m_pWindow = newwin(height(), width(), y(), x());
}
