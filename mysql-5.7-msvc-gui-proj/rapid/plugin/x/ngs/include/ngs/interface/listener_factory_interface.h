/*
 * Copyright (c) 2016, 2023, Oracle and/or its affiliates.
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

#ifndef _NGS_LISTENER_FACTORY_INTERFACE_H_
#define _NGS_LISTENER_FACTORY_INTERFACE_H_

#include "ngs/interface/listener_interface.h"
#include "ngs/socket_events_interface.h"
#include "ngs/memory.h"


namespace ngs
{

class Socket_events;
typedef Memory_instrumented<Listener_interface>::Unique_ptr Listener_interface_ptr;

class Listener_factory_interface
{
public:
  virtual ~Listener_factory_interface() {}

  virtual Listener_interface_ptr create_unix_socket_listener(const std::string &unix_socket_path, Socket_events_interface &event, const uint32 backlog) = 0;
  virtual Listener_interface_ptr create_tcp_socket_listener(std::string &bind_address, const unsigned short port, const uint32 port_open_timeout,
                                                            Socket_events_interface &event, const uint32 backlog) = 0;
};

} // namespace ngs

#endif // _NGS_LISTENER_FACTORY_INTERFACE_H_
