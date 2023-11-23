# Install script for directory: D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/scripts

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

if(CMAKE_INSTALL_COMPONENT STREQUAL "Server" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share" TYPE FILE FILES
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/scripts/mysql_system_tables.sql"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/scripts/mysql_system_tables_data.sql"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/scripts/fill_help_tables.sql"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/scripts/mysql_sys_schema.sql"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/scripts/mysql_test_data_timezone.sql"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/scripts/mysql_security_commands.sql"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE FILES "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/build-cmake/scripts/mysql_config.pl")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Server_Scripts" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE FILES "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/build-cmake/scripts/mysqld_multi.pl")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Server_Scripts" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE FILES "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/build-cmake/scripts/mysqldumpslow.pl")
endif()

