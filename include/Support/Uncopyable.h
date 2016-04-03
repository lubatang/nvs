//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#ifndef NVS_SUPPORT_UNCOPYABLE_H
#define NVS_SUPPORT_UNCOPYABLE_H

namespace nvs {

/** \class Uncopyable
 *  \brief Uncopyable provides the base class to forbit copy operations.
 *
 */
class Uncopyable
{
protected:
  Uncopyable() { }

  ~Uncopyable() { }

private:
  Uncopyable(const Uncopyable&) = delete; /// NOT TO IMPLEMENT
  Uncopyable& operator=(const Uncopyable&) = delete; /// NOT TO IMPLEMENT
};

} // namespace of nvs

#endif

