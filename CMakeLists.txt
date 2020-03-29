cmake_minimum_required(VERSION 3.1)
project(AVM)

set(CMAKE_CXX_STANDARD 17)

set(AVM_SOURCES ${AVM_SOURCES} main.cpp Service/ParseContext.cpp Service/ExecuteFile.cpp)

set(AVM_HEADERS ${AVM_HEADERS} UnitTests/UnitTests.hpp Service/AVM.h)
include_directories(UnitTests)

add_subdirectory(Operands)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Operands ${CMAKE_CURRENT_SOURCE_DIR}/Operands/IOperand)

add_subdirectory(StackMachine)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/StackMachine)

add_subdirectory(StackMachine/Instruction)
include_directories(StackMachine/Instruction)

add_subdirectory(Grammar)
include_directories(Grammar)

add_executable(${PROJECT_NAME} ${AVM_SOURCES} ${AVM_HEADERS})
