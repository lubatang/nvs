//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <NVSApplication.h>
#include <NVSView.h>

int main(int pArgc, char* pArgv[])
{
  nvs::Application app;
  nvs::View view;
  view.show();
  app.exec();
}
