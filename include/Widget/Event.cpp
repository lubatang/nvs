//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <Widget/Event.h>

using namespace nvs;

//===----------------------------------------------------------------------===//
// Event
//===----------------------------------------------------------------------===//
Event::Event(Type pType)
  : m_Type(pType) {
}

//===----------------------------------------------------------------------===//
// KeyEvent
//===----------------------------------------------------------------------===//
KeyEvent::KeyEvent(int pKey)
  : Event(KeyPress), m_Key(pKey) {
}