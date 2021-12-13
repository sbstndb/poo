#include "Timer.h"
#include <iostream>
#include <chrono>


namespace sc = std::chrono ; 

Timer::Timer(void){ //init to zero time
	time_start = sc::steady_clock::now() ; 
	time_stop = sc::steady_clock::now();
	sc::duration<double>  time_delta ; 
}
Timer::~Timer(void){;};	


void Timer::start(void){  time_start = sc::steady_clock::now() ; };
void Timer::stop(void){  time_stop = sc::steady_clock::now() ; };
void Timer::print(void){
	time_delta = sc::duration_cast<sc::duration<double>>(this->time_stop - this->time_start);	
	std::cout << "duration  : " << time_delta.count()<< std::endl ; 
};


