//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <Subversion/Exception.h>
#include <string>
#include <sstream>

using namespace nvs;

//===----------------------------------------------------------------------===//
// Internal structure
//===----------------------------------------------------------------------===//
struct Exception::Data
{
public:
  std::string message;
  apr_status_t apr_err;

public:
  Data(const char * msg)
      : message(msg)
  {
  }


  Data(const Data& other)
      : message(other.message), apr_err(other.apr_err)
  {
  }
};

//===----------------------------------------------------------------------===//
// Exception
//===----------------------------------------------------------------------===//
Exception::Exception(const char * message) throw()
{
  m = new Data(message);
}

Exception::Exception(const Exception & other) throw()
{
  m = new Data(*other.m);
}

Exception::~Exception() throw()
{
  delete m;
}

apr_status_t
Exception::apr_err() const
{
  return m->apr_err;
}

const char *
Exception::message() const
{
  return m->message.c_str();
}

//===----------------------------------------------------------------------===//
// ClientException
//===----------------------------------------------------------------------===//
ClientException::ClientException(svn_error_t * error) throw()
  : Exception("") {
  if (error == 0)
    return;

  m->apr_err = error->apr_err;
  svn_error_t * next = error->child;
  /// @todo send rapidsvn an hint that error->message may sometimes NULL!
  std::string & message = m->message;
  if (error->message)
    message = error->message;
  else
  {
    message = "Unknown error!\n";
    if (error->file)
    {
      message += "In file ";
      message += error->file;
      std::stringstream num;
      num << " Line " << error->line;
      message += num.str();
    }
  }
  while (next != NULL && next->message != NULL)
  {
    message = message + "\n" + next->message;

    next = next->child;
  }
  svn_error_clear(error);
}

ClientException::ClientException(apr_status_t status) throw()
  : Exception("") {
  m->apr_err = status;
}

ClientException::ClientException(const ClientException & src) throw()
  : Exception(src.message()) {
}

ClientException::~ClientException() throw()
{
}
