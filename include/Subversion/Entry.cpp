//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <Subversion/Entry.h>
#include <svn_wc.h>

using namespace nvs;

//===----------------------------------------------------------------------===//
// Entry
//===----------------------------------------------------------------------===//
Entry::Entry(const svn_wc_entry_t * src)
  : m_entry(0), m_pool(0), m_valid(false) {
  init(src);
}

Entry::Entry(const Entry & src)
  : m_entry(0), m_pool(0), m_valid(false) {
  init(src);
}

Entry::~Entry()
{
  // no need to explicitely de-allocate m_entry
  // since this will be handled by m_pool
}

void Entry::init(const svn_wc_entry_t * src)
{
  if (src) {
    // copy the contents of src
    m_entry = svn_wc_entry_dup(src, m_pool.handler());
    m_valid = true;
  }
  else {
    // create an empty entry
    m_entry = (svn_wc_entry_t*)
      apr_pcalloc(m_pool.handler(), sizeof(svn_wc_entry_t));
  }
}

Entry& Entry::operator=(const Entry & src)
{
  if (this == &src)
    return *this;

  init(src);
  return *this;
}
