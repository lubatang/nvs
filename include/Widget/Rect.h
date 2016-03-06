//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#ifndef NVS_WIDGET_RECTANGLE_H
#define NVS_WIDGET_RECTANGLE_H
#include <Widget/Point.h>

namespace nvs {

/** \class Rect
 *  \brief Rect defines a rectangle in the plane using integer precision
 */
class Rect
{
public:
  Rect();

  Rect(const Point& pTopLeft, const Point& pBottomRight);

  Rect(int pX, int pY, int pWidth, int pHeight);

  void setX(int pX) { m_X = pX; }
  void setY(int pY) { m_Y = pY; }
  void setWidth(int pW) { m_W = pW; }
  void setHeight(int pH) { m_H = pH; }

  int x() const { return m_X; }
  int y() const { return m_Y; }
  int width() const { return m_W; }
  int height() const { return m_H; }

  bool contains(int pX, int pY) const;

  Point center() const { return Point(m_X + m_W/2, m_Y + m_H/2); }

  int left() const { return m_X; }
  int right() const { return (m_X + m_W); }
  int top() const { return m_Y; }
  int bottom() const { return (m_Y + m_H); }

  Point topLeft() const { return Point(left(), top()); }
  Point topRight() const { return Point(right(), top()); }
  Point bottomLeft() const { return Point(left(), bottom()); }
  Point bottomRight() const { return Point(right(), bottom()); }

private:
  int m_X;
  int m_Y;
  int m_W;
  int m_H;
};

} // namespace of nvs

#endif
