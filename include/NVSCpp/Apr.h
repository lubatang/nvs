//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#ifndef NVS_NVSCPP_APR_H
#define NVS_NVSCPP_APR_H
#include <apr_general.h>

namespace nvs {

/** \class Apr
 * Apache Runtime (APR) support.
 */
class Apr
{
public:
  /// Default constructor. Initializes APR
  Apr() {  apr_initialize(); }

  /// Destructor. Terminates APR
  ~Apr() { apr_terminate(); }

private:
  Apr(const Apr &) = delete;

  Apr& operator=(const Apr &) = delete;
};

} // namespace of nvs

#endif
