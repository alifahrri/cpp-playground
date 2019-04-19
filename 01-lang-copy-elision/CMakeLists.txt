project(cpp-exercise-01)
cmake_minimum_required(VERSION 3.5)

# add_compile_options(-std=c++11)

include_directories(
	include
)

add_executable(${PROJECT_NAME}-demo-01 src/demo-01.cpp)
add_executable(${PROJECT_NAME}-demo-01-no-elision src/demo-01.cpp)
add_executable(${PROJECT_NAME}-demo-02 src/demo-02.cpp)
add_executable(${PROJECT_NAME}-demo-02-no-elision src/demo-02.cpp)

target_compile_options(${PROJECT_NAME}-demo-01
	PUBLIC -std=c++11
)
target_compile_options(${PROJECT_NAME}-demo-02
	PUBLIC -std=c++11
)
target_compile_options(${PROJECT_NAME}-demo-01-no-elision 
	PUBLIC -fno-elide-constructors -std=c++11
)
target_compile_options(${PROJECT_NAME}-demo-02-no-elision 
	PUBLIC -fno-elide-constructors -std=c++11
)

project(cpp17-exercise-01)

add_executable(${PROJECT_NAME}-demo-01 src/demo-01.cpp)
add_executable(${PROJECT_NAME}-demo-01-no-elision src/demo-01.cpp)
add_executable(${PROJECT_NAME}-demo-02 src/demo-02.cpp)
add_executable(${PROJECT_NAME}-demo-02-no-elision src/demo-02.cpp)

target_compile_options(${PROJECT_NAME}-demo-01
	PUBLIC -std=c++17
)
target_compile_options(${PROJECT_NAME}-demo-02
	PUBLIC -std=c++17
)
target_compile_options(${PROJECT_NAME}-demo-01-no-elision 
	PUBLIC -fno-elide-constructors -std=c++17
)
target_compile_options(${PROJECT_NAME}-demo-02-no-elision 
	PUBLIC -fno-elide-constructors -std=c++17
)