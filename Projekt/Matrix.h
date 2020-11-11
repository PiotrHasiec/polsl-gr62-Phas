#pragma once
#include <iostream>
class Matrix//< Dynamic allocated Matrix
{
	double** m;//<
	int x;//< size of matrix in x dimension
	int y;//< size of matrix in y dimension
	int c_x;//< capacity of x dimension
	int c_y;//<capacity of y dimension
public:

	/**Konstruktor domy�lny macierzy
	Tworzy obiekt ale nie rezerwuje na niego �adnej pami�ci*/
	Matrix();

	/** Konstruktor - tworzy macierz o rozmiarach AxB gdzie A to liczba wierszy, a B to liczba kolumn
	@param[in] a liczba wierszy macierzy
	@param[in] b liczba kolumn macierzy*/
	Matrix(int a, int b);

	/** Konstruktor kopiuj�cy
	@param[in] A macierz za pomoc� kt�rej nale�y zainicjowa� dan� macierz*/
	Matrix(Matrix& A);

	/**Destruktor macierzy*/
	~Matrix();

	/**Operator pozwalaj�cy na dost�p do konkretnych kom�rek macierzy.
	Je�li macierz ma jedn� wiersz lub kolumn� to nale�y odwo�a� si� do niej - np A[0][n]*/
	double* operator[] (int a) const;

	/**Operator przepisania macierzy*/
	Matrix& operator= (const Matrix& A);

	/**Operator przepisania tablicy do macierzy. Zak�adam, �e tablica ma rozmiar taki jak aktualnie ma macierz*/
	Matrix& operator=(double** a);

	Matrix operator+ (const Matrix& A)const;
	Matrix& operator+= (Matrix& A);
	Matrix operator* (const Matrix& A)const;
	Matrix operator* (const double a)const;
	Matrix operator*= (double a);
	friend Matrix operator* (double a,Matrix A);
	void change_x(int x1, int x2);
	void change_y(int y1, int y2);
	void add_d_x(int x);
	void set_d(int y,int x);
	void add_d_y(int y);
	const void print();
	const void print(int precision, int width);
	const void print(int precision);

	friend std::ostream& operator<<(std::ostream& os,  Matrix& A);

	const int size_y()const;
	const int size_x()const;
	const int capacity_x()const;
	const int capacity_y()const;


};




