//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <Subversion/Client.h>
#include <Subversion/Path.h>
#include <Subversion/Exception.h>
#include <Subversion/Pool.h>
#include <Subversion/Revision.h>
#include <svn_client.h>

using namespace nvs;

//===----------------------------------------------------------------------===//
//  Client
//===----------------------------------------------------------------------===//
/**
 * lists properties in @a path no matter whether local or
 * repository
 *
 * @param path
 * @param revision
 * @param recurse
 * @return PropertiesList
 */
PathPropertiesMapList
Client::proplist(const Path & path, const Revision & revision, bool recurse)
{
  Pool pool;
  apr_array_header_t *props;

  svn_error_t* error = svn_client_proplist(&props,
          path.c_str(),
          revision.revision(),
          recurse,
          *m_context,
          pool.handler());
  if (error != NULL)
    throw ClientException(error);

  PathPropertiesMapList path_prop_map_list;
  for (int j = 0; j < props->nelts; ++j) {
    svn_client_proplist_item_t *item = ((svn_client_proplist_item_t **) props->elts)[j];

    PropertiesMap  prop_map;

    apr_hash_index_t* hi = apr_hash_first(pool.handler(), item->prop_hash);
    while (nullptr != hi) {
      const void* key = nullptr;
      void* val = nullptr;

      apr_hash_this(hi, &key, nullptr, &val);

      prop_map[std::string((const char *)key)] = std::string(((const svn_string_t *)val)->data);
      hi = apr_hash_next(hi);
    }

    path_prop_map_list.push_back(PathPropertiesMapEntry(item->node_name->data, prop_map));
  }

  return path_prop_map_list;
}

/**
 * lists properties in @a path no matter whether local or
 * repository
 *
 * @param path
 * @param revision
 * @param recurse
 * @return PropertiesList
 */

PathPropertiesMapList
Client::propget(const char *propName, const Path & path, const Revision & revision, bool recurse)
{
  Pool    pool;

  apr_hash_t* props;
  svn_error_t* error = svn_client_propget(&props,
         propName,
         path.c_str(),
         revision.revision(),
         recurse,
         *m_context,
         pool.handler());

  if (error != NULL)
    throw ClientException(error);

  PathPropertiesMapList path_prop_map_list;
  apr_hash_index_t *hi = apr_hash_first(pool.handler(), props);
  while (nullptr != hi) {
    PropertiesMap  prop_map;

    const void* key = nullptr;
    void* val = nullptr;

    apr_hash_this(hi, &key, NULL, &val);

    prop_map[std::string(propName)] = std::string(((const svn_string_t *)val)->data);

    path_prop_map_list.push_back(PathPropertiesMapEntry((const char *)key, prop_map));

    hi = apr_hash_next(hi);
  }

  return path_prop_map_list;
}

/**
 * set property in @a path no matter whether local or
 * repository
 *
 * @param path
 * @param revision
 * @param propName
 * @param propValue
 * @param recurse
 * @return PropertiesList
 */
void Client::propset(const char *propName,
                     const char *propValue,
                     const Path & path,
                     const Revision & /* revision */ ,
                     bool recurse,
                     bool skip_checks)
{
  Pool pool;

  const svn_string_t *propval = svn_string_create((const char *)propValue, pool.handler());

  svn_error_t* error = svn_client_propset2(propName,
          propval,
          path.c_str(),
          recurse,
          skip_checks,
          *m_context,
          pool.handler());
  if (error != NULL)
    throw ClientException(error);
}

/**
 * delete property in @a path no matter whether local or
 * repository
 *
 * @param path
 * @param revision
 * @param propName
 * @param propValue
 * @param recurse
 * @return PropertiesList
 */
void Client::propdel(const char *propName, const Path & path,
                     const Revision&, bool recurse)
{
  Pool pool;

  svn_error_t* error =
     svn_client_propset(propName, NULL, path.c_str(), recurse, pool.handler());
  if (error != NULL)
    throw ClientException(error);
}

//===----------------------------------------------------------------------===//
// revprop functions
//===----------------------------------------------------------------------===//
/**
 * lists revision properties in @a path no matter whether local or
 * repository
 *
 * @param path
 * @param revision
 * @param recurse
 * @return PropertiesList
 */
std::pair<svn_revnum_t, PropertiesMap>
Client::revproplist(const Path & path, const Revision & revision)
{
  Pool pool;

  apr_hash_t* props;
  svn_revnum_t revnum;
  svn_error_t* error = svn_client_revprop_list(&props,
        path.c_str(),
        revision.revision(),
        &revnum,
        *m_context,
        pool.handler());

  if (error != NULL)
    throw ClientException(error);

  PropertiesMap  prop_map;
  apr_hash_index_t *hi = apr_hash_first(pool.handler(), props);
  while (nullptr != hi) {
    const void* key;
    void* val;

    apr_hash_this(hi, &key, NULL, &val);
    prop_map[std::string((const char *)key)] = std::string(((const svn_string_t *)val)->data);

    hi = apr_hash_next(hi);
  }

  return std::pair<svn_revnum_t, PropertiesMap> (revnum, prop_map);
}

/**
 * lists one revision property in @a path no matter whether local or
 * repository
 *
 * @param path
 * @param revision
 * @param recurse
 * @return PropertiesList
 */
std::pair<svn_revnum_t, std::string>
Client::revpropget(const char *propName, const Path & path, const Revision & revision)
{
  Pool pool;

  svn_string_t* propval;
  svn_revnum_t revnum;
  svn_error_t* error = svn_client_revprop_get(propName,
                                              &propval,
                                              path.c_str(),
                                              revision.revision(),
                                              &revnum,
                                              *m_context,
                                              pool.handler());

  if (error != NULL)
    throw ClientException(error);

  // if the property does not exist NULL is returned
  if (propval == NULL)
    return std::pair<svn_revnum_t, std::string>(0, std::string());

  return std::pair<svn_revnum_t, std::string> (revnum, std::string(propval->data));
}

/**
 * set property in @a path no matter whether local or
 * repository
 *
 * @param path
 * @param revision
 * @param propName
 * @param propValue
 * @param recurse
 * @param revprop
 * @return PropertiesList
 */
svn_revnum_t
Client::revpropset(const char *propName, const char *propValue,
                   const Path& path, const Revision& revision,
                   bool force)
{
  Pool pool;

  const svn_string_t *propval = svn_string_create((const char *)propValue, pool.handler());

  svn_revnum_t revnum;
  svn_error_t* error = svn_client_revprop_set(propName,
                                              propval,
                                              path.c_str(),
                                              revision.revision(),
                                              &revnum,
                                              force,
                                              *m_context,
                                              pool.handler());

  if (error != NULL)
    throw ClientException(error);

  return revnum;
}

/**
 * delete property in @a path no matter whether local or
 * repository
 *
 * @param path
 * @param revision
 * @param propName
 * @param propValue
 * @param recurse
 * @param revprop
 * @return PropertiesList
 */
svn_revnum_t Client::revpropdel(const char *propName, const Path & path, const Revision & revision, bool force)
{
  Pool pool;

  svn_revnum_t revnum;
  svn_error_t* error = svn_client_revprop_set(propName,
                                          NULL, //value = NULL
                                          path.c_str(),
                                          revision.revision(),
                                          &revnum,
                                          force,
                                          *m_context,
                                          pool.handler());

  if (error != NULL)
    throw ClientException(error);

  return revnum;
}
