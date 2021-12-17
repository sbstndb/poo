include_directories(${Simulator_SOURCE_DIR}/inc)
set(SRC  ${Simulator_SOURCE_DIR}/src/Problem.cpp ${Simulator_SOURCE_DIR}/src/Equation.cpp ${Simulator_SOURCE_DIR}/src/Time.cpp ${Simulator_SOURCE_DIR}/src/Variable.cpp ${Simulator_SOURCE_DIR}/src/Timer.cpp)
add_executable(TestDiscretization ${Simulator_SOURCE_DIR}/test/test_discretization.cpp ${SRC})
add_executable(TestVariable ${Simulator_SOURCE_DIR}/test/test_variable.cpp ${SRC})


add_test(testDiscretization TestDiscretization)
add_test(testVariable TestVariable)
