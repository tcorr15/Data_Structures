#ifndef MATRIX_H
#define MATRIX_H
#include<iostream>

using namespace std;

template <typename T>
class matrix {
public:
	// constructor & destructor
	matrix(int n_rows, int n_cols);
	~matrix();
	// copy constructor
	matrix(const matrix& o);
	// overload [] to return pointer to the i'th row of data
	T* operator[](int i);
	// overload + and * for matrices addition & multiplication
	matrix operator+(const matrix& a);
	matrix operator*(const matrix& a);
private:
	// matrx dimensions & data
	int num_rows, num_cols;
	T** data;
};

template <typename T>
matrix<T>::matrix(int n_rows, int n_cols) {
	num_rows = n_rows;
	num_cols = n_cols;
	data = new T * [num_rows];
	for (int i = 0; i < num_rows; i++)
		data[i] = new T[num_cols];
}

template<typename T>
matrix<T>::~matrix() {
	for (int i = 0; i < num_rows; i++)
		delete[] data[i];
	delete[] data;
}

template<typename T>
matrix<T>::matrix(const matrix& o) {
	num_rows = o.num_rows;
	num_cols = o.num_cols;
	data = new T * [num_rows];
	for (int i = 0; i < num_rows; i++) {
		data[i] = new T[num_cols];
		for (int j = 0; j < num_cols; j++)
			data[i][j] = o.data[i][j];
	}
}

template<typename T>
T* matrix<T>::operator[](int i) {
	return data[i];
}

template<typename T>
matrix<T> matrix<T>::operator+(const matrix& a) {
	if (num_cols != a.num_cols || num_rows != a.num_rows) {
		cout << "Unable to add these matrices together" << endl;
		exit(1);
	}
	matrix temp(num_rows, num_cols);
	for (int i = 0; i < num_rows; i++) {
		for (int j = 0; j < num_cols; j++)
			temp[i][j] = data[i][j] + a.data[i][j];
	}
	return temp;
}

template<typename T>
matrix<T> matrix<T>::operator*(const matrix& a) {
	if (num_cols != a.num_rows) {
		cout << "Unable to multiply these matrices together" << endl;
		exit(1);
	}
	matrix temp(num_rows, a.num_cols);
	for (int i = 0; i < num_rows; i++) {
		for (int j = 0; j < a.num_cols; j++) {
			T sum = 0;
			for (int k = 0; k < num_cols; k++)
				sum += data[i][k] * a.data[k][j];
			temp.data[i][j] = sum;
		}
	}
	return temp;
}

#endif // !MATRIX_H
