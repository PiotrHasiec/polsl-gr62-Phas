#pragma once
#include "Solver.h"
#include "Matrix.h"
class Solver_Gauss : public Solver//<Odpowiada za rozwi�zywanie uk�ad�w r�wna�
{
public:
	bool solv(Matrix A);
};
