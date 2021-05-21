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
* CentOS 7 under WSL2
* CMake binaries provided by Microsoft for Linux
* Google Test master branch as of May 21, 2021
* Sample of CMake test

Please note that Test Explorer doesn't work when you have WSL target, but unit test is getting produced and can be executed from shell. If you target Windows, then
Test Explorer works just fine.
