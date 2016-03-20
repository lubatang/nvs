//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <Widget/Palette.h>
#include <curses.h>

using namespace nvs;

//===----------------------------------------------------------------------===//
// Palette
//===----------------------------------------------------------------------===//
bool Palette::hasColors()
{
  return has_colors();
}

bool Palette::init()
{
  if (hasColors()) {
    start_color();
    use_default_colors();

    short fg, bg;
    for (fg = 0; fg < Color::TotalColors; ++fg)
      for (bg = 0; bg < Color::TotalColors; ++bg)
        init_pair(id(fg, bg), fg, bg);

    return true;
  }
  return false;
}

short Palette::id(short pFore, short pBack)
{
  return (pFore*Color::TotalColors + pBack);
}

int Palette::attr(const Color& pColor)
{
  return (COLOR_PAIR(id(pColor.fore(), pColor.back())) | pColor.attribute());
}
