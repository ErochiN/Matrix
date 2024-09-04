#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class MatrixClass
{
public:
	friend ostream& operator<< (ostream& os, const MatrixClass& other);
	friend istream& operator>>(istream& os, MatrixClass& other);

	MatrixClass& operator= (const MatrixClass& other);

	MatrixClass();
	MatrixClass(int rows, int columns);
	~MatrixClass();

	void ClearMatrix();
	void CreatingMatrix(int rows, int columns);

	int GetRows() const { return this->rows; }
	int GetColumns() const { return this->columns; }
	int GetMeaning(int i, int j) const { return arr[i][j]; }

	void SetMeaning(int i, int j, int value) { arr[i][j] = value; }

	MatrixClass Transposition();
private:
	int rows;
	int columns;
	int** arr;

};

