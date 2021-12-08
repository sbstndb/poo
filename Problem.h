#pragma once
#include "Equation.h"
#include "Variable.h"
#include "Time.h"
#include <memory>
#include <iostream>

class Problem {
	public:
		Problem();
		~Problem();
		double time = 0 ; 
		double dt = 0 ; 
		int nb_points ; 
		Equation e ; 

		std::shared_ptr<ITimeDiscretization> ptr_discretization = std::make_shared<UniformTimeDiscretization>();
		void set_uniform_discretization();
		void set_specific_discretization();
		void solve();

};
