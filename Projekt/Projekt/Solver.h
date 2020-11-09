#pragma once
#include "Matrix.h"
class Solver
{
protected:

Matrix wyniki;
public:
	virtual bool solv(Matrix A) = 0;
	Matrix results();
};
class Solver_i :public Solver
{
protected:

	bool norm1(Matrix& A);
	bool norm2(Matrix& A);
	bool norm3(Matrix& A);
	double precision = 0.001;
public:
	virtual bool solv(Matrix A) = 0;
	void set_precision(double precision);
	

};

