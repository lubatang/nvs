//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#ifndef NVS_WIDGET_LABEL_H
#define NVS_WIDGET_LABEL_H
#include <Widget/Widget.h>
#include <string>

namespace nvs {

/** \class Label
 *  \brief The Label widget provides a text display.
 *
 *  Label is used for displaying text. No user interaction functionality is
 *  provided.
 */
class Label : public Widget
{
public:
  explicit Label(Widget* pParent = nullptr);

  Label(const std::string& pText, Widget* pParent = nullptr);

  virtual ~Label();

  void setText(const std::string& pText);

  void setScaledContents(bool pEnable = true) { m_ScaledContents = pEnable; }

  bool hasScaledContents() const { return m_ScaledContents; }

protected:
  std::string m_Text;
  bool m_ScaledContents;
};

} // namespace of nvs

#endif
