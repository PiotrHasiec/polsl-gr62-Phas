#pragma once
#include "Solver.h"
#include "Matrix.h"
class Solver_Seidl : public Solver_i//<Odpowiada za rozwi�zywanie uk�ad�w r�wna�
{

public:
	bool solv(Matrix A);
};


