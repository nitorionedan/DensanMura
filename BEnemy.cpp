#include "Include\BEnemy.hpp"
#include "DxLib.h"

#include <cmath>


BEnemy::BEnemy()
	: img(new Image)
{
	img->Load("Images/Characters/prcn.png", "prcn");
	img->Load("Images/Objects/kage_prcn.png", "shadow");
	Initialize();
}


BEnemy::~BEnemy()
{
}


void BEnemy::Initialize()
{
	shadowPos.SetVecor2D(450., 380.);
	pos.SetVecor2D(450., 300.);
	c_move = 0.f;
}


void BEnemy::Update()
{
	c_move += 0.01f;

	pos.y += std::cos(c_move) * 0.2;
}


void BEnemy::Draw()
{
	img->DrawRota(shadowPos.x, shadowPos.y, 1. + (std::sin(c_move) * 0.2), 0., "shadow", true);
	img->DrawRota(pos.x, pos.y - 20, 1., 0., "prcn", true);
}


void BEnemy::Move()
{

}

// EOF