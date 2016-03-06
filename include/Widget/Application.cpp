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

void nvs::RegisterObject(Object& pObject)
{
  g_App->addObject(pObject);
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
  shutdown();
}

// The main event loop
void Application::exec()
{
  clear(); // curses call to clear screen, send cursor to position (0,0)
  refresh();

  do {
    // key event
    int key = getch();
    KeyEvent event(key);
    ObjectList::iterator obj, oEnd = m_Objects.end();
    for (obj = m_Objects.begin(); obj != oEnd; ++obj) {
      (*obj)->event(event);
    }

    refresh();
  } while(1);
}
