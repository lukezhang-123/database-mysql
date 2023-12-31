/* Copyright (c) 2016, 2023, Oracle and/or its affiliates.

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
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301  USA */

#include <stdlib.h>
#include "xcom_cfg.h"

cfg_app_xcom_st* the_app_xcom_cfg = NULL;

/* Reasonable initial cache limit */
#define CACHE_LIMIT 1000000000ULL

void init_cfg_app_xcom()
{
	if (!the_app_xcom_cfg)
		the_app_xcom_cfg = (cfg_app_xcom_st *) malloc(sizeof(cfg_app_xcom_st));

	the_app_xcom_cfg->m_poll_spin_loops = 0;
	the_app_xcom_cfg->cache_limit = CACHE_LIMIT;

}

void deinit_cfg_app_xcom()
{
	free(the_app_xcom_cfg);
	the_app_xcom_cfg = NULL;
}


