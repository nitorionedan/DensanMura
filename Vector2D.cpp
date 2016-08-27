#include "Include/Vector2D.hpp"

#include <algorithm>
#include <cassert>
#include <cmath>

#undef min
#undef max


Vector2D::Vector2D(double x, double y)
{
	this->x = x;
	this->y = y;
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
	assert(MAX > MIN && "Vector2D::BorderStop()");

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


Vector2D & Vector2D::GetVec(double x, double y)
{
	return  Vector2D(x, y);
}


Vector2D & Vector2D::GetVec2(const Vector2D & vec1, const Vector2D & vec2)
{
	double x = vec2.x - vec1.x;
	double y = vec2.y - vec1.y;
	return Vector2D(x, y);
}


Vector2D & Vector2D::Normalize()
{
	const double& len = Length();
	if (len < FLT_EPSILON)
		return Vector2D(0., 0.);
	x /= len;
	y /= len;
	return *this;
}

double Vector2D::Length() const{
	return std::sqrt(DotProduct(*this));
}


double Vector2D::DotProduct(const Vector2D & other) const {
	return (x * other.x) + (y * other.y);
}


double Vector2D::CrossProduct(const Vector2D & other) const {
	return (x * other.y) - (y * other.x);
}


Vector2D& Vector2D::operator=(const Vector2D& obj)
{
	this->x = obj.x;
	this->y = obj.y;
	return *this;
}


Vector2D Vector2D::operator+()
{
	return *this;
}


Vector2D Vector2D::operator-()
{
	return Vector2D(-x, -y);
}


Vector2D& Vector2D::operator+=(const Vector2D& obj)
{
	this->x += obj.x;
	this->y += obj.y;
	return *this;
}


Vector2D& Vector2D::operator-=(const Vector2D& obj)
{
	this->x -= obj.x;
	this->y -= obj.y;
	return *this;
}


Vector2D& Vector2D::operator*=(const Vector2D& obj)
{
	this->x *= obj.x;
	this->y *= obj.y;
	return *this;
}


Vector2D& Vector2D::operator/=(const Vector2D& obj)
{
	this->x /= obj.x;
	this->y /= obj.y;
	return *this;
}


Vector2D operator+(const Vector2D& v1, const Vector2D& v2)
{
	Vector2D tmp;
	tmp.x = v1.x + v2.x;
	tmp.y = v1.y + v2.y;
	return tmp;
}


Vector2D operator-(const Vector2D& v1, const Vector2D& v2)
{
	Vector2D tmp;
	tmp.x = v1.x - v2.x;
	tmp.y = v1.y - v2.y;
	return tmp;
}


// EOF