
class Vector3
{
public:
	float X;
	float Y;
	float Z;

	Vector3();
	Vector3(float x, float y, float z);

	friend Vector3 operator+(const Vector3& lhs, const Vector3& rhs) noexcept;
	friend Vector3 operator-(const Vector3& lhs, const Vector3& rhs) noexcept;
	friend Vector3 operator*(const Vector3& lhs, const Vector3& rhs) noexcept;
	friend Vector3 operator*(const float inScala, const Vector3& rhs) noexcept;
	friend Vector3 operator*(const Vector3& lhs, const float inScala) noexcept;

	const Vector3& operator+=(const Vector3& rhs) noexcept;
	const Vector3& operator-=(const Vector3& rhs) noexcept;
	const Vector3& operator*=(const Vector3& rhs) noexcept;

	const float length() const noexcept;

	void normalize() noexcept;

	friend float dot(const Vector3& lhs, const Vector3& rhs) noexcept;

	float sumOfSquare(const Vector3& value) const noexcept;

	float magnitude(const Vector3& value) const noexcept;

	float distance(const Vector3& lhs, const Vector3& rhs) noexcept;
	
};

