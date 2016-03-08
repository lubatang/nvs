//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <NVSView.h>
#include <curses.h>
#include <iostream>

using namespace nvs;

//===----------------------------------------------------------------------===//
// nvs::View
//===----------------------------------------------------------------------===//
View::View()
  : Widget(), m_Label("Hello World !!!", this) {
}

bool View::keyEvent(KeyEvent* pEvent)
{
  switch (pEvent->key()) {
    case KEY_LEFT:
      m_Label.move(-1, 0);
      break;
    case KEY_RIGHT:
      m_Label.move(1, 0);
      break;
    case KEY_UP:
      m_Label.move(0, -1);
      break;
    case KEY_DOWN:
      m_Label.move(0, 1);
      break;
    case ' ':
      if (m_Label.isVisible())
        m_Label.hide();
      else
        m_Label.show();
      break;
  } // end of switch
  return true;
}
