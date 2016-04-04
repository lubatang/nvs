//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#ifndef NVS_SUBVERSION_DIRENT_H
#define NVS_SUBVERSION_DIRENT_H
#include <svn_client.h>

namespace nvs {

  class DirEntry
  {
  public:
    /**
     * default constructor
     */
    DirEntry();

    /**
     * constructor for existing @a svn_dirent_t entries
     */
    DirEntry(const char * name, svn_dirent_t * dirEntry);

    /**
     * copy constructor
     */
    DirEntry(const DirEntry & src);

    /**
     * destructor
     */
    ~DirEntry();

    /**
     * assignment operator
     */
    DirEntry &
    operator = (const DirEntry &);

    const char *
    name() const;

    svn_node_kind_t
    kind() const;

    svn_filesize_t
    size() const;

    bool
    hasProps() const;

    svn_revnum_t
    createdRev() const;

    apr_time_t
    time() const;

    const char *
    lastAuthor() const;

  private:
    struct Data;
    Data * m;
  };

} // namespace of nvs

#endif
