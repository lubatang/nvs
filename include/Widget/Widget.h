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
#include <Widget/Object.h>

namespace nvs {

class Widget : public Object
{
public:
  bool event(Event* pEvent);

  virtual bool keyEvent(KeyEvent* pEvent) { return true; }

  virtual bool paintEvent(PaintEvent* pEvent) { return true; }
};

} // namespace of nvs

#endif
