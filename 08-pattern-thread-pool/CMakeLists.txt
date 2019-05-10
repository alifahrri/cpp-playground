project(cpp-exercise-05)

include_directories(
	include
)

add_executable(${PROJECT_NAME}-demo-01 src/demo-01.cpp)
target_compile_options(${PROJECT_NAME}-demo-01 
    PUBLIC -std=c++11
)
target_link_libraries(${PROJECT_NAME}-demo-01
    pthread
)