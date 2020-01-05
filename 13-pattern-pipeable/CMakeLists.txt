project(cpp-exercise-13)

add_executable(${PROJECT_NAME}-demo-01 src/demo-01.cpp)
set_target_properties(${PROJECT_NAME}-demo-01 PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED YES
)