#include "MathVector.h"

void Vector::CoordinateDifference(double& x, double& y, double& z) {
	x = endX - startX;
	y = endY - startY;
	z = endZ - startZ;
}

bool Vector::IsNullVector() {
	double x, y, z;
	CoordinateDifference(x, y, z);
	if (x == 0 && y == 0 && z == 0)
		return true;
	else return false;
}

Vector::Vector(double valueStartX, double valueStartY, double valueStartZ, double valueEndX, double valueEndY, double valueEndZ)
	: startX(valueStartX), startY(valueStartY), startZ(valueStartZ), endX(valueEndX), endY(valueEndY), endZ(valueEndZ) {};

Vector::Vector() {
	startX = startY = startZ = 0;
	endX = 1;
	endY = 2;
	endZ = 3;
}

Vector::Vector(const Vector& other) {
	startX = other.startX;
	startY = other.startY;
	startZ = other.startZ;
	endX = other.endX;
	endY = other.endY;
	endZ = other.endZ;
}

void Vector::SetStartCoordinates(double startX, double startY, double startZ) {
	this->startX = startX;
	this->startY = startY;
	this->startZ = startZ;
}

void Vector::SetEndCoordinates(double endX, double endY, double endZ) {
	this->endX = endX;
	this->endY = endY;
	this->endZ = endZ;
}

double Vector::GetStartX() {
	return startX;
}

double Vector::GetStartY() {
	return startY;
}

double Vector::GetStartZ() {
	return startZ;
}

double Vector::GetEndX() {
	return endX;
}

double Vector::GetEndY() {
	return endY;
}

double Vector::GetEndZ() {
	return endZ;
}

double Vector::CalculateLength() {
	double x, y, z;
	CoordinateDifference(x, y, z);
	double length = sqrt(x * x + y * y + z * z);
	return length;
}

Vector Vector::operator + (Vector& other) {
	Vector tempVectorForSum;
	tempVectorForSum.startX = this->startX;
	tempVectorForSum.startY = this->startY;
	tempVectorForSum.startZ = this->startZ;
	double otherX, otherY, otherZ;
	other.CoordinateDifference(otherX, otherY, otherZ);
	tempVectorForSum.endX = this->endX + otherX;
	tempVectorForSum.endY = this->endY + otherY;
	tempVectorForSum.endZ = this->endZ + otherZ;
	return tempVectorForSum;
}

Vector& Vector::operator +=(Vector& other) {
	double otherX, otherY, otherZ;
	other.CoordinateDifference(otherX, otherY, otherZ);
	this->endX += otherX;
	this->endY += otherY;
	this->endZ += otherZ;
	return *this;
}

Vector Vector::operator - (Vector& other) {
	Vector tempVectorForDifference;
	double otherX, otherY, otherZ;
	other.CoordinateDifference(otherX, otherY, otherZ);
	tempVectorForDifference.startX = this->startX + otherX;
	tempVectorForDifference.startY = this->startY + otherY;
	tempVectorForDifference.startZ = this->startZ + otherZ;
	tempVectorForDifference.endX = this->endX;
	tempVectorForDifference.endY = this->endY;
	tempVectorForDifference.endZ = this->endZ;
	return tempVectorForDifference;
}

Vector& Vector::operator -= (Vector& other) {
	double otherX, otherY, otherZ;
	other.CoordinateDifference(otherX, otherY, otherZ);
	this->startX += otherX;
	this->startY += otherY;
	this->startZ += otherZ;
	return *this;
}

Vector Vector::operator * (Vector& other) {
	Vector tempVectorForMultiplication;
	tempVectorForMultiplication.startX = this->startX;
	tempVectorForMultiplication.startY = this->startY;
	tempVectorForMultiplication.startZ = this->startZ;
	double thisX, thisY, thisZ;
	this->CoordinateDifference(thisX, thisY, thisZ);
	double otherX, otherY, otherZ;
	other.CoordinateDifference(otherX, otherY, otherZ);
	tempVectorForMultiplication.endX = thisY * otherZ - thisZ * otherY + tempVectorForMultiplication.startX;
	tempVectorForMultiplication.endY = -1 * thisX * otherZ + thisZ * otherX + tempVectorForMultiplication.startY;
	tempVectorForMultiplication.endZ = thisX * otherY - thisY * otherX + tempVectorForMultiplication.startZ;
	return tempVectorForMultiplication;
}

Vector& Vector::operator *= (Vector& other) {
	Vector tempVectorForMultiEq = *this;
	double tempVectorMultiEqX, tempVectorMultiEqY, tempVectorMultiEqZ;
	tempVectorForMultiEq.CoordinateDifference(tempVectorMultiEqX, tempVectorMultiEqY, tempVectorMultiEqZ);
	double otherX, otherY, otherZ;
	other.CoordinateDifference(otherX, otherY, otherZ);
	this->endX = tempVectorMultiEqY * otherZ - tempVectorMultiEqZ * otherY + tempVectorForMultiEq.startX;
	this->endY = -1 * tempVectorMultiEqX * otherZ + tempVectorMultiEqZ * otherX + tempVectorForMultiEq.startY;
	this->endZ = tempVectorMultiEqX * otherY - tempVectorMultiEqY * otherX + tempVectorForMultiEq.startZ;
	return *this;
}

double Vector::operator * (Vector* other) {
	double thisX, thisY, thisZ;
	this->CoordinateDifference(thisX, thisY, thisZ);
	double otherX, otherY, otherZ;
	other->CoordinateDifference(otherX, otherY, otherZ);
	return thisX * otherX + thisY * otherY + thisZ * otherZ;
}

Vector Vector::operator * (const double& lambda) {
	Vector tempVectorForMultiValue;
	tempVectorForMultiValue.startX = lambda * this->startX;
	tempVectorForMultiValue.startY = lambda * this->startY;
	tempVectorForMultiValue.startZ = lambda * this->startZ;
	tempVectorForMultiValue.endX = lambda * this->endX;
	tempVectorForMultiValue.endY = lambda * this->endY;
	tempVectorForMultiValue.endZ = lambda * this->endZ;
	return tempVectorForMultiValue;
}

Vector operator *(const double& lambda, const Vector& value) {
	Vector tempVectorForValueMultiplication;
	tempVectorForValueMultiplication.startX = lambda * value.startX;
	tempVectorForValueMultiplication.startY = lambda * value.startY;
	tempVectorForValueMultiplication.startZ = lambda * value.startZ;
	tempVectorForValueMultiplication.endX = lambda * value.endX;
	tempVectorForValueMultiplication.endY = lambda * value.endY;
	tempVectorForValueMultiplication.endZ = lambda * value.endZ;
	return tempVectorForValueMultiplication;
}

Vector& Vector::operator *= (const double& lambda) {
	this->startX *= lambda;
	this->startY *= lambda;
	this->startZ *= lambda;
	this->endX *= lambda;
	this->endY *= lambda;
	this->endZ *= lambda;
	return *this;
}

Vector Vector::operator / (const Vector& other) {
	if (other.startX == 0 || other.startY == 0 || other.startZ == 0 || other.endX == 0 || other.endY == 0 || other.endZ == 0) {
		throw runtime_error("Impossible to calculate! Denominator's coordinates equal zero!");
	}

	Vector tempVectorForDivision;
	tempVectorForDivision.startX = this->startX / other.startX;
	tempVectorForDivision.startY = this->startY / other.startY;
	tempVectorForDivision.startZ = this->startZ / other.startZ;
	tempVectorForDivision.endX = this->endX / other.endX;
	tempVectorForDivision.endY = this->endY / other.endY;
	tempVectorForDivision.endZ = this->endZ / other.endZ;
	return tempVectorForDivision;
}

Vector& Vector::operator /= (const Vector& other) {
	if (other.startX == 0 || other.startY == 0 || other.startZ == 0 || other.endX == 0 || other.endY == 0 || other.endZ == 0) {
		throw runtime_error("Impossible to calculate! Denominator's coordinates equal zero!");
	}
	this->startX /= other.startX;
	this->startY /= other.startY;
	this->startZ /= other.startZ;
	this->endX /= other.endX;
	this->endY /= other.endY;
	this->endZ /= other.endZ;
	return *this;
}

double Vector::operator ^ (Vector& other) {
	if (this->IsNullVector() == true || other.IsNullVector() == true) {
		throw runtime_error("Impossible to count! There is null vector!");
	}
	double numerator = *this * &other;
	double thisLength = this->CalculateLength();
	double otherLength = other.CalculateLength();
	double cosine = numerator / (thisLength * otherLength);
	cosine = max(-1.0, min(1.0, cosine));
	return cosine;
}

bool Vector::operator > (Vector& other) {
	double thisLength = this->CalculateLength();
	double otherLength = other.CalculateLength();
	return thisLength > otherLength;
}

bool Vector::operator >= (Vector& other) {
	double thisLength = this->CalculateLength();
	double otherLength = other.CalculateLength();
	return thisLength >= otherLength;
}

bool Vector::operator < (Vector& other) {
	double thisLength = this->CalculateLength();
	double otherLength = other.CalculateLength();
	return thisLength < otherLength;
}

bool Vector::operator <= (Vector& other) {
	double thisLength = this->CalculateLength();
	double otherLength = other.CalculateLength();
	return thisLength <= otherLength;
}

bool Vector::operator == (Vector& other) {
	double thisLength = this->CalculateLength();
	double otherLength = other.CalculateLength();
	return thisLength == otherLength;
}

bool Vector::operator != (Vector& other) {
	double thisLength = this->CalculateLength();
	double otherLength = other.CalculateLength();
	return thisLength != otherLength;
}

Vector& Vector::operator = (Vector& other) {
	if (this != &other) {
		this->startX = other.startX;
		this->startY = other.startY;
		this->startZ = other.startZ;
		this->endX = other.endX;
		this->endY = other.endY;
		this->endZ = other.endZ;
	}
	return *this;
}

Vector& Vector::operator = (Vector&& other) noexcept {
	if (this != &other) {
		this->startX = other.startX;
		this->startY = other.startY;
		this->startZ = other.startZ;
		this->endX = other.endX;
		this->endY = other.endY;
		this->endZ = other.endZ;
		other.startX = other.startY = other.startZ = 0;
		other.endX = other.endY = other.endZ = 0;
	}
	return *this;
}

ostream& operator << (ostream& output, Vector& other) {
	return output << "\nStart:\t(" << other.GetStartX() << ", " << other.GetStartY() << ", " << other.GetStartZ() << ")\n"
		<< "End:\t(" << other.GetEndX() << ", " << other.GetEndY() << ", " << other.GetEndZ() << ")\n";
}

istream& operator >> (istream& input, Vector& other) {
	double startX, startY, startZ, endX, endY, endZ;
	input >> startX >> startY >> startZ >> endX >> endY >> endZ;
	other.SetStartCoordinates(startX, startY, startZ);
	other.SetEndCoordinates(endX, endY, endZ);
	return input;
}
