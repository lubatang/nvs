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
  LogChangePathEntry(const std::string& pPath,
                     char pAction,
                     const std::string& pCopyFromPath,
                     const RevNum& pCopyFromRevision);

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

  LogEntry(const RevNum& revision,
           const std::string& pAuthor,
           const std::string& pDate,
           const std::string& pMesg);

public:
  RevNum revision;
  std::string author;
  std::string message;
  std::list<LogChangePathEntry> changedPaths;
  Date date;
};

} // namespace of nvs

#endif
