include_directories(${Simulator_SOURCE_DIR}/inc)
set(SRC main.cpp Problem.cpp Equation.cpp Time.cpp Variable.cpp Timer.cpp)
add_executable(Simulator ${SRC})

