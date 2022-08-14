#include "linearequ.h"
#include <iostream>
using namespace std;
int main() {
	double a[] = { 1,2,3,4 };
	double b[] = { 3,7 };
	linearequ equ(2);
	equ.setlinearequ(a, b);
	equ.printlinearequ();
	if (equ.solve())equ.printsolution();

}
