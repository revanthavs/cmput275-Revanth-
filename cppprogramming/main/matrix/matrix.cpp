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

Matrix& Matrix::operator+(const Matrix& rhs){
	Matrix F_matrix(this->num_rows, this->num_columns, -1.0);
	for (unsigned int i = 0; i < num_rows; i++){
		for (unsigned int j = 0; j < num_columns; j++){
			F_matrix.matrix[i][j] = this->matrix[i][j] + rhs.matrix[i][j];
		}
	}
	return F_matrix;
}

Matrix& Matrix::operator-(const Matrix& rhs){
	Matrix F_matrix(this->num_rows, this->num_columns, -1.0);
	for (unsigned int i = 0; i < num_rows; i++){
		for (unsigned int j = 0; j < num_columns; j++){
			F_matrix.matrix[i][j] = this->matrix[i][j] - rhs.matrix[i][j];
		}
	}
	return F_matrix;
}

Matrix& Matrix::operator*(const Matrix& rhs){
	Matrix F_matrix(this->num_rows, rhs.num_columns, -1.0);
	for (unsigned int i = 0; i < this->num_rows, i++){
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

Matrix& Matrix::operator~(){
	Matrix F_matrix(num_rows, num_columns, -1.0);
	for (unsigned int i = 0; i < num_rows; i++){
		for (unsigned int j = 0; j < num_columns; j++){
			F_matrix.matrix[i][j] = -(this->matrix[i][j]);
		}
	}
	return F_matrix;
}

Matrix Matrix::transpose(){
	Matrix F_matrix(num_columns, num_rows, -1.0);
	for (unsigned int i = 0; i < this->num_columns; i++){
		for (unsigned int j = 0; j < this->num_rows; j++){
			F_matrix.matrix[i][j] = this->matrix[j][i];
		}
	}
	return F_matrix;
}

Matrix Matrix::submatrix(unsigned int row_start, unsigned int row_end,
	unsigned int column_start, unsigned int column_end){
	Matrix F_matrix(row_end, column_end, -1.0);
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

const float* Matrix::operator[](unsigned int index){
	return this->matrix[index];
}

istream& Matrix::operator>>(istream& in){
	for (unsigned int i = 0; i < this->num_rows; i++){
		for (unsigned int j = 0; j < this->num_columns; j++){
			in >> this->matrix[i][j];
		}
	}
	return in;
}

ostream& Matrix::operator<<(ostream& out){
	for (unsigned int i = 0; i < this->num_rows; i++){
		for (unsigned int j = 0; j < this->num_columns; j++){
			if (j != this->num_columns)
				out << this->matrix[i][j] << " ";
			else
				out << this->matrix[i][j];
		}
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
	delete[] matrix;
}

int main(){

}