# Install script for directory: D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/rapid/plugin/x

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

if(CMAKE_INSTALL_COMPONENT STREQUAL "Developement" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/build-cmake/rapid/plugin/x/generated/mysqlx_error.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Developement" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/build-cmake/rapid/plugin/x/generated/mysqlx_ername.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Developement" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/build-cmake/rapid/plugin/x/generated/mysqlx_version.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Server" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/plugin" TYPE MODULE FILES "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/build-cmake/rapid/plugin/x/Debug/mysqlx.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/plugin" TYPE MODULE FILES "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/build-cmake/rapid/plugin/x/Release/mysqlx.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/plugin" TYPE MODULE FILES "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/build-cmake/rapid/plugin/x/MinSizeRel/mysqlx.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/plugin" TYPE MODULE FILES "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/build-cmake/rapid/plugin/x/RelWithDebInfo/mysqlx.dll")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Debuginfo" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/plugin" TYPE FILE FILES "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/build-cmake/rapid/plugin/x/Debug/mysqlx.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/plugin" TYPE FILE FILES "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/build-cmake/rapid/plugin/x/Release/mysqlx.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/plugin" TYPE FILE FILES "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/build-cmake/rapid/plugin/x/MinSizeRel/mysqlx.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/plugin" TYPE FILE FILES "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/build-cmake/rapid/plugin/x/RelWithDebInfo/mysqlx.pdb")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Server" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee]|[Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/plugin/debug" TYPE FILE OPTIONAL PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE FILES "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/build-cmake/rapid/plugin/x/Debug/mysqlx.dll")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Server" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee]|[Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/plugin/debug" TYPE FILE OPTIONAL FILES "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/build-cmake/rapid/plugin/x/Debug/mysqlx.pdb")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Client" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/build-cmake/rapid/plugin/x/Debug/mysqlxtest.exe")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/build-cmake/rapid/plugin/x/Release/mysqlxtest.exe")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/build-cmake/rapid/plugin/x/MinSizeRel/mysqlxtest.exe")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/build-cmake/rapid/plugin/x/RelWithDebInfo/mysqlxtest.exe")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Debuginfo" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE FILES "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/build-cmake/rapid/plugin/x/Debug/mysqlxtest.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE FILES "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/build-cmake/rapid/plugin/x/Release/mysqlxtest.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE FILES "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/build-cmake/rapid/plugin/x/MinSizeRel/mysqlxtest.pdb")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE FILES "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/build-cmake/rapid/plugin/x/RelWithDebInfo/mysqlxtest.pdb")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Test" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/mysql-test/suite/x" TYPE FILE FILES "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/rapid/plugin/x/tests/mtr/plugin.defs")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Test" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/mysql-test/suite/x" TYPE DIRECTORY FILES
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/rapid/plugin/x/tests/mtr/t"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/rapid/plugin/x/tests/mtr/r"
    "D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/rapid/plugin/x/tests/mtr/include"
    USE_SOURCE_PERMISSIONS REGEX "/collections$" EXCLUDE)
endif()

