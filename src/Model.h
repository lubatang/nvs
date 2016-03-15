//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#ifndef NVS_MODEL_H
#define NVS_MODEL_H
#include <vector>
#include <string>

namespace nvs {

struct Change
{
public:
  enum Kind {
    File,
    Directory
  };

  enum Action {
    Edited,
    Added,
    Deleted
  };

public:
  Kind kind;
  Action action;
  std::string path;
  std::string diffs;
};

struct Log
{
public:
  typedef std::vector<Change> ChangeList;

public:
  unsigned int revision;
  std::string author;
  struct tm timestamp;
  std::string message;
  ChangeList changes;
};

} // namespace of nvs

#endif
