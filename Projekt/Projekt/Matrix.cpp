#include "Matrix.h"
#include <iostream>
#include <algorithm>
#include <iomanip>
Matrix::Matrix()
{
	m = 0;
	x = y = capacity_x = capacity_y = 0;

}

Matrix::Matrix(int a, int b)
{
	y = a;
	x = b;
	capacity_x =  x;
	capacity_y =  y;
	m = new double* [y];
	for (int i = 0; i < y; i++)
		m[i] = new double[x];

}
Matrix::Matrix(Matrix& A)
{
	if (this != &A)
	{
		int y = A.size_y();
		int x = A.size_x();
		double** tmp = new double* [y];
		for (int i = 0; i < y; i++)
			tmp[i] = new double[x];

		for (int i = 0; i < y; i++)
			for (int j = 0; j <x; j++)
			{
				(tmp[i][j]) = double(A.m[i][j]);
			}


		this->m = tmp;
		this->x = x;
		this->y = y;
			
	}
	else
	{
		m = 0;
		x = 0;
		y = 0;
	}
	capacity_x = x;
	capacity_y = y;
}
Matrix::~Matrix()
{

	for (int i = 0; i < capacity_y; i++)
		delete[] m[i];
	delete m;
	m = 0;

}
double* Matrix:: operator[] (int a)
{
	return m[a];
}

Matrix& Matrix::operator=(Matrix& A)
{

	if (this != &A)
	{
		int y = A.size_y();
		int x = A.size_x();
		double** tmp = new double* [y];
		for (int i = 0; i < y; i++)
			tmp[i] = new double[x];

		for (int i = 0; i < y; i++)
			for (int j = 0; j < x; j++)
			{
				(tmp[i][j]) = (A.m[i][j]);
			}

		for (int i = 0; i < y; i++)
			delete[] m[i];
		delete[] m;
		m = tmp;
		x = x;
		y = y;

	}
	return *this;
}

Matrix& Matrix::operator+=(Matrix& A)
{
	if (x == A.x and y == A.y)
	{
		for (int i = 0; i < y; i++)
		{
			for (int j = 0; j < x; j++)
			{
				m[i][j] += A.m[i][j];
			}
		}
	}
	return *this;
}

Matrix Matrix::operator+(Matrix& A)
{
	Matrix tmp{ y,x };
	if (x == A.x and y == A.y)
	{
		
		for (int i = 0; i < y; i++)
		{
			for (int j = 0; j < x; j++)
			{
				tmp.m[i][j] = m[i][j] + A.m[i][j];
			}
		}
	}
	return tmp;
}

Matrix Matrix::operator*(Matrix& A)
{
	Matrix l{ x,y };
	return l;
}

void Matrix::change_x(int x1, int x2)
{

	for (int i = 0; i < y; i++)
	{
		std::swap(m[i][x1], m[i][x2]);

	}

}
void Matrix::change_y(int y1, int y2)
{

	for (int i = 0; i < x; i++)
	{
		std::swap(m[y1][i], m[y1][i]);

	}

}
void Matrix::add_d_y(int d)
{
	if (y + d < capacity_y)
	{
		y += d;
	}
	else if (this->y + d > 0)
	{
		2 * capacity_y < y + d ? capacity_y += 2 * d : capacity_y *= 2;
		double** tmp = new double* [capacity_y];
		for (int i = 0; i < y + d; i++)
			tmp[i] = new double[x];

		for (int i = 0; i < y + d; i++)
			for (int j = 0; j < x; j++)
			{
				tmp[i][j] = this->m[i][j];
			}

		for (int i = 0; i < y; i++)
			delete[] m[i];
		delete[] m;
		m = tmp;
		x = x + d;
	}
	else
	{

		for (int i = 0; i < y; i++)
			delete[] m[i];
		delete[] m;
		m = 0;
		x = y = 0;
	}
}

void Matrix::set_d(int dy,int dx)
{
	if (dy < capacity_y and dx < capacity_x)
	{
		y = dy;
		x = dx;
	}
	else
	{
		double** tmp = new double* [dy];
		for (int i = 0; i < dy; i++)
			tmp[i] = new double[dx];

		

		for (int i = 0; i < y; i++)
			delete[] m[i];
		delete[] m;
		m = tmp;
		capacity_y = y = dy;
		capacity_x = x = dx;

	}
}

void Matrix::add_d_x(int d)
{

	if (x + d < capacity_x)
	{
		x += d;
	}
	if (this->x + d > 0)
	{
		2 * capacity_x < x + d ? capacity_x += 2 * d : capacity_x *= 2;
		double** tmp = new double* [y];
		for (int i = 0; i < y; i++)
			tmp[i] = new double[capacity_x];

		for (int i = 0; i < y ; i++)
			for (int j = 0; j < x && j < capacity_x ; j++)
			{
				tmp[i][j] = double(this->m[i][j]);
			}

		for (int i = 0; i < y; i++)
			delete[] m[i];
		delete[] m;
		m = tmp;
		y = y + d;
	}
	else
	{

		for (int i = 0; i < y; i++)
			delete[] m[i];
		delete[] m;
		m = 0;
		x = y = 0;
	}
}



void Matrix::wypisz()
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			std::cout<<std::fixed<<std::setw(7)<<std::setprecision(5) << m[i][j] << " ";

		}
		std::cout << std::endl;
	}
}
void Matrix::wypisz(int precision,int width)
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			std::cout << std::fixed << std::setw(width) << std::setprecision(precision) << m[i][j] << " ";

		}
		std::cout << std::endl;
	}
}
void Matrix::wypisz(int precision)
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			std::cout << std::fixed  << std::setprecision(precision) << m[i][j] << " ";

		}
		std::cout << std::endl;
	}
}
int Matrix::size_y()
{
	return y;
}

int Matrix::size_x()
{
	return x;
}



