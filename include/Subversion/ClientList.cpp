//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <Subversion/Client.h>
#include <Subversion/Dirent.h>
#include <Subversion/Exception.h>
#include <svn_client.h>
#include <svn_path.h>
#include <svn_sorts.h>

using namespace nvs;

//===----------------------------------------------------------------------===//
// Client
//===----------------------------------------------------------------------===//
DirEntries Client::list(const char* pPathOrURL,
                        svn_opt_revision_t* pRevision,
                        bool pRecurse) throw(ClientException)
{
  Pool pool;

  apr_hash_t* hash;
  svn_error_t* error = svn_client_ls(&hash, pPathOrURL, pRevision, pRecurse,
                                     *m_pContext, pool.handler());

  if (nullptr != error)
    throw ClientException(error);

  DirEntries entries;
  apr_hash_index_t* item = apr_hash_first(pool.handler(), hash);
  while (nullptr != item) {
    const char* entryname = nullptr;
    svn_dirent_t* dirent;
    apr_hash_this(item, (const void **)&entryname, nullptr, (void **)&dirent);
    entries.push_back(DirEntry(entryname, dirent));

    item = apr_hash_next(item);
  }
  return entries;
}
