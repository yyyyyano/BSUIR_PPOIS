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
	Vector temp;
	temp.startX = this->startX;
	temp.startY = this->startY;
	temp.startZ = this->startZ;
	double otherX, otherY, otherZ;
	other.CoordinateDifference(otherX, otherY, otherZ);
	temp.endX = this->endX + otherX;
	temp.endY = this->endY + otherY;
	temp.endZ = this->endZ + otherZ;
	return temp;
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
	Vector temp;
	double otherX, otherY, otherZ;
	other.CoordinateDifference(otherX, otherY, otherZ);
	temp.startX = this->startX + otherX;
	temp.startY = this->startY + otherY;
	temp.startZ = this->startZ + otherZ;
	temp.endX = this->endX;
	temp.endY = this->endY;
	temp.endZ = this->endZ;
	return temp;
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
	Vector temp;
	temp.startX = this->startX;
	temp.startY = this->startY;
	temp.startZ = this->startZ;
	double thisX, thisY, thisZ;
	this->CoordinateDifference(thisX, thisY, thisZ);
	double otherX, otherY, otherZ;
	other.CoordinateDifference(otherX, otherY, otherZ);
	temp.endX = thisY * otherZ - thisZ * otherY + temp.startX;
	temp.endY = -1 * thisX * otherZ + thisZ * otherX + temp.startY;
	temp.endZ = thisX * otherY - thisY * otherX + temp.startZ;
	return temp;
}

Vector& Vector::operator *= (Vector& other) {
	Vector temp = *this;
	double tempX, tempY, tempZ;
	temp.CoordinateDifference(tempX, tempY, tempZ);
	double otherX, otherY, otherZ;
	other.CoordinateDifference(otherX, otherY, otherZ);
	this->endX = tempY * otherZ - tempZ * otherY + temp.startX;
	this->endY = -1 * tempX * otherZ + tempZ * otherX + temp.startY;
	this->endZ = tempX * otherY - tempY * otherX + temp.startZ;
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
	Vector temp;
	temp.startX = lambda * this->startX;
	temp.startY = lambda * this->startY;
	temp.startZ = lambda * this->startZ;
	temp.endX = lambda * this->endX;
	temp.endY = lambda * this->endY;
	temp.endZ = lambda * this->endZ;
	return temp;
}

Vector operator *(const double& lambda, const Vector& value) {
	Vector temp;
	temp.startX = lambda * value.startX;
	temp.startY = lambda * value.startY;
	temp.startZ = lambda * value.startZ;
	temp.endX = lambda * value.endX;
	temp.endY = lambda * value.endY;
	temp.endZ = lambda * value.endZ;
	return temp;
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

	Vector temp;
	temp.startX = this->startX / other.startX;
	temp.startY = this->startY / other.startY;
	temp.startZ = this->startZ / other.startZ;
	temp.endX = this->endX / other.endX;
	temp.endY = this->endY / other.endY;
	temp.endZ = this->endZ / other.endZ;
	return temp;
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
