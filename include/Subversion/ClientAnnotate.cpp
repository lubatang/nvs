//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <Subversion/Client.h>
#include <svn_client.h>

using namespace nvs;

//===----------------------------------------------------------------------===//
// Client
//===----------------------------------------------------------------------===//
static svn_error_t* annotateReceiver(void *baton,
    apr_int64_t line_no,
    svn_revnum_t revision,
    const char *author,
    const char *date,
    const char *line,
    apr_pool_t * /*pool*/)
{
  AnnotatedFile * entries = (AnnotatedFile *) baton;
  entries->push_back(
      AnnotateLine(line_no, revision,
        author?author:"unknown",
        date?date:"unknown date",
        line?line:"???"));

  return NULL;
}

AnnotatedFile*
Client::annotate(const Path& path,
                 const Revision& revisionStart,
                 const Revision& revisionEnd) throw(ClientException)
{
  Pool pool;
  AnnotatedFile * entries = new AnnotatedFile;
  svn_error_t *error;
  error = svn_client_blame(
      path.c_str(),
      revisionStart.revision(),
      revisionEnd.revision(),
      annotateReceiver,
      entries,
      *this->m_context, // client ctx
      pool.handler());

  if (error != NULL) {
    delete entries;
    throw ClientException(error);
  }

  return entries;
}
