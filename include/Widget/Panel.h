//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#ifndef NVS_PANEL_H
#define NVS_PANEL_H
#include <panel.h>
#include <Widget/Window.h>

namespace nvs {

/** \class Panel
 *  \brief The Panel class controls a layer on the screen.
 *
 *  A Panel object creates a PANEL in curses. Concepturally,
 *  A Panel object creates a layer on the screen. Widgets belong to a Panel
 *  shares WINDOW and we can handle all Widgets' visibility by the Panel.
 */
class Panel
{
public:
  Panel(Window& pWindow);

  ~Panel();

  static void update();

protected:
  Window& m_Window;
  PANEL*  m_pPanel;
};

} // namespace of nvs

#endif
