//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#ifndef NVS_APPLICATION_H
#define NVS_APPLICATION_H

namespace nvs {

/** \class NVSApplication
 *  \brief provides the application for MVC pattern.
 */
class NVSApplication
{
public:
  NVSApplication();

  ~NVSApplication();

  /// The main entrance of the application
  virtual void run();
};

} // namespace of nvs

#endif
