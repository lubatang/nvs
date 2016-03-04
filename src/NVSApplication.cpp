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
// Application
//===----------------------------------------------------------------------===//
Application::Application()
{
    ::initscr();
}

Application::~Application()
{
  /* curses must end with endwin() */
  ::endwin();
}

void Application::exec()
{
  do {
    ::refresh();
  } while (1);
}
