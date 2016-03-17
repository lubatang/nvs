//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#ifndef NVS_WIDGET_MAINWINDOW_H
#define NVS_WIDGET_MAINWINDOW_H
#include <Widget/Widget.h>
#include <Widget/Layout.h>
#include <Widget/StatusBar.h>

namespace nvs {

/** \class MainWindow
 *  \brief The MainWindow class provides a main application window.
 */
class MainWindow : public Widget
{
public:
  MainWindow();

  ~MainWindow();

  void setCentralWidget(Widget* pWidget) { m_pCentralWidget = pWidget; }

  Widget* centralWidget() const { return m_pCentralWidget; }

  StatusBar* statusBar() const { return &m_StatusBar; }

protected:
  Widget* m_pCentralWidget;
  StatusBar m_StatusBar;
};

} // namespace nvs

#endif
