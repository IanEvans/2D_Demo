/*
	Ian Evans - Vector Code
*/

#ifndef __VECTOR_H_
#define __VECTOR_H_
//Header Guard

#include <math.h>
#include <iostream>

class Vector3
{
	public:

		//----- Constructors ------
		Vector3(): x(0.0), y(0.0), z(0.0){}
		Vector3(double _x, double _y, double _z): x(_x), y(_y), z(_z){}
		
		//----- Variables -----
		double x;
		double y;
		double z;

		//----- Functions ------
		double Length(void) const;
		double LengthSq(void) const;
		Vector3& Normalize(void);
		Vector3& Reverse(void);
		Vector3& Cross(const Vector3&) const;
		double Dot(const Vector3&) const;
		double AngleBetween(const Vector3&) const;
		Vector3& Truncate(double);
		bool IsZero(void) const;
		Vector3& MakeZero(void);

		//----- Overloads -----
		Vector3& operator+=(const Vector3&);
		friend Vector3& operator+(const Vector3&, const Vector3&);
		Vector3& operator-=(const Vector3&);
		friend Vector3& operator-(const Vector3&, const Vector3&);
		Vector3& operator*=(double);
		friend Vector3& operator*(const Vector3&, double);
		Vector3& operator/=(double);
		friend Vector3& operator/(const Vector3&, double);

		friend std::ostream& operator<<(std::ostream&, const Vector3&);

		// ----- added functions -----

		void Draw(); //draws with arrowhead ?

};

#endif