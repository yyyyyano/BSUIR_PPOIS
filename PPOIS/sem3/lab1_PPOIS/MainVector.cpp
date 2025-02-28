#include"Vector.h"

int main()
{
	Vector a;
	Vector b(-1.5, 4, 7.8, 1, 3.05, -5);
	cout << "Vector a:\n";
	cout << a;
	cout << "\nVector b:\n";
	cout << b;

	Vector c = a;

	cout << "\n\n\nVector's a length = " << a.CalculateLength();
	cout << "\nVector's b length = " << b.CalculateLength();

	Vector sum = a + b;
	cout << "\n\n\nThe sum of 2 vectors:   sum = a + b\n";
	cout << sum;
	cout << "\nThe sum of 2 vectors:   a += b";
	c += b;
	cout << c;

	Vector difference = a - b;
	cout << "\n\n\nThe difference of 2 vectors:   difference = a - b\n";
	cout << difference;
	cout << "\nThe difference of 2 vectors:   a -= b\n";
	c -= b;
	cout << c;

	Vector vectorsProduct = a * b;
	cout << "\n\n\nVectors product:   vectorsProduct = a * b\n";
	cout<<vectorsProduct;
	cout << "\nVectors product:   a *= b\n";
	a *= b;
	cout << a;

	double scalarProduct;
	scalarProduct = a * &b;
	cout << "\n\n\nScalar product:   scalarProduct = a * b = " << scalarProduct << endl;

	double value = 1.5;
	cout << "\n\n\nProduct of a vector and a number:   VNproduct = 1.5 * a =\n";
	Vector VNproduct = value * a;
	cout<<VNproduct;
	cout << "\nProduct of a vector and a number:   a *= 1.5\n";
	a *= value;
	cout << a;

	Vector division = a / b;
	cout << "\n\n\nVector division:   division = a / b\n";
	cout<<division;
	cout << "\nVector division:   a /= b\n";
	a /= b;
	cout << a;

	double cosineAB = a ^ b;
	cout << "\n\n\nCosine:   a ^ b = " << cosineAB << endl;

	cout << "\n\n\nCreate same vector:\n";
	cout << "\nUsing copy constructor:   Vector d = a\n";
	Vector d = a;
	cout << d;
	cout << "\nUsing assignment operator:   operator =\n";
	Vector e;
	e = a;
	cout << e;

	return 0;
}
