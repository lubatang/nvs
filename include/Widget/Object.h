//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#ifndef NVS_WIDGET_OBJECT_H
#define NVS_WIDGET_OBJECT_H
#include <Widget/Event.h>

namespace nvs {

class Object
{
public:
  Object();

  ~Object();

  /// This virtual function receives events to an object and should return true
  /// if the event @ref pEvent was recognized and processed.
  ///
  /// The event() function can be reimplemented to customize the behavior of an object.
  virtual bool event(Event* pEvent) { return true; }
};

/// Register an object to Application
void RegisterObject(Object& pObject);

} // namespace of nvs

#endif
