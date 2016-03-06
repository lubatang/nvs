//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#ifndef NVS_WIDGET_APPLICATION_H
#define NVS_WIDGET_APPLICATION_H
#include <deque>

namespace nvs {

class Object;

/** \class Application
 *  \brief The Application class manages TUI application's control flow and main
 *  settings.
 *
 *  Application contains the main event loop, where all events from the widget
 *  system and other sources are processed and dispatched. It also handles
 *  the application's initialization and finalization. In addition, Application
 *  handles most of the system-wide and application-wide settings.
 *
 *  There is precisely one Application object, no matter whether the application
 *  has multiple windows at any given time.
 */
class Application
{
public:
  Application();

  ~Application();

  /// The main entrance of the application
  void exec();

  static Application* instance();

protected:
  friend void RegisterObject(Object&);

  typedef std::deque<Object*> ObjectList;

protected:
  void addObject(Object& pObject) { m_Objects.push_back(&pObject); }

protected:
  ObjectList m_Objects;
};

/// A global pointer referring to the unique application object. It's
/// equivalent to the pointer returned by the Application::instance
Application* sApp();

} // namespace of nvs

#endif
