//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#ifndef NVS_SUBVERSION_CONTEXT_DATA_H
#define NVS_SUBVERSION_CONTEXT_DATA_H
#include <Subversion/Apr.h>
#include <Subversion/Pool.h>
#include <Subversion/ContextListener.h>

namespace nvs {

struct Context::Data
{
public:
  ContextListener* listener;
  bool logIsSet;
  int promptCounter;
  Pool pool;
  svn_client_ctx_t* ctx;
  std::string username;
  std::string password;
  std::string logMessage;
  std::string configDir;

public:
  Data();

  Data(const std::string& pConfigDir);

  void setAuthCache(bool value);

  void setLogin(const char * usr, const char * pwd);

  void setLogMessage(const char * msg);

  static svn_error_t * onLogMsg(const char **log_msg,
                                const char **tmp_file,
                                apr_array_header_t *, //UNUSED commit_items
                                void *baton,
                                apr_pool_t * pool);

    /**
     * this is the callback function for the subversion
     * api functions to signal the progress of an action
     */
    static void
    onNotify(void * baton,
             const char *path,
             svn_wc_notify_action_t action,
             svn_node_kind_t kind,
             const char *mime_type,
             svn_wc_notify_state_t content_state,
             svn_wc_notify_state_t prop_state,
             svn_revnum_t revision);

#if (SVN_VER_MAJOR >= 1) && (SVN_VER_MINOR >= 2)
    /**
     * this is the callback function for the subversion 1.2
     * api functions to signal the progress of an action
     *
     * @todo right now we forward only to @a onNotify,
     *       but maybe we should a notify2 to the listener
     * @since subversion 1.2
     */
    static void
    onNotify2(void*baton,const svn_wc_notify_t *action,apr_pool_t *);
#endif

    /**
     * this is the callback function for the subversion
     * api functions to signal the progress of an action
     */
    static svn_error_t* onCancel(void * baton);

    /**
     * @see svn_auth_simple_prompt_func_t
     */
    static svn_error_t *
    onSimplePrompt(svn_auth_cred_simple_t **cred,
                   void *baton,
                   const char *realm,
                   const char *username,
                   svn_boolean_t _may_save,
                   apr_pool_t *pool);

    /**
     * @see svn_auth_ssl_server_trust_prompt_func_t
     */
    static svn_error_t *
    onSslServerTrustPrompt(svn_auth_cred_ssl_server_trust_t **cred,
                           void *baton,
                           const char *realm,
                           apr_uint32_t failures,
                           const svn_auth_ssl_server_cert_info_t *info,
                           svn_boolean_t may_save,
                           apr_pool_t *pool);

    /**
     * @see svn_auth_ssl_client_cert_prompt_func_t
     */
    static svn_error_t *
    onSslClientCertPrompt(svn_auth_cred_ssl_client_cert_t **cred,
                          void *baton,
                          apr_pool_t *pool);

    /**
     * @see svn_auth_ssl_client_cert_pw_prompt_func_t
     */
    static svn_error_t *
    onSslClientCertPwPrompt(
      svn_auth_cred_ssl_client_cert_pw_t **cred,
      void *baton,
      const char *realm,
      svn_boolean_t maySave,
      apr_pool_t *pool);

    const char * getUsername() const;

    const char * getPassword() const;

    const char * getLogMessage() const;

    /**
     * if the @a listener is set, use it to retrieve the log
     * message using ContextListener::contextGetLogMessage.
     * This return values is given back, then.
     *
     * if the @a listener is not set the its checked whether
     * the log message has been set using @a setLogMessage
     * yet. If not, return false otherwise true
     *
     * @param msg log message
     * @retval false cancel
     */
    bool retrieveLogMessage(std::string & msg);

    /**
     * if the @a listener is set and no password has been
     * set yet, use it to retrieve login and password using
     * ContextListener::contextGetLogin.
     *
     * if the @a listener is not set, check if setLogin
     * has been called yet.
     *
     * @return continue?
     * @retval false cancel
     */
    bool retrieveLogin(const char * username_, const char * realm, bool &may_save);

  /**
   * if the @a listener is set call the method
   * @a contextNotify
   */
  void notify(const char *path,
           svn_wc_notify_action_t action,
           svn_node_kind_t kind,
           const char *mime_type,
           svn_wc_notify_state_t content_state,
           svn_wc_notify_state_t prop_state,
           svn_revnum_t revision);

  /// if the @a listener is set call the method @a contextCancel
  bool cancel();

  /// translate native c-string to utf8
  static svn_error_t *
  translateString(const char* pStr, const char** pNewStr, apr_pool_t*);

  /**
   * the @a baton is interpreted as Data *
   * Several checks are performed on the baton:
   * - baton == 0?
   * - baton->Data
   * - listener set?
   *
   * @param baton
   * @param data returned data if everything is OK
   * @retval SVN_NO_ERROR if everything is fine
   * @retval SVN_ERR_CANCELLED on invalid values
   */
  static svn_error_t * getData(void * baton, Data ** data);

private:
  void initialize(const char* pConfigDir);
};

} // namespace of nvs

#endif
