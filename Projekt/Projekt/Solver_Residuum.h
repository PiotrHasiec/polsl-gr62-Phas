#pragma once
#include "Solver.h"
#include "Matrix.h"
class Solver_Residuum : public Solver_i//<Odpowiada za rozwi�zywanie uk�ad�w r�wna�
{

	double residuum(int& c, Matrix& a, Matrix& b);
public:
	bool solv(Matrix A);

};

