# vs community 2022 编译 mysql 5.7
mysql

源码
https://cdn.mysql.com//Downloads/MySQL-5.7/mysql-boost-5.7.44.tar.gz

安装openssl
https://slproweb.com/download/Win64OpenSSL-1_1_1w.exe
安装完openssl到默认配置，cmake自动识别

cd /d D:\tmp\mysql-5.7.44
mkdir build-cmake
cd build-cmake
cmake .. -DWITH_BOOST=D:\tmp\mysql-5.7.44\boost\boost_1_59_0  # -DWITH_SSL=C:\Program Files\OpenSSL-Win64\include
cmake --build . --config relwithdebinfo --target package
