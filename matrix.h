#ifndef _max
#define _max
class matrix {
private:double* elements; int size;
public:
	matrix(int size = 2);
	~matrix() { delete[]elements; };
	void setmatrix(const double* values);
	void print()const;
	int getsize()const { return size; };
	double& element(int i, int j) { return elements[i * size + j]; }
	double element(int i, int j) const{ return elements[i * size + j]; }
};










#endif

