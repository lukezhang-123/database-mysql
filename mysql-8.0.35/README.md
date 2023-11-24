# mysql-8.0.35

https://cdn.mysql.com/Downloads/MySQL-8.0/mysql-boost-8.0.35.tar.gz


bison >= 3.0.4

cd /d D:\proj\github\lukezhang-123\database-mysql\mysql-8.0.35
mkdir build-cmake
cd build-cmake
cmake .. -DWITH_BOOST=..\boost\boost_1_77_0 -DBISON_EXECUTABLE=D:\aaa\msys64\usr\bin\bison

vs 打开 MySQL.sln  918个项目


### 问题

错误 MSB3491 未能向文件“XXX”写入命令行完全限定的文件名必须少于 260 个字符

HKLM\SYSTEM\CurrentControlSet\Control\FileSystem
LongPathsEnabled 值该为 1
重启vs


innodb_zipdecompress 项目加 utf8


mysql-8.0.35\components\example\test_string_service_charset.cc#L173  # 遥想公瑾当年，小乔初嫁了，雄姿英发


