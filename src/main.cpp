
#include "Problem.h"
#include <vector>
#include <memory>
#include <iostream>
#include "Timer.h"

int main()
{	
	Timer t1 ; 
	t1.start();
	
	Problem p ; 

	p.parallel_solve();
	
	t1.stop();
	t1.print();
		
}
