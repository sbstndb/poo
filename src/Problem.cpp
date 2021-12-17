#include <iostream>
#include <thread>
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
	nb_points = ptr_discretization->npas + 1 ; 
	v.variable.resize(nb_points);
	ptr_discretization->compute_time();
	
	e.compute_initial_condition(v, ptr_discretization, t_0, y_0);
	e.compute_initial_condition(v_ana, ptr_discretization, t_0, y_0);	
		std::cout << " 222" << std::endl ; 
	// lambda fnction for analytical solution 
	auto y_ana = [](double y_0, auto t_0, auto current_time){ return y_0 - t_0 * t_0 / 2 + current_time * current_time / 2 ; };
		std::cout << " 333" << std::endl ; 
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

void Problem::parallel_solve(){
	nb_points = ptr_discretization->npas + 1 ; 
	v.variable.resize(nb_points);
	ptr_discretization->compute_time();
	
	e.compute_initial_condition(v, ptr_discretization, t_0, y_0);
	e.compute_initial_condition(v_ana, ptr_discretization, t_0, y_0);	
	
	// lambda fnction for analytical solution 
	auto y_ana = [](double y_0, auto t_0, auto current_time){ return y_0 - t_0 * t_0 / 2 + current_time * current_time / 2 ; };
	
	ptimer.start();
	
	// reverse solving
	
	std::thread compute_reverse_variable([this] {
		for (int i = ptr_discretization->iteration(t_0) -1 ; i >= 0 ; i--){
			time = ptr_discretization->time[i];
			dt = -time +ptr_discretization->time[i+1];
			v.variable[i] = e.compute(time, -dt, v );
		}
	});
	
	std::thread compute_reverse_variable_ana([this, y_ana] {
		for (int i = ptr_discretization->iteration(t_0) -1 ; i >= 0 ; i--){
			time = ptr_discretization->time[i];
			dt = -time +ptr_discretization->time[i+1];
			v_ana.variable[i] = 	y_ana(y_0, t_0, time) ;
		}
	});	
	
	
	std::thread compute_variable([this] {
		for (int i = ptr_discretization->iteration(t_0) +1 ; i < nb_points ; i++){
			time = ptr_discretization->time[i-1];
			dt = -time +ptr_discretization->time[i+1];
			v.variable[i] = e.compute(time, -dt, v );
		}
	});
	
	std::thread compute_variable_ana([this, y_ana] {
		for (int i = ptr_discretization->iteration(t_0) +1 ; i < nb_points ; i++){
			time = ptr_discretization->time[i-1];
			dt = +time - ptr_discretization->time[i+1];
			v_ana.variable[i] = 	y_ana(y_0, t_0, time) ;
		}
	});	
	
	compute_reverse_variable_ana.join() ; 	
	compute_variable_ana.join() ; 	
	compute_reverse_variable.join() ; 
	compute_variable.join() ; 

	
	
	ptimer.stop();
	
	v.print();
	v_ana.print();
	
	ptimer.print();
	
};




