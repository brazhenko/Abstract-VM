cmake_minimum_required(VERSION 3.15)
project(AVM)

set(CMAKE_CXX_STANDARD 17)

set(AVM_SOURCES ${AVM_SOURCES} main.cpp)

add_subdirectory(Operands)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Operands ${CMAKE_CURRENT_SOURCE_DIR}/Operands/IOperand)

add_subdirectory(StackMachine)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/StackMachine)

add_subdirectory(StackMachine/Instruction)
include_directories(StackMachine/Instruction)

add_executable(${PROJECT_NAME} ${AVM_SOURCES} ${AVM_HEADERS})
