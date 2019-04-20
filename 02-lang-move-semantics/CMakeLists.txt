project(cpp-exercise-00)

include_directories(
	include
)

add_executable(${PROJECT_NAME}-demo-01 src/demo-01.cpp)
target_compile_options(${PROJECT_NAME}-demo-01 
    PUBLIC -std=c++11
)

project(cpp17-exercise-00)
add_executable(${PROJECT_NAME}-demo-01 src/demo-01.cpp)
target_compile_options(${PROJECT_NAME}-demo-01 
    PUBLIC -std=c++17
)