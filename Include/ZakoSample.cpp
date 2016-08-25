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
	pos = Vector2D(GetRand(1280) - 640, GetRand(960) - 480); // âÊñ ì‡ÇÃÇ«Ç±Ç©Ç…ÅEÅEÅE
	vmove.SetZero();
	time = 0;
}


void ZakoSample::Update()
{
	time++;

	Move();
	Boundary(&shadowPos.x, &shadowPos.y);

	HitCheck();
}


void ZakoSample::Draw()
{
	DrawCircle(shadowPos.x, shadowPos.y, 4, GetColor(255, 255, 255), TRUE);
	DrawAnime(pos.x, pos.y, 0., _countof(gh), 100, gh);
}


void ZakoSample::Move()
{
	pos += vmove;
}


void ZakoSample::Boundary(double * x, double * y)
{
	*x = std::max(std::min(*x, (double)BD_RIGHT), (double)BD_LEFT);
	*y = std::max(std::min(*y, (double)BD_BOTTOM), (double)BD_TOP);
}


bool ZakoSample::HitCheck()
{
	return false;
}
