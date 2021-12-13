#pragma once
#include <vector>
#include <memory>
#include "Time.h"



class Variable{

	public:
	
		Variable(std::shared_ptr<ITimeDiscretization>, int);	
		~Variable();	
		float operator()(double);
		void print()  ; 	
		
		std::shared_ptr<ITimeDiscretization> ptr_discretization ; 
		std::vector<double> variable ; 
		int type = 0 ; 	


};
