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
#include <Subversion/Subversion.h>
#include <list>
#include <string>

namespace nvs {

struct LogChangePathEntry
{
public:
  LogChangePathEntry(const char *path_,
                     char action_,
                     const char *copyFromPath_,
                     const RevNum copyFromRevision_);

public:
  std::string path;
  char action;
  std::string copyFromPath;
  RevNum copyFromRevision;
};


struct LogEntry
{
public:
  LogEntry();

  LogEntry(const RevNum revision,
           const char * author,
           const char * date,
           const char * message);

public:
  RevNum revision;
  std::string author;
  std::string message;
  std::list<LogChangePathEntry> changedPaths;
  Date date;
};

} // namespace of nvs

#endif
