#pragma once
#include <vector>
#include <memory>
#include "Time.h"



class Variable{
	public:
	
	std::shared_ptr<ITimeDiscretization> ptr_discretization ; 
	std::vector<double> variable ; 
	int type = 0 ; 	
	
	
	Variable(std::shared_ptr<ITimeDiscretization>, int);
	~Variable();
	float operator()(double);
	void print()  ; 

	// need to be modify : il faut recuperer le pointeur deja cree (smart pointeur? )
	//ITimeDiscretization* ptr_discretization = new UniformTimeDiscretization{};

	//void Init_variable();
};
