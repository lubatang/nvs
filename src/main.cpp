//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <Widget/Application.h>
#include <Widget/Label.h>
#include <Widget/Window.h>
#include <Widget/Cursor.h>
#include <NVSView.h>
#include <Subversion/Client.h>

using namespace nvs;

static void item(Cursor& pCursor, int pX, int pY)
{
  pCursor.move(pX, pY);
  pCursor << Color::Blue << "2016-01-04 13:14 "
          << Color::Green << "Jonas Fonseca "
          << Color::Cyan << "     o "
          << Color::Reset << "Update NEWS with post 2.1.1 changes";
}

static void bar(Cursor& pCursor, int pX, int pY)
{
  pCursor.move(pX, pY);
  pCursor << Color::White << Color::bg << Color::Green
          << "2016-01-04 13:14 "
          << "Jonas Fonseca "
          << "     o "
          << "Update NEWS with post 2.1.1 changes" << Color::Reset;
}

int main(int pArgc, char* pArgv[])
{
  Application app;

  Window win;
  Cursor* cursor = new Cursor(win, 0, 0);
  for (int i = 0; i < win.height(); ++i)
    item(*cursor, 0, i);

  cursor->reset();
  int cur_y = 0;
  do {
    // paint event
    doupdate();

    // key event
    int key = getch();
    switch (key) {
      case KEY_UP: {
        if (0 == cur_y)
          break;
        item(*cursor, 0, cur_y);
        bar(*cursor, 0, --cur_y);
        break;
      }
      case KEY_DOWN: {
        if (win.height()-1 == cur_y)
          break;
        item(*cursor, 0, cur_y);
        bar(*cursor, 0, ++cur_y);
        break;
      }
      default:
        break;
    }
  } while(1);
}
