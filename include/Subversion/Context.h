//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#ifndef NVS_SUBVERSION_CONTEXT_H
#define NVS_SUBVERSION_CONTEXT_H
#include <Subversion/Pool.h>
#include <svn_client.h>
#include <string>

namespace nvs {

class ContextListener;

/** \class Context
 *  \brief The Context class presents svn_client_ctx objects.
 */
class Context
{
public:
  /// @param[in] pConfigDir location where the subversion api stores its
  /// configuration
  Context(const std::string &pConfigDir);

  Context(const Context &pOther);

  virtual ~Context();

  /// enable/disable authentication caching
  /// @param[in] pEnable true=enable/false=disable
  void setAuthCache(bool pEnable);

  /// set username/password for authentication
  void setLogin(const std::string& pUsername, const std::string& pPassword);


  /// this will be called at the beginning of an action.
  /// the log message will be reset.
  void reset();

  void setLogMessage(const char * msg);

  const char* getLogMessage() const;

  const char* getUsername() const;

  const char* getPassword() const;

  void setListener(ContextListener* pListener);

  ContextListener* getListener() const;

  /// operator to get svn_client_ctx object
  operator svn_client_ctx_t* ();

private:
  struct Data; ///< forward and hidden declaration

  /// return the svn_client_ctx object
  svn_client_ctx_t * ctx();

private:
  Data* m_pData;

  Context& operator=(const Context &) = delete;
};

} // namespace of nvs

#endif
