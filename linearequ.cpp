#include <iostream>
#include <cmath>
#include "linearequ.h"
using namespace std;
void linearequ::printlinearequ()const {
	cout << "the linearequ is" << endl;;
	for (int i = 0; i < getsize(); i++) {
		for (int j = 0; j < getsize(); j++) {
			cout << element(i, j) << " ";
		}cout <<"  "<< sums[i] << endl;
	 }
}

void linearequ::printsolution() const{
	cout << "the result is:" << endl;
	for (int i = 0; i < getsize(); i++) {
		cout << sums[i] << " ";
	}
}
inline void swap(double* a, double* b) {
	double temp = *a; *a = *b; *b = temp;
}

bool linearequ::solve() {
	int *js = new int[getsize()];
	for (int k = 0; k < getsize() - 1; k++) {
		
		
		
		int is;
		double max = 0;
		for (int i = k; i < getsize(); i++) 
			for (int j = k; j < getsize(); j++) {
				double t = fabs(element(i, j));
				if (t > max) {
					max = t; js[k] = j; is = i;
				}

			}


			if (max == 0) { delete[] js; return false; }
			else {
				if (js[k] != k)
					for (int i = 0; i < getsize(); i++) swap(element(i, k), element(i, js[k]));
				if (is != k)
				{
					for (int j = k; j < getsize(); j++)swap(element(k, j), element(is, j));
					swap(sums[k], sums[is]);
				}			
			}


			double major = element(k, k);
			for (int j = k + 1; j < getsize(); j++)element(k, j) = major;
			sums[k] /= major;
			for (int i = k + 1; i < getsize(); i++) {
				for (int j = k + 1; j < getsize(); j++)element(i, j) -= element(i, k) * element(k, j);
				sums[i] -= element(i, k) * sums[k];
			}
		
		
	}//



	double d = element(getsize() - 1, getsize() - 1);
	if (fabs(d) < 1e-15) { delete[]js; return false; }


	solutions[getsize() - 1] = sums[getsize() - 1] / d;
	for (int i = getsize() - 2; i >= 0; i--) {
		double t = 0.0;
		for (int j = i + 1; j < getsize() - 1; j++)t += element(i, j) * solutions[j];
		solutions[i] = sums[i] - t;

	}
	js[getsize() - 1] = getsize() - 1;
	for (int k = getsize() - 1; k >= 0; k--)
		if (js[k] != k)swap(solutions[k], solutions[js[k]]);
	delete[]js;
	return true;
}