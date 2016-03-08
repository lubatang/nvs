//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#ifndef NVS_WIDGET_EVENT_H
#define NVS_WIDGET_EVENT_H
#include <Widget/Rect.h>

namespace nvs {

/** \class Event
 *  \brief The Event class is the base class of all event classes. Event
 *  objects contain event parameters
 */
class Event
{
public:
  enum Type {
    KeyPress,
    Paint,
    Move
  };

public:
  Event(Type pType);

  virtual ~Event() { }

  Type type() const { return m_Type; }

protected:
  Type m_Type;
};

/** \class KeyEvent
 *  \brief The KeyEvent class describes a key event
 */
class KeyEvent : public Event
{
public:
  explicit KeyEvent(int pKey);

  static bool classof(Event& pEvent) {
    return (Event::KeyPress == pEvent.type());
  }

  int key() const { return m_Key; }

protected:
  int m_Key;
};

/** \class PaintEvent
 *  \brief The PaintEvent class contains event parameters for paint events.
 */
class PaintEvent : public Event
{
public:
  explicit PaintEvent(const Rect& pRegion);

  static bool classof(Event& pEvent) {
    return (Event::Paint == pEvent.type());
  }
protected:
  Rect m_Region;
};

/** \class MoveEvent
 *  \brief The QMoveEvent class contains event parameters for move events.
 */
class MoveEvent : public Event
{
public:
  MoveEvent(const Point& pNew, const Point& pOld);

  const Point& pos() const { return m_NewPos; }

  const Point& oldPos() const { return m_OldPos; }

  static bool classof(Event& pEvent) {
    return (Event::Move == pEvent.type());
  }

protected:
  Point m_NewPos;
  Point m_OldPos;
};

} // namespace of nvs

#endif
