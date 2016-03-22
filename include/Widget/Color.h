//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#ifndef NVS_WIDGET_COLOR_H
#define NVS_WIDGET_COLOR_H
#include <curses.h>

namespace nvs {

class Color
{
public:
  enum Type {
    White   = COLOR_WHITE,
    Red     = COLOR_RED,
    Green   = COLOR_GREEN,
    Yellow  = COLOR_YELLOW,
    Blue    = COLOR_BLUE,
    Magenta = COLOR_MAGENTA,
    Cyan    = COLOR_CYAN,
    Black   = COLOR_BLACK,
    TotalColors = 8,
    Reset   = -1
  };

  enum Attribute {
    Normal    = A_NORMAL,     ///< Normal display (no highlight)
    Standout  = A_STANDOUT,   ///< Best highlighting mode of the terminal.
    Underline = A_UNDERLINE,  ///< Underlining
    Reverse   = A_REVERSE,    ///< Reverse video
    Blink     = A_BLINK,      ///< Blinking
    Dim       = A_DIM,        ///< Half bright
    Bold      = A_BOLD,       ///< Extra bright or bold
  };

  enum Playground {
    Foreground,
    Background
  };

  static const Playground fg = Foreground;
  static const Playground bg = Background;

public:
  Color();

  Color(short pFG, short pBG, attr_t pAttr);

  short fore() const { return m_FG; }

  void setFore(Type pType) { m_FG = pType; }

  short back() const { return m_BG; }

  void setBack(Type pType) { m_BG = pType; }

  Color& add(attr_t pAttr);

  Color& remove(attr_t pAttr);

  attr_t attribute() const { return m_Attr; }

  void setAttribute(attr_t pAttr) { m_Attr = pAttr; }

protected:
  short m_FG;
  short m_BG;
  attr_t m_Attr;
};

} // namespace of nvs

#endif
