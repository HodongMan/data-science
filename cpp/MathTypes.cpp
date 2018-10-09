#include "MathTypes.h"
#include <math.h>

Vector3::Vector3()
	: X{ -1 }
	, Y{ -1 }
	, Z{ -1 }
{

}

Vector3::Vector3(float x, float y, float z)
	: X{ x }
	, Y{ y }
	, Z{ z }
{

}

Vector3 operator+(const Vector3& lhs, const Vector3& rhs) noexcept
{
	return Vector3(lhs.X + rhs.X, lhs.Y + rhs.Y, lhs.Z + rhs.Z);
}
Vector3 operator-(const Vector3& lhs, const Vector3& rhs) noexcept
{
	return Vector3(lhs.X - rhs.X, lhs.Y - rhs.Y, lhs.Z - rhs.Z);
}

Vector3 operator*(const Vector3& lhs, const Vector3& rhs) noexcept
{
	return Vector3(lhs.X * rhs.X, lhs.Y * rhs.Y, lhs.Z * rhs.Z);
}

Vector3 operator*(const float inScala, const Vector3& rhs) noexcept
{
	return Vector3(inScala * rhs.X, inScala * rhs.Y, inScala * rhs.Z);
}

Vector3 operator*(const Vector3& lhs, const float inScala) noexcept
{
	return Vector3(lhs.X * inScala, lhs.Y * inScala, lhs.Z * inScala);
}

const Vector3& Vector3::operator+=(const Vector3& rhs) noexcept
{
	X += rhs.X;
	Y += rhs.Y;
	Z += rhs.Z;
	return *this;
}

const Vector3& Vector3::operator-=(const Vector3& rhs) noexcept
{
	X -= rhs.X;
	Y -= rhs.Y;
	Z -= rhs.Z;
	return *this;
}

const Vector3& Vector3::operator*=(const Vector3& rhs) noexcept
{
	X *= rhs.X;
	Y *= rhs.Y;
	Z *= rhs.Z;
	return *this;
}

const float Vector3::length() const noexcept
{
	return sqrtf(X * X + Y * Y + Z * Z);
}

void Vector3::normalize() noexcept
{
	const float len = length();
	X /= len;
	Y /= len;
	Z /= len;
}

float dot(const Vector3& lhs, const Vector3& rhs) noexcept
{
	return (lhs.X * rhs.X + lhs.Y * rhs.Y + lhs.Z * rhs.Z);
}

float Vector3::sumOfSquare(const Vector3& value) const noexcept
{
	return dot(value, value);
}

float Vector3::magnitude(const Vector3& value) const noexcept
{
	return sqrt( sumOfSquare( value ) );
}

float distance(const Vector3& lhs, const Vector3& rhs) noexcept
{
	return sqrt( dot( lhs - rhs, lhs - rhs ) );
}
