# Copyright (c) 2006, 2023, Oracle and/or its affiliates.
# 
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License, version 2.0,
# as published by the Free Software Foundation.
#
# This program is also distributed with certain software (including
# but not limited to OpenSSL) that is licensed under separate terms,
# as designated in a particular file or component or in included license
# documentation.  The authors of MySQL hereby grant you an additional
# permission to link the program and your derivative works with the
# separately licensed software that they have included with MySQL.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License, version 2.0, for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA

ADD_DEFINITIONS("-DMYSQL_CLIENT")

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/include)

ADD_EXECUTABLE(mysql_client_test mysql_client_test.c)
TARGET_LINK_LIBRARIES(mysql_client_test mysqlclient)
SET_TARGET_PROPERTIES(mysql_client_test PROPERTIES LINKER_LANGUAGE CXX)

IF(WITH_UNIT_TESTS)
  ADD_EXECUTABLE(bug25714 bug25714.c)
  TARGET_LINK_LIBRARIES(bug25714 mysqlclient)
  SET_TARGET_PROPERTIES(bug25714 PROPERTIES LINKER_LANGUAGE CXX)
ENDIF()

INSTALL(TARGETS mysql_client_test DESTINATION ${INSTALL_BINDIR} COMPONENT Test)
