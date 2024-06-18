set(SOURCE singleton.cpp main.cpp)

add_executable(singleton ${SOURCE})

target_include_directories(singleton PUBLIC ${PROJECT_SOURCE_DIR}/include)

set_target_properties(singleton PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)