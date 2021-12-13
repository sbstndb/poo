#pragma once 
#include "Variable.h"



class Equation{

	public:
	
		Equation();
		~Equation();
		
		double compute(double, double, Variable&);
		void compute_initial_condition(Variable&, double, double);
};
