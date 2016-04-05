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
LogChangePathEntry::LogChangePathEntry(const std::string& pPath,
                                       char pAction,
                                       const std::string& pCopyFromPath,
                                       const RevNum& pCopyFromRevision)
  : path(pPath), action(pAction),
    copyFromPath(pCopyFromPath), copyFromRevision(pCopyFromRevision) {
}

//===----------------------------------------------------------------------===//
// LogEntry
//===----------------------------------------------------------------------===//
LogEntry::LogEntry()
{
}

LogEntry::LogEntry(const RevNum& pRev,
                   const std::string& pAuthor,
                   const std::string& pDate,
                   const std::string& pMesg)
  : revision(pRev), author(pAuthor), message(pMesg), date(0) {
  if (!pDate.empty()) {
    Pool pool;
    if (0 != svn_time_from_cstring(&date, pDate.c_str(), pool.handler()))
      date = 0;
  }
}
