project(cpp-exercise-03)

add_compile_options(-std=c++14)

include_directories(
	include
)

add_executable(${PROJECT_NAME}-demo-01 src/demo-01.cpp)
target_link_libraries(${PROJECT_NAME}-demo-01 pthread)

add_executable(${PROJECT_NAME}-demo-02 src/demo-02.cpp)
target_link_libraries(${PROJECT_NAME}-demo-02 pthread)

add_executable(${PROJECT_NAME}-demo-03 src/demo-03.cpp)
target_link_libraries(${PROJECT_NAME}-demo-03 pthread)

add_executable(${PROJECT_NAME}-demo-04 src/demo-04.cpp)
target_link_libraries(${PROJECT_NAME}-demo-04 pthread)

add_executable(${PROJECT_NAME}-demo-05 src/demo-05.cpp)
target_link_libraries(${PROJECT_NAME}-demo-05 pthread)