//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#ifndef NVS_VIEW_H
#define NVS_VIEW_H
#include <Widget/Widget.h>
#include <Widget/Label.h>

namespace nvs {

class View : public Widget
{
public:
  View();

   bool keyEvent(KeyEvent* pEvent);

   void show() { m_Label.show(); }

   void hide() { m_Label.hide(); }

private:
  Label m_Label;
};

} // namespace of nvs

#endif
