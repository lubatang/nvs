//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <Widget/Object.h>

using namespace nvs;

//===----------------------------------------------------------------------===//
// Object
//===----------------------------------------------------------------------===//
Object::Object()
{
  RegisterObject(*this);
}

Object::~Object()
{
}
