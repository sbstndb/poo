
#include "Problem.h"
#include <vector>
#include <memory>
#include <iostream>

int main()
{
	Problem p ; 
	

	/*
	SpecificTimeDiscretization D ; 
	UniformTimeDiscretization DU ; 
	std::cout << D.get_dt(0.0) << std::endl ;	
	std::cout << DU.get_dt(0.0) << std::endl ;

	std::cout << D.get_dt(1.0) << std::endl ;	
	std::cout << DU.get_dt(1.0) << std::endl ;

	std::cout << D.get_dt(10) << std::endl ;	
	std::cout << DU.get_dt(10) << std::endl ;
	*/
	//Variable v = Variable(p.ptr_discretization) ; 
	// copy du ptr
	//v.ptr_discretization = p.ptr_discretization;
	//v.Init_variable() ;
	//std::cout << "nb points in v is : " << v.variable.size() << std::endl ; 
	//std::cout << "adresse ptr in v is : " << v.ptr_discretization << std::endl ; 	
	
/*
	p.solve();

	double number = 8.0 ; 
	int index_0 = p.ptr_discretization->iteration(number);
	std::cout <<" index : " << index_0 << std::endl ; 
	
	p.set_specific_discretization();
	p.solve();
	number = 0.03 ; 
	index_0 = p.ptr_discretization->iteration(number);
	std::cout <<" index : " << index_0 << std::endl ; 
	
	number = 8.0 ; 	
	
	// test operator 
	//int n = p->ptr_discretization(number)
	std::cout <<"resultat operator "<< v(number) << std::endl ;
	v.variable[8]=3.20;

	std::cout <<"resultat operator "<< v(number) << std::endl ;
*/
	

	for (int i = 0 ; i < 10 ; i++){
		std::cout << " variable[" << i << "] : " << p.v.variable[i] << std::endl ; 
	}
	//p.set_specific_discretization();
	p.solve();
	
	
	for (int i = 0 ; i < 10 ; i++){
		std::cout << " variable[" << i << "] : " << p.v.variable[i] << std::endl ; 
	}
	for (int i = 0 ; i < 10 ; i++){
		std::cout << " time[" << i << "] : " << p.ptr_discretization->time[i] << std::endl ; 
	}	
	
	double y = p.v(1.0); 
	std::cout << "value of y " << y << std::endl ; 	
	y = 2 ;  
	std::cout << "value of y " << p.v(1.0) << std::endl ; 
	

	
	
	
	
	
		
}
