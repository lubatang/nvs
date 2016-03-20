//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <Widget/Color.h>

using namespace nvs;

//===----------------------------------------------------------------------===//
// Color
//===----------------------------------------------------------------------===//
Color::Color()
  : m_FG(0), m_BG(0), m_Attr(0) {
}

Color::Color(short pFG, short pBG, attr_t pAttr)
  : m_FG(pFG), m_BG(pBG), m_Attr(pAttr) {
}

Color& Color::add(attr_t pAttr)
{
  m_Attr |= pAttr;
  return *this;
}

Color& Color::remove(attr_t  pAttr)
{
  m_Attr &= ~pAttr;
  return *this;
}
