
#include "Problem.h"


//#include "Equation.h"

Problem::Problem(void){;};
Problem::~Problem(void){;};

void Problem::set_uniform_discretization(){
	//delete ptr_discretization ; 
	//ptr_discretization = new UniformTimeDiscretization{};
	ptr_discretization = std::make_shared<UniformTimeDiscretization>();	

};

void Problem::set_specific_discretization(){
	//delete ptr_discretization ; 
	//ptr_discretization = new SpecificTimeDiscretization{};
	ptr_discretization = std::make_shared<SpecificTimeDiscretization>();
};



void Problem::solve(){
	nb_points = ptr_discretization->nb_points ; 
	ptr_discretization->compute_time();
	for (int i = 0 ; i < nb_points ; i++)
	{
		//ptr_discretization->time[i] = time ; 		
		e.compute(ptr_discretization->time[i]);	
	}
};



