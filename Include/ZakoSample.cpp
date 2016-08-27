#include "ZakoSample.hpp"
#include "Graphics2D.hpp"
#include <cassert>
#include <algorithm>
#undef min
#undef max


ZakoSample::ZakoSample()
	: img(new Image)
{
	gh[0] = LoadGraph("Images/Characters/zako1_1.png");
	gh[1] = LoadGraph("Images/Characters/zako1_2.png");
	gh[2] = LoadGraph("Images/Characters/zako1_3.png");

	Initialize();
}


ZakoSample::~ZakoSample()
{
	for (auto i : gh)	DeleteGraph(i);
}


void ZakoSample::Initialize()
{
	//pos = Vector2D(GetRand(1260) - 630, GetRand(940) - 470); // 画面内のどこかに・・・
	shadowPos.SetVecor2D(320, 240);
	vmove.SetZero();
	time = 0;
	walkSpeed = 1;
	jumpPower = 20;
}


void ZakoSample::Update(const Player& player)
{
	time++;

	/* 自機向かいテスト */
	if(time == 180)
	{
		Vector2D tmp = Vector2D::GetVec2(shadowPos, player.GetPos());
		vmove.x = tmp.Normalize().x * walkSpeed;
		vmove.y = tmp.Normalize().y * walkSpeed;
	}

	/* キャラ画像の位置を調整 */
	pos.SetVecor2D(shadowPos.x, shadowPos.y - 40);

	Move();
	Boundary(&shadowPos.x, &shadowPos.y);

	HitCheck();
}


void ZakoSample::Draw()
{
	DrawAnime(pos.x, pos.y, 0., _countof(gh), 100, gh);
	DrawCircle(shadowPos.x, shadowPos.y, 4, GetColor(255, 0, 0), TRUE);

	/* TEST */
	//DrawFormatString(320, 240, GetColor(255, 0, 0), "%lf", vmove.x);
}


void ZakoSample::Move()
{
	shadowPos += vmove;
}


void ZakoSample::Boundary(double * x, double * y)
{
	*x = std::max(std::min(*x, (double)BD_RIGHT), (double)BD_LEFT); // BD_RIGHt  <= x <= BD_LEFT
	*y = std::max(std::min(*y, (double)BD_BOTTOM), (double)BD_TOP); // BD_BOTTOM <= y <= BD_TOP
}


bool ZakoSample::HitCheck()
{
	return false;
}