#pragma once
#include <vector>
#include <memory>
#include "Time.h"



class Variable{
	public:
	
	std::shared_ptr<ITimeDiscretization> ptr_discretization ; 
	std::vector<double> variable ; 	
	
	
	Variable(std::shared_ptr<ITimeDiscretization>);
	~Variable();

	// need to be modify : il faut recuperer le pointeur deja cree (smart pointeur? )
	//ITimeDiscretization* ptr_discretization = new UniformTimeDiscretization{};

	//void Init_variable();
};
