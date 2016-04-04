//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <Subversion/Client.h>

using namespace nvs;

//===----------------------------------------------------------------------===//
// Client
//===----------------------------------------------------------------------===//
Client::Client(Context * context)
{
  setContext(context);
}

Client::~Client()
{
}

const Context* Client::getContext() const
{
  return m_context;
}

Context* Client::getContext()
{
  return m_context;
}

void Client::setContext(Context * context)
{
  m_context = context;
}
