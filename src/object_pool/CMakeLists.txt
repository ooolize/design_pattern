set(SOURCE object_pool.cpp main.cpp)

add_executable(object_pool ${SOURCE})

target_include_directories(object_pool PUBLIC ${PROJECT_SOURCE_DIR}/include)

set_target_properties(object_pool PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)