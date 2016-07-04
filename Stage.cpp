#include "Stage.hpp"
#include "DxLib.h"
#include "Keyboard.hpp"


Stage::Stage()
	: img(new Image)
{
	img->Load("Images/Stages/test_back.png", "back");

	Initialize();
}


Stage::~Stage()
{
}


void Stage::Initialize()
{
	pos.SetVecor2D(0., 0.);
	
	int wid, hei;
	img->GetSize("back", &wid, &hei);

	leftEnd = 0;
	rightEnd = wid - 640;
}


void Stage::Update()
{
	TestMove();
}


void Stage::Draw()
{
	img->DrawRect(0, 0, pos.x, pos.y, 640, 480, "back");
}


void Stage::Move()
{
}


void Stage::TestMove()
{
	if (pos.x < leftEnd)	pos.x = leftEnd;
	if (pos.x > rightEnd)	pos.x = rightEnd;
}

// EOF