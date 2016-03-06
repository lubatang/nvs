//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <Widget/Layout.h>

using namespace nvs;

//===----------------------------------------------------------------------===//
// Layout
//===----------------------------------------------------------------------===//
bool Layout::event(Event* pEvent)
{
  // bypass all events.
  ComponentList::iterator component, cEnd = m_Components.end();
  for (component = m_Components.begin(); component != cEnd; ++component)
    (*component)->event(pEvent);
  return true;
}
