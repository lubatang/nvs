//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <curses.h>

int main(int pArgc, char* pArgv[])
{
  do {
    initscr(); /* must only be called once in each program */
    /* do something */
    refresh();
  } while (1);

  endwin();
}
