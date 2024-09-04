#include "MatrixClass.h"

MatrixClass& MatrixClass::operator=(const MatrixClass& other)
{
	this->ClearMatrix();

	this->rows = other.GetRows();
	this->columns = other.GetColumns();

	this->CreatingMatrix(other.GetRows(), other.GetColumns());

	for (int i = 0; i < other.GetRows(); i++)
		for (int j = 0; j < other.GetColumns(); j++)
			this->arr[i][j] = other.arr[i][j];

	return *this;
}

MatrixClass::MatrixClass()
{
	this->rows = 0;
	this->columns = 0;
	CreatingMatrix(0, 0);
}

MatrixClass::MatrixClass(int rows, int columns)
{
	this->rows = rows;
	this->columns = columns;

	CreatingMatrix(rows, columns);
}

MatrixClass::~MatrixClass()
{
	ClearMatrix();
}

void MatrixClass::CreatingMatrix(int rows, int columns)
{
	arr = new int* [rows];

	for (int i = 0; i < rows; i++)
		arr[i] = new int[columns];
}

MatrixClass MatrixClass::Transposition()
{
	MatrixClass temp(this->columns, this->rows);

	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->columns; j++)
			temp.arr[i][j] = this->arr[j][i];

	return temp;
}

void MatrixClass::ClearMatrix()
{
	for (int i = 0; i < GetRows(); i++)
		delete[] arr[i];
	delete[] arr;
}

ostream& operator<<(ostream& os, const MatrixClass& other)
{
	for (int i = 0; i < other.GetRows(); i++)
	{
		for (int j = 0; j < other.GetColumns(); j++)
		{
			os << other.GetMeaning(i, j) << " ";
		}
		os << endl;
	}
	return os;
}

istream& operator>>(istream& os, MatrixClass& other)
{
	for (int i = 0; i < other.GetRows(); i++)
		for (int j = 0; j < other.GetColumns(); j++)
		{
			os >> other.arr[i][j];
		}
	return os;
}
