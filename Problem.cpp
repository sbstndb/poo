#include <iostream>
#include "Problem.h"


//#include "Equation.h"

Problem::Problem(void){;};
Problem::~Problem(void){;};

void Problem::set_uniform_discretization(){
	//delete ptr_discretization ; 
	//ptr_discretization = new UniformTimeDiscretization{};
	ptr_discretization = std::make_shared<UniformTimeDiscretization>();	
	v = Variable(ptr_discretization, 0) ; 
	v_ana = Variable(ptr_discretization, 1) ; 
};

void Problem::set_specific_discretization(){
	//delete ptr_discretization ; 
	//ptr_discretization = new SpecificTimeDiscretization{};
	ptr_discretization = std::make_shared<SpecificTimeDiscretization>();
	v = Variable(ptr_discretization, 0) ; 
	v_ana = Variable(ptr_discretization, 1) ; 
};



void Problem::solve(){
	set_uniform_discretization();
	std::cout << "set discretization" <<std::endl ; 
	nb_points = ptr_discretization->nb_points ; 
	std::cout << "set nb points "<< nb_points <<std::endl ; 
	ptr_discretization->compute_time();
	std::cout << "compute time" <<std::endl ; 
	e.compute_initial_condition(v, t_0);
	std::cout << "initial condition" <<std::endl ; 
	e.compute_initial_condition(v_ana, t_0);
	std::cout << "initial condition" <<std::endl ; 	
	// lambda fnction for analytical solution 
	
	auto y_ana = [](Variable v, auto current_time){ return v.variable[0] + current_time*current_time/2 ; };
	for (int i = 1 ; i < nb_points ; i++)
	{
		std::cout << "i : " <<i << std::endl ; 
		//ptr_discretization->time[i] = time ; 		
		//e.compute(ptr_discretization->time[i]);
		time = ptr_discretization->time[i];
		std::cout << "time : " <<time << std::endl ; 
		dt = +time -ptr_discretization->time[i-1];
		std::cout << "dt : " <<dt << std::endl ; 
		v.variable[i] = e.compute(time, dt, v );
		std::cout << "new_y from problem: " << v.variable[i] << std::endl ; 	
		std::cout << "exact solution " << y_ana(v, time) << std::endl ; 	
		v_ana.variable[i] = 	y_ana(v, time) ; 
	}
	v.print();
	v_ana.print();
};



