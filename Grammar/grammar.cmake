set(
		FILES_GENERATED_PROPERTIES
)

add_subdirectory(Grammar)
include_directories(Grammar)

set_source_files_properties(
		${FILES_GENERATED_PROPERTIES}
		PROPERTIES GENERATED TRUE
)
