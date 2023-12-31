/* Copyright (c) 2006, 2023, Oracle and/or its affiliates.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License, version 2.0,
   as published by the Free Software Foundation.

   This program is also distributed with certain software (including
   but not limited to OpenSSL) that is licensed under separate terms,
   as designated in a particular file or component or in included license
   documentation.  The authors of MySQL hereby grant you an additional
   permission to link the program and your derivative works with the
   separately licensed software that they have included with MySQL.

   Without limiting anything contained in the foregoing, this file,
   which is part of C Driver for MySQL (Connector/C), is also subject to the
   Universal FOSS Exception, version 1.0, a copy of which can be found at
   http://oss.oracle.com/licenses/universal-foss-exception.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License, version 2.0, for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301  USA */

#ifndef THR_MALLOC_INCLUDED
#define THR_MALLOC_INCLUDED

#include "my_global.h"

typedef struct charset_info_st CHARSET_INFO;
typedef struct st_mem_root MEM_ROOT;
typedef unsigned int PSI_memory_key;

void init_sql_alloc(PSI_memory_key key,
                    MEM_ROOT *root, size_t block_size, size_t pre_alloc_size);

void *sql_alloc(size_t);
void *sql_calloc(size_t);
char *sql_strdup(const char *str);
char *sql_strmake(const char *str, size_t len);
void *sql_memdup(const void * ptr, size_t size);
char *sql_strmake_with_convert(const char *str, size_t arg_length,
			       const CHARSET_INFO *from_cs,
			       size_t max_res_length,
			       const CHARSET_INFO *to_cs, size_t *result_length);

#endif /* THR_MALLOC_INCLUDED */
