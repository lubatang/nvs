//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <NVSCpp/Apr.h>
#include <apr_general.h>

using namespace nvs;

//===----------------------------------------------------------------------===//
// Apr
//===----------------------------------------------------------------------===//
Apr::Apr()
{
  apr_initialize();
}

Apr::~Apr()
{
  apr_terminate();
}
