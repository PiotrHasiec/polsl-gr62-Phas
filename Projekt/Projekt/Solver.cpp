#include "Solver.h"
#include <algorithm>
bool Solver_i::norm1(Matrix& A)
{
	double tmp = 0;
	for (int i = 0; i < A.size_y(); i++)
	{
		tmp = 0;
		for (int j = 0; j < A.size_y(); j++)
		{
			if (i != j)
				tmp += abs(A[i][j] / A[i][i]);
		}
		if (tmp > 1)
			return 0;
	}
	return 1;
}

bool Solver_i::norm2(Matrix& A)
{
	double tmp = 0;
	for (int i = 0; i < A.size_y(); i++)
	{
		tmp = 0;
		for (int j = 0; j < A.size_y(); j++)
		{
			if (i != j)
				tmp += abs(A[j][i] / A[i][i]);
		}
		if (tmp > 1)
			return 0;
	}
	return 1;
}

bool Solver_i::norm3(Matrix& A)
{
	double tmp = 0;
	for (int i = 0; i < A.size_y(); i++)
	{
		tmp = 0;
		for (int j = 0; j < A.size_y(); j++)
		{
			if (i != j)
				tmp += (A[j][i] / A[i][i])* (A[j][i] / A[i][i]);
		}
		
	}
	if (tmp > 1)
			return 0;
	return 1;
}

void Solver_i::set_precision(double precision)
{
	this->precision =  precision;
}

Matrix Solver::results()
{
	return wyniki;
}
