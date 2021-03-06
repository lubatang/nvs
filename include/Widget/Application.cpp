//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <Widget/Application.h>
#include <Widget/Widget.h>
#include <Widget/Event.h>
#include <Widget/Palette.h>
#include <Support/ManagedStatic.h>
#include <assert.h>
#include <curses.h>

using namespace nvs;

extern WINDOW* stdscr;

static Application* g_App = nullptr;

//===----------------------------------------------------------------------===//
// Non-member functions
//===----------------------------------------------------------------------===//
Application* sApp()
{
  return Application::instance();
}

void nvs::RegisterTopLevel(Widget* pWidget)
{
  assert(nullptr != g_App && "No existing nvs::Application object");
  g_App->addWidget(pWidget);
}

//===----------------------------------------------------------------------===//
// Application
//===----------------------------------------------------------------------===//
Application::Application()
{
  assert(nullptr == g_App && "Multiple nvs::Application objects");
  g_App = this;
  initscr();
  cbreak(); //< Line buffering disabled, Pass on everty thing to me
  noecho();
  keypad(stdscr, true); //< I need that nifty Fn
  Palette::initialize();
}

Application::~Application()
{
  endwin();
  shutdown();
}

Application* Application::instance()
{
  assert(nullptr != g_App && "No existing nvs::Application object");
  return g_App;
}

// The main event loop
void Application::exec()
{
  clear(); // curses call to clear screen, send cursor to position (0,0)
  refresh();

  do {
    // paint event
    doupdate();

    // key event
    int key = getch();
    KeyEvent key_event(key);
    WidgetList::iterator widget, wEnd = m_Widgets.end();
    for (widget = m_Widgets.begin(); widget != wEnd; ++widget)
      (*widget)->doEvent(&key_event);

  } while(1);
}
