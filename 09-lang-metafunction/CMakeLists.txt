project(cpp-exercise-09)

include_directories(
	include
)

add_executable(${PROJECT_NAME}-demo-01 src/demo-01.cpp)
target_compile_options(${PROJECT_NAME}-demo-01 
    PUBLIC -std=c++11
)

add_executable(${PROJECT_NAME}-demo-02 src/demo-02.cpp)

add_executable(${PROJECT_NAME}-demo-03 src/demo-03.cpp)
target_compile_options(${PROJECT_NAME}-demo-03 
    PUBLIC -std=c++11
)

add_executable(${PROJECT_NAME}-demo-04 src/demo-04.cpp)

add_executable(${PROJECT_NAME}-demo-05 src/demo-05.cpp)
target_compile_options(${PROJECT_NAME}-demo-05 
    PUBLIC -std=c++11
)

add_executable(${PROJECT_NAME}-demo-06 src/demo-06.cpp)
target_compile_options(${PROJECT_NAME}-demo-06
    PUBLIC -std=c++11
)

add_executable(${PROJECT_NAME}-demo-07 src/demo-07.cpp)
target_compile_options(${PROJECT_NAME}-demo-07
    PUBLIC -std=c++11
)