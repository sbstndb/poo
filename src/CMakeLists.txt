include_directories(${Simulator_SOURCE_DIR}/inc)
add_executable(Simulator main.cpp Problem.cpp Equation.cpp Time.cpp Variable.cpp Timer.cpp)
