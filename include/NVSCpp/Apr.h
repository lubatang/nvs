//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#ifndef NVS_SUBVERSION_APR_H
#define NVS_SUBVERSION_APR_H
#include <Support/Uncopyable.h>
#include <apr_general.h>

namespace nvs {

/** \class Apr
 * Apache Runtime (APR) support.
 */
class Apr : private Uncopyable
{
public:
  /// Default constructor. Initializes APR
  Apr() {  apr_initialize(); }

  /// Destructor. Terminates APR
  ~Apr() { apr_terminate(); }
};

} // namespace of nvs

#endif
