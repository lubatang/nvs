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

int main(int pArgc, char* pArgv[])
{
  nvs::Application app;
  nvs::Label label("Hello world!\nMy World!\n");
  label.show();
  app.exec();
}
