cmake_minimum_required(VERSION 3.1)


set(AVM_SOURCES ${AVM_SOURCES}
		${CMAKE_CURRENT_SOURCE_DIR}/IOperand/IOperand.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/FactoryOperand.cpp
		PARENT_SCOPE)

set(AVM_HEADERS ${AVM_HEADERS}
		${CMAKE_CURRENT_SOURCE_DIR}/IOperand/IOperand.h
		${CMAKE_CURRENT_SOURCE_DIR}/Operand.hpp
		${CMAKE_CURRENT_SOURCE_DIR}/FactoryOperand.h
		PARENT_SCOPE)

