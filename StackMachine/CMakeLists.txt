cmake_minimum_required(VERSION 3.14)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

include_directories(Exceptions)
add_subdirectory(Exceptions)

set(AVM_SOURCES ${AVM_SOURCES}
		${CMAKE_CURRENT_SOURCE_DIR}/StackMachine.cpp
		PARENT_SCOPE)

set(AVM_HEADERS ${AVM_HEADERS}
		${CMAKE_CURRENT_SOURCE_DIR}/StackMachine.h
		PARENT_SCOPE)

