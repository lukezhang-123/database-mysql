#ifndef KEYCACHES_INCLUDED
#define KEYCACHES_INCLUDED

/* Copyright (c) 2002, 2023, Oracle and/or its affiliates.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License, version 2.0,
   as published by the Free Software Foundation.

   This program is also distributed with certain software (including
   but not limited to OpenSSL) that is licensed under separate terms,
   as designated in a particular file or component or in included license
   documentation.  The authors of MySQL hereby grant you an additional
   permission to link the program and your derivative works with the
   separately licensed software that they have included with MySQL.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License, version 2.0, for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   51 Franklin Street, Suite 500, Boston, MA 02110-1335 USA */

#include "sql_list.h"
#include <keycache.h>

extern PSI_memory_key key_memory_NAMED_ILINK_name;

extern "C"
{
  typedef int (*process_key_cache_t) (const char *, KEY_CACHE *);
}

/**
  ilink (intrusive list element) with a name
*/
class NAMED_ILINK :public ilink<NAMED_ILINK>
{
public:
  const char *name;
  size_t name_length;
  uchar* data;

  NAMED_ILINK(I_List<NAMED_ILINK> *links, const char *name_arg,
              size_t name_length_arg, uchar* data_arg)
    :name_length(name_length_arg), data(data_arg)
  {
    name= my_strndup(key_memory_NAMED_ILINK_name,
                     name_arg, name_length, MYF(MY_WME));
    links->push_back(this);
  }

  bool cmp(const char *name_cmp, size_t length)
  {
    return length == name_length && !memcmp(name, name_cmp, length);
  }

  ~NAMED_ILINK()
  {
    my_free((void *) name);
  }
};

class NAMED_ILIST: public I_List<NAMED_ILINK>
{
  public:
  void delete_elements(void (*free_element)(const char*, uchar*));
};

extern LEX_STRING default_key_cache_base;
extern KEY_CACHE zero_key_cache;
extern NAMED_ILIST key_caches;

KEY_CACHE *create_key_cache(const char *name, size_t length);
KEY_CACHE *get_key_cache(LEX_STRING *cache_name);
KEY_CACHE *get_or_create_key_cache(const char *name, size_t length);
void free_key_cache(const char *name, KEY_CACHE *key_cache);
bool process_key_caches(process_key_cache_t func);

#endif /* KEYCACHES_INCLUDED */
