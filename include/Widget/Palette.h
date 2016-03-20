//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#ifndef NVS_WIDGET_PALETTE_H
#define NVS_WIDGET_PALETTE_H
#include <Widget/WinCursor.h>
#include <Widget/Color.h>

namespace nvs {

class Palette
{
public:
  static bool hasColors();

  static bool initialize();

  static short id(short pFore, short pBack);

  static int attr(const Color& pColor);
};

} // namespace of nvs

#endif
