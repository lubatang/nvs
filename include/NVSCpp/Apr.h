//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#ifndef NVS_SVNCPP_APR_H
#define NVS_SVNCPP_APR_H

namespace nvs {

/** \class Apr
 * Apache Runtime (APR) support.
 */
class Apr
{
public:
  /// Default constructor. Initializes APR
  Apr();

  /// Destructor. Terminates APR
  ~Apr();

private:
  Apr(const Apr &) = delete;

  Apr& operator=(const Apr &) = delete;
};

} // namespace of nvs

#endif
