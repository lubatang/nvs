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
bool Widget::event(Event* pEvent)
{
  if (KeyEvent::classof(*pEvent))
    return this->keyEvent(dynamic_cast<KeyEvent*>(pEvent));

  if (PaintEvent::classof(*pEvent))
    return this->paintEvent(dynamic_cast<PaintEvent*>(pEvent));
}
