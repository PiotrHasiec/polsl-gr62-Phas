/** @file */
#pragma once
#include "Solver.h"
#include "Matrix.h"
class Solver_Seidl : public Solver_i///<Odpowiada za rozwiazywanie ukladow rowna�metoda Gaussa-Seidla
{

public:
	/** Implementacja metody rozwiazywania rowna� metoda Gaussa-Seidla
	@param[in] A macierz dolaczona Nx(N+1) gdzie lewa czesc NxN jest macierza wspolczynnikow, a ostatni wiersz jest wektorem wynikow rownania w postaci macierzowej*/
	bool solv(Matrix A);
};


