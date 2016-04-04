//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#ifndef NVS_SUBVERSION_WC_H
#define NVS_SUBVERSION_WC_H
#include <Subversion/Revision.h>


namespace nvs {

  // forward declarations
  class Path;

  /**
   * Class that deals with a working copy
   */
  class Wc
  {
  public:
    /**
     * check if Path is a valid working directory
     *
     * @param dir path to a directory
     * @return true=valid working copy
     */
    static bool
    checkWc(const char * dir);

    static bool
    checkWc(const Path & dir);

    /**
     * ensure that an administrative area exists for @a dir, so that @a dir
     * is a working copy subdir based on @a url at @a revision.
     *
     * @param dir path to a directory
     * @param uuid
     * @param url corresponding url
     * @param revision expected working copy revision
     */
    static void
    ensureAdm(const char * dir, const char * uuid,
              const char * url, const Revision & revision);

    /**
     * use \a dir as name for the subversion administrative directory
     * instead of the standard ".svn"
     *
     * @param dir
     */
    static void
    setAdmDir(const char * dir);

    /**
     * checks whether @a name is an administrative directory
     *
     * @remarks @a name may only be a filename, not an absolute path
     */
    static bool
    isAdmDir(const char * name);

  private:
  };

} // namespace of nvs

#endif
