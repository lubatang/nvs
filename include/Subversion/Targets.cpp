//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <Subversion/Targets.h>
#include <Subversion/Path.h>
#include <Subversion/Pool.h>
#include <svn_types.h>
#include <apr_pools.h>
#include <apr_strings.h>

using namespace nvs;

//===----------------------------------------------------------------------===//
// Targets
//===----------------------------------------------------------------------===//
Targets::Targets(const PathVector & targets)
{
  m_targets = targets;
}

Targets::Targets(const apr_array_header_t * apr_targets)
{
  int i;

  m_targets.clear();
  m_targets.reserve(apr_targets->nelts);

  for (i = 0; i < apr_targets->nelts; i++) {
    const char ** target =
      &APR_ARRAY_IDX(apr_targets, i, const char *);

    m_targets.push_back(Path(*target));
  }
}

Targets::Targets(const Targets & targets)
{
  m_targets = targets.targets();
}

Targets::Targets(const char * target)
{
  if (target != 0)
    m_targets.push_back(target);
}

Targets::~Targets()
{
}

const apr_array_header_t* Targets::array(const Pool& pool) const
{
  PathVector::const_iterator it;

  apr_pool_t *apr_pool = pool.handler();
  apr_array_header_t *apr_targets =
    apr_array_make(apr_pool,
                   m_targets.size(),
                   sizeof(const char *));

  for (it = m_targets.begin(); it != m_targets.end(); it++) {
    const Path &path = *it;
    const char * target =
      apr_pstrdup(apr_pool, path.c_str());

    (*((const char **) apr_array_push(apr_targets))) = target;
  }

  return apr_targets;
}

const PathVector& Targets::targets() const
{
  return m_targets;
}

size_t Targets::size() const
{
  return m_targets.size();
}

const Path Targets::target() const
{
  if (m_targets.size() > 0)
  {
    return m_targets[0];
  }
  else {
    return "";
  }
}

void Targets::push_back(const Path & path)
{
  m_targets.push_back(path);
}

void Targets::clear()
{
  m_targets.clear();
}

void Targets::reserve(size_t size)
{
  m_targets.reserve(size);
}
