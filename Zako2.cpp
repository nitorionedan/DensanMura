/*
@brief	Zako2.hpp‚ÌŽÀ‘•
@author	‹g‘º
*/

#include "Include\Zako2.hpp"
#include "Include\Game.hpp"
#include <cassert>
#include <random>
#include <DxLib.h>


std::random_device rnd;     // ”ñŒˆ’è“I‚È—”¶¬Ší

Zako2::Zako2()
	: img(new Image)
	, Movintime(180)
	, Wait(60)
	, attacktime(180)
{
	
	img->Load("Images/Characters/zako1_1.png", "idle_1");
	img->Load("Images/Characters/zako1_2.png", "idle_2");
	img->Load("Images/Characters/zako1_3.png", "idle_3");

	Initialize();
}


Zako2::~Zako2()
{
}


void Zako2::Initialize()
{
	pos = Vector2D(160., 100.);
}


void Zako2::Update(const Player& player)
{
	Move();
	HitCheck();
}


void Zako2::Draw()
{
	switch(attackPhase)
	{
	case 0:
		img->Draw(pos.x, pos.y, "idle_1", true);
		break;
	
	case 1:
		img->Draw(pos.x, pos.y, "idle_2", true);
		break;
	
	case 2:
		const bool& IS_ATK = (movin_count % 4 < 2);
		if (IS_ATK)
			img->Draw(pos.x, pos.y, "idle_3", true);
		else 
			img->Draw(pos.x, pos.y, "idle_1", true);
		break;
	}
}


void Zako2::Move()
{	
	if (movin_count < Movintime)
	{
		attackPhase = 0;
		switch (movemuki)
		{
		case 0:
			if (pos.x < BD_RIGHT)
				pos.x++;
			else
				movin_count = Movintime;
			break;

		case 1:
			if (pos.x > BD_LEFT)
				pos.x--;
			else
				movin_count = Movintime;
			break;

		case 2:
			if (pos.y < BD_TOP)
				pos.y++;
			else
				movin_count = Movintime;
			break;

		case 3:
			if (pos.y > BD_BOTTOM)
				pos.y--;
			else
				movin_count = Movintime;
			break;
		}
	}
	else if(movin_count<Movintime+Wait)
		attackPhase = 1;
	else if (movin_count < Movintime + Wait + attacktime)
		attackPhase = 2;
	else
	{
		movin_count = 0;
		movemuki = rnd()%4;
	}

	movin_count++;
}


bool Zako2::HitCheck()
{
	return false;
}
