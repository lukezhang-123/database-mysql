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
#include "mysys_err.h"
#include "my_thread_local.h"
#include <sys/types.h>
#include <sys/stat.h>
#ifdef _WIN32
#include <direct.h>
#endif

int my_mkdir(const char *dir, int Flags, myf MyFlags)
{
  DBUG_ENTER("my_dir");
  DBUG_PRINT("enter",("dir: %s",dir));

#if defined(_WIN32)
  if (mkdir((char*) dir))
#else
  if (mkdir((char*) dir, Flags & my_umask_dir))
#endif
  {
    set_my_errno(errno);
    DBUG_PRINT("error",("error %d when creating direcory %s",my_errno(),dir));
    if (MyFlags & (MY_FFNF | MY_FAE | MY_WME))
    {
      char errbuf[MYSYS_STRERROR_SIZE];
      my_error(EE_CANT_MKDIR,  MYF(0), dir,
               my_errno(), my_strerror(errbuf, sizeof(errbuf), my_errno()));
    }
    DBUG_RETURN(-1);
  }
  DBUG_RETURN(0);
}
