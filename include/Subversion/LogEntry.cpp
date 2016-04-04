//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <Subversion/LogEntry.h>
#include <Subversion/Pool.h>
#include <svn_time.h>
#include <string>

using namespace nvs;

//===----------------------------------------------------------------------===//
// LogChangePathEntry
//===----------------------------------------------------------------------===//
LogChangePathEntry::LogChangePathEntry(const char* pPath, char pAction,
                                       const char *pCopyFromPath,
                                       const svn_revnum_t pCopyFromRevision)
  : path(pPath), action(pAction),
  copyFromPath(pCopyFromPath != NULL ? pCopyFromPath : ""),
  copyFromRevision(pCopyFromRevision) {
}

//===----------------------------------------------------------------------===//
// LogEntry
//===----------------------------------------------------------------------===//
LogEntry::LogEntry()
{
}

LogEntry::LogEntry(const svn_revnum_t pRev,
                   const char * pAuthor, const char * pDate, const char * pMesg)
{
  date = 0;

  if (pDate != 0) {
    Pool pool;

    if (svn_time_from_cstring(&date, pDate, pool.handler()) != 0)
      date = 0;
  }

  revision = pRev;
  author = pAuthor == 0 ? "" : pAuthor;
  message = pMesg == 0 ? "" : pMesg;
}
