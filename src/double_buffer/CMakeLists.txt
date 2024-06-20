set(SOURCE double_buffer.cpp main.cpp)

add_executable(double_buffer ${SOURCE})

target_include_directories(double_buffer PUBLIC ${PROJECT_SOURCE_DIR}/include)

set_target_properties(double_buffer PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)