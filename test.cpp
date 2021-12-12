
#include <iterator>
#include <iostream>
#include <algorithm>

class Functor {
public:
	Functor(){;}
	int operator()(int a){
		return 2*a ; 
	}
};



int main() {
	int base = 1 ; 
	int result ;
	Functor result2 = Functor() ; 
	result = result2(base); 
	std::cout << result << std::endl ; 
 
	result = result2(2*base); 
	std::cout << result << std::endl ;  
 

    return 0;
    
}
