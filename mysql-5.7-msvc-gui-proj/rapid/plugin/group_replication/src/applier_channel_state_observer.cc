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
   along with this program; if not, write to the Free Software Foundation,
   51 Franklin Street, Suite 500, Boston, MA 02110-1335 USA */

#include "applier_channel_state_observer.h"
#include "plugin.h"

Applier_channel_state_observer::
Applier_channel_state_observer()
{}

int Applier_channel_state_observer::
thread_start(Binlog_relay_IO_param *param)
{
  return 0;
}

int Applier_channel_state_observer::thread_stop(Binlog_relay_IO_param *param)
{
  return 0;
}

int Applier_channel_state_observer::
applier_start(Binlog_relay_IO_param *param)
{
  return 0;
}

int Applier_channel_state_observer::
applier_stop(Binlog_relay_IO_param *param, bool aborted)
{
  applier_module->inform_of_applier_stop(param->channel_name, aborted);
  return 0;
}

int Applier_channel_state_observer::
before_request_transmit(Binlog_relay_IO_param *param,
                        uint32 flags)
{
  return 0;
}

int Applier_channel_state_observer::
after_read_event(Binlog_relay_IO_param *param,
                 const char *packet, unsigned long len,
                 const char **event_buf,
                 unsigned long *event_len)
{
  return 0;
}

int Applier_channel_state_observer::
after_queue_event(Binlog_relay_IO_param *param,
                  const char *event_buf,
                  unsigned long event_len,
                  uint32 flags)
{
  return 0;
}

int Applier_channel_state_observer::
after_reset_slave(Binlog_relay_IO_param *param)
{
  return 0;
}
