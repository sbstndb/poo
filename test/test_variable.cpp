
#include "Problem.h"
#include <vector>
#include <memory>
#include <iostream>
#include "Timer.h"

//throw std::runtime_error("error") ; 


void test_thread(){

	std::cout << " begin test variable " << std::endl ; 

	Problem p ; 
	std::cout << " begin uniform discretization " << std::endl ; 
	p.set_uniform_discretization();	
	// set a time discret from 0.0 to 10.0 with 10 npas.
	std::cout << " set parameters " << std::endl ; 
	p.ptr_discretization->time_init = 0.0 ; 
	p.ptr_discretization->time_end = 10.0 ;		
	p.ptr_discretization->npas=10 ;	
	p.ptr_discretization->compute_time();
	
	std::cout << p.ptr_discretization->time[0] << std::endl ;	
	std::cout << p.ptr_discretization->time[1] << std::endl ;
	std::cout << p.ptr_discretization->time[2]<< std::endl ;	
	std::cout << p.ptr_discretization->time[3] << std::endl ;	
	std::cout << p.ptr_discretization->time[4]<< std::endl ;	
	std::cout << p.ptr_discretization->time[5] << std::endl ;	
	std::cout << p.ptr_discretization->time[6] << std::endl ;	
	std::cout << p.ptr_discretization->time[7] << std::endl ;	
	std::cout << p.ptr_discretization->time[8] << std::endl ;	
	std::cout << p.ptr_discretization->time[9] << std::endl ;	
	std::cout << p.ptr_discretization->time[10] << std::endl ;	
	
	
		
	
	p.t_0 = 0  ;
	p.y_0 = 0 ;		

	p.solve();
	std::cout << " solved" << std::endl ; 
	double v0 = p.v.variable[0] ; 
	double v1 = p.v.variable[1] ; 
	double v2 = p.v.variable[2] ; 
	double v3 = p.v.variable[3] ; 
	double v4 = p.v.variable[4] ; 
	double v5 = p.v.variable[5] ; 
	double v6 = p.v.variable[6] ; 
	double v7 = p.v.variable[7] ; 	
	double v8 = p.v.variable[8] ; 
	double v9 = p.v.variable[9] ; 
	double v10 = p.v.variable[10] ; 
	std::cout << v0 << " " << v1 << " " << v2 << " " << v10 << std::endl ;

	double s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10 ; 
	
	s0 = 0.0 ; 
	s1 = 1.0 ;
	s2 = 3.0 ; 
	s3 = 6.0 ;
	s4 = 10.0 ; 
	s5 = 15.0 ;	
	s6 = 21.0 ; 
	s7 = 28.0 ;
	s8 = 36.0 ; 
	s9 = 45.0 ;
	s10 = 55.0 ; 	
	
	
	if (v0 != s0 || v1 != s1 | v2 != s2 || v3 != s3 || v4 != s4 || v5 != s5 || v6 != s6 || v10 != s10)
	{
		throw std::runtime_error("error") ;
	}

}




int main(){

	test_thread();
	return 0 ; 
	
}






