# DataBase-MySQL 项目

[MySQL 官网](https://dev.mysql.com/downloads/mysql/)

<img src="README/mysql-logo.svg" alt="PostgreSQL" height="200">

## mysql 5.7.44 构建 Visual Studio Community 2022 IDE工程

### 构建过程


1. 下载源码包，

    1) 官网 https://downloads.mysql.com/archives/community/ ， 选择版本 5.7.44，源码包，下载平台无关包含全部源码的tarball

        ![](README/2024-03-20-19-24-35.png)

    2) 官网cdn连接直接下载，https://cdn.mysql.com//Downloads/MySQL-5.7/mysql-boost-5.7.44.tar.gz

2. 安装OpenSSL， vs2022安装cmake组件
   
    https://slproweb.com/download/Win64OpenSSL-1_1_1w.exe

    安装完openssl到默认配置，cmake自动识别

    ![](README/2024-03-20-19-36-54.png)

3. cmake在新目录生成整个工程的解决方案文件
   
   ```
   cd {directory}/database-mysql/mysql-5.7.44

   mkdir build-cmake
   cd build-cmake
   cmake .. -DWITH_BOOST=..\boost\boost_1_59_0
   ```

    ![](README/2024-03-20-20-31-10.png)

4. vs2022打开  {directory}/database-mysql/mysql-5.7.44/build-cmake/MySQL.sln

    ![](README/2024-03-20-19-46-56.png)


    手动修改，下面文件，最后是行号，添加新一行 `#include "functional"`
    ```
    G:\tmp\db-mysql\mysql-5.7.44\storage\myisam\sort.cc:L33
    G:\tmp\db-mysql\mysql-5.7.44\sql\json_dom.h:L39
    G:\tmp\db-mysql\mysql-5.7.44\storage\innobase\sync\sync0debug.cc:L52
    ```

    在vs2022的项目列表，sql_embedded, sql 两个项目右键，属性，添加编译配置 /utf-8

    ![](README/2024-03-20-20-17-58.png)

5. mysql-5.7.44源码目录400MB，编译耗时5min  编译后7.7GB，编译完成结果

    ![](README/2024-03-20-20-25-15.png)

6. 中间报错结果

    ![](README/2024-03-20-20-03-56.png)

    ![](README/2024-03-20-20-11-53.png)

### 其他

```
安装
cd build-cmake
cmake --install . --config Debug --prefix D:\tmp\mysql5.7-01

打包
cd build-cmake
cpack  # _CPack_Packages\win64\ZIP\mysql-5.7.44-winx64  目录下是要打包的文件

cpack -G ZIP --version
cpack build-cmake/ -G ZIP --version
```

编译安装 https://downloads.mysql.com/docs/mysql-sourcebuild-excerpt-5.7-en.pdf

查看可配置选项 -D参数, `cmake .. -L`

### vs四种编译模式 Debug, Release, RelWithDebInfo, MinSizeRel

```
devenv MySQL.sln /build RelWithDebInfo
devenv MySQL.sln /build Debug
执行解决方案内具体一个方案，方案名
devenv MySQL.sln /build Debug /project package
执行install项目，C:/Program Files (x86)/MySQL/，需要权限
devenv MySQL.sln /build Debug /project install
```