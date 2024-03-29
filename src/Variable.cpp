
#include "Variable.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <numeric>


Variable::Variable(std::shared_ptr<ITimeDiscretization> ptr, int type ){ 
	this->type = type;
	ptr_discretization = ptr ; 	
	variable.resize(ptr_discretization->npas + 1);
};	
Variable::~Variable(void){;};	

float Variable::operator()(double t_n){
	int index = ptr_discretization->iteration(t_n) ; 	
	//if (index == -1){
	//	return 0.0 ; 
	//}	
	
	//std::cout << " variable operator : "<< variable[index]  << std::endl ; 	
	return variable[index] ; 
};


void Variable::print(void){
	std::cout <<"*-------- Variable data --------*"<< std::endl ;
	std::cout << "| solution initiale : " << variable.front() << std::endl ;
	std::cout << "| solution finale : " << variable.back() << std::endl ;
	std::cout << "| solution minimale : " << *std::min_element(variable.begin(), variable.end()) << std::endl ;
	std::cout << "| solution maximale : " << *std::max_element(variable.begin(), variable.end()) << std::endl ;
	std::cout << "| solution moyenne : " << (std::accumulate(variable.begin(), variable.end(), 0.0) / variable.size()) << std::endl ;
	std::cout <<"*-------------------------------*"<< std::endl<< std::endl ;	
	
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

