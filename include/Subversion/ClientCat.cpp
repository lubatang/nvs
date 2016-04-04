//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <cstdio>
#include <svn_client.h>
#include <Subversion/Client.h>
#include <Subversion/Exception.h>
#include <Subversion/Pool.h>
#include <Subversion/Status.h>

using namespace nvs;

//===----------------------------------------------------------------------===//
// Client
//===----------------------------------------------------------------------===//
std::string Client::cat(const Path & path,
                        const Revision & revision,
                        const Revision & peg_revision) throw(ClientException)
{
  Pool pool;

  svn_stringbuf_t * stringbuf = svn_stringbuf_create("", pool.handler());
  svn_stream_t * stream = svn_stream_from_stringbuf(stringbuf, pool.handler());

  svn_error_t * error;
  error = svn_client_cat2(stream,
      path.c_str(),
      peg_revision.revision(),
      revision.revision(),
      *m_context,
      pool.handler());

  if (error != 0)
    throw ClientException(error);

  return std::string(stringbuf->data, stringbuf->len);
}

/**
 * Create a new temporary file in @a dstPath. If @a dstPath
 * is empty (""), then construct the temporary filename
 * from the temporary directory and the filename component
 * of @a path. The file-extension of @a path will be transformed
 * to @a dstPath and @a dstPath will be a unique filename
 *
 * @param dstPath path to temporary file. Will be constructed
 *                from @a path and temporary dir (and unique elements)
 *                if empty string
 * @param path existing filename. Necessary only for construction
 *             of @a dstPath
 * @param pool pool to use
 * @return open file
 */
static apr_file_t*
openTempFile(Path& dstPath, const Path& path,
             const Revision & revision, Pool & pool) throw(ClientException)
{
  apr_file_t * file = 0;

  if (dstPath.length() > 0) {
    apr_status_t status = apr_file_open(&file, dstPath.c_str(),
                    APR_WRITE | APR_CREATE | APR_TRUNCATE | APR_BINARY,
                    APR_OS_DEFAULT,
                    pool.handler());
    if (status != 0)
      throw ClientException(status);
  }
  else {
    // split the path into its components
    std::string dir, filename, ext;
    path.split(dir, filename, ext);

    // add the revision number to the filename
    char revstring[20];
    if (revision.kind() == revision.HEAD)
      strcpy(revstring, "HEAD");
    else
      sprintf(revstring, "%" SVN_REVNUM_T_FMT, revision.revnum());
    filename += "-";
    filename += revstring;

    // replace the dir component with tempdir
    Path tempPath = Path::getTempDir();
    tempPath.addComponent(filename);

    const char * unique_name;
    svn_error_t * error =
      svn_io_open_unique_file(
          &file, &unique_name,
          tempPath.c_str(),  // path
          ext.c_str(),  // suffix
          0, // dont delete on close
          pool.handler());

    if (error != 0)
      throw ClientException(error);

    dstPath = unique_name;
  }

  return file;
}

void Client::get(Path& dstPath,
                 const Path & path,
                 const Revision & revision,
                 const Revision & peg_revision) throw(ClientException)
{
  Pool pool;

  // create a new file and suppose we only want
  // this users to be able to read and write the file

  apr_file_t * file = openTempFile(dstPath, path, revision, pool);

  // now create a stream and let svn_client_cat write to the
  // stream
  svn_stream_t * stream = svn_stream_from_aprfile(file, pool.handler());
  if (stream != 0) {
    svn_error_t * error = svn_client_cat2(
        stream,
        path.c_str(),
        peg_revision.revision() ,
        revision.revision(),
        *m_context,
        pool.handler());

    if (error != 0)
      throw ClientException(error);

    svn_stream_close(stream);
  }

  // finalize stuff
  apr_file_close(file);
}
