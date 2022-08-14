#ifndef _linearequ
#define _linearequ
#include "matrix.h"
#include <iostream>
using namespace std;
class linearequ :public matrix {
private:double* sums, * solutions;
public:
	linearequ(int size = 2) :matrix(size) {
		sums = new double[size]; solutions = new double[size];
	};
	~linearequ() { delete[]sums; delete[]solutions; };
	void setlinearequ(const double* a, const double* b) {
		setmatrix(a); for (int i = 0; i < getsize(); i++) {
			sums[i] = b[i]; 
		}
	};
	bool solve();
	void printlinearequ()const;
	void printsolution()const;

};

#endif
