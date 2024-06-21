set(SOURCE subclass_sandbox.cpp main.cpp)

add_executable(subclass_sandbox ${SOURCE})

target_include_directories(subclass_sandbox PUBLIC ${PROJECT_SOURCE_DIR}/include)

set_target_properties(subclass_sandbox PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)