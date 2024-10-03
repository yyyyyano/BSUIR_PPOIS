#ifndef MATHVECTOR_H
#define MATHVECTOR_H

#include <iostream>
using namespace std;

class Vector {
	double startX, startY, startZ;
	double endX, endY, endZ;

	void CoordinateDifference(double&, double&, double&);

	bool IsNullVector();

public:
	Vector(double, double, double, double, double, double);

	Vector();

	Vector(const Vector& other);

	void SetStartCoordinates(double, double, double);

	void SetEndCoordinates(double, double, double);

	double GetStartX();

	double GetStartY();

	double GetStartZ();

	double GetEndX();

	double GetEndY();

	double GetEndZ();

	double CalculateLength();

	Vector operator + (Vector&);

	Vector& operator +=(Vector&);

	Vector operator - (Vector&);

	Vector& operator -= (Vector&);

	Vector operator * (Vector&);

	Vector& operator *= (Vector&);

	double operator * (Vector*);

	Vector operator * (const double&);

	friend Vector operator *(const double&, const Vector&);

	Vector& operator *= (const double&);

	Vector operator / (const Vector&);

	Vector& operator /= (const Vector&);

	double operator ^ (Vector&);

	bool operator > (Vector&);

	bool operator >= (Vector&);

	bool operator < (Vector&);

	bool operator <= (Vector&);

	bool operator == (Vector&);

	bool operator != (Vector&);

	Vector& operator = (Vector&);

	Vector& operator = (Vector&&) noexcept;

};

ostream& operator << (ostream&, Vector&);

istream& operator >> (istream&, Vector&);

#endif
