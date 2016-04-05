//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#ifndef NVS_SUBVERSION_TARGETS_H
#define NVS_SUBVERSION_TARGETS_H
#include <apr_tables.h>
#include <Subversion/Path.h>

namespace nvs {

class Pool;

/**
 * Encapsulation for Subversion target arrays handling
 */
class Targets
{
public:
  Targets();

  /**
   * Constructor
   *
   * @param targets vector of paths
   */
  Targets(const PathVector & targets);

  /**
   * Constructor from an APR array containing
   * char *.
   *
   * @param targets APR array header
   */
  Targets(const apr_array_header_t * targets);

  /**
   * Constructor. Initializes list with just
   * one entry
   *
   * @param target
   */
  Targets(const std::string& pTarget);

  /**
   * Copy Constructor
   *
   * @param targets Source
   */
  Targets(const Targets & targets);

  /**
   * Destructor
   */
  virtual ~Targets();

  /**
   * Returns an apr array containing
   * char *.
   *
   * @param pool Pool used for conversion
   */
  const apr_array_header_t* array(const Pool & pool) const;

  /**
   * Returns a vector of paths
   *
   * @return vector of paths
   */
  const PathVector& targets() const;

  /**
   * @return the number of targets
   */
  size_t size() const;

  /**
   * operator to return the vector
   *
   * @return vector with targets
   */
  operator const PathVector & () const
  {
    return m_targets;
  }

  /**
   * returns one single target. in fact,
   * the first in the vector, it there are more
   * than one. if there is no target returns
   * an empty path
   *
   * @return single path
   */
  const Path target() const;

  /**
   * adds a @ref Path to the existing entries
   *
   * @remark you have to make sure the path is
   *         unique
   */
  void push_back(const Path & path);


  /**
   * clears all entries
   */
  void clear();

  /**
   * reserve the size for following calls
   * to @ref push_back
   */
  void reserve(size_t size);

private:
  PathVector m_targets;
};

} // namespace of nvs

#endif
