/*
  Copyright (c) 2015, 2023, Oracle and/or its affiliates.

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

#include "thread_specific_connection_provider.h"

using namespace Mysql::Tools::Dump;

Mysql::Tools::Base::Mysql_query_runner*
  Thread_specific_connection_provider::get_runner(
    Mysql::I_callable<bool, const Mysql::Tools::Base::Message_data&>*
      message_handler)
{
  Mysql::Tools::Base::Mysql_query_runner* runner= m_runner.get();
  if (runner == NULL)
  {
    runner= this->create_new_runner(message_handler);
    runner->run_query("SET SQL_QUOTE_SHOW_CREATE= 1");
    /*
      Do not allow server to make any timezone conversion even if it
      has a different time zone set.
    */
    runner->run_query("SET TIME_ZONE='+00:00'");
    m_runner.reset(runner);

    my_boost::mutex::scoped_lock lock(m_runners_created_lock);
    m_runners_created.push_back(runner);
  }
  // Deliver copy of original runner.
  return new Mysql::Tools::Base::Mysql_query_runner(*runner);
}

Thread_specific_connection_provider::Thread_specific_connection_provider(
  Mysql::Tools::Base::I_connection_factory* connection_factory)
  : Abstract_connection_provider(connection_factory)
{}

Thread_specific_connection_provider::~Thread_specific_connection_provider()
{
  for (std::vector<Mysql::Tools::Base::Mysql_query_runner*>::iterator
    it= m_runners_created.begin(); it != m_runners_created.end(); ++it)
  {
    delete *it;
  }
}
