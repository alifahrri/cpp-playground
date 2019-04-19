project(cpp-exercise-00)

add_compile_options(-std=c++17)

include_directories(
	include
)

add_executable(${PROJECT_NAME}-demo-01 src/demo-01.cpp)
