#ifndef __MATRIX_H__
#define __MATRIX_H__

using namespace std;

class Matrix{
public:
	// Creates the 2DARRAY(Matrix) and initializes all the elements to init
	Matrix(unsigned int num_rows, unsigned int num_columns, float init);
	// Creates the 2DARRAY(Matrix) and initializes the elements using data
	// stored in a 1DARRAY which is pointed to arr_ptr
	Matrix(unsigned int num_rows, unsigned int num_columns, float* arr_ptr);

	// Overloads the + addition operator and performs operation
	// according to Matrix addition
	Matrix& operator+(const Matrix& rhs);

	// Overloads the - subtraction operator and performs operation
	// according to Matrix subraction
	Matrix& operator-(const Matrix& rhs);

	// Overloads the x multiplication operator and performs operation
	// according to Matrix multiplication
	Matrix& operator*(const Matrix& rhs);

	// Return matrix where all the the elements signs are flipped
	Matrix& operator~();

	// Returns a transpose matrix by turning rows into columns
	Matrix transpose();

	// Returns a submatrix of the original matrix
	Matrix submatrix(unsigned int row_start, unsigned int row_end,
		unsigned int column_start, unsigned int column_end);

	// Returns the index row of matrix as a float pointer
	float* operator[](unsigned int index);
	const float* operator[](unsigned int index) const;

	// The Insertion operator reads num_rows x num_columns space separated
	// elements from the input stream
	istream& operator>>(istream& in);

	// The extraction operator print elements row by row
	ostream& operator<<(ostream& out);

	// Makes a deep copy of the Matrix class
	Matrix(const Matrix& copy);

	// Overrides the equal to operator and make the deep copy of
	// rhs Matrix
	Matrix& operator=(const Matrix& rhs);

	// All the allocated memeory is freed when a matrix object goes
	// out of scope
	~Matrix();
}

#endif