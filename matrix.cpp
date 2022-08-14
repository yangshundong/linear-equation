#include <iostream>
#include <cmath>
#include "matrix.h"
using namespace std;

void matrix::setmatrix(const double* values) {
	for (int i = 0; i < size * size; i++) {
		elements[i] = values[i];
	}
}

matrix::matrix(int size) :size(size) {
	elements = new double[size * size];
}
void matrix::print()const {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			cout << elements[i * size + j] << " ";
		}cout << endl;
	}
}










