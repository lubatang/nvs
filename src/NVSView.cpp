//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <NVSView.h>
#include <curses.h>

using namespace nvs;

void View::show()
{
  ::printw("Hello World !!!");
}
