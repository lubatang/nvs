//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#ifndef NVS_SUBVERSION_PROPERTY_H
#define NVS_SUBVERSION_PROPERTY_H
#include <vector>
#include <string>
#include <Subversion/Context.h>
#include <Subversion/Path.h>

namespace nvs {

  struct PropertyEntry
  {
    std::string name;
    std::string value;

    PropertyEntry(const char * name, const char * value);
  };

  // forward declarations
  class Path;

  /**
   * Class for manipulating Subversion properties.
   */
  class Property
  {
  public:
    Property(Context * context = 0,
             const Path & path = "");

    virtual ~Property();

    /**
     * get the list of properties for the path.
     * throws an exception if the path isnt versioned.
     */
    const std::vector<PropertyEntry> &
    entries() const
    {
      return m_entries;
    }

    /**
     * Sets an existing property with a new value or adds a new
     * property.  If a result is added it does not reload the
     * result set.  Run loadPath again.
     * @exception ClientException
     */
    void set(const char * name, const char * value);

    /**
     * Deletes a property.
     * @exception ClientException
     */
    void remove(const char * name);

  private:
    Context * m_context;
    Path m_path;
    std::vector<PropertyEntry> m_entries;

    std::string getValue(const char * name);
    void list();
  };

} // namespace of nvs

#endif
