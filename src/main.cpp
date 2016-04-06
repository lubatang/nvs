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
#include <Subversion/Context.h>
#include <Subversion/Apr.h>

using namespace nvs;

static void item(Cursor& pCursor, int pX, int pY, const LogEntries& pEntries)
{
  std::string msg(pEntries[pY].message.substr(0, pEntries[pY].message.find_first_of('\n')));
  pCursor.move(pX, pY);
  pCursor << Color::Blue <<  pEntries[pY].revision
          << " "
          << Color::Green << pEntries[pY].author
          << Color::Cyan << "     o "
          << Color::Reset << msg;
}

static void bar(Cursor& pCursor, int pX, int pY, const LogEntries& pEntries)
{
  std::string msg(pEntries[pY].message.substr(0, pEntries[pY].message.find_first_of('\n')));
  pCursor.move(pX, pY);
  pCursor << Color::White << Color::bg << Color::Green
          << pEntries[pY].revision
          << " "
          << pEntries[pY].author
          << "     o "
          << msg << Color::Reset;
}

int main(int pArgc, char* pArgv[])
{
  std::string URL;
  if (pArgc <= 1) {
    printf("Usage:  %s URL\n", pArgv[0]);
    return EXIT_FAILURE;
  }
  else
    URL = pArgv[1];

  Application app;

  // Window
  Window win;
  Cursor* cursor = new Cursor(win, 0, 0);

  // Subversion
  Apr apr;
  Context context;
  Client client(context);
  const LogEntries* entries = client.log(URL, Revision::START, Revision::WORKING);

  for (int i = 0; i < win.height(); ++i)
    item(*cursor, 0, i, *entries);

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
        item(*cursor, 0, cur_y, *entries);
        bar(*cursor, 0, --cur_y, *entries);
        break;
      }
      case KEY_DOWN: {
        if (win.height()-1 == cur_y)
          break;
        item(*cursor, 0, cur_y, *entries);
        bar(*cursor, 0, ++cur_y, *entries);
        break;
      }
      case KEY_RIGHT: {
      }

      default:
        break;
    }
  } while(1);
}
