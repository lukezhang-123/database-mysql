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

#include "composite_message_handler.h"

using namespace Mysql::Tools::Dump;

bool Composite_message_handler::pass_message(
  const Mysql::Tools::Base::Message_data& message_data)
{
  for (
    std::vector<Mysql::I_callable<
    bool, const Mysql::Tools::Base::Message_data&>*>
    ::reverse_iterator it= m_message_handlers.rbegin();
  it != m_message_handlers.rend(); ++it
    )
  {
    if ((**it)(message_data))
    {
      return true;
    }
  }
  return false;
}

Composite_message_handler::Composite_message_handler(
  const std::vector<Mysql::I_callable<bool,
    const Mysql::Tools::Base::Message_data&>*>& message_handlers)
  : m_message_handlers(message_handlers)
{}

Mysql::I_callable<bool, const Mysql::Tools::Base::Message_data&>*
  Composite_message_handler::create_composite_handler(
    const std::vector<Mysql::I_callable<
      bool, const Mysql::Tools::Base::Message_data&>*>& message_handlers)
{
  return new Mysql::Instance_callback<bool,
    const Mysql::Tools::Base::Message_data&, Composite_message_handler>(
      new Composite_message_handler(message_handlers),
        &Composite_message_handler::pass_message);
}
