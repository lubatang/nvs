//===----------------------------------------------------------------------===//
//
//                            The NVS Project
//
// This file is distributed under GNU GENERAL PUBLIC LICENSE, Version 3.
// See LICENSE for details.
//
//===----------------------------------------------------------------------===//
#include <Subversion/URL.h>
#include <Subversion/Pool.h>
#include <svn_path.h>

using namespace nvs;

//===----------------------------------------------------------------------===//
// Helper
//===----------------------------------------------------------------------===//
static void
findAndReplace(std::string & source, const std::string & find, const std::string & replace)
{
  // start seaching from the beginning
  size_t pos = 0;
  size_t findLength = find.length();
  size_t replaceLength = replace.length();

  do {
    // search for the next occurrenc
    pos = source.find(find, pos);
  
    // found?
    if (pos != std::string::npos) {
      // yes, place
      source.replace(pos, findLength, replace);

      // Make sure we dont search from the beginning
      // othwise replacing % with %25 would result 
      // in an endless loop
      pos = pos + replaceLength;
    }
  } while (pos != std::string::npos);
}

//===----------------------------------------------------------------------===//
// URL
//===----------------------------------------------------------------------===//
Url::Url() {
}

Url::~Url() {
}

bool Url::isValid(const char * pURL)
{
  return (0 != svn_path_is_url(pURL));
}

bool Url::isValid(const std::string& pURL)
{
  return (0 != svn_path_is_url(pURL.c_str()));
}

std::string Url::escape(const char * url)
{
  Pool pool;

  // First make sure % gets escaped
  std::string partlyEscaped(url);
  findAndReplace(partlyEscaped, "%", "%25");

  // Let svn do the first part of the work
  partlyEscaped=svn_path_uri_autoescape(partlyEscaped.c_str(), pool.handler());

  // Then worry about the rest
  findAndReplace(partlyEscaped, "#", "%23");
  findAndReplace(partlyEscaped, ";", "%3B");
  findAndReplace(partlyEscaped, "?", "%3F");
  findAndReplace(partlyEscaped, "[", "%5B");
  findAndReplace(partlyEscaped, "]", "%5D");

  return partlyEscaped;
}


std::string Url::unescape(const char * url)
{
  Pool pool;
  return svn_path_uri_decode(url, pool.handler());
}

/**
 * the implementation of the function that pull the supported
 * url schemas out of the ra layer it rather dirty now since
 * we are lacking a higher level of abstraction
 */
std::vector<std::string> Url::supportedSchemas()
{
  std::vector<std::string> schemas;

  return schemas;
}
