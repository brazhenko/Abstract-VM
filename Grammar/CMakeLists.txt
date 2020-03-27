cmake_minimum_required(VERSION 3.14)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

#add_executable(Foo
#Foo.cc
#${BISON_MyParser_OUTPUTS}
#${FLEX_MyScanner_OUTPUTS}
#)

set(AVM_SOURCES ${AVM_SOURCES}
		${FLEX_MyScanner_OUTPUTS}
		PARENT_SCOPE)

set(AVM_HEADERS ${AVM_HEADERS}
		PARENT_SCOPE)


#YACC_FILE(${})
