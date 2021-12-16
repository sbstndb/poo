#pragma once
#include <vector>



class ITimeDiscretization {

	public:
	
		ITimeDiscretization();
		virtual ~ITimeDiscretization() = default ; 	
		
		double get_time_init();
		double get_time_end();
		virtual double get_dt(double) = 0;	
		virtual double get_dt(double, double, double, double) =0;	
		int iteration(double) ; 
		virtual void compute_time() = 0;		
		
		std::vector<double> time ; 
		double time_init = 0;
		double time_end = 10 ; 
		double dt ;
		int npas = 20 ; 
		
		double tlim = 10 ;
		double dtbefore = 1.0 ;
		double  dtafter = 1.0;
		
	
};


 

class UniformTimeDiscretization : public ITimeDiscretization{
	public:
		double get_dt(double) override ; 
		double get_dt(double, double, double, double) override ; 
		void compute_time(void) override ; 
};

class SpecificTimeDiscretization : public ITimeDiscretization{
	public:
		double get_dt(double) override ; 
		double get_dt(double, double, double, double) override  ; 
		void compute_time(void) override ; 
};



