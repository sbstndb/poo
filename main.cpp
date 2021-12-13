
#include "Problem.h"
#include <vector>
#include <memory>
#include <iostream>
#include "Timer.h"

int main()
{
	Problem p ; 

	Timer t1 ; 
	t1.start();

	p.solve();
	
	t1.stop();
	t1.print();
		
}
