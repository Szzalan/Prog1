#include "std_lib_facilities.h"
#include "Matrix.h"
#include "MatrixIO.h"
#include <complex>
int sq(int x)
{	
	if(x<0) error("no square root");
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
	//3
	cout << "a Matrix size: " << a.size() << endl;
	cout << "b Matrix size: " << b.size() << endl;
	cout << "c Matrix size: " << c.size() << endl;
	cout << "d Matrix size: " << d.size() << endl;
	cout << "e Matrix size: " << e.size() << endl;
	//4
	int test;
	cout << "Enter an intiger!" << endl;
	cin >> test;
	cout << sq(test) << endl;
	//5
	cout << "Enter ten doubles" << endl;
	Matrix<double> bruh(10);
	for (int i = 0; i < bruh.size(); ++i)
	{
		cin >> bruh[i];
	}
	cout << "Your matrix -> ";
	cout << bruh << endl;
	//6
	cout << "Enter an m and n integer" << endl;
	int m; int n;
	cin >> m; cin >> n;
	Matrix<int,2> table(n,m);
	for (Index i = 0; i < table.dim1(); ++i)
	{
		for (Index j = 0; j < table.dim2(); ++j)
		{
			table(i, j) = (i+1)*(j+1);
			cout << setw(3) << table(i,j);
		}
		cout << endl;

	}
	//7
	Matrix<complex<double>> mc(10);
	cout << "Enter 10 complex nums like (Real,Imaginary): ";
	complex<double>cp;
	for (int i = 0; i < 10; ++i)
	{
		cin >> cp;
		if(!cin) error("Problem reading complex number!");
		mc[i] = cp;
	}
	cout << "Complex matrix: " << mc << endl;
	complex<double> sum;
	for (Index i = 0; i < mc.size(); ++i)
	{
		sum += mc[i];
	}
	cout << "Sum: " << sum << endl;
	//8
	cout << "Enter 6 integers for a 2x3 Matrix: " << endl;
    Matrix<int,2> m23 (2,3);
    for (int i = 0; i < m23.dim1(); ++i)
    {
        for (int j = 0; j < m23.dim2(); ++j)
        {
            cin >> m23[i][j];
        }
    }
    cout << "Your matrix -> "<< m23 << endl;
	return 0;
}
