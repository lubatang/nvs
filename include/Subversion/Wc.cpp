//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <Subversion/exception.h>
#include <Subversion/path.h>
#include <Subversion/pool.h>
#include <Subversion/wc.h>
#include <svn_wc.h>

using namespace nvs;

//===----------------------------------------------------------------------===//
// Wc
//===----------------------------------------------------------------------===//
bool Wc::checkWc(const char * dir)
{
  Path path(dir);
  return Wc::checkWc(path);
}

bool Wc::checkWc(const Path & dir)
{
  Pool pool;
  int wc;

  svn_error_t * error = svn_wc_check_wc(dir.c_str(), &wc, pool.handler());

  if ((error != NULL) || (wc == 0))
  {
    return false;
  }

  return true;
}

void Wc::ensureAdm(const char * dir, const char *uuid,
                   const char * url, const Revision & revision)
{
  Pool pool;
  Path dirPath(dir);
  Path urlPath(url);

  svn_error_t * error =
    svn_wc_ensure_adm(dirPath.c_str(),      // path
                      uuid,                // UUID
                      urlPath.c_str(),     // url
                      revision.revnum(),   // revision
                      pool.handler());

  if (error != NULL)
    throw ClientException(error);
}

void Wc::setAdmDir(const char * dir)
{
  Pool pool;

  svn_error_t * error =
    svn_wc_set_adm_dir(dir, pool.handler());

  if (error != NULL)
    throw ClientException(error);
}

bool Wc::isAdmDir(const char * name)
{
  Pool pool;
  return 0 != svn_wc_is_adm_dir(name, pool.handler());
}
