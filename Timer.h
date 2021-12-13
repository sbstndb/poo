#pragma once
#include <chrono>

namespace sc = std::chrono ; 


class Timer {
	public : 
	sc::steady_clock::time_point  time_start; 
	sc::steady_clock::time_point  time_stop;
	sc::duration<double>  time_delta ; 	
	Timer();
	~Timer();

	
	void start(void);
	void stop(void);
	void print(void);


};
