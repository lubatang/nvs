//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#ifndef NVS_SUBVERSION_REVISION_H
#define NVS_SUBVERSION_REVISION_H
#include <svn_types.h>
#include <svn_opt.h>
#include <Subversion/Datetime.h>

namespace nvs {

  /**
   * Class that encapsulates svn_opt_revnum_t.
   *
   * @see svn_opt_revnum_t
   */
  class Revision
  {
  private:
    svn_opt_revision_t m_revision;

    void
    init(const svn_opt_revision_t * revision);

  public:
    static const Revision START;
    static const Revision BASE;
    static const Revision HEAD;
    static const Revision WORKING;
    static const Revision UNSPECIFIED;

    /**
     * Constructor
     *
     * @param revision revision information
     */
    Revision(const svn_opt_revision_t * revision);

    /**
     * Constructor
     *
     * @param revnum revision number
     */
    Revision(const svn_revnum_t revnum);

    /**
     * Constructor
     *
     * @param kind
     */
    Revision(const svn_opt_revision_kind kind = svn_opt_revision_unspecified);

    /**
     * Constructor
     *
     * @param dateTime DateTime wrapper for apr_time_t
     */
    Revision(const DateTime dateTime);

    /**
     * Copy constructor
     *
     * @param revision Source
     */
    Revision(const Revision & revision);

    /**
     * @return revision information
     */
    const svn_opt_revision_t *
    revision() const;

    /**
     * @see revision (). Same function
     * but with operator overloading
     */
    operator svn_opt_revision_t * ()
    {
      return &m_revision;
    }

    /**
     * @return revision numver
     */
    svn_revnum_t
    revnum() const;

    /**
     * @return revision kind
     */
    svn_opt_revision_kind
    kind() const;

    /**
     * @see kind (). Same function
     * but with operator overloading
     */
    operator svn_opt_revision_kind() const
    {
      return kind();
    }

    /**
     * @return date
     */
    apr_time_t
    date() const;
  };

} // namespace of nvs

#endif
