#!/usr/bin/perl
# Call mtr in out-of-source build
$ENV{MTR_BINDIR} = 'D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/build-cmake';
chdir('D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/mysql-test');
exit(system($^X, 'D:/proj/github/lukezhang-123/database-mysql/mysql-5.7-msvc-gui-proj/mysql-test/mysql-test-run.pl', @ARGV) >> 8);
