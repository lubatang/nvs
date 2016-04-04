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

  /**
   * Generic exception class.
   */
  class Exception
  {
  public:
    /**
     * Constructor.  Assigns the exception reason.
     */
    Exception(const char * message) throw();

    ~Exception() throw();

    /**
     * @return the exception message.
     */
    const char * message() const;

    /**
     * @return the outermost error code.
     */
    apr_status_t apr_err() const;

  protected:
    struct Data;
    Data * m;

  private:

    Exception(const Exception &) throw();

    Exception() throw();

    Exception & operator = (const Exception &);
  };

  /**
   * Subversion client exception class.
   */
  class ClientException : public Exception
  {
  public:
    /**
     * Constructor.  Sets the error template and an optional message.
     */
    ClientException(svn_error_t * error) throw();


    /**
     * Constructor that takes only an apr errorcode
     */
    ClientException(apr_status_t status) throw();

    ClientException(const char * message) throw()
        : Exception(message)
    {
    }


    /**
     * Copy constructor
     */
    ClientException(const ClientException & src) throw();

    virtual ~ClientException() throw();

  private:
    ClientException() throw();

    ClientException & operator = (ClientException &);
  };

} // namespace of nvs

#endif
