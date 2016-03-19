//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <Widget/Layout.h>
#include <Widget/Widget.h>
#include <curses.h>
#include <assert.h>

using namespace nvs;

extern WINDOW* stdscr;

//===----------------------------------------------------------------------===//
// Layout
//===----------------------------------------------------------------------===//
Layout::Layout(Orientations pDirection, Widget& pParent)
  : m_Parent(pParent), m_pWindow(nullptr), m_Direction(pDirection) {
  if (pParent.isTopLevel()) {
    m_pWindow = stdscr;
  }
  else { //< get the size from the parent
    m_pWindow = newwin(m_Parent.height(), m_Parent.width(),
                       m_Parent.y(), m_Parent.x());
  }
}

Layout::~Layout()
{
  if (stdscr != m_pWindow)
    delwin(m_pWindow);
}

// re-calculate the size of the layout and all widgets.
void Layout::addWidget(Widget& pWidget)
{
  m_Components.push_back(&pWidget);
}

bool Layout::isTopLevel() const
{
  return (stdscr == m_pWindow);
}

void Layout::refresh()
{
  wrefresh(m_pWindow);
}

void Layout::move(int pX, int pY)
{
  doMove(pX, pY);
  mvwin(m_pWindow, pY, pX);
}

void Layout::resize(int pW, int pH)
{
  doResize(pW, pH);
  wresize(m_pWindow, pH, pW);
}

//===----------------------------------------------------------------------===//
// HLayout
//===----------------------------------------------------------------------===//
HLayout::HLayout(Widget& pParent)
  : Layout(Layout::Horizontal, pParent) {
}

void HLayout::doResize(int pW, int pH)
{
  int tile = pW / m_Components.size();
  ComponentList::iterator com, cEnd = m_Components.end();
  for (com = m_Components.begin(); com != cEnd; ++com)
    (*com)->resize(tile, pH);
}

void HLayout::doMove(int pX, int pY)
{
  int tile = pX / m_Components.size();
  ComponentList::iterator com, cEnd = m_Components.end();
  for (com = m_Components.begin(); com != cEnd; ++com, pX += tile)
    (*com)->move(pX, pY);
}

//===----------------------------------------------------------------------===//
// VLayout
//===----------------------------------------------------------------------===//
VLayout::VLayout(Widget& pParent)
  : Layout(Layout::Vertical, pParent) {
}

void VLayout::doResize(int pW, int pH)
{
  int tile = pH / m_Components.size();
  ComponentList::iterator com, cEnd = m_Components.end();
  for (com = m_Components.begin(); com != cEnd; ++com)
    (*com)->resize(pW, tile);
}

void VLayout::doMove(int pX, int pY)
{
  int tile = pY / m_Components.size();
  ComponentList::iterator com, cEnd = m_Components.end();
  for (com = m_Components.begin(); com != cEnd; ++com, pY += tile)
    (*com)->move(pX, pY);
}
