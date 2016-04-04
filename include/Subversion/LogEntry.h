//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#ifndef NVS_SUBVERSION_LOG_ENTRY_H
#define NVS_SUBVERSION_LOG_ENTRY_H
#include <apr_time.h>
#include <svn_types.h>
#include <list>
#include <string>

namespace nvs {

  struct LogChangePathEntry
  {
    LogChangePathEntry(const char *path_,
                       char action_,
                       const char *copyFromPath_,
                       const svn_revnum_t copyFromRevision_);

    std::string path;
    char action;
    std::string copyFromPath;
    svn_revnum_t copyFromRevision;
  };


  struct LogEntry
  {
public:
    LogEntry();

    LogEntry(const svn_revnum_t revision,
             const char * author,
             const char * date,
             const char * message);

    svn_revnum_t revision;
    std::string author;
    std::string message;
    std::list<LogChangePathEntry> changedPaths;
    apr_time_t date;
  };

} // namespace of nvs

#endif
