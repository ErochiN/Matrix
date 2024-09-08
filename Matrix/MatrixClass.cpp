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

MatrixClass MatrixClass::operator+(const MatrixClass& other)
{
	if (this->GetRows() != other.GetRows() &&
		this->GetColumns() != other.GetColumns())
		return *this;
	else
	{
		MatrixClass sumMatrix(this->GetRows(), this->GetColumns());

		for (int i = 0; i < this->GetRows(); i++)
			for (int j = 0; j < this->GetColumns(); j++)
			{
				sumMatrix.arr[i][j] = this->arr[i][j] + other.arr[i][j];
			}
		return sumMatrix;
	}

}

MatrixClass MatrixClass::operator-(const MatrixClass& other)
{
	if (this->GetRows() != other.GetRows() &&
		this->GetColumns() != other.GetColumns())
		return *this;
	else
	{
		MatrixClass sumMatrix(this->GetRows(), this->GetColumns());

		for (int i = 0; i < this->GetRows(); i++)
			for (int j = 0; j < this->GetColumns(); j++)
			{
				sumMatrix.arr[i][j] = this->arr[i][j] - other.arr[i][j];
			}
		return sumMatrix;
	}
}

MatrixClass MatrixClass::operator*(const MatrixClass& other)
{
	if (this->GetRows() != other.GetColumns())
		return *this;
	else
	{
		MatrixClass resultMatrix(this->GetRows(), other.GetColumns());

		for (int i = 0; i < this->GetRows(); i++)
		{
			for (int k = 0; k < other.GetColumns(); k++)
			{
				int positionCounter = 0;
				int one = this->arr[i][positionCounter] * other.arr[positionCounter][k];
				int two = this->arr[i][positionCounter + 1] * other.arr[positionCounter + 1][k];

				resultMatrix.arr[i][k] = (one + two);
				positionCounter++;
			}
		}
		return resultMatrix;
	}
}

MatrixClass::MatrixClass()
{
	this->rows = 0;
	this->columns = 0;
	CreatingMatrix(0, 0);
}

MatrixClass::MatrixClass(const MatrixClass& other)
{
	this->rows = other.GetRows();
	this->columns = other.GetColumns();

	this->CreatingMatrix(other.GetRows(), other.GetColumns());

	for (int i = 0; i < other.GetRows(); i++)
		for (int j = 0; j < other.GetColumns(); j++)
			this->arr[i][j] = other.arr[i][j];
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

bool MatrixClass::operator==(const MatrixClass& other)
{
	if (this->GetColumns() != other.GetColumns() &&
		this->GetRows() != other.GetRows())
		return false;

	else
	{
		for (int i = 0; i < this->GetRows(); i++)
			for (int j = 0; j < this->GetColumns(); j++)
				if (this->arr[i][j] != other.arr[i][j])
					return false;
	}
	return true;
}

bool MatrixClass::operator!=(const MatrixClass& other)
{
	return !(*this == other);
}

void MatrixClass::CreatingMatrix(int rows, int columns)
{
	arr = new int* [rows];

	for (int i = 0; i < rows; i++)
		arr[i] = new int[columns];
}

void MatrixClass::CreatesSingleMatrix()
{
	int supplement = 0;
	for (int i = 0; i < this->GetRows(); i++)
	{
		for (int j = 0; j < this->GetColumns(); j++)
		{
			if (j == supplement)
				this->arr[i][j] = 1;
			else
				this->arr[i][j] = 0;
		}
		supplement++;
	}

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
