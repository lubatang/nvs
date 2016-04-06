//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#ifndef NVS_SUBVERSION_EXCEPTION_H
#define NVS_SUBVERSION_EXCEPTION_H
#include <svn_client.h>

namespace nvs {

class Exception
{
public:
  Exception(const char * message) throw();

  ~Exception() throw();

  const char * message() const;

  apr_status_t apr_err() const;

protected:
  struct Data;
  Data * m;

private:

  Exception(const Exception &) throw();

  Exception() throw();

  Exception & operator = (const Exception &);
};

class ClientException : public Exception
{
public:
  ClientException(svn_error_t * error) throw();

  ClientException(apr_status_t status) throw();

  ClientException(const char * message) throw()
    : Exception(message) {
  }

  ClientException(const ClientException & src) throw();

  virtual ~ClientException() throw();

private:
  ClientException() throw();

  ClientException & operator = (ClientException &);
};

} // namespace of nvs

#endif
