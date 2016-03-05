//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <Widget/Point.h>

using namespace nvs;

//===----------------------------------------------------------------------===//
// Point
//===----------------------------------------------------------------------===//
Point::Point()
  : m_X(0), m_Y(0) {
}

Point::Point(int pX, int pY)
  : m_X(pX), m_Y(pY) {
}
