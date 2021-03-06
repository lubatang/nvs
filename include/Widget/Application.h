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

class Widget;

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

  unsigned int getNumOfChildren() const { return m_Widgets.size(); }

protected:
  friend void RegisterTopLevel(Widget*);

  typedef std::deque<Widget*> WidgetList;

protected:
  void addWidget(Widget* pWidget) { m_Widgets.push_back(pWidget); }

protected:
  WidgetList m_Widgets;
};

/// A global pointer referring to the unique application object. It's
/// equivalent to the pointer returned by the Application::instance
Application* sApp();

} // namespace of nvs

#endif
