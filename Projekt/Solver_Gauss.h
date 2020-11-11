#pragma once
#include "Solver.h"
#include "Matrix.h"
class Solver_Gauss : public Solver//<Odpowiada za rozwi¹zywanie uk³adów równañ
{
public:
	bool solv(Matrix A);
};
