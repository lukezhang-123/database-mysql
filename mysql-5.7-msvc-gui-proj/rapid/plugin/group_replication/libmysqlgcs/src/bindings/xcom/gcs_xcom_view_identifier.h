/* Copyright (c) 2015, 2023, Oracle and/or its affiliates.

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

#ifndef GCS_XCOM_VIEW_IDENTIFIER_INCLUDED
#define GCS_XCOM_VIEW_IDENTIFIER_INCLUDED

#include "gcs_view_identifier.h"
#include "gcs_types.h"

#include <string>
#include <stdint.h>

class Gcs_xcom_view_identifier: public Gcs_view_identifier
{
public:
  explicit Gcs_xcom_view_identifier(uint64_t fixed_part_arg,
                                    int monotonic_part_arg);

  virtual ~Gcs_xcom_view_identifier();


  uint64_t get_fixed_part() const
  {
    return fixed_part;
  }


  int get_monotonic_part() const
  {
    return monotonic_part;
  }


  void increment_by_one();


  virtual const std::string &get_representation() const;


  Gcs_view_identifier *clone() const;

private:
  void init(uint64_t fixed_part_arg, int monotonic_part_arg);

  uint64_t fixed_part;
  int               monotonic_part;
  std::string       representation;
};

#endif  /* GCS_XCOM_VIEW_IDENTIFIER_INCLUDED */
