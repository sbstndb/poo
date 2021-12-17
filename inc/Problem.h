#pragma once
#include "Equation.h"
#include "Variable.h"
#include "Timer.h"
#include "Time.h"
#include <memory>
#include <iostream>

class Problem {

	public:
		Problem();
		~Problem();
		
		void set_uniform_discretization();
		void set_specific_discretization();
		void solve();
		void parallel_solve();		
			
		double time = 0 ; 
		double dt = 0 ; 
		int nb_points ; 
		double t_0 = 5 ;
		double y_0 = 5 ; 
		Equation e ; 
		std::shared_ptr<ITimeDiscretization> ptr_discretization = std::make_shared<UniformTimeDiscretization>();
		Variable v = Variable(ptr_discretization, 0) ; 
		Variable v_ana = Variable(ptr_discretization, 1); //1 is for analytical variable
		Timer ptimer ; 				
				

		


};
