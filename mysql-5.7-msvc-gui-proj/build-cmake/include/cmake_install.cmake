# Install script for directory: D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/include

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/MySQL")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/include/../libbinlogevents/export/binary_log_types.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/include/mysql.h"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/include/mysql_com.h"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/include/my_command.h"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/include/mysql_time.h"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/include/my_list.h"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/include/my_alloc.h"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/include/typelib.h"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/include/mysql/plugin.h"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/include/mysql/plugin_audit.h"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/include/mysql/plugin_ftparser.h"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/include/mysql/plugin_validate_password.h"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/include/mysql/plugin_keyring.h"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/include/mysql/plugin_group_replication.h"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/include/my_dbug.h"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/include/m_string.h"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/include/my_sys.h"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/include/my_xml.h"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/include/mysql_embed.h"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/include/my_thread.h"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/include/my_thread_local.h"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/include/decimal.h"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/include/errmsg.h"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/include/my_global.h"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/include/my_getopt.h"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/include/sslopt-longopts.h"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/include/my_dir.h"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/include/sslopt-vars.h"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/include/sslopt-case.h"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/include/sql_common.h"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/include/keycache.h"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/include/m_ctype.h"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/include/my_compiler.h"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/include/mysql_com_server.h"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/include/my_byteorder.h"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/include/byte_order_generic.h"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/include/byte_order_generic_x86.h"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/include/little_endian.h"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/include/big_endian.h"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/include/thr_cond.h"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/include/thr_mutex.h"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/include/thr_rwlock.h"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/build-cmake/include/mysql_version.h"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/build-cmake/include/my_config.h"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/build-cmake/include/mysqld_ername.h"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/build-cmake/include/mysqld_error.h"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/build-cmake/include/sql_state.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/mysql" TYPE DIRECTORY FILES "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/include/mysql/" REGEX "/[^/]*\\.h$" REGEX "/psi\\_abi[^/]*$" EXCLUDE)
endif()

