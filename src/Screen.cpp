//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <Screen.h>
#include <Widget/Application.h>
#include <curses.h>

using namespace nvs;

//===----------------------------------------------------------------------===//
// Screen
//===----------------------------------------------------------------------===//
Screen::Screen(Application& pParent)
  : m_Parent(pParent), m_RowSize(-1), m_ColumnSize(-1), m_CurPoint(0, 0) {
}

Screen::~Screen()
{
}
