//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <Widget/Panel.h>

using namespace nvs;

//===----------------------------------------------------------------------===//
// Panel
//===----------------------------------------------------------------------===//
Panel::Panel(Window& pWindow)
  : m_Window(pWindow), m_pPanel(::new_panel(pWindow.win())) {
  set_panel_userptr(m_pPanel, this);
}

Panel::~Panel()
{
}

void Panel::update()
{
  update_panels();
}
