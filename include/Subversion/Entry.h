//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#ifndef NVS_SUBVERSION_ENTRY_H
#define NVS_SUBVERSION_ENTRY_H
#include <svn_wc.h>
#include <Subversion/Pool.h>

namespace nvs {

  /**
   * C++ API for Subversion.
   * This class wraps around @a svn_wc_entry_t.
   */
  class Entry
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
    Entry(const svn_wc_entry_t * src = 0);

    /**
     * copy constructor
     */
    Entry(const Entry & src);

    /**
     * destructor
     */
    virtual ~Entry();

    /**
     * returns whether this is a valid=versioned
     * entry.
     *
     * @return is entry valid
     * @retval true valid entry
     * @retval false invalid or unversioned entry
     */
    bool isValid() const
    {
      return m_valid;
    }

    /**
     * @return entry's name
     */
    const char *
    name() const
    {
      return m_entry->name;
    }

    /**
     * @return base revision
     */
    svn_revnum_t
    revision() const
    {
      return m_entry->revision;
    }

    /**
     * @return url in repository
     */
    const char *
    url() const
    {
      return m_entry->url;
    }

    /**
     * @return canonical repository url
     */
    const char *
    repos() const
    {
      return m_entry->repos;
    }

    /**
     * @return repository uuid
     */
    const char *
    uuid() const
    {
      return m_entry->uuid;
    }

    /**
     * @return node kind (file, dir, ...)
     */
    svn_node_kind_t
    kind() const
    {
      return m_entry->kind;
    }

    /**
     * @return scheduling (add, delete, replace)
     */
    svn_wc_schedule_t
    schedule() const
    {
      return m_entry->schedule;
    }

    /**
     * @return TRUE if copied
     */
    bool
    isCopied() const
    {
      return m_entry->copied != 0;
    }

    /**
     * @return true if deleted
     */
    bool
    isDeleted() const
    {
      return m_entry->deleted != 0;
    }

    /**
     * @return true if deleted
     */
    bool
    isAbsent() const
    {
      return m_entry->absent != 0;
    }

    /**
     * @return copyfrom location
     */
    const char *
    copyfromUrl() const
    {
      return m_entry->copyfrom_url;
    }

    /**
     * @return copyfrom revision
     */
    svn_revnum_t
    copyfromRev() const
    {
      return m_entry->copyfrom_rev;
    }

    /**
     * @return old version of conflicted file
     */
    const char *
    conflictOld() const
    {
      return m_entry->conflict_old;
    }

    /**
     * @return new version of conflicted file
     */
    const char *
    conflictNew() const
    {
      return m_entry->conflict_new;
    }

    /**
     * @return working version of conflicted file
     */
    const char *
    conflictWrk() const
    {
      return m_entry->conflict_wrk;
    }

    /**
     * @return property reject file
     */
    const char *
    prejfile() const
    {
      return m_entry->prejfile;
    }

    /**
     * @return last up-to-date time for text contents
     * @retval 0 no information available
     */
    apr_time_t
    textTime() const
    {
      return m_entry->text_time;
    }

    /**
     * @return last up-to-date time for properties
     * @retval 0 no information available
     */
    apr_time_t
    propTime() const
    {
      return m_entry->prop_time;
    }

    /**
     * @return base64 encoded checksum
     * @retval NULL for backwards compatibility
     */
    const char *
    checksum() const
    {
      return m_entry->checksum;
    }

    /**
     * @return last revision this was changed
     */
    svn_revnum_t
    cmtRev() const
    {
      return m_entry->cmt_rev;
    }

    /**
     * @return last date this was changed
     */
    apr_time_t
    cmtDate() const
    {
      return m_entry->cmt_date;
    }

    /**
     * @return last commit author of this file
     */
    const char *
    cmtAuthor() const
    {
      return m_entry->cmt_author;
    }

    /**
     * @return svn_wc_entry_t for this class
     */
    operator svn_wc_entry_t * () const
    {
      return m_entry;
    }

    /**
     * assignment operator
     */
    Entry &
    operator = (const Entry &);

  private:
    svn_wc_entry_t * m_entry;
    Pool m_pool;
    bool m_valid;

    /**
     * initializes the members
     */
    void
    init(const svn_wc_entry_t * src);
  };

} // namespace of nvs

#endif
