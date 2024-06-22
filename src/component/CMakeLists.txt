set(SOURCE component.cpp main.cpp)

add_executable(component ${SOURCE})

target_include_directories(component PUBLIC ${PROJECT_SOURCE_DIR}/include)

set_target_properties(component PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)