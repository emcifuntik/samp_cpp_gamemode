#pragma once

class CVector3f {
public:
	float x;
	float y;
	float z;


	CVector3f() {
		x = 0;
		y = 0;
		z = 0;
	}

	CVector3f(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	float getX() { 
		return x;
	}

	float getY() {
		return y;
	}

	float getZ() {
		return z;
	}

	float length() {
		return sqrt((x * x) + (y * y) + (z * z));
	}

	CVector3f normalized() {
		float mag = length();

		return CVector3f(x / mag, y / mag, z / mag);
	}

	CVector3f neg() {
		return CVector3f(-x, -y, -z);
	}

	double dot(CVector3f other) {
		return x * other.getX() + y * other.getY() + z * other.getZ();
	}

	CVector3f cross(CVector3f other) {
		float x_ = y * other.getZ() - z * other.getY();
		float y_ = z * other.getX() - x * other.getZ();
		float z_ = x * other.getY() - y * other.getX();

		return CVector3f(x_, y_, z_);
	}

	CVector3f operator + (const CVector3f &other) {
		return CVector3f(x + other.x, y + other.y, z + other.z);
	}

	CVector3f operator - (const CVector3f &other) {
		return CVector3f(x - other.x, y - other.y, z - other.z);
	}

	CVector3f operator * (const CVector3f &other) {
		return CVector3f(x * other.x, y * other.y, z * other.z);
	}

	CVector3f operator / (const CVector3f &other) {
		return CVector3f(x / other.x, y / other.y, z / other.z);
	}

	operator std::string() const
	{
		std::stringstream ss;
		ss << "X = " << x << ", Y = " << y << ", Z = " << z;
		return ss.str();
	}
};

