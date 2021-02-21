#include <iostream>
#include "matrix.h"
using namespace std;

/*
	Creates the 2DARRAY(Matrix) and initializes all the elements to init
	
	Arguments:
		num_rows(unsigned int): Number of Rows
		num_columns(unsigned int): Number of columns
		init(float): The value to be initialized

*/
Matrix::Matrix(unsigned int num_rows, unsigned int num_columns, float init){
	
	// Initializing the dimention and the size of the Matrix to
	// the called object to get access them anytime needed in program
	this->num_rows = num_rows;
	this->num_columns = num_columns;
	this->size = (num_rows * num_columns);

	// Allocating memory from heap for an array of float-pointers
	this->matrix = new float*[num_rows];

	// Allocating memory from heap for each row with number of columns
	// float elements
	for (unsigned int i = 0; i < num_rows; i++){
		matrix[i] = new float[num_columns];
	}

	// Initializing all the elements to the init value spacified by the user
	for (unsigned int i = 0; i < num_rows; i++){
		for (unsigned int j = 0; j < num_columns; j++){
			matrix[i][j] = init;
		}
	}

}

/*
	Creates the 2DARRAY(Matrix) and initializes the elements using data
	stored in a 1DARRAY which is pointed to arr_ptr

	Arguments:
		num_rows(unsigned int): Number of Rows
		num_columns(unsigned int): Number of columns
		arr_ptr(float *): Pointer to the 1D array of elements

*/


Matrix::Matrix(unsigned int num_rows, unsigned int num_columns,
	float* arr_ptr){

	// Initializing the dimention and the size of the Matrix to
	// the called object to get access them anytime needed in program
	this->num_rows = num_rows;
	this->num_columns = num_columns;
	this->size = (num_rows * num_columns);

	// Allocating memory from heap for an array of float-pointers
	this->matrix = new float*[num_rows];

	// Allocating memory from heap for each row with number of columns
	// float elements
	for (unsigned int i = 0; i < num_rows; i++){
		matrix[i] = new float[num_columns];
	}
	unsigned index = 0;

	// Initializing all the elements to the values spacified by the user
	for (unsigned int i = 0; i < num_rows; i++){
		for (unsigned int j = 0; j < num_columns; j++){
			matrix[i][j] = arr_ptr[index];
			index++;
		}
	}

}

/*
	Overloads the + addition operator and performs operation
	according to Matrix addition
	Since we are creating the new instance rather than modifying
	the existing object it's a constant
	
	Arguments:
		rhs(Matrix&): reference to the Matrix instance

	Returns:
		F_matrix(Matrix): The new instance after add the matrixs

*/

Matrix Matrix::operator+(const Matrix& rhs) const{
	// To return the Matrix object after performing the assigned operation
	Matrix F_matrix = Matrix(this->num_rows, this->num_columns, -1.0);
	// Since the matrix addition is to add every element to
	// the corresponding elements of the matrix
	for (unsigned int i = 0; i < num_rows; i++){
		for (unsigned int j = 0; j < num_columns; j++){
			F_matrix.matrix[i][j] = this->matrix[i][j] + rhs.matrix[i][j];
		}
	}
	return F_matrix;
}


/*
	Overloads the - subtraction operator and performs operation
	according to Matrix subraction
	Since we are creating the new instance rather than modifying
	the existing object it's a constant
	
	Arguments:
		rhs(Matrix&): reference to the Matrix instance

	Returns:
		F_matrix(Matrix): The new instance after add the matrixs
	
*/
Matrix Matrix::operator-(const Matrix& rhs) const{
	// To return the Matrix object after performing the assigned operation
	Matrix F_matrix = Matrix(this->num_rows, this->num_columns, -1.0);
	// Since matrix subtraction is to subract every element to
	// the corresponding elements of the Matrix
	for (unsigned int i = 0; i < num_rows; i++){
		for (unsigned int j = 0; j < num_columns; j++){
			F_matrix.matrix[i][j] = this->matrix[i][j] - rhs.matrix[i][j];
		}
	}
	return F_matrix;
}

/*

	Overloads the x multiplication operator and performs operation
	according to Matrix multiplication
	Since we are creating the new instance rather than modifying
	the existing object it's a constant
	
	Arguments:
		rhs(Matrix&): reference to the Matrix instance

	Returns:
		F_matrix(Matrix): The new instance after add the matrixs

*/
Matrix Matrix::operator*(const Matrix& rhs) const{
	// To return the Matrix object after performing the assigned operation
	Matrix F_matrix = Matrix(this->num_rows, rhs.num_columns, -1.0);
	// Performing multiplication according to the Matrix Multiplication
	for (unsigned int i = 0; i < this->num_rows; i++){
		for (unsigned int j =0 ; j < rhs.num_columns; j++){
			float result = 0.0;
			for (unsigned int k = 0; k < this->num_columns; k++){
				result += (this->matrix[i][k] * rhs.matrix[k][j]);
			}
			F_matrix.matrix[i][j] = result;
		}
	}
	return F_matrix;
}

/*

	Returns matrix where all the the elements signs are flipped
	Since we are creating the new instance rather than modifying
	the existing object it's a constant

	Returns:
		F_matrix(Matrix): The new instance after add the matrixs
	
*/
Matrix Matrix::operator~() const{
	// To return the Matrix object after performing the assigned operation
	Matrix F_matrix = Matrix(num_rows, num_columns, -1.0);
	// Changing the sign of each element and assigning it to new instance
	for (unsigned int i = 0; i < num_rows; i++){
		for (unsigned int j = 0; j < num_columns; j++){
			F_matrix.matrix[i][j] = -(this->matrix[i][j]);
		}
	}
	return F_matrix;
}

/*

	Returns a transpose matrix by turning rows into columns
	Since we are creating the new instance rather than modifying
	the existing object it's a constant

	Returns:
		F_matrix(Matrix): The new instance after add the matrixs
	
*/
Matrix Matrix::transpose() const{
	// To return the Matrix object after performing the assigned operation
	Matrix F_matrix = Matrix(num_columns, num_rows, -1.0);
	// Exchanging the elements of row to columns and columns to rows
	for (unsigned int i = 0; i < this->num_columns; i++){
		for (unsigned int j = 0; j < this->num_rows; j++){
			F_matrix.matrix[i][j] = this->matrix[j][i];
		}
	}
	return F_matrix;
}

/*
	
	Returns a submatrix of the original matrix
	Since we are creating the new instance rather than modifying
	the existing object it's a constant
	
	Arguments:
		row_start(unsigned int): Start of the row 
		row_end(unsigned int): end of the row
		column_start(unsigned int): start of the column
		column_end(unsigned int): end of the column

	Returns:
		F_matrix(Matrix): The new instance after add the matrixs
		
*/
Matrix Matrix::submatrix(unsigned int row_start, unsigned int row_end,
	unsigned int column_start, unsigned int column_end) const{
	// To return the Matrix object after performing the assigned operation
	// According to the given dimentions
	Matrix F_matrix = Matrix(row_end, column_end, -1.0);
	// Assigning the values
	for (unsigned int i = row_start; i < row_end; i++){
		for (unsigned int j = column_start; j < column_end; j++){
			F_matrix.matrix[i][j] = this->matrix[i][j];
		}
	}
	return F_matrix;
}

/*
	Returns the index row of matrix as a float pointer
	depends on the version of weather constant version or non 
	constant version
	
	Arguments:
		index(unsigned int): The index of the matrix

	Returns:
		float*
	
*/
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
		out << endl;
	}

	return out;
}

// Copy Construtor
Matrix::Matrix(const Matrix& copy){
	// Initializing the dimention and the size of the Matrix to
	// the called object to get access them anytime needed in program
	this->num_rows = copy.num_rows;
	this->num_columns = copy.num_columns;
	this->size = ((copy.num_rows) * (copy.num_columns));

	// Allocating memory from heap for an array of float-pointers
	this->matrix = new float*[num_rows];

	// Allocating memory from heap for each row with number of columns
	// float elements
	for (unsigned int i = 0; i < num_rows; i++){
		matrix[i] = new float[num_columns];
	}
	for (unsigned int i = 0; i < num_rows; i++){
		for (unsigned int j = 0; j < num_columns; j++){
			this->matrix[i][j] = copy.matrix[i][j];
		}
	}
}

// Destrcutor
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