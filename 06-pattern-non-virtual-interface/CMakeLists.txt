project(cpp-exercise-06)

include_directories(
	include
)

add_executable(${PROJECT_NAME}-demo-01 src/demo-01.cpp)
target_compile_options(${PROJECT_NAME}-demo-01 
    PUBLIC -std=c++14
)