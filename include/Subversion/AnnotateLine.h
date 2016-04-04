//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#ifndef NVS_SUBVERSION_ANNOTATE_LINE_H
#define NVS_SUBVERSION_ANNOTATE_LINE_H
#include <svn_types.h>

namespace nvs {
  /**
   * This class holds the data for one line in an annotation
   */
  class AnnotateLine
  {
  public:
    AnnotateLine(apr_int64_t line_no,
                 svn_revnum_t revision,
                 const char *author,
                 const char *date,
                 const char *line)
        : m_line_no(line_no), m_revision(revision),
        m_author(author), m_date(date), m_line(line)
    {
    }

    AnnotateLine(const AnnotateLine &other)
        : m_line_no(other.m_line_no), m_revision(other.m_revision),
        m_author(other.m_author), m_date(other.m_date),
        m_line(other.m_line)
    {
    }

    /**
     * destructor
     */
    virtual ~AnnotateLine()
    {
    }

    apr_int64_t
    lineNumber() const
    {
      return m_line_no;
    }
    svn_revnum_t
    revision() const
    {
      return m_revision;
    }


    const std::string &
    author() const
    {
      return m_author;
    }


    const std::string &
    date() const
    {
      return m_date;
    }


    const std::string &
    line() const
    {
      return m_line;
    }

  private:
    apr_int64_t m_line_no;
    svn_revnum_t m_revision;
    std::string m_author;
    std::string m_date;
    std::string m_line;
  };

} // namespace of nvs

#endif
