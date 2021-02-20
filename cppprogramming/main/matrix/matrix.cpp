#include <iostream>
#include "matrix.h"
using namespace std;

Matrix::Matrix(unsigned int num_rows, unsigned int num_columns, float init){
	this->num_rows = num_rows;
	this->num_columns = num_columns;
	this->size = (num_rows * num_columns);
	this->matrix = new float*[num_rows];
	for (unsigned int i = 0; i < num_rows; i++){
		matrix[i] = new float[num_columns];
	}
	for (unsigned int i = 0; i < num_rows; i++){
		for (unsigned int j = 0; j < num_columns; j++){
			matrix[i][j] = init;
		}
	}
}

Matrix::Matrix(unsigned int num_rows, unsigned int num_columns, float* arr_ptr){
	this->num_rows = num_rows;
	this->num_columns = num_columns;
	this->size = (num_rows * num_columns);
	this->matrix = new float*[num_rows];
	for (unsigned int i = 0; i < num_rows; i++){
		matrix[i] = new float[num_columns];
	}
	unsigned index = 0;
	for (unsigned int i = 0; i < num_rows; i++){
		for (unsigned int j = 0; j < num_columns; j++){
			matrix[i][j] = arr_ptr[index];
			index++;
		}
	}
}

Matrix Matrix::operator+(const Matrix& rhs){
	Matrix F_matrix = Matrix(this->num_rows, this->num_columns, -1.0);
	for (unsigned int i = 0; i < num_rows; i++){
		for (unsigned int j = 0; j < num_columns; j++){
			F_matrix.matrix[i][j] = this->matrix[i][j] + rhs.matrix[i][j];
		}
	}
	return F_matrix;
}

Matrix Matrix::operator-(const Matrix& rhs){
	Matrix F_matrix = Matrix(this->num_rows, this->num_columns, -1.0);
	for (unsigned int i = 0; i < num_rows; i++){
		for (unsigned int j = 0; j < num_columns; j++){
			F_matrix.matrix[i][j] = this->matrix[i][j] - rhs.matrix[i][j];
		}
	}
	return F_matrix;
}

Matrix Matrix::operator*(const Matrix& rhs){
	Matrix F_matrix = Matrix(this->num_rows, rhs.num_columns, -1.0);
	for (unsigned int i = 0; i < this->num_rows; i++){
		for (unsigned int j =0 ; j < rhs.num_columns; j++){
			float result = 0.0;
			for (unsigned int k = 0; k < rhs.num_columns; k++){
				result += (this->matrix[i][k] * rhs.matrix[k][j]);
			}
			F_matrix.matrix[i][j] = result;
		}
	}
	return F_matrix;
}

Matrix Matrix::operator~(){
	Matrix F_matrix = Matrix(num_rows, num_columns, -1.0);
	for (unsigned int i = 0; i < num_rows; i++){
		for (unsigned int j = 0; j < num_columns; j++){
			F_matrix.matrix[i][j] = -(this->matrix[i][j]);
		}
	}
	return F_matrix;
}

Matrix Matrix::transpose(){
	Matrix F_matrix = Matrix(num_columns, num_rows, -1.0);
	// Matrix F_matrix = Matrix(num_columns, num_rows, -1.0);
	for (unsigned int i = 0; i < this->num_columns; i++){
		for (unsigned int j = 0; j < this->num_rows; j++){
			F_matrix.matrix[i][j] = this->matrix[j][i];
		}
	}
	return F_matrix;
}

Matrix Matrix::submatrix(unsigned int row_start, unsigned int row_end,
	unsigned int column_start, unsigned int column_end){
	Matrix F_matrix = Matrix(row_end, column_end, -1.0);
	for (unsigned int i = row_start; i < row_end; i++){
		for (unsigned int j = column_start; j < column_end; j++){
			F_matrix.matrix[i][j] = this->matrix[i][j];
		}
	}
	return F_matrix;
}

float* Matrix::operator[](unsigned int index){
	return this->matrix[index];
}

const float* Matrix::operator[](unsigned int index) const{
	return this->matrix[index];
}

istream& operator>>(istream& in, Matrix& rhs){
	for (unsigned int i = 0; i < rhs.num_rows; i++){
		for (unsigned int j = 0; j < rhs.num_columns; j++){
			in >> rhs.matrix[i][j];
		}
	}
	return in;
}

ostream& operator<<(ostream& out, const Matrix& rhs){
	for (unsigned int i = 0; i < rhs.num_rows; i++){
		for (unsigned int j = 0; j < rhs.num_columns; j++){
			if (j != rhs.num_columns-1)
				out << rhs.matrix[i][j] << " ";
			else
				out << rhs.matrix[i][j];
		}
		if (i != rhs.num_rows-1)
			out << endl;
	}
	return out;
}

Matrix::Matrix(const Matrix& copy){
	this->num_rows = copy.num_rows;
	this->num_columns = copy.num_columns;
	this->size = ((copy.num_rows) * (copy.num_columns));
	this->matrix = new float*[num_rows];
	for (unsigned int i = 0; i < num_rows; i++){
		matrix[i] = new float[num_columns];
	}
	for (unsigned int i = 0; i < num_rows; i++){
		for (unsigned int j = 0; j < num_columns; j++){
			this->matrix[i][j] = copy.matrix[i][j];
		}
	}
}

Matrix::~Matrix(){
	for(unsigned int i = 0; i < this->num_rows; i++){
		if (matrix[i] != NULL){
			delete[] matrix[i];
			matrix[i] = NULL;
		}
	}
	if (matrix != NULL){
		delete[] matrix;
		matrix = NULL;
	}
}

float arr_ptr[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};

int main(){
    // Test the first constructor
    Matrix A = Matrix(2, 3, 1.0);
    Matrix B = Matrix(2, 3, 2.0);
    const Matrix C = Matrix(3, 2, 3.0);

    cout << "A\n" << A << endl;
    cout << "B\n" << B << endl;

    // Test the second constructor
    Matrix D = Matrix(3, 2, arr_ptr);
    cout << "D\n" << D << endl;

    // Test matrix addition
    cout << "A + B\n" << (A + B) << endl;

    // Test matrix subtraction
    cout << "A - B\n" << (A - B) << endl;

    // Test matrix multiplication
    cout << "B * C\n" << (B * C) << endl;

    // Test unary negation
    cout << "-B\n" << (~B) << endl;

    // Test bracket operator
    // non-const
    A[0][0] = 0.0;
    cout << "modified A\n" << A << endl;
    // const
    cout << "C[0][0]\n" << C[0][0] << endl << endl;
   // C[0][0] = 1.0;  // compiler error!

    // Test transpose
    cout << "A.transpose()\n" << A.transpose() << endl;

    // Test submatrix
    cout << "D.submatrix(1, 3, 0, 1)\n"
              << D.submatrix(1, 3, 0, 1) << endl;

    // Test extraction operator
    Matrix E = Matrix(3, 2, 0.0);
    cout << "Please enter 6 floats to populate E" << endl;
    cin >> E;
    cout << "E after extraction\n" << E << endl;

    // Test copy constructor
    Matrix F = B;
    F[0][0] = 100;
    cout << "B after B's copy is modified\n" << B << endl;

    return 0;
}