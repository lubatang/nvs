//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <Widget/Application.h>
#include <Widget/Object.h>
#include <Widget/Event.h>
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

void nvs::RegisterTopLevel(Object& pObject)
{
  assert(nullptr != g_App && "No existing nvs::Application object");
  g_App->addObject(pObject);
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
  keypad(stdscr, true); //< I need that nifty Fn
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
    refresh();

    // re-calculate max size in case the size of termial is changing.
    int x, y;
    getmaxyx(stdscr, y, x);
    Rect rect(0, 0, x, y);
    PaintEvent paint_event(rect);
    ObjectList::iterator obj, oEnd = m_Objects.end();
    for (obj = m_Objects.begin(); obj != oEnd; ++obj)
      (*obj)->doEvent(&paint_event);

    // key event
    int key = getch();
    KeyEvent key_event(key);
    for (obj = m_Objects.begin(); obj != oEnd; ++obj)
      (*obj)->doEvent(&key_event);

  } while(1);
}
