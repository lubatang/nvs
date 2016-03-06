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
Object::Object(Object* pParent)
  : m_pParent(pParent) {

  if (nullptr == pParent)
    RegisterTopLevel(*this);
  else
    m_pParent->addChild(*this);
}

Object::~Object()
{
}

bool Object::event(Event* pEvent)
{
  // by pass all events to the children.
  bool result = true;
  Children::iterator child, cEnd = m_Children.end();
  for (child = m_Children.begin(); child != cEnd; ++child)
    result |= (*child)->event(pEvent);
  return result;
}
