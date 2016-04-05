//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#ifndef NVS_SUBVERSION_URL_H
#define NVS_SUBVERSION_URL_H
#include <string>
#include <vector>

namespace nvs {

  class Url
  {
  public:
    /** Constructor */
    Url();

    /** Destructor */
    virtual ~Url();

    /**
     * Checks if @a url is valid
     *
     * Example of a valid URL:
     *   http://svn.collab.net/repos/svn
     * Example of an invalid URL:
     *   /home/foo/bar
     */
    static bool isValid(const char * urlToValidate);

    static bool isValid(const std::string& urlToValidate);

    /**
     * returns a url with forbidden charachters like spaces escaped
     *
     * Example of input:
     *   http://rapidsvn.tigris.org/x y z.html
     * Output:
     *   http://rapidsvn.tigris.org/x%20y%20z.html
     */
    static std::string
    escape(const char * url);

    /**
     * returns a url with forbidden charachters like spaces unescaped
     *
     * Undo the changes done by the previous function, escape ()
     */
    static std::string
    unescape(const char * url);

    /**
     * returns a vector with url schemas that are
     * supported by svn
     *
     * @return vector with entries like "file:", "http:"
     * @deprecated since 0.9.1 (returns an empty vector now)
     */
    static std::vector<std::string>
    supportedSchemas();
  };

} // namespace of nvs

#endif
