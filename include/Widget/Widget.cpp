//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <Widget/Widget.h>

using namespace nvs;

//===----------------------------------------------------------------------===//
// Widget
//===----------------------------------------------------------------------===//
Widget::Widget(Widget* pParent)
  : Object(pParent), m_Size() {
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
