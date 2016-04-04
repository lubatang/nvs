//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#ifndef NVS_SUBVERSION_DATETIME_H
#define NVS_SUBVERSION_DATETIME_H
#include <svn_types.h>

namespace nvs {
  /**
   * Class that encapsulates apr_time_t.
   *
   * @see apr_time_t
   */
  class DateTime
  {
  private:
    apr_time_t m_time;

  public:

    /**
     * Default Constructor
     */
    DateTime();

    /**
     * Constructor
     *
     * @param time number of microseconds since 00:00:00 january 1, 1970 UTC
     */
    DateTime(const apr_time_t time);

    /**
     * Copy constructor
     *
     * @param dateTime Source
     */
    DateTime(const DateTime & dateTime);

    /**
     * @param dateTime Source
     */
    const DateTime &
    operator =(const DateTime & dateTime);

    /**
     * @param dateTime Comparator
     */
    bool
    operator ==(const DateTime & dateTime);

    /**
     * @param dateTime Comparator
     */
    bool
    operator !=(const DateTime & dateTime);

    /**
     * @return Is a valid (non-zero) date
     */
    bool
    IsValid() const;

    /**
     * @return APR apr_time_t
     */
    apr_time_t
    GetAPRTimeT() const;

    /**
     * Set from date string of the form below, using apr_date_parse_rfc
     *
     * <PRE>
     *     Sun, 06 Nov 1994 08:49:37 GMT
     * </PRE>
     *
     * @see apr_date_parse_rfc
     * @return Successfully parsed
     */
    bool
    SetRFC822Date(const char* date);
  };

} // namespace of nvs

#endif
