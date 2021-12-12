
#include "Variable.h"
#include <vector>
#include <iostream>
#include <fstream>

Variable::Variable(std::shared_ptr<ITimeDiscretization> ptr, int type ){ 
	this->type = type;
	ptr_discretization = ptr ; 	
	variable.resize(ptr_discretization->nb_points);
};	
Variable::~Variable(void){;};	

float Variable::operator()(double t_n){
	int index = ptr_discretization->iteration(t_n) ; 
	std::cout << "index in operator  :" << index << std::endl ;
	std::cout << "variable in operator  :" <<  variable[index]  << std::endl ;
	if (index == -1){
		return 0.0 ; 
	}
	
	
	return variable[index] ; 
};


void Variable::print(void){
	std::cout <<" initial y from print method : "<< variable[0] << std::endl ; 
	std::cout <<" final y from print method : "<< variable.back() << std::endl ; 
	std::cout <<" type : "<< type << std::endl ; 
	std::string str1 ; 
	if (type == 0){
		str1 = "result.txt";
	}
	else if(type==1){
		str1 = "result_ana.txt";
	}
	
	std::ofstream of (str1, std::ofstream::out);
	
	
	for (int i = 0 ; i < variable.size(); i++){
		of << variable[i] << std::endl ; 
	}
	of.close();
	
};

