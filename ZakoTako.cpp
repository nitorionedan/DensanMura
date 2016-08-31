#include "Include\ZakoTako.hpp"
#include "Include\Keyboard.hpp"

#include <cassert>



ZakoTako::ZakoTako()
	: img(new Image)
	, PLAYER_SIZE_X(50)
	, PLAYER_SIZE_Y(100)
	, TAKO_SIZE_X(200)
	, TAKO_SIZE_Y(200)
	, TFOLLW_SPEED(1.)
	, TESCAPE_SPEED(4.)
{

	img->Load("Images/Characters/zako1_1.png", "idle_1");
	img->Load("Images/Characters/zako1_2.png", "idle_2");
	img->Load("Images/Characters/zako1_3.png", "idle_3");

	Initialize();
}


ZakoTako::~ZakoTako()
{
}


void ZakoTako::Initialize()
{
	pos = Vector2D(320., 240.);
	Tmode = Tfollow;
}


void ZakoTako::Update(const Player& player)
{
	Move();
	HitCheck();

	//Playerの位置取得(キャラ同士の中心が重なるように座標修正)
	PlaX = player.GetPos().x - TAKO_SIZE_X / 2;
	PlaY = player.GetPos().y - PLAYER_SIZE_Y / 2 - TAKO_SIZE_Y / 2;

}


void ZakoTako::Draw()
{
	img->DrawRota(pos.x, pos.y, 1., 0., "idle_2", true);
}



void ZakoTako::Move()
{
	double walk_speed;
	bool ismoveX = true;
	bool ismoveY = true;

	//モード変更
	if (KeyIsVertical() | KeyIsHorizontal())
		Tmode = Tescape;
	else
		Tmode = Tfollow;


	switch (Tmode)
	{
	case Tfollow:
		walk_speed = TFOLLW_SPEED;

		if (PlaX > pos.x + walk_speed) {
			if (pos.x < BD_RIGHT) pos.x += walk_speed;
		}
		else if (PlaX < pos.x - walk_speed) {
			if (pos.x > BD_LEFT) pos.x -= walk_speed;
		}
		else
			ismoveX = false;

		if (PlaY >pos.y + walk_speed) {
			if (pos.y < BD_BOTTOM)	pos.y += walk_speed;
		}
		else if (PlaY < pos.y - walk_speed) {
			if (pos.y > BD_TOP) pos.y -= walk_speed;
		}
		else
			ismoveY = false;
		break;

	case Tescape:
		walk_speed = TESCAPE_SPEED;

		if (PlaX > pos.x + walk_speed) {
			if (pos.x > BD_LEFT) pos.x -= walk_speed;
		}
		else if (PlaX < pos.x - walk_speed) {
			//if (pos.x < 640 - TAKO_SIZE_X) pos.x += walk_speed;
			if (pos.x < BD_RIGHT)	pos.x += walk_speed;
		}
		else
			ismoveX = false;

		if (PlaY > pos.y + walk_speed) {
			if (pos.y > BD_TOP) pos.y -= walk_speed;
		}
		else if (PlaY < pos.y - walk_speed) {
			//if (pos.y < 480 - TAKO_SIZE_Y) pos.y += walk_speed;
			if (pos.y < BD_BOTTOM)	pos.y += walk_speed;
		}
		else
			ismoveY = false;
		break;

	default:	walk_speed = TFOLLW_SPEED;	break;
	}

	if (ismoveX | ismoveY) walk_speed = walk_speed / 1.7;
}


bool ZakoTako::HitCheck()
{
	return false;
}
