
#include "Equation.h"
#include <iostream>

Equation::Equation(void){;}
Equation::~Equation(void){;}


double Equation::compute(double current_time, double dt, Variable& v){
	double y = v(current_time - dt)  ;
	//std::cout << "compute equation at time : " << current_time  <<" in value y "<< y << std::endl ;	
	std::cout << "y : " << y << std::endl ; 
	std::cout << "current time : " << current_time << std::endl ; 
	std::cout << "current dt : " << dt << std::endl ; 
	double new_y = y + dt * current_time ;
	std::cout << "new_y from equation: " << new_y << std::endl ; 
	return new_y ; 
}

void Equation::compute_initial_condition(Variable& v, double t_0){
	// f(t_0) = t_0
	//d_ty = f(t)
	// je trouve la question etrange, il n'y a pas de lien entre y(t_0) et f(t_0).
	// proposition : soit une condition limite y(t_0) = f(t_0) 
	double ci = t_0 ; 
	v.variable[0] = ci  ; 
	std::cout << "initial condition : " << ci   << std::endl ;
}
