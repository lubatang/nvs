//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#ifndef NVS_SUBVERSION_INFO_H
#define NVS_SUBVERSION_INFO_H
#include <svn_client.h>

namespace nvs {

  // forward declarations
  class Path;

  /**
   * C++ API for Subversion.
   * This class wraps around @a svn_info_t.
   */
  class Info
  {
  public:
    /**
     * default constructor. if @a src is set,
     * copy its contents.
     *
     * If @a src is not set (=0) this will be
     * a non-versioned entry. This can be checked
     * later with @a isValid ().
     *
     * @param src another entry to copy from
     */
    Info(const Path & path, const svn_info_t * src = 0);

    /**
     * copy constructor
     */
    Info(const Info & src);

    /**
     * destructor
     */
    virtual ~Info();

    /**
     * assignment operator
     */
    Info &
    operator = (const Info &);

    /**
     * returns whether this is a valid=versioned
     * entry.
     *
     * @return is entry valid
     * @retval true valid entry
     * @retval false invalid or unversioned entry
     */
    bool isValid() const;

    /** @return entry's name */
    const Path &
    path() const;

    /** @return base revision */
    svn_revnum_t
    revision() const;

    /** @return url in repository */
    const char *
    url() const;

    /** @return canonical repository url */
    const char *
    repos() const;

    /** @return repository uuid */
    const char *
    uuid() const;

    /** @return node kind (file, dir, ...) */
    svn_node_kind_t
    kind() const;

    svn_revnum_t
    lastChangedRev() const;

    apr_time_t
    lastChangedDate() const;

    const char *
    lastChangedAuthoer() const;

    /** @todo MORE ENTRIES FROM @ref svn_info_to IF NEEDED */

  private:
    struct Data;

    Data * m;
  };

} // namespace of nvs

#endif
