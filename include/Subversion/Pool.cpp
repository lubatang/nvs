//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <Subversion/Pool.h>

using namespace nvs;

//===----------------------------------------------------------------------===//
// Pool
//===----------------------------------------------------------------------===//
Pool::Pool(Pool* pParent)
  : m_pParent(pParent), m_pPool(nullptr) {
  doInit();
}

Pool::~Pool()
{
  doClean();
}

void Pool::renew()
{
  doClean();
  doInit();
}

void Pool::doInit()
{
  /// Apr initializes the pool automatically.
  if (nullptr != m_pParent)
    m_pPool = svn_pool_create(m_pParent->handler());
  else
    m_pPool = svn_pool_create(nullptr);
}

void Pool::doClean()
{
  if (isValid())
    svn_pool_destroy(m_pPool);
}
