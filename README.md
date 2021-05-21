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

Please note that Test Explorer doesn't work when you have WSL target, but unit test is getting produced and can be executed from shell. If you target Windows, then
Test Explorer works just fine.

### Postscriptum

My actual (much bigger than this demo) project has a requirement for C++ 17. This is reflected in CMakeList.txt files of this project.
By default, GCC 4.8.5 that is shipped with CentOS 7.9 doesn't support this C++ standard. There are 2 solutions for this issue: compile own
copy of GCC or use SCL aproach. I chose first option and compiled own copy of GCC 11. Second aproach is a bit more tricky to configure
in WSL environment. In any case, you might have issues down the road trying to distribute your code to standard installations of CentOS 7.

Standard installation of CentOS 8.3 supports C++ 17 out of the box.
