# Copyright (c) 2011, 2023, Oracle and/or its affiliates.
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
IF(WITH_INNODB_MEMCACHED AND UNIX)
  MY_CHECK_C_COMPILER_FLAG("-Wdiscarded-qualifiers" HAVE_DISCARDED_QUALIFIERS)
  IF (HAVE_DISCARDED_QUALIFIERS)
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-discarded-qualifiers")
  ENDIF()
  MY_CHECK_C_COMPILER_FLAG("-Wimplicit-fallthrough" HAVE_IMPLICIT_FALLTHROUGH)
  IF (HAVE_IMPLICIT_FALLTHROUGH)
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-implicit-fallthrough")
  ENDIF()
  SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-missing-field-initializers")
  SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-sign-compare")
  SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-undef")
  SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-unused-parameter")
  SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-unused-variable")
  SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-vla")

  MY_CHECK_C_COMPILER_FLAG("-Wdeclaration-after-statement"
    HAVE_DECLARATION_AFTER_STATEMENT)
  IF (HAVE_DECLARATION_AFTER_STATEMENT)
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-declaration-after-statement")
  ENDIF()

  MY_CHECK_C_COMPILER_FLAG("-Wduplicate-decl-specifier"
    HAVE_DUPLICATE_DECL_SPECIFIER)
  IF(HAVE_DUPLICATE_DECL_SPECIFIER)
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-duplicate-decl-specifier")
  ENDIF()

  MY_CHECK_C_COMPILER_FLAG("-Wint-conversion" HAVE_INT_CONVERSION)
  IF(HAVE_INT_CONVERSION)
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-int-conversion")
  ENDIF()

  MY_CHECK_C_COMPILER_FLAG("-Wstringop-overflow" HAVE_STRINGOP_OVERFLOW)
  IF(HAVE_STRINGOP_OVERFLOW)
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-stringop-overflow")
  ENDIF()

  MY_CHECK_C_COMPILER_FLAG("-Wstringop-truncation" HAVE_STRINGOP_TRUNCATION)
  IF(HAVE_STRINGOP_TRUNCATION)
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-stringop-truncation")
  ENDIF()

  MY_CHECK_C_COMPILER_FLAG("-Wsuggest-attribute=format"
    HAVE_SUGGEST_ATTRIBUTE_FORMAT)
  IF(HAVE_SUGGEST_ATTRIBUTE_FORMAT)
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-suggest-attribute=format")
  ENDIF()

  MY_CHECK_C_COMPILER_FLAG("-Wunused-but-set-parameter"
    HAVE_UNUSED_BUT_SET_PARAMETER)
  IF(HAVE_UNUSED_BUT_SET_PARAMETER)
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-unused-but-set-parameter")
  ENDIF()

  MY_CHECK_C_COMPILER_FLAG("-Wunused-but-set-variable"
    HAVE_UNUSED_BUT_SET_VARIABLE)
  IF(HAVE_UNUSED_BUT_SET_VARIABLE)
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-unused-but-set-variable")
  ENDIF()

  ADD_SUBDIRECTORY(daemon_memcached)
  ADD_SUBDIRECTORY(innodb_memcache)
ENDIF()

INSTALL(FILES "${CMAKE_SOURCE_DIR}/plugin/innodb_memcached/innodb_memcache/scripts/innodb_memcached_config.sql"
 DESTINATION ${INSTALL_MYSQLSHAREDIR} COMPONENT Server
 PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ)
