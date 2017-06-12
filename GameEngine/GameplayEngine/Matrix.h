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
	Matrix operator+(float x);
	Matrix operator-(float x);
	Matrix operator*(float x);
	Matrix operator/(float x);
	Matrix operator-(const Matrix&);
	Matrix operator*(const Matrix&);
	Matrix inv();
	void PrintMatrix();
	float Determinant();
	~Matrix();
};

