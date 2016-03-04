//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <NVSApplication.h>
#include <curses.h>

using namespace nvs;

//===----------------------------------------------------------------------===//
// NVSApplication
//===----------------------------------------------------------------------===//
NVSApplication::NVSApplication()
{
    ::initscr();
}

NVSApplication::~NVSApplication()
{
  /* curses must end with endwin() */
  ::endwin();
}

void NVSApplication::run()
{
  ::printw("Hello World !!!");
  do {
    ::refresh();
  } while (1);
}
