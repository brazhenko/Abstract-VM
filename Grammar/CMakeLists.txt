cmake_minimum_required(VERSION 3.14)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})


#FIND_PACKAGE(BISON REQUIRED)
#SET(BisonOutput ${CMAKE_SOURCE_DIR}/src/rcdgen/parser.cpp)
#IF(BISON_FOUND)
#	ADD_CUSTOM_COMMAND(
#			OUTPUT ${BisonOutput}
#			COMMAND ${BISON_EXECUTABLE}
#			--defines=${CMAKE_SOURCE_DIR}/src/rcdgen/tokens.h
#			--output=${BisonOutput}
#			${CMAKE_SOURCE_DIR}/src/rcdgen/parser.y
#			COMMENT "Generating parser.cpp"
#	)
#ENDIF()

FIND_PACKAGE(FLEX 2.5.13)
message(${FLEX_EXECUTABLE})
SET(FlexOutput ${CMAKE_BINARY_DIR}/AVMLexer.ll.cpp)
IF(FLEX_FOUND)
	ADD_CUSTOM_COMMAND(
			OUTPUT ${FlexOutput}
			COMMAND ${FLEX_EXECUTABLE}
			--outfile=${FlexOutput}
			${CMAKE_SOURCE_DIR}/AVMLexer.l
			COMMENT "Generating scanner.cpp"
	)
ENDIF()


set(AVM_SOURCES ${AVM_SOURCES}
		${FLEX_MyScanner_OUTPUTS}
		PARENT_SCOPE)

set(AVM_HEADERS ${AVM_HEADERS}
		PARENT_SCOPE)




#YACC_FILE(${})
