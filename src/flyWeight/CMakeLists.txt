set(SOURCE flyweight.cpp main.cpp)

add_executable(flyweight ${SOURCE})

target_include_directories(flyweight PUBLIC ${PROJECT_SOURCE_DIR}/include)

set_target_properties(flyweight PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)