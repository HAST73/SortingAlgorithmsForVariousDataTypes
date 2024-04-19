cmake_minimum_required(VERSION 3.23)
project(Project_AIZO)

set(CMAKE_CXX_STANDARD 23)

add_executable(Project_AIZO Sources/main.cpp Sources/Menu.cpp Headers/Menu.h Headers/SelectDataType.h Sources/SelectDataType.cpp Sources/test.txt Sources/ReadFile.cpp Headers/ReadFile.h Headers/ViewArrays.h Sources/ViewArrays.cpp Sources/SelectWriteOrUse.cpp Headers/SelectWriteOrUse.h Sources/Sort.cpp Headers/Sort.h Sources/SelectSort.cpp Headers/SelectSort.h)
