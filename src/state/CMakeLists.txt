set(SOURCE state.cpp main.cpp)

add_executable(state ${SOURCE})

target_include_directories(state PUBLIC ${PROJECT_SOURCE_DIR}/include)

set_target_properties(state PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)