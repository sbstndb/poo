include_directories(${Simulator_SOURCE_DIR}/inc)
find_package(Threads)
find_package(TBB)
set(SRC main.cpp Problem.cpp Equation.cpp Time.cpp Variable.cpp Timer.cpp)

add_executable(Simulator ${SRC})
target_link_libraries(Simulator Threads::Threads TBB::tbb)
