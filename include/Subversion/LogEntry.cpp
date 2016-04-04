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
LogChangePathEntry::LogChangePathEntry(
  const char *path_,
  char action_,
  const char *copyFromPath_,
  const svn_revnum_t copyFromRevision_)
    : path(path_), action(action_),
    copyFromPath(copyFromPath_ != NULL ? copyFromPath_ : ""),
    copyFromRevision(copyFromRevision_)
{
}

//===----------------------------------------------------------------------===//
// LogEntry
//===----------------------------------------------------------------------===//
LogEntry::LogEntry()
{
}

LogEntry::LogEntry(
  const svn_revnum_t revision_,
  const char * author_,
  const char * date_,
  const char * message_)
{
  date = 0;

  if (date_ != 0)
  {
    Pool pool;

    if (svn_time_from_cstring(&date, date_, pool.handler()) != 0)
      date = 0;
  }

  revision = revision_;
  author = author_ == 0 ? "" : author_;
  message = message_ == 0 ? "" : message_;
}
