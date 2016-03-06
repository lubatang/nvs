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
#include <vector>
#include <curses.h>

namespace nvs {

class Object
{
public:
  typedef std::vector<Object*> Children;

public:
  Object(Object* pParent = nullptr);

  ~Object();

  /// This virtual function receives events to an object and should return true
  /// if the event @ref pEvent was recognized and processed.
  ///
  /// The event() function can be reimplemented to customize the behavior of
  /// an object.
  virtual bool event(Event* pEvent);

  /// The parent
  virtual Object* parent() const = 0;

  /// Returns a list of child objects. The Children class is defined in
  /// <Object.h> header file as the following:
  /// @code
  ///   typedef std::vector<Object*> Children.
  /// @endcode
  const Children& children() const { return m_Children; }

protected:
  void addChild(Object& pC) { m_Children.push_back(&pC); }

protected:
  Children m_Children;
};

/// Register an object to Application
void RegisterTopLevel(Object& pObject);

} // namespace of nvs

#endif
