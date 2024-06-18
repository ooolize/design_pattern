set(SOURCE prototype.cpp main.cpp)

add_executable(prototype ${SOURCE})

target_include_directories(prototype PUBLIC ${PROJECT_SOURCE_DIR}/include)

set_target_properties(prototype PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)