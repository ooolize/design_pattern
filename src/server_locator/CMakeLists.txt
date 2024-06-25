set(SOURCE server_locator.cpp main.cpp)

add_executable(server_locator ${SOURCE})

target_include_directories(server_locator PUBLIC ${PROJECT_SOURCE_DIR}/include)

set_target_properties(server_locator PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)