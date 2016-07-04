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

	double x, y;

private:
};