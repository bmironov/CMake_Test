# Visual Studio 2019 Demo CMake Project

This is very simple project that shows how to use Visual Studio 2019 / CMake / Google Test / VS Test Explorer under Windows 10.

## Description

Quite often CMake projects under Visual Studio 2019 lack ability to use Test Explorer. This project shows how make that functionality available in your project.
As a sample, we have 3 main parts:
* apps (this where we have "main" that initializes our "object")
* object (this is where we define our class with main logic of the app)
* tests (this is where we keep our Google Tests against our "object")

"Object" is getting generated as library that is later linked to 2 executables (main & UnitTest).

## Getting Started

### Dependencies

This project has been successfully tested against following configuration: 
* Windows 10 20H2 build 19042.985
* Visual Studio 2019 v16.9.6
* CentOS 7.9 under WSL2
* CMake binaries provided by Microsoft for Linux
* Google Test master branch as of May 21, 2021
* Sample of CMake test
* This project will use *default* WSL distro set by `wsl -s`

Please note that Test Explorer doesn't work when you have WSL target, but unit test is getting produced and can be executed from shell. If you target Windows, then
Test Explorer works just fine.

### Postscriptum

My actual (much bigger than this demo) project has a requirement for C++ 17. This is reflected in CMakeList.txt files of this project.
By default, CentOS 7.9 is shipped with GCC 4.8.5, which doesn't support this C++ standard. The best solution for this is to install newer
GCC via "Development Toolset" and make it default.

Follow wonderful explanation of how to install any Linux distro via Docker running under WSL Ubuntu. These instructions are applicable to WSL2.
[Import any Linux distribution to use with WSL](https://docs.microsoft.com/en-us/windows/wsl/use-custom-distro)

After that install everything required by Visual Studio 2019 to support CMake.
[C++ with Visual Studio 2019 and Windows Subsystem for Linux (WSL).](https://devblogs.microsoft.com/cppblog/c-with-visual-studio-2019-and-windows-subsystem-for-linux-wsl/)
or
[Create a CMake Linux project in Visual Studio.](https://docs.microsoft.com/en-us/cpp/linux/cmake-linux-project?view=msvc-160)

And last but not least: install newer GCC 9.3.1. Below is pretty much all commands to prepare your CentOS 7:
```
yum install passwd sudo wget which
yum install centos-release-scl
yum install devtoolset-9-gcc devtoolset-9-gcc-c++ devtoolset-9-gdb devtoolset-9-make
yum install git rsync
yum install epel-release
yum install ninja-build cmake3
cd /usr/bin
ln -s cmake3 cmake
ln -s ccmake3 ccmake
ln -s cpack3 cpack
ln -s ctest3 ctest
ln -s /opt/rh/devtoolset-9/root/usr/bin/gcc gcc
ln -s /opt/rh/devtoolset-9/root/usr/bin/gdb gdb
ln -s /opt/rh/devtoolset-9/root/usr/bin/make make
```

Standard installation of CentOS 8.3 supports C++ 17 out of the box.

Test application that was produced via this project under CentOS 7.9 with newer GCC successfully runs under default configuration of Red Hat Enterprise Linux 7.7.
