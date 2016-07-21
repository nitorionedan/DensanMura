#include "Camera.hpp"
#include "DxLib.h"


Camera::Camera()
	: WIDTH(640)
	, HEIGHT(480)
{
	Initialize();
}


Camera::~Camera()
{
}


void Camera::Initialize()
{
	pos.SetZero();
}


void Camera::Update(const double & PosX, const double & PosY)
{
	pos.SetVecor2D(PosX, 0.);
}


void Camera::Draw()
{
	/*
	const int& CENTER_X = WIDTH / 2;
	const int& CENTER_Y = HEIGHT / 2;

	DrawCircle(CENTER_X, CENTER_Y, 3, GetColor(255, 0, 0), true);
	DrawBox(0, 0, WIDTH, HEIGHT, GetColor(255, 0, 0), false);
	DrawLine(CENTER_X - 20, CENTER_Y, CENTER_X + 20, CENTER_Y, GetColor(255, 0, 0));
	DrawLine(CENTER_X, CENTER_Y - 20, CENTER_X, CENTER_Y + 20, GetColor(255, 0, 0));
	*/
}

// EOF