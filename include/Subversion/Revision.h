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
public:
  static const Revision START;
  static const Revision BASE;
  static const Revision HEAD;
  static const Revision WORKING;
  static const Revision UNSPECIFIED;

public:
  Revision(const svn_opt_revision_t * revision);

  Revision(const svn_revnum_t revnum);

  Revision(const svn_opt_revision_kind kind = svn_opt_revision_unspecified);

  Revision(const DateTime dateTime);

  Revision(const Revision& revision);

  /**
   * @return revision information
   */
  const svn_opt_revision_t* revision() const;

  /**
   * @see revision (). Same function
   * but with operator overloading
   */
  operator svn_opt_revision_t * () { return &m_revision; }

  /**
   * @return revision numver
   */
  svn_revnum_t revnum() const;

  /**
   * @return revision kind
   */
  svn_opt_revision_kind kind() const;

  /**
   * @see kind (). Same function
   * but with operator overloading
   */
  operator svn_opt_revision_kind() const { return kind(); }

  apr_time_t date() const;

private:
  svn_opt_revision_t m_revision;

  void init(const svn_opt_revision_t * revision);
};

} // namespace of nvs

#endif
