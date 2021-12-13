#pragma once
#include <vector>



class ITimeDiscretization {

	public:
	
		ITimeDiscretization();
		virtual ~ITimeDiscretization() = default ; 	
		
		double get_time_init();
		double get_time_end();
		virtual double get_dt(double) = 0;		
		int iteration(double) ; 
		void compute_time();		
		
		std::vector<double> time ; 
		double time_init = 0;
		double time_end = 10 ; 
		double dt ;
		int npas = 1000 ; 
	
};


 

class UniformTimeDiscretization : public ITimeDiscretization{
	public:
		double get_dt(double) override ; 
};

class SpecificTimeDiscretization : public ITimeDiscretization{
	public:
		double get_dt(double) override ; 
};


