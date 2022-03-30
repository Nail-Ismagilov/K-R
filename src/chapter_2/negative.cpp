#include "stdio.h"
#include <iostream>
using namespace std;

int main(){

    unsigned int i1, i2;
    i1 = 2;
    i2 = 1;

    cout << i2-i1 << endl << i1-i2<<endl;
    cout << sizeof(int)<< endl;
    unsigned int uint;
    uint = 2;
    for(int i = 2; i <= (sizeof(int)*8); ++i){
	uint = uint * 2;    
	cout << "iteration #" << i << "     ";
       	cout << "uint: " << uint << endl;;	
    }
	
    cout << endl << endl << i2-10 << endl;;
    cout << uint+6+(i2-2) << endl;

    return(0);
}
