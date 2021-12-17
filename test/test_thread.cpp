
#include "Problem.h"
#include <vector>
#include <memory>
#include <iostream>
#include "Timer.h"

//throw std::runtime_error("error") ; 


void test_thread(){

	Problem p ; 
	p.set_uniform_discretization();
	
	// set a time discret from 1.0 to 2.0 with 2 npas.
	// we have 1.0 1.5 2.0
	p.ptr_discretization->time_init = 1.0 ; 
	p.ptr_discretization->time_end = 2.0 ;	
	p.ptr_discretization->npas = 2000 ;		

	p.ptr_discretization->compute_time() ;	
	
	double t0 = p.ptr_discretization->time[0] ;
	double t1 = p.ptr_discretization->time[2000] ;

	
	
	Problem pt ; 
	pt.set_uniform_discretization();
	
	// set a time discret from 1.0 to 2.0 with 2 npas.
	// we have 1.0 1.5 2.0
	pt.ptr_discretization->time_init = 0.0 ; 
	pt.ptr_discretization->time_end = 10.0 ;	
	pt.ptr_discretization->npas = 2000 ;		

	pt.ptr_discretization->compute_time() ;	
	
	double tt0 = p.ptr_discretization->time[0] ;
	double tt1 = p.ptr_discretization->time[2000] ;
	

	if (t0 != tt0 || t1 != tt1){
		throw std::runtime_error("error");	
	}


}




int main(){

	test_thread();
	return 0 ; 
	
}






