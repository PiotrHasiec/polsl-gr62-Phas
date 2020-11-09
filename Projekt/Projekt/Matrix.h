#pragma once

class Matrix//< Dynamicznie tworzona macierz
{
	double** m;
	int x;
	int y;
	int capacity_x;
	int capacity_y;
public:
	Matrix();
	Matrix(int a, int b);
	Matrix(Matrix& A);
	~Matrix();
	double* operator[] (int a);
	Matrix& operator= (Matrix& A);
	Matrix operator+ (Matrix& A);
	Matrix& operator+= (Matrix& A);
	Matrix operator* (Matrix& A);
	void change_x(int x1, int x2);
	void change_y(int y1, int y2);
	void add_d_x(int);

	void set_d(int,int);
	void add_d_y(int);
	void wypisz();
	void wypisz(int precision, int width);
	void wypisz(int precision);
	int size_y();
	int size_x();

};




