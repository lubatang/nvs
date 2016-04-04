//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#ifndef NVS_SUBVERSION_STATUS_H
#define NVS_SUBVERSION_STATUS_H
#include <svn_wc.h>
#include <Subversion/Entry.h>
#include <Subversion/Pool.h>
#include <vector>

namespace nvs {

  /**
   * Subversion status API.
   *
   * @see svn_wc.hpp
   */
  class Status
  {
  public:
    /**
     * default constructor
     *
     * @param path
     * @param status
     */
    Status(const char * path = 0, const svn_wc_status2_t * status = 0);

    /**
     * copy constructor
     */
    Status(const Status & src);

    /**
     * destructor
     */
    ~Status();

    /**
     * @return path of status entry
     */
    const char *
    path() const;

    /**
     * @return entry for this path
     * @retval entry.isValid () = false item is not versioned
     */
    const Entry
    entry() const;

    /**
     * @return file status property enum of the "textual" component.
     */
    svn_wc_status_kind
    textStatus() const;

    /**
     * @return file status property enum of the "property" component.
     */
    svn_wc_status_kind
    propStatus() const;

    /**
     * @retval TRUE if under version control
     */
    bool
    isVersioned() const;

    /**
     * @retval TRUE if copied
     */
    bool
    isCopied() const;

    /**
     * @retval TRUE if switched
     */
    bool
    isSwitched() const;

    /**
     * @return the entry's text status in the repository
     */
    svn_wc_status_kind
    reposTextStatus() const;

    /**
     * @return the entry's prop status in the repository
     */
    svn_wc_status_kind
    reposPropStatus() const;

    /**
     * @return true if locked
     */
    bool
    isLocked() const;

    /**
     * @return true if has repository lock (not local)
     */
    bool
    isRepLock() const;

    /**
     * @return lock token or null if not locked
     */
    const char *
    lockToken() const;

    /**
     * @return lock owner or null if not locked
     */
    const char *
    lockOwner() const;

    /**
     * @return comment lock, null or no comment
     */
    const char *
    lockComment() const;

    /**
     * @return lock creation date or 0 if not locked
     */
    apr_time_t
    lockCreationDate() const;

    /**
     * assignment operator
     */
    Status &
    operator = (const Status &);

    /**
     * check whether the instance contains real data
     * or nothing if it has constructed with the default
     * constructor
     *
     * @note This is the successor of @a isset which had to be removed
     *       since there was a name conflict with system headers on
     *       some systems (see issue 676)
     * @since 0.12
     */
    bool
    isSet() const;

  private:
    struct Data;
    Data * m;
  };

typedef std::vector<Status> StatusVector;

} // namespace of nvs

#endif
