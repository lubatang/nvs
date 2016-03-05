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
  : m_Screen(*this) {
}

Application::~Application()
{
}

void Application::exec()
{
  do {
    ::refresh();
  } while (1);
}
