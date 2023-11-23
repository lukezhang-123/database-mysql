# vs community 2022 编译 mysql 5.7
mysql

源码
https://cdn.mysql.com//Downloads/MySQL-5.7/mysql-boost-5.7.44.tar.gz

安装openssl
https://slproweb.com/download/Win64OpenSSL-1_1_1w.exe
安装完openssl到默认配置，cmake自动识别

cd /d D:\proj\github\lukezhang-123\database-mysql\mysql-5.7-msvc-gui-proj
mkdir build-cmake
cd build-cmake
cmake .. -DWITH_BOOST=..\boost\boost_1_59_0
vs 打开 MySQL.sln

#include "functional"  // std::binary_function
sql\json_dom.h
storage\myisam\sort.cc
storage\innobase\sync\sync0debug.cc

sql_embedded, sql 项目报错字符sql\sql_locale.cc要加 /utf-8
libmysqld\sql_embedded.vcxproj   ItemDefinitionGroup标签，值Debug|x64的下AdditionalOptions标签内容最后加 /utf-8
sql\sql.vcxproj

在最上面的解决方案右键，生成解决方案，编译全部项目组件195个

安装
cd build-cmake
cmake --install . --config Debug --prefix D:\tmp\mysql5.7-01

打包
cd build-cmake
cpack  # _CPack_Packages\win64\ZIP\mysql-5.7.44-winx64  目录下是要打包的文件

cpack -G ZIP --version
cpack build-cmake/ -G ZIP --version

编译安装
https://downloads.mysql.com/docs/mysql-sourcebuild-excerpt-5.7-en.pdf

查看可配置选项 -D参数
cmake .. -L

# vs四种编译模式 Debug, Release, RelWithDebInfo, MinSizeRel
devenv MySQL.sln /build RelWithDebInfo
devenv MySQL.sln /build Debug
执行解决方案内具体一个方案，方案名
devenv MySQL.sln /build Debug /project package
执行install项目，C:/Program Files (x86)/MySQL/，需要权限
devenv MySQL.sln /build Debug /project install
