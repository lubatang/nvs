//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <Subversion/Exception.h>
#include <Subversion/Path.h>
#include <Subversion/Pool.h>
#include <Subversion/Property.h>
#include <Subversion/Revision.h>
#include <svn_client.h>

using namespace nvs;

//===----------------------------------------------------------------------===//
// PropertyEntry
//===----------------------------------------------------------------------===//
PropertyEntry::PropertyEntry(const char * name, const char * value)
{
  this->name = name;
  this->value = value;
}

//===----------------------------------------------------------------------===//
// Property
//===----------------------------------------------------------------------===//
Property::Property(Context * context, const Path & path)
  : m_context(context), m_path(path) {
  list();
}

Property::~Property()
{
}

void Property::list()
{
  Pool pool;
  Revision revision;

  m_entries.clear();
  apr_array_header_t * props;
  svn_error_t * error =
    svn_client_proplist(&props,
                        m_path.c_str(),
                        revision,
                        false, /* recurse */
                        *m_context,
                        pool.handler());
  if (error != NULL)
  {
    throw ClientException(error);
  }

  for (int j = 0; j < props->nelts; ++j)
  {
    svn_client_proplist_item_t *item =
      ((svn_client_proplist_item_t **)props->elts)[j];

    apr_hash_index_t *hi;

    for (hi = apr_hash_first(pool.handler(), item->prop_hash); hi;
         hi = apr_hash_next(hi)) {
      const void *key;
      void *val;

      apr_hash_this(hi, &key, NULL, &val);

      m_entries.push_back(PropertyEntry(
                            (const char *)key, getValue((const char *)key).c_str()));
    }
  }
}

std::string Property::getValue(const char * name)
{
  Pool pool;
  Revision revision;

  apr_hash_t *props;
  svn_client_propget(&props,
                     name,
                     m_path.c_str(),
                     revision,
                     false, // recurse
                     *m_context,
                     pool.handler());

  apr_hash_index_t *hi = apr_hash_first(pool.handler(), props);
  if (!hi) {
    return "";
  }

  const void *key;
  void *val;
  const svn_string_t *propval;
  apr_hash_this(hi, &key, NULL, &val);
  propval = (const svn_string_t *)val;

  return propval->data;
}

void Property::set(const char * name, const char * value)
{
  Pool pool;

  const svn_string_t * propval =
    svn_string_create((const char *) value, pool.handler());

  bool recurse = false;
  bool skip_checks = false;

  svn_error_t * error =
    svn_client_propset2(name,
                        propval,
                        m_path.c_str(),
                        recurse,
                        skip_checks,
                        *m_context,
                        pool.handler());

  if (error != NULL)
    throw ClientException(error);
}

void Property::remove(const char * name)
{
  Pool pool;

  svn_error_t * error =
    svn_client_propset(name,
                       NULL, // value = NULL
                       m_path.c_str(),
                       false, //dont recurse
                       pool.handler());
  if (error != NULL)
    throw ClientException(error);
}
