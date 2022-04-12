#include "std_lib_facilities.h"
#include "Matrix.h"
#include "MatrixIO.h"
int sq(int x)
{
	return sqrt(x); 
}

using namespace Numeric_lib;
int main()
{
	cout << "char size: " << sizeof(char) << endl;
	cout << "short size: " << sizeof(short) << endl;
	cout << "int size: " << sizeof(int) << endl;
	cout << "long size: " << sizeof(long) << endl;
	cout << "float size: " << sizeof(float) << endl;
	cout << "double size: " << sizeof(double) << endl;
	cout << "int* size: " << sizeof(int*) << endl;
	cout << "double* size: " << sizeof(double*) << endl;
	Matrix<int> a(10); Matrix<int> b(100);Matrix<double> c(10); Matrix<int,2> d(10,10); 
	Matrix<int,3> e(10,10,10);
		cout << "a Matrix size: " << sizeof(a) << endl;
		cout << "b Matrix size: " << sizeof(b) << endl;
		cout << "c Matrix size: " << sizeof(c) << endl;
		cout << "d Matrix size: " << sizeof(d) << endl;
		cout << "e Matrix size: " << sizeof(e) << endl;
	int test;
	cout << "Enter an intiger!" << endl;
	cin >> test;
	cout << sq(test) << endl;
	return 0;
}
