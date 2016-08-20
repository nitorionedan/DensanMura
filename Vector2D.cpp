#include <DxLib.h>
#include "Include\Vector2D.hpp"

#include <algorithm>
#include <cassert>
#include <cmath>

#undef min
#undef max


Vector2D::Vector2D(double X, double Y)
{
	this->x = X;
	this->y = Y;
}


void Vector2D::SetVecor2D(const double& X, const double& Y)
{
	this->x = X;
	this->y = Y;
}


void Vector2D::SetZero()
{
	this->x = 0.;
	this->y = 0.;
}


void Vector2D::AddVec(Vector2D& vec)
{
	this->x += vec.x;
	this->y += vec.y;
}


void Vector2D::Fill(const double & XY){
	x = y = XY;
}


void Vector2D::BorderStop(double* pos, const double MIN, const double MAX)
{
	if(MAX <= MIN)
	{
		printfDx("§ŒÀ’lƒGƒ‰[\n");
		return;
	}

	*pos = std::min(MAX, std::max(MIN, *pos));
}

void Vector2D::AddVecAngele(double * PosX, double * PosY, const double& angle, const double& force)
{
	*PosX += std::cos(angle) * force;
	*PosY += std::sin(angle) * force;
}


bool Vector2D::CirclePointCollision(const double& MyX, const double& MyY, const double& TarX, const double& TarY, const double& Radius)
{
	const double& WIDTH = (TarX - MyX) * (TarX - MyX);
	const double& HEIGHT = (TarY - MyY) * (TarY - MyY);
	const double& DISTANCE = (WIDTH + HEIGHT);
	const double& RADIUS = Radius * Radius;
	bool isHit = (RADIUS >= DISTANCE);
	
	return isHit;
}


bool Vector2D::CirclesCollision(const double & Range1, const double & Range2, const double & X1, const double & Y1, const double & X2, const double & Y2)
{
	const double& hLengrth = (Range1 + Range2);
	const double& xLength = (X1 - X2);
	const double& yLength = (Y1 - Y2);
	const bool& isHit = (hLengrth * hLengrth >= xLength * xLength + yLength * yLength);

	return isHit;
}


bool Vector2D::RectanglePointCollision(const double & MyX, const double & MyY, const double & Width, const double & Height, const double & TarX, const double & TarY)
{
	const double& MyX2 = (MyX + Width);
	const double& MyY2 = (MyY + Height);
	const bool& isHit = (MyX <= TarX && TarX <= MyX2 && MyY <= TarY && TarY <= MyY2);

	return isHit;
}
