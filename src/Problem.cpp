#include <iostream>
#include "Problem.h"


//#include "Equation.h"

Problem::Problem(void){;};
Problem::~Problem(void){;};

void Problem::set_uniform_discretization(){
	ptr_discretization = std::make_shared<UniformTimeDiscretization>();	
	v = Variable(ptr_discretization, 0) ; 
	v_ana = Variable(ptr_discretization, 1) ; 
};

void Problem::set_specific_discretization(){
	ptr_discretization = std::make_shared<SpecificTimeDiscretization>();
	v = Variable(ptr_discretization, 0) ; 
	v_ana = Variable(ptr_discretization, 1) ; 
};



void Problem::solve(){
	set_uniform_discretization();
	nb_points = ptr_discretization->npas + 1 ; 
	ptr_discretization->compute_time();
	
	e.compute_initial_condition(v, ptr_discretization, t_0, y_0);
	e.compute_initial_condition(v_ana, ptr_discretization, t_0, y_0);	
	
	// lambda fnction for analytical solution 
	auto y_ana = [](double y_0, auto t_0, auto current_time){ return y_0 - t_0 * t_0 / 2 + current_time * current_time / 2 ; };
	
	ptimer.start();
	
	// reverse solving
	for (int i = ptr_discretization->iteration(t_0) -1 ; i >= 0 ; i--)
	{ 
		time = ptr_discretization->time[i];
		dt = -time +ptr_discretization->time[i+1];
		v.variable[i] = e.compute(time, -dt, v );	
		v_ana.variable[i] = 	y_ana(y_0, t_0, time) ; 
	}	
	
	for (int i = ptr_discretization->iteration(t_0) +1 ; i < nb_points ; i++)
	{ 
		time = ptr_discretization->time[i];
		dt = +time -ptr_discretization->time[i-1];
		v.variable[i] = e.compute(time, dt, v );	
		v_ana.variable[i] = 	y_ana(y_0, t_0, time) ; 
	}
	ptimer.stop();
	
	v.print();
	v_ana.print();
	
	ptimer.print();
};



