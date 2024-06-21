set(SOURCE type_object.cpp main.cpp)

add_executable(type_object ${SOURCE})

target_include_directories(type_object PUBLIC ${PROJECT_SOURCE_DIR}/include)

set_target_properties(type_object PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)