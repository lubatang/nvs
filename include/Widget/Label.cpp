//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <Widget/Label.h>
#include <iostream>

using namespace nvs;

//===----------------------------------------------------------------------===//
// Label
//===----------------------------------------------------------------------===//
Label::Label(Widget* pParent)
  : Widget(pParent), m_ScaledContents(true) {
}

Label::Label(const std::string& pText, Widget* pParent)
  : Widget(pParent), m_Text(), m_ScaledContents(true) {
  setText(pText);
}

Label::~Label()
{
}

void Label::setText(const std::string& pText)
{
  m_Text = pText;
  if (hasScaledContents()) {
    int x = 0, cur_x = 0;
    int y = 1;
    std::string::const_iterator ch, cEnd = pText.end();
    for (ch = pText.begin(); ch != cEnd; ++ch) {
      if ('\n' == *ch) {
        ++y;
        if (cur_x > x) {
          x = cur_x;
          cur_x = 0;
        }
      }
      else
        ++cur_x;
    }

    if (cur_x > x)
      x = cur_x;

    resize(x, y);
  }
}

bool Label::paintEvent(PaintEvent* pEvent)
{
  mvwaddstr(win(), y(), x(), m_Text.c_str());
  return true;
}
