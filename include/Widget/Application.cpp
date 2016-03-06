//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <Widget/Application.h>
#include <Support/ManagedStatic.h>
#include <curses.h>

using namespace nvs;

static ManagedStatic<Application> g_App;

//===----------------------------------------------------------------------===//
// Non-member functions
//===----------------------------------------------------------------------===//
Application* sApp()
{
  return &g_App;
}

//===----------------------------------------------------------------------===//
// Application
//===----------------------------------------------------------------------===//
Application::Application()
{
  initscr();
}

Application::~Application()
{
  endwin();
}

// The main event loop
void Application::exec()
{
  clear(); // curses call to clear screen, send cursor to position (0,0)
  refresh();

  do {
    // update all widgets
    refresh();
  } while(1);
}
