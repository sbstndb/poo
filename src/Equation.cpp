
#include "Equation.h"
#include <iostream>

Equation::Equation(void){;}
Equation::~Equation(void){;}


double Equation::compute(double current_time, double dt, Variable& v){

	double y = v(current_time - dt)  ;
	double new_y = y + dt * current_time ;
	//std::cout << " current time "<< current_time  << std::endl ; 
	//std::cout << " dt "<< dt  << std::endl ; 

	return new_y ; 
}

void Equation::compute_initial_condition(Variable& v, double t_0, double y_0){

	double ci = t_0 ; 
	v.variable[0] = y_0  ;
	
	// il faudrait faire avec un index  
}
