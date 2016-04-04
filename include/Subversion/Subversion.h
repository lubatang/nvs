//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#ifndef NVS_SUBVERSION_SUBVERSION_H
#define NVS_SUBVERSION_SUBVERSION_H
#include <svn_types.h>
#include <apr_time.h>

namespace nvs {

typedef svn_revnum_t RevNum;
typedef apr_time_t Date;

} // namespace of nvs

#endif
