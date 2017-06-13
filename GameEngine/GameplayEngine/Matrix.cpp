#include "Matrix.h"
#include <iostream>

Matrix::Matrix()
{
	int rows_ = 3, cols_ = 3;
	rows = rows_;cols = cols_;
	dim = rows*cols;
	mat = new float*[rows];
	for (int i = 0; i < rows; i++)
		mat[i] = new float[cols];

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			mat[i][j] = 0.0f;
	}
}
Matrix::~Matrix()
{
	for (int i = 0; i < rows; i++)
		delete[] mat[i];
	delete mat;
}

Matrix::Matrix(const Matrix &A)
{
	rows = A.rows;
	cols = A.cols;
	dim = A.dim;

	mat = new float*[rows];

	for (int i = 0; i < rows; i++)
	{
		mat[i] = new float[cols];
		for (int j = 0; j < cols; j++)
			mat[i][j] = A.mat[i][j];
	}
}
float & Matrix::operator()(int i, int j)
{
	return mat[i][j];
}

Matrix & Matrix::operator=(const Matrix& A)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			mat[i][j] = A.mat[i][j];
	}
	return *this;
}

Matrix Matrix::operator+(const Matrix& A)
{
	Matrix B;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			B.mat[i][j] = mat[i][j] + A.mat[i][j];
	return Matrix(B);
}

Matrix Matrix::operator+(float x)
{
	Matrix B;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			B.mat[i][j] = mat[i][j] + x;
	return Matrix(B);
}

Matrix Matrix::operator-(float x)
{
	Matrix B;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			B.mat[i][j] = mat[i][j] - x;
	return Matrix(B);
}

Matrix Matrix::operator*(float x)
{
	Matrix B;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			B.mat[i][j] = mat[i][j] * x;
	return Matrix(B);
}

Matrix Matrix::operator/(float x)
{
	Matrix B;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			B.mat[i][j] = mat[i][j] / x;
	return Matrix(B);
}

Matrix Matrix::operator-(const Matrix& A)
{
	Matrix B;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			B.mat[i][j] = mat[i][j] - A.mat[i][j];
	return Matrix(B);
}

Matrix Matrix::operator*(const Matrix& A)		// think of a better implementation
{
	Matrix B;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			B.mat[i][j] = 0;

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			for (int k = 0; k < cols; k++)			// assert cols = A.rows
				B.mat[i][j] += mat[i][k] * A.mat[k][j];
	return B;
}
void Matrix::PrintMatrix()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			std::cout << mat[i][j];
		std::cout << std::endl;
	}
}


Matrix Matrix::inv()
{
	Matrix B;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			B.mat[i][j] = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			B.mat[i][j] = ((mat[(j + 1) % 3][(i + 1) % 3] * mat[(j + 2) % 3][(i + 2) % 3]) - (mat[(j + 1) % 3][(i + 2) % 3] * mat[(j + 2) % 3][(i + 1) % 3])) / Determinant();
		}
	}
	return B;
}
float Matrix::Determinant()
{
	float determinant = 0;
	for (int i = 0; i < 3; i++)
		determinant = determinant + (mat[0][i] * (mat[1][(i + 1) % 3] * mat[2][(i + 2) % 3] - mat[1][(i + 2) % 3] * mat[2][(i + 1) % 3]));
	return determinant;
}




