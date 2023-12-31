/* Copyright (c) 2010, 2023, Oracle and/or its affiliates.

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
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA */

#ifndef RPL_INFO_VALUES_H
#define RPL_INFO_VALUES_H

#include "my_global.h"

class String;


class Rpl_info_values
{
public:
  Rpl_info_values(int param_ninfo);
  virtual ~Rpl_info_values();

  bool init();

  /** 
    Sequence of values to be read from or stored into a repository.
  */
  String *value;

private:
  /* This property represents the number of fields. */
  int ninfo;

  Rpl_info_values& operator=(const Rpl_info_values& values);
  Rpl_info_values(const Rpl_info_values& values);
};
#endif /* RPL_INFO_VALUES_H */
