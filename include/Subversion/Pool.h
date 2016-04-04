//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#ifndef NVS_SUBVERSION_POOL_H
#define NVS_SUBVERSION_POOL_H
#include <Support/Uncopyable.h>
#include <svn_pools.h>

namespace nvs {

/** \class Pool
 *  \brief The Pool class represents an APR memory pool.
 */
class Pool : private Uncopyable
{
public:
  /// @param[in,out] pParent If pParent is nullptr, then use the global pool.
  Pool(Pool* pParent = nullptr);

  virtual ~Pool();

  bool isValid() const { return (nullptr != m_pPool); }

  /// release pool and create a new one
  void renew();

  /// @return apr handle to the pool
  apr_pool_t* handler() const { return m_pPool; }

private:
  void doInit();

  void doClean();

private:
  Pool* m_pParent;
  apr_pool_t* m_pPool;
};

} // namespace of nvs

#endif
