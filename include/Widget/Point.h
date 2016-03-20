//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#ifndef NVS_WIDGET_POINT_H
#define NVS_WIDGET_POINT_H

namespace nvs {

class Point
{
public:
  Point();

  Point(int pX, int pY);

  int x() const { return m_X; }

  int y() const { return m_Y; }

  void setX(int pX) { m_X = pX; }

  void setY(int pY) { m_Y = pY; }

private:
  int m_X;
  int m_Y;
};

} // namespace of nvs

#endif
