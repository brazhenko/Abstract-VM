cmake_minimum_required(VERSION 3.1)
project(avm)

set(CMAKE_CXX_STANDARD 17)



set(AVM_SOURCES ${AVM_SOURCES} main.cpp Service/ParseContext.cpp Service/ExecuteFile.cpp Service/GetUsage.cpp)

set(AVM_HEADERS ${AVM_HEADERS} UnitTests/UnitTests.hpp Service/AVM.h Operands/Operand.cpp)
include_directories(UnitTests)

add_subdirectory(Operands)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Operands ${CMAKE_CURRENT_SOURCE_DIR}/Operands/IOperand)

add_subdirectory(StackMachine)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/StackMachine)

add_subdirectory(StackMachine/Instruction)
include_directories(StackMachine/Instruction)



include(Grammar/grammar.cmake)

add_executable(${PROJECT_NAME} ${AVM_SOURCES} ${AVM_HEADERS})
#target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)

add_dependencies(${PROJECT_NAME} Grammar)
#add_dependencies(${PROJECT_NAME} generateAVMGrammar)
