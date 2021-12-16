
#include "Problem.h"
#include <vector>
#include <memory>
#include <iostream>
#include "Timer.h"

//throw std::runtime_error("error") ; 

void test_discretization()
{
		std::cout << " begin test " << std::endl ; 


	Problem p ; 
	p.set_uniform_discretization();
	
	// set a time discret from 1.0 to 2.0 with 2 npas.
	// we have 1.0 1.5 2.0
	p.ptr_discretization->time_init = 1.0 ; 
	p.ptr_discretization->time_end = 2.0 ;	
	p.ptr_discretization->npas = 2 ;		

	p.ptr_discretization->compute_time() ;	
	
	double t0 = p.ptr_discretization->time[0] ;
	double t1 = p.ptr_discretization->time[1] ;
	double t2 = p.ptr_discretization->time[2] ;
	double t3 ;
	double t4 ;
	
	if (t0 != 1.0 || t1 != 1.5 || t2 != 2.0){
		throw std::runtime_error("error");
	}


			std::cout << "resize discretization " << std::endl ;	
	// set a new discretization : from 2.0 to 5.0 with npas = 3
	// we have 2.0 3.0 4.0 5.0
	// potential error : bad resize of vector
	
	p.ptr_discretization->time_init = 2.0 ; 
	p.ptr_discretization->time_end = 5.0 ;	
	p.ptr_discretization->npas = 3 ;		

	p.ptr_discretization->compute_time() ;	
	
	t0 = p.ptr_discretization->time[0] ;
	t1 = p.ptr_discretization->time[1] ;
	t2 = p.ptr_discretization->time[2] ;
	t3 = p.ptr_discretization->time[3] ;

	
	if (t0 != 2.0 || t1 != 3.0 || t2 != 4.0 || t3 != 5.0){
		throw std::runtime_error("error");
	}	

			std::cout << "new kind of  discretization " << std::endl ;		
	
	// we now change discretization type contract
	// dt before t = 2 is 1, dt after t = 2 is 2
	// we create time discretisation from 0 to 5 so
	// we have 0.0 1.0 3.0 5.0
	
	p.set_specific_discretization();	
	p.ptr_discretization->time_init = 0.0 ; 
	p.ptr_discretization->time_end = 5.0 ;	
	p.ptr_discretization->dtbefore = 1 ;	
	p.ptr_discretization->dtafter = 2 ;
	p.ptr_discretization->tlim = 1 ;	

	p.ptr_discretization->compute_time() ;	

	t0 = p.ptr_discretization->time[0] ;
	t1 = p.ptr_discretization->time[1] ;
	t2 = p.ptr_discretization->time[2] ;
	t3 = p.ptr_discretization->time[3] ;


	if (t0 != 0.0 || t1 != 1.0 || t2 != 3.0 || t3 != 5.0){
		throw std::runtime_error("error");
	}	
	if (p.ptr_discretization->npas != 3){
		throw std::runtime_error("error");
	}

		
}







int main(){

	test_discretization();
	
	return 0 ; 
	
}






