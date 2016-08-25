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

	// @brief				ベクトルを生成
	// @param[in]	x, y	座標
	// @return				生成したベクトル
	Vector2D& GetVec(double x, double y);

	// @brief				自分→相手のベクトルを生成
	// @param[in]	x1, y1	自分の座標
	// @param[in]	x2, y2	相手の座標
	// @return				生成したベクトル
	Vector2D& GetVec2(double x1, double y1, double x2, double y2);

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