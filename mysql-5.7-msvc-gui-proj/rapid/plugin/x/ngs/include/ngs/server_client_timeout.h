/*
 * Copyright (c) 2015, 2023, Oracle and/or its affiliates.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2.0,
 * as published by the Free Software Foundation.
 *
 * This program is also distributed with certain software (including
 * but not limited to OpenSSL) that is licensed under separate terms,
 * as designated in a particular file or component or in included license
 * documentation.  The authors of MySQL hereby grant you an additional
 * permission to link the program and your derivative works with the
 * separately licensed software that they have included with MySQL.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License, version 2.0, for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301  USA
 */

#ifndef MYSQLX_NGS_SERVER_CLIENT_TIMEOUT_H_
#define MYSQLX_NGS_SERVER_CLIENT_TIMEOUT_H_

#include "ngs_common/chrono.h"
#include "ngs/interface/client_interface.h"
#include "ngs_common/bind.h"


namespace ngs
{

class Server_client_timeout
{
public:
  Server_client_timeout(const chrono::time_point &release_all_before_time);
  void validate_client_state(
      ngs::shared_ptr<Client_interface> client);

  chrono::time_point get_oldest_client_accept_time();

private:
  chrono::time_point m_oldest_client_accept_time;
  const chrono::time_point& m_release_all_before_time;
};

} // namespace ngs

#endif // MYSQLX_NGS_SERVER_CLIENT_TIMEOUT_H_
