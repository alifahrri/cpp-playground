project(cpp-exercise-04)

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

add_executable(${PROJECT_NAME}-demo-02 src/demo-02.cpp)
target_compile_options(${PROJECT_NAME}-demo-02
    PUBLIC -std=c++11
)
target_link_libraries(${PROJECT_NAME}-demo-02
    pthread
)

add_executable(${PROJECT_NAME}-demo-03 src/demo-03.cpp)
target_compile_options(${PROJECT_NAME}-demo-03
    PUBLIC -std=c++11
)
target_link_libraries(${PROJECT_NAME}-demo-03
    pthread
)

add_executable(${PROJECT_NAME}-demo-04 src/demo-04.cpp)
target_compile_options(${PROJECT_NAME}-demo-04
    PUBLIC -std=c++11
)
target_link_libraries(${PROJECT_NAME}-demo-04
    pthread
)