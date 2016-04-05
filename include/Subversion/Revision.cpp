//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <Subversion/Revision.h>

using namespace nvs;

const Revision Revision::START(svn_opt_revision_number);
const Revision Revision::BASE(svn_opt_revision_base);
const Revision Revision::HEAD(svn_opt_revision_head);
const Revision Revision::WORKING(svn_opt_revision_working);
const Revision Revision::UNSPECIFIED(svn_opt_revision_unspecified);

//===----------------------------------------------------------------------===//
// Revision
//===----------------------------------------------------------------------===//
Revision::Revision(const svn_opt_revision_t * revision)
{
  init(revision);
}

Revision::Revision(const svn_revnum_t revnum)
{
  m_revision.kind = svn_opt_revision_number;
  m_revision.value.number = revnum;
}

Revision::Revision(const svn_opt_revision_kind kind)
{
  m_revision.kind = kind;
  m_revision.value.number = 0;
}

Revision::Revision(const DateTime dateTime)
{
  m_revision.kind = svn_opt_revision_date;
  m_revision.value.date = dateTime.GetAPRTimeT();
}

Revision::Revision(const Revision& revision)
{
  init(revision.revision());
}

void Revision::init(const svn_opt_revision_t * revision)
{
  if (!revision) {
    m_revision.kind = svn_opt_revision_unspecified;
  }
  else {
    m_revision.kind = revision->kind;

    // m_revision.value is a union so we are not
    // allowed to set number if we want to use date
    // and vice versa

    switch (revision->kind) {
    case svn_opt_revision_number:
      m_revision.value.number = revision->value.number;
      break;

    case svn_opt_revision_date:
      m_revision.value.date = revision->value.date;
      break;

    default:
      m_revision.value.number = 0;
    }
  }
}

const svn_opt_revision_t* Revision::revision() const
{
  return &m_revision;
}

svn_revnum_t Revision::revnum() const
{
  return m_revision.value.number;
}

apr_time_t Revision::date() const
{
  return m_revision.value.date;
}

svn_opt_revision_kind Revision::kind() const
{
  return m_revision.kind;
}
