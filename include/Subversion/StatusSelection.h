//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#ifndef NVS_SUBVERSION_STATUS_SELECTION_H
#define NVS_SUBVERSION_STATUS_SELECTION_H
#include <Subversion/status.h>
#include <Subversion/path.h>

namespace nvs {

  // forward declarations
  class Pool;
  class Targets;

  /**
   * Container for a vector full of @ref Status
   */
  class StatusSel
  {
  public:
    /**
     * default constructor
     */
    StatusSel();

    /**
     * Destructor
     */
    virtual ~ StatusSel();

    /**
     * Copy Constructor
     *
     * @param src Source
     */
    StatusSel(const StatusSel & src);

    /**
     * Assignment operator
     */
    StatusSel &
    operator = (const StatusSel & src);

    /**
     * Returns an apr array containing
     * char *.
     *
     * @param pool Pool used for conversion
     */
    const apr_array_header_t *
    array(const Pool & pool) const;

    /**
     * Returns a vector of statuses
     *
     * @return vector of statuses
     */
    const StatusVector &
    statusVector() const;

    /**
     * Returns a vector of paths
     *
     * @return vector of paths
     */
    const Targets &
    targets() const;

    /**
     * returns the first target in the list
     * or an empty Path if no entries
     * are present
     * @return the first @ref Path in the list
     */
    const Path &
    target() const;

    /**
     * @return the number of targets
     */
    size_t size() const;

    /**
     * reserves @a size
     */
    void
    reserve(size_t size);

    /**
     * add and check the next entry
     *
     * @param status @ref Status to add
     */
    void
    push_back(const Status & status);

    /**
     * cleans out all entries
     */
    void
    clear();

    /**
     * operator to return the vector
     *
     * @return vector with targets
     */
    operator const PathVector & () const;

    /** at least one target is a file */
    bool
    hasFiles() const;

    /** at least one target is a directory */
    bool
    hasDirs() const;

    /** at least one target is versioned */
    bool
    hasVersioned() const;

    /** at least one target is unversioned */
    bool
    hasUnversioned() const;

    /** at least one target is a repository URL */
    bool
    hasUrl() const;

    /** at least one target is a local file or dir */
    bool
    hasLocal() const;

  private:
    struct Data;
    Data * m;
  };

} // namespace of nvs

#endif
