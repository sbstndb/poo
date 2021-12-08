
#include "Variable.h"
#include <vector>

Variable::Variable(std::shared_ptr<ITimeDiscretization> ptr){ 
	ptr_discretization = ptr ; 	
	variable.resize(ptr_discretization->nb_points);
};	
Variable::~Variable(void){;};	

