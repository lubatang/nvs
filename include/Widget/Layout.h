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
#include <Widget/Widget.h>
#include <vector>

namespace nvs {

class Layout : public Object
{
public:
  explicit Layout(Widget* pParent);
};

} // namespace of nvs

#endif
