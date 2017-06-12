#pragma once
class Matrix
{
	int rows, cols;
	int dim;
	float** mat;

public:
	Matrix();
	Matrix(const Matrix &);
	float & operator()(int, int);
	Matrix & operator=(const Matrix&);

	Matrix operator+(const Matrix&);
	Matrix operator-(const Matrix&);
	Matrix operator*(const Matrix&);
	Matrix inv(const Matrix&);
	float Determinant();
	~Matrix();
};

