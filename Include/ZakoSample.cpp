#include "ZakoSample.hpp"
#include <cassert>


ZakoSample::ZakoSample()
	: img(new Image)
{
	img->Load("Images/Characters/zako1_1.png", "idle_1");
	img->Load("Images/Characters/zako1_2.png", "idle_2");
	img->Load("Images/Characters/zako1_3.png", "idle_3");
	
	Initialize();
}


ZakoSample::~ZakoSample()
{
}


void ZakoSample::Initialize()
{
	pos = Vector2D(320., 240.);
}


void ZakoSample::Update()
{
	Move();
	HitCheck();
}


void ZakoSample::Draw()
{
	img->Draw(pos.x, pos.y, "idle_1", true);
}


void ZakoSample::Move()
{
}


bool ZakoSample::HitCheck()
{
	return false;
}
