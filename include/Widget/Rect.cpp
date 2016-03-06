//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <Widget/Rect.h>

using namespace nvs;

//===----------------------------------------------------------------------===//
// Rect
//===----------------------------------------------------------------------===//
Rect::Rect()
  : m_X(-1), m_Y(-1), m_W(0), m_H(0) {
}

Rect::Rect(int pX, int pY, int pWidth, int pHeight)
  : m_X(pX), m_Y(pY), m_W(pWidth), m_H(pHeight) {
}

Rect::Rect(const Point& pTL, const Point& pBR)
  : m_X(pTL.x()), m_Y(pTL.y()),
    m_W(pBR.x() - pTL.x()),
    m_H(pBR.y() - pTL.y()) {
}

bool Rect::contains(int pX, int pY) const
{
  return ((x() < pX && pX < left()) && (y() < pY && pY < right()));
}
