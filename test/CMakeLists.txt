include_directories(${Simulator_SOURCE_DIR}/inc)
set(SRC  ${Simulator_SOURCE_DIR}/src/Problem.cpp ${Simulator_SOURCE_DIR}/src/Equation.cpp ${Simulator_SOURCE_DIR}/src/Time.cpp ${Simulator_SOURCE_DIR}/src/Variable.cpp ${Simulator_SOURCE_DIR}/src/Timer.cpp)

find_package(Threads)
find_package(TBB)


add_executable(TestDiscretization ${Simulator_SOURCE_DIR}/test/test_discretization.cpp ${SRC})
add_executable(TestThread ${Simulator_SOURCE_DIR}/test/test_thread.cpp ${SRC})

target_link_libraries(TestDiscretization Threads::Threads TBB::tbb)
target_link_libraries(TestThread Threads::Threads TBB::tbb)


add_test(testDiscretization TestDiscretization)
add_test(testThread TestThread)
