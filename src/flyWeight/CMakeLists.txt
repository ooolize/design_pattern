set(SOURCE flyWeight.cpp main.cpp)

add_executable(flyWeight ${SOURCE})

target_include_directories(flyWeight PUBLIC ${PROJECT_SOURCE_DIR}/include)

set_target_properties(flyWeight PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)