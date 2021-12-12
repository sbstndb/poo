#pragma once
#include <vector>



class ITimeDiscretization {
	public:
	
		std::vector<double> time ; 
		ITimeDiscretization();
		virtual ~ITimeDiscretization() = default ; 
		double time_init = 0;
		double time_end = 10 ; 
		double dt = 1 ; 
		int npas = 10 ; 
		int nb_points = 11  ;
		
		double get_time_init();
		double get_time_end();
		virtual double get_dt(double) = 0;
		
		int iteration(double) ; 
		void compute_time();

};



class UniformTimeDiscretization : public ITimeDiscretization{
	public:
		double get_dt(double) override ; 
};

class SpecificTimeDiscretization : public ITimeDiscretization{
	public:
		double get_dt(double) override ; 
};


