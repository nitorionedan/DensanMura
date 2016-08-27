#pragma once


class Vector2D
{
public:
	Vector2D(const double X, const double Y);
	Vector2D() {}

	void SetVecor2D(const double& X, const double& Y);
	void SetZero();
	void AddVec(Vector2D& vec);
	void Fill(const double& XY);

	static void BorderStop(double* pos, const double MIN, const double MAX);
	static void AddVecAngele(double* PosX, double* PosY, const double& angle, const double& force);
	static bool CirclePointCollision(const double& MyX, const double& MyY, const double& TarX, const double& TarY, const double& Radius);
	static bool CirclesCollision(const double& Range1, const double& Range2,
		const double& X1, const double& Y1, const double& X2, const double& Y2);
	static bool RectanglePointCollision(const double& MyX, const double& MyY, const double& Width, const double& Height, const double& TarX, const double& TarY);

	// @brief				�x�N�g���𐶐�
	// @param[in]	x, y	���W
	// @return				���������x�N�g��
	Vector2D& GetVec(double x, double y);

	// @brief				����������̃x�N�g���𐶐�
	// @param[in]	vec1	����
	// @param[in]	vec2	����
	// @return				���������x�N�g��
	static Vector2D& GetVec2(const Vector2D& vec1, const Vector2D& vec2);

	Vector2D& Normalize();

	double Length() const;

	// @brief				���ς��v�Z
	// @param[in]	other	����̃x�N�g��
	// @return				����
	double DotProduct(const Vector2D& other) const;

	// @brief				�O�ς��v�Z
	// @param[in]	other	����̃x�N�g��
	// @return				�O��
	double CrossProduct(const Vector2D& other) const;

	/* operators */
	Vector2D& Vector2D::operator=(const Vector2D& obj);
	Vector2D& operator+=(const Vector2D& obj);
	Vector2D& operator-=(const Vector2D& obj);
	Vector2D& operator*=(const Vector2D& obj);
	Vector2D& operator/=(const Vector2D& obj);
	Vector2D operator+();
	Vector2D operator-();

	double x, y;
};


Vector2D operator+(const Vector2D& v1, const Vector2D& v2);

Vector2D operator-(const Vector2D& v1, const Vector2D& v2);

// EOF