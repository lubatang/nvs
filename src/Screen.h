//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#ifndef NVS_SCREEN_H
#define NVS_SCREEN_H
#include <Widget/Point.h>

namespace nvs {

class Application;

/** \class Screen
 *  \brief contains the information of the global screen window
 */
class Screen
{
public:
public:
  Screen(Application& pParent);

  ~Screen();

  int getRowSize() const { return m_RowSize; }

  int getColumnSize() const { return m_ColumnSize; }

private:
  Application& m_Parent;
  int m_RowSize;
  int m_ColumnSize;
  Point m_CurPoint;
};

} // namespace of nvs

#endif
