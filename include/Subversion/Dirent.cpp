//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <Subversion/Dirent.h>
#include <string>

using namespace nvs;

//===----------------------------------------------------------------------===//
// Internal structure
//===----------------------------------------------------------------------===//
struct DirEntry::Data
{
public:
  std::string name;
  svn_node_kind_t kind;
  svn_filesize_t size;
  bool hasProps;
  svn_revnum_t createdRev;
  apr_time_t time;
  std::string lastAuthor;

public:
  Data()
    : kind(svn_node_unknown), size(0), hasProps(false),
      createdRev(0), time(0) {
  }

  Data(const char * _name, svn_dirent_t * dirEntry)
    : name(_name), kind(dirEntry->kind), size(dirEntry->size),
      hasProps(dirEntry->has_props != 0),
      createdRev(dirEntry->created_rev), time(dirEntry->time) {
    lastAuthor = dirEntry->last_author == 0 ? "" : dirEntry->last_author;
  }

  Data(const DirEntry & src)
  {
    init(src);
  }

  void init(const DirEntry & src)
  {
    name = src.name();
    kind = src.kind();
    size = src.size();
    hasProps = src.hasProps();
    createdRev = src.createdRev();
    time = src.time();
    lastAuthor = src.lastAuthor();
  }
};

//===----------------------------------------------------------------------===//
// DirEntry
//===----------------------------------------------------------------------===//
DirEntry::DirEntry()
  : m(new Data()) {
}

DirEntry::DirEntry(const char * name, svn_dirent_t * DirEntry)
  : m(new Data(name, DirEntry)) {
}

DirEntry::DirEntry(const DirEntry & src)
  : m(new Data(src)) {
}

DirEntry::~DirEntry()
{
  delete m;
}

svn_node_kind_t DirEntry::kind() const
{
  return m->kind;
}

svn_filesize_t DirEntry::size() const
{
  return m->size;
}

bool DirEntry::hasProps() const
{
  return m->hasProps;
}

svn_revnum_t DirEntry::createdRev() const
{
  return m->createdRev;
}

apr_time_t DirEntry::time() const
{
  return m->time;
}

const char * DirEntry::lastAuthor() const
{
  return m->lastAuthor.c_str();
}

const char * DirEntry::name() const
{
  return m->name.c_str();
}

DirEntry& DirEntry::operator= (const DirEntry & dirEntry)
{
  if (this == &dirEntry)
    return *this;

  m->init(dirEntry);
  return *this;
}
