set(SOURCE event_queue.cpp main.cpp)

add_executable(event_queue ${SOURCE})

target_include_directories(event_queue PUBLIC ${PROJECT_SOURCE_DIR}/include)

set_target_properties(event_queue PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)