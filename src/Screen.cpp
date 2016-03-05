//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <Screen.h>
#include <NVSApplication.h>
#include <curses.h>

using namespace nvs;

//===----------------------------------------------------------------------===//
// Screen
//===----------------------------------------------------------------------===//
Screen::Screen(Application& pParent)
  : m_Parent(pParent), m_RowSize(-1), m_ColumnSize(-1), m_CurCursor(0, 0) {
  WINDOW* window = initscr();
  getmaxyx(window, m_RowSize, m_ColumnSize);
  clear(); // curses call to clear screen, send cursor to position (0,0)
  refresh();
}

Screen::~Screen()
{
  /* curses must end with endwin() */
  endwin();
}
