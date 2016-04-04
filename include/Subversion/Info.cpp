//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <Subversion/Info.h>
#include <Subversion/Path.h>
#include <Subversion/Pool.h>

using namespace nvs;

//===----------------------------------------------------------------------===//
// Internal structure
//===----------------------------------------------------------------------===//
struct Info::Data
{
public:
  svn_info_t* info;
  Path path;
  Pool pool;

public:
  /** constructor (because of optional param */
  Data(const Path & path_, const svn_info_t * info_ = 0)
      : info(0), path(path_)
  {
    if (info_ != 0)
      info = svn_info_dup(info_, pool.handler());
  }

  /** copy constructor */
  Data(const Data * src)
      : info(0), path(src->path)
  {
    if (src->info != 0)
      info = svn_info_dup(src->info, pool.handler());
  }
};

//===----------------------------------------------------------------------===//
// Info
//===----------------------------------------------------------------------===//
Info::Info(const Path & path, const svn_info_t * info)
  : m(new Data(path, info)) {
}

Info::Info(const Info & src)
  : m(new Data(src.m)) {
}

Info::~Info()
{
  delete m;
}

Info& Info::operator = (const Info & src)
{
  if (this != &src)
  {
    delete m;
    m = new Data(src.m);
  }

  return *this;
}

svn_node_kind_t Info::kind() const
{
  if (0 == m->info)
    return svn_node_none;
  else
    return m->info->kind;
}

bool Info::isValid() const
{
  return m->info != 0;
}

const char * Info::url() const
{
  if (0 == m->info)
    return 0;
  else
    return m->info->URL;
}
