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
  enum Qualifier {
    Edited,
    Added,
    Deleted
  };

  std::string file;
  Qualifier qualifier;
  std::vector<std::string> diffs;
  
};

struct Commit
{
  std::string revision;
  std::string timestamp;
  std::string author;
  std::string log;
  std::vector<Change> changes;
};

/** \class Model
 *  \brief The Model class contains all information of SVN.
 */
typedef std::vector<Commit> Model;

};

} // namespace of nvs

#endif
