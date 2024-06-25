set(SOURCE dirty_flag.cpp main.cpp)

add_executable(dirty_flag ${SOURCE})

target_include_directories(dirty_flag PUBLIC ${PROJECT_SOURCE_DIR}/include)

set_target_properties(dirty_flag PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)