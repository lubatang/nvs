//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#ifndef NVS_SUBVERSION_PATH_H
#define NVS_SUBVERSION_PATH_H
#include <string>
#include <vector>

namespace nvs {

  /**
   * Encapsulation for Subversion Path handling
   */
  class Path
  {
  private:
    std::string m_path;
    bool m_pathIsUrl;

    /**
     * initialize the class
     *
     * @param path Path string
     */
    void init(const char* path);

  public:
    /**
     * Constructor that takes a string as parameter.
     * The string is converted to subversion internal
     * representation. The string is copied.
     *
     * @param path Path string
     */
    Path(const std::string& pPath);

    /**
     * Constructor
     *
     * @see Path::Path (const std::string &)
     * @param path Path string
     */
    Path(const char* pPath = nullptr);

    /**
     * Copy constructor
     *
     * @param path Path to be copied
     */
    Path(const Path & path);

    /**
     * Assignment operator
     */
    Path& operator= (const Path&);

    /**
     * Comparison operator
     */
    bool operator== (const Path&) const;

    /**
     * @return Path string
     */
    const std::string& path() const;

    /**
     * @return Path string as c string
     */
    const char* c_str() const;

    /**
     * check whether a path is set. Right now
     * this checks only if the string is non-
     * empty.
     *
     * @note This is the successor of @a isset which had to be removed
     *       since there was a name conflict with system headers on
     *       some systems (see issue 676)
     * @since 0.12
     *
     * @return true if there is a path set
     */
    bool isSet() const;

    /**
     * shows whether we have a path or url
     *
     * @return true if the path is a valid url
     */
    bool isUrl() const;

    /**
     * adds a new URL component to the path
     *
     * @param component new component to add
     */
    void addComponent(const char * component);

    /**
     * adds a new URL component to the path
     *
     * @param component new component to add
     */
    void addComponent(const std::string & component);

    /**
     * split path in its components
     *
     * @param dirpath directory/path component
     * @param basename filename
     */
    void split(std::string & dirpath, std::string & basename) const;

    /**
     * split path in its components including
     * file extension
     *
     * @param dir directory component
     * @param filename filename
     * @param ext extension (including leading dot ".")
     */
    void split(std::string & dir, std::string & filename, std::string & ext) const;

    /**
     * get a basename of a file
     *
     * @return basename filename without path
     */
    std::string basename() const;

    /**
     * get a name of directory containing file
     *
     * @return dirpath path of directory
     */
    std::string dirpath() const;

    /**
     * get a substring of a path, starting at index
     *
     * @param index
     * @return substr substring
     */
    std::string substr(const size_t index) const;

    /**
     * return path as a string with unescaped special characters
     *
     * @return unescaped path
     */
    std::string unescape() const;

    /**
     * returns the temporary directory
     */
    static Path getTempDir();

    /** return the length of the path-string */
    size_t length() const;

    /** returns the path with native separators */
    std::string native() const;
  };

  typedef std::vector<Path> PathVector;

  extern const PathVector EmptyPathVector;

} // namespace of nvs

#endif
