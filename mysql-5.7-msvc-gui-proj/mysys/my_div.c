/* Copyright (c) 2000, 2023, Oracle and/or its affiliates.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License, version 2.0,
   as published by the Free Software Foundation.

   This program is also distributed with certain software (including
   but not limited to OpenSSL) that is licensed under separate terms,
   as designated in a particular file or component or in included license
   documentation.  The authors of MySQL hereby grant you an additional
   permission to link the program and your derivative works with the
   separately licensed software that they have included with MySQL.

   Without limiting anything contained in the foregoing, this file,
   which is part of C Driver for MySQL (Connector/C), is also subject to the
   Universal FOSS Exception, version 1.0, a copy of which can be found at
   http://oss.oracle.com/licenses/universal-foss-exception.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License, version 2.0, for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA */

#include "mysys_priv.h"
#include "my_sys.h"

/*
  Get filename of file

  SYNOPSIS
    my_filename()
      fd	File descriptor
*/

char * my_filename(File fd)
{
  DBUG_ENTER("my_filename");
  if ((uint) fd >= (uint) my_file_limit)
    DBUG_RETURN((char*) "UNKNOWN");
  if (fd >= 0 && my_file_info[fd].type != UNOPEN)
  {
    DBUG_RETURN(my_file_info[fd].name);
  }
  else
    DBUG_RETURN((char*) "UNOPENED");	/* Debug message */
}
