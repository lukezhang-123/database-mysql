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
   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301  USA */

#include "mysys_priv.h"
#include "my_sys.h"
#include <m_string.h>

/**
  Returns full load-path for a file. to may be = path.

  @param to   Pointer to destination which will hold the expanded path.
  @param path Pointer to buffer containing the supplied path.
  @param own_path_prefix  Prefix to be appended to path.

  @retval to  Pointer to the supplied destination buffer
              that will hold the full load-path.
*/

char * my_load_path(char * to, const char *path,
		       const char *own_path_prefix)
{
  char buff[FN_REFLEN];
  int cur_prefix_len;
  const char *buff_ptr= path;

  DBUG_ENTER("my_load_path");
  DBUG_PRINT("enter",("path: %s  prefix: %s",path,
		      own_path_prefix ? own_path_prefix : ""));

  cur_prefix_len= (path[0] == FN_CURLIB && path[1] == FN_LIBCHAR)?2:0;

  // If path starts with current dir or parent-dir unpack path.
  if ( cur_prefix_len || is_prefix(path, FN_PARENTDIR))
  {
    if ((strlen(path) + cur_prefix_len) < FN_REFLEN &&
        !my_getwd(buff, (uint) (FN_REFLEN - strlen(path) + cur_prefix_len), MYF(0)))
    {
        (void) strncat(buff, path + cur_prefix_len, FN_REFLEN - strlen(buff) - 1);
        buff_ptr= buff;
    }
  }
  /*
    Prepend the path with own_path_prefix if own_path_prefix is
    specified and path doesn't start with home directory character
    and path is not a hard-path.
    If path is hard path or home dir, return the path.
  */
  else if (own_path_prefix != NULL &&
           !(path[0] == FN_HOMELIB && path[1] == FN_LIBCHAR) &&
           !test_if_hard_path(path))
  {
    (void) strxnmov(buff, sizeof(buff)-1, own_path_prefix, path, NullS);
    buff_ptr= buff;
  }

  my_stpnmov(to, buff_ptr, FN_REFLEN);
  to[FN_REFLEN-1]= '\0';
  DBUG_PRINT("exit",("to: %s",to));
  DBUG_RETURN(to);
} /* my_load_path */
