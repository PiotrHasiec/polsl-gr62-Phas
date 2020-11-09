#include "Solver_Jacobi.h"
#include <algorithm>
#include <iostream>
bool Solver_Jacobi::solv(Matrix A)
{
	if (norm1(A) || norm2(A) || norm3(A))
	{
		wyniki.set_d(A.size_y(), 1);
		Matrix x{ 2,A.size_y() };
		Matrix a{ 1, A.size_x() };
		double m = 0;
		for (int i = 0; i < A.size_y(); i++)
		{
			a[0][i] = A[i][i];
			A[i][i] = 0;

			for (int j = 0; j < A.size_y(); j++)
			{

				A[i][j] /= -a[0][i];

			}
		}
		bool stop = 1;

		int k = 0;
		for (k = 0; stop; k++)
		{
			stop = 0;
			for (int i = 0; i < A.size_y(); i++)
			{
				x[k % 2][i] = A[i][A.size_y()] / a[0][i];
				for (int j = 0; j < A.size_y(); j++)
				{
					x[k % 2][i] += (x[(k + 1) % 2][j] * A[i][j]);
				}
				if ((abs(x[k % 2][i] - x[(k + 1) % 2][i]) > precision))
				{
					stop = 1;
				}

			}

		}
		for (int i = 0; i < A.size_y(); i++)
			wyniki[i][0] = x[k % 2][i];
	}
	return false;

}