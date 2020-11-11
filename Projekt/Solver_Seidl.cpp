#include "Solver_Seidl.h"
#include <algorithm>
#include <iostream>
bool Solver_Seidl::solv(Matrix A)
{
	if (norm1(A) || norm2(A) || norm3(A))
	{
		wyniki.set_d(A.size_y(), 1);
		Matrix x{ A.size_y(),2 };
		Matrix a{ A.size_x(), 1 };
		double m = 0;
		for (int i = 0; i < A.size_y(); i++)
		{
			a[i][0] = A[i][i];
			A[i][i] = 0;

			for (int j = 0; j < A.size_y(); j++)
			{

				A[i][j] /= -a[i][0];

			}
		}
		bool stop = 1;


		int k = 0;
		for (k = 0; stop; k++)
		{
			stop = 0;
			for (int i = 0; i < A.size_y(); i++)
			{
				x[i][0] = A[i][A.size_y()] / a[i][0];
				for (int j = 0; j < A.size_y(); j++)
				{
					x[i][0] += (x[j][0] * A[i][j]);
				}

				if ((abs(x[i][0] - x[i][1]) > precision))
				{
					stop = 1;
				}

			}
			for (int l = 0; l < A.size_y(); l++)
				x[l][1] = x[l][0];

		}
		
		for (int i = 0; i < A.size_y(); i++)
			wyniki[i][0] = x[i][k % 2];
		

		return true;
	}
	else
		return false;
}