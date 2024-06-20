set(SOURCE update_method.cpp main.cpp)

add_executable(update_method ${SOURCE})

target_include_directories(update_method PUBLIC ${PROJECT_SOURCE_DIR}/include)

set_target_properties(update_method PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)