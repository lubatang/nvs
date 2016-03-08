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
{
  if (nullptr == pParent)
    RegisterTopLevel(*this);
  else
    pParent->addChild(*this);
}

bool Object::doEvent(Event* pEvent)
{
  // by pass all events to the children.
  bool result = event(pEvent);
  Children::iterator child, cEnd = m_Children.end();
  for (child = m_Children.begin(); child != cEnd; ++child)
    result |= (*child)->doEvent(pEvent);
  return result;
}
