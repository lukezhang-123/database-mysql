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

#ifndef COMPRESSION_ZLIB_WRITER_INCLUDED
#define COMPRESSION_ZLIB_WRITER_INCLUDED

#include "i_output_writer.h"
#include "abstract_output_writer_wrapper.h"
#include "i_callable.h"
#include "base/mutex.h"
#include "zlib.h"
#include <string.h>

namespace Mysql{
namespace Tools{
namespace Dump{

/**
  Wrapper to another Output Writer, compresses formatted data stream with zlib.
 */
class Compression_zlib_writer : public I_output_writer,
  public Abstract_output_writer_wrapper
{
public:
  Compression_zlib_writer(
    Mysql::I_callable<bool, const Mysql::Tools::Base::Message_data&>*
      message_handler, Simple_id_generator* object_id_generator,
    uint compression_level);

  ~Compression_zlib_writer();

  void append(const std::string& data_to_append);

private:
  void process_buffer(bool flush_stream);

  my_boost::mutex m_zlib_mutex;
  z_stream m_compression_context;
  std::vector<char> m_buffer;

  const static int buffer_size= 128*1024;
};

}
}
}

#endif
