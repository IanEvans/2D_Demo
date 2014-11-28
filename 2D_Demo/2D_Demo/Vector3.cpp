#include "vector3.h"

double Vector3::Length(void) const
{
	return sqrt(x*x + y*y + z*z);
}

double Vector3::LengthSq(void) const
{
	return(x*x + y*y + z*z);
}

Vector3& Vector3::Normalize(void)
{
	double len = this->Length();
	x = x/len; y = y/len; z = z/len;
	return *this;
}

Vector3& Vector3::Reverse(void)
{
	x = -x;
	y = -y;
	z = -z;
	return *this;
}

Vector3& Vector3::Cross(const Vector3& other) const
{
	return Vector3(	( (y * other.z) - (z * other.y)),
					(-(x * other.z) + (z * other.x)),
					( (x * other.y) - (y * other.x))	);
}

double Vector3::Dot(const Vector3& other) const
{
	return (x * other.x) + (y * other.y) + (z * other.z);
}

double Vector3::AngleBetween(const Vector3& other) const
{
	double dot = this->Dot(other);
	double mag1 = this->Length();
	double mag2 = other.Length();
	return (acos(dot / (mag1 * mag2))) * 180.0 / 3.14159265358979323846;
}

Vector3& Vector3::Truncate(double max)
{
	if(x > max) x = max;
	if(y > max) y = max;
	if(z > max) z = max;
	return *this;
}

Vector3& Vector3::operator+=(const Vector3& other)
{
	x = x + other.x;
	y = y + other.y;
	z = z + other.z;
	return *this;
}

Vector3& operator+(const Vector3& other, const Vector3& other2)
{
	return Vector3(other.x + other2.x, other.y + other2.y, other.z + other2.z);
}

Vector3& Vector3::operator-=(const Vector3& other)
{
	x = x - other.x;
	y = y - other.y;
	z = z - other.z;
	return *this;
}

Vector3& operator-(const Vector3& other, const Vector3& other2)
{
	return Vector3(other.x - other2.x, other.y - other2.y, other.z - other2.z);
}

Vector3& Vector3::operator*=(double s)
{
	x = x * s;
	y = y * s;
	z = z * s;
	return *this;
}

Vector3& operator*(const Vector3& other, double s)
{
	return Vector3(other.x * s, other.y * s, other.z * s);
}

Vector3& Vector3::operator/=(double s)
{
	x = x / s;
	y = y / s;
	z = z / s;
	return *this;
}

Vector3& operator/(const Vector3& other, double s)
{
	return Vector3(other.x / s, other.y / s, other.z / s);
}

bool Vector3::IsZero(void) const
{
	return (x == 0 && y == 0 && z == 0);
}

Vector3& Vector3::MakeZero(void)
{
	x = 0;
	y = 0;
	z = 0;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Vector3& other)
{
	return os << other.x << ", " << other.y << ", " << other.z;
}