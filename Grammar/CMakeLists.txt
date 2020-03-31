cmake_minimum_required(VERSION 3.14)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_VERBOSE_MAKEFILE ON)

set(
		FILES_GENERATED_PROPERTIES
		PARENT_SCOPE
)


set(
		AVM_LEXER_OUTPUT
		"${CMAKE_CURRENT_BINARY_DIR}/AVMLexer.ll.cpp"
)

set(
		AVM_LEXER_FILE
		${CMAKE_CURRENT_SOURCE_DIR}/AVMLexer.l
)

### flex target ####
add_custom_command(OUTPUT ${AVM_LEXER_OUTPUT}
		COMMAND lex -o ${AVM_LEXER_OUTPUT}  ${AVM_LEXER_FILE}
		# make it compatible with c++17 :)
		COMMAND sed -i "" -- "s/register//g" ${AVM_LEXER_OUTPUT}
		DEPENDS ${AVM_LEXER_FILE}
		COMMENT "generating lexer"
		VERBATIM
		)
add_custom_target(generateAVMScanner DEPENDS ${AVM_LEXER_OUTPUT} VERBATIM)
####################
set(
		AVM_PARSER_SOURCE_FILE
		"${CMAKE_CURRENT_BINARY_DIR}/AVMParser.yy.cpp"
)
set(
		AVM_PARSER_FILE
		${CMAKE_CURRENT_SOURCE_DIR}/AVMGrammar.y
)
### yacc target ###
add_custom_command(OUTPUT ${AVM_PARSER_SOURCE_FILE}
		COMMAND yacc -d -o ${AVM_PARSER_SOURCE_FILE} ${AVM_PARSER_FILE}
		DEPENDS "${AVM_PARSER_FILE}"
		COMMENT "generating parser"
		VERBATIM
		)


add_custom_target(generateAVMGrammar DEPENDS ${AVM_PARSER_SOURCE_FILE} VERBATIM)
####################

set(
		FILES_GENERATED_PROPERTIES
		${AVM_PARSER_SOURCE_FILE}
		${AVM_LEXER_OUTPUT}
		${CMAKE_CURRENT_BINARY_DIR}/AVMParser.yy.hpp
		PARENT_SCOPE
)


set(AVM_SOURCES ${AVM_SOURCES}
		${CMAKE_CURRENT_BINARY_DIR}/AVMLexer.ll.cpp
		${CMAKE_CURRENT_BINARY_DIR}/AVMParser.yy.cpp
		PARENT_SCOPE)

set(AVM_HEADERS ${AVM_HEADERS}
		${CMAKE_CURRENT_SOURCE_DIR}/AVMLexer.h
		${CMAKE_CURRENT_BINARY_DIR}/AVMParser.yy.hpp
		PARENT_SCOPE)




add_custom_target(Grammar DEPENDS ${AVM_PARSER_SOURCE_FILE} VERBATIM)
add_dependencies(Grammar generateAVMScanner)
