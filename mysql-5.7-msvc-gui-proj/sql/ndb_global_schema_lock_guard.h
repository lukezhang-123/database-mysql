/*
   Copyright (c) 2011, 2023, Oracle and/or its affiliates.

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
   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301  USA
*/

#ifndef NDB_GLOBAL_SCHEMA_LOCK_GUARD_H
#define NDB_GLOBAL_SCHEMA_LOCK_GUARD_H

#include <mysql/plugin.h>

class Ndb_global_schema_lock_guard
{
public:
  Ndb_global_schema_lock_guard(THD *thd);
  ~Ndb_global_schema_lock_guard();
  int lock(bool no_lock_queue=false,
           bool report_cluster_disconnected=true);
private:
  THD* m_thd;
  bool m_locked;
};

#endif

