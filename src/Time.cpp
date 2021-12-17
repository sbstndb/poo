#include "Time.h"
#include <cmath>
#include <iostream>


ITimeDiscretization::ITimeDiscretization(){}

double ITimeDiscretization::get_time_init(){
	return time_init ;
};

double ITimeDiscretization::get_time_end(){
	return time_end ;
};

void ITimeDiscretization::set_npas(int np){
	npas = np ; 
};

/*
void ITimeDiscretization::compute_time(void ){
	time.resize(npas + 1 ) ; 
	time[0] = time_init ; 
	double current_time = time_init ; 
	for (int i = 1 ; i < npas + 1 ; i++){
		dt = get_dt(current_time); 
		current_time += dt ; 
		time[i] =  current_time ; 
	}
};
*/
int ITimeDiscretization::iteration(double t_n){

	//int index = -1 ; 
	//for (int i = 0 ; i < npas + 1 ; i++){

	//	if (abs(time[i] - t_n) < 10e-11){
	//		return i ; 
	//	};
	//}
	
	auto index2 = std::lower_bound(time.begin(), time.end(), t_n) ;
	//std::cout << "index2 : " << (index2 - time.begin()) << std::endl ; 
	//std::cout << "iteration " << std::endl ;
	return (index2 - time.begin()) ; 
};



double UniformTimeDiscretization::get_dt(double time){
	double dt = (time_end - time_init)/npas;
	return dt;	
};

double UniformTimeDiscretization::get_dt(double time,  double tlim, double dtb, double dta){	
	std::cout << "issue : discretization implementation "<<  std::endl ;
	throw std::runtime_error("error");
	double dt = 0.1 ; 
	return dt;	
};


void UniformTimeDiscretization::compute_time(void ){
	time.resize(npas + 1 ) ; 
	time[0] = time_init ; 
	double current_time = time_init ; 
	for (int i = 1 ; i < npas + 1 ; i++){
		dt = get_dt(current_time); 
		current_time += dt ; 
		time[i] =  current_time ; 
	}
};

double SpecificTimeDiscretization::get_dt(double time){
	std::cout << "issue : discretization implementation " << std::endl ;	
	throw std::runtime_error("error");
	double dt = 0.1 ; 
	return dt;	
};

double SpecificTimeDiscretization::get_dt(double time, double tlim, double dtbefore, double dtafter){
	double dt ;
	if (time  < tlim) {
		dt = dtbefore;
	}
	else{
		dt = dtafter;	
	}; 
	return dt;	
};





void SpecificTimeDiscretization::compute_time(void){
	time.resize(0) ; 
	time.push_back(time_init) ; 
	double current_time = time_init ; 
	while (current_time < time_end){
		dt = get_dt(current_time, tlim, dtbefore, dtafter); 
		current_time += dt ;  
		time.push_back(current_time) ; 
	}
	npas = time.size() - 1 ; 
};



