//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <Subversion/Context.h>
#include <Subversion/ContextListener.h>
#include <Subversion/ContextData.h>
#include <Subversion/Apr.h>
#include <apr_xlate.h>
#include <svn_auth.h>
#include <svn_config.h>
#include <svn_subst.h>

using namespace nvs;

//===----------------------------------------------------------------------===//
// Context
//===----------------------------------------------------------------------===//
Context::Context()
  : m_pData(new Data()) {
}

Context::Context(const std::string& pConfigDir)
  : m_pData(new Data(pConfigDir)) {
}

Context::Context(const Context& pOther)
  : m_pData(new Data(pOther.m_pData->configDir)) {
  setLogin(pOther.getUsername(), pOther.getPassword());
}

Context::~Context()
{
  delete m_pData;
}

void Context::setAuthCache(bool pEnable)
{
  m_pData->setAuthCache(pEnable);
}

void Context::setLogin(const std::string& pUsername, const std::string& pPassword)
{
  m_pData->setLogin(pUsername.c_str(), pPassword.c_str());
}

Context::operator svn_client_ctx_t* ()
{
  return &(m_pData->ctx);
}

svn_client_ctx_t* Context::ctx()
{
  return &(m_pData->ctx);
}

void Context::setLogMessage(const char * msg)
{
  m_pData->setLogMessage(msg);
}

const char* Context::getUsername() const
{
  return m_pData->getUsername();
}

const char* Context::getPassword() const
{
  return m_pData->getPassword();
}

const char* Context::getLogMessage() const
{
  return m_pData->getLogMessage();
}

void Context::setListener(ContextListener * listener)
{
  m_pData->listener = listener;
}

ContextListener* Context::getListener() const
{
  return m_pData->listener;
}

void Context::reset()
{
  m_pData->promptCounter = 0;
  m_pData->logIsSet = false;
}
