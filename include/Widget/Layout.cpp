//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <Widget/Layout.h>
#include <assert.h>

using namespace nvs;

//===----------------------------------------------------------------------===//
// Layout
//===----------------------------------------------------------------------===//
Layout::Layout(Widget* pParent)
  : Object(pParent) {
  assert(nullptr != pParent && "Layout must have a parent!");
}
