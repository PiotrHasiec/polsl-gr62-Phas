#pragma once
#include "Solver.h"
#include "Matrix.h"
class Solver_Seidl : public Solver_i//<Odpowiada za rozwi¹zywanie uk³adów równañ
{

public:
	bool solv(Matrix A);
};


