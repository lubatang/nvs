//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <Subversion/Datetime.h>
#include <apr_date.h>

using namespace nvs;

//===----------------------------------------------------------------------===//
// DateTime
//===----------------------------------------------------------------------===//
DateTime::DateTime()
  : m_time(APR_DATE_BAD) {
}

DateTime::DateTime(const apr_time_t time)
  : m_time(time) {
}

DateTime::DateTime(const DateTime & dateTime)
  : m_time(dateTime.m_time) {
}

const DateTime & DateTime::operator=(const DateTime & dateTime)
{
  m_time = dateTime.m_time;
  return *this;
}

bool DateTime::operator==(const DateTime & dateTime)
{
  return m_time == dateTime.m_time;
}

bool DateTime::operator !=(const DateTime & dateTime)
{
  return m_time != dateTime.m_time;
}

bool DateTime::IsValid() const
{
  return m_time != APR_DATE_BAD;
}

apr_time_t DateTime::GetAPRTimeT() const
{
  return m_time;
}

bool DateTime::SetRFC822Date(const char* date)
{
  m_time = apr_date_parse_rfc(date);
  return IsValid();
}
