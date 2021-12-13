
#include <iterator>
#include <iostream>
#include <algorithm>

#include <chrono>

/*
class Functor {
public:
	Functor(){;}
	int operator()(int a){
		return 2*a ; 
	}
};

*/

int main() {
/*
	int base = 1 ; 
	int result ;
	Functor result2 = Functor() ; 
	result = result2(base); 
	std::cout << result << std::endl ; 
 
	result = result2(2*base); 
	std::cout << result << std::endl ;  
 */
 
 	// need -lstdc++
	auto start = std::chrono::steady_clock::now() ; 
	int a = 0 ; 
	auto end = std::chrono::steady_clock::now() ; 
	std::chrono::duration<double> elapsed_seconds = end-start;	
	std::cout << elapsed_seconds.count()<< std::endl ; 
	
    return 0;
    
}
