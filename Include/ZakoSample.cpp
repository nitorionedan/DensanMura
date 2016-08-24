#include "ZakoSample.hpp"
#include <cassert>


static int g_test = 0;


ZakoSample::ZakoSample()
	: img(new Image)
{
	int tmp[3];
	tmp[0] = img->Load("Images/Characters/zako1_1.png", "idle_1");
	tmp[1] = img->Load("Images/Characters/zako1_2.png", "idle_2");
	tmp[2] = img->Load("Images/Characters/zako1_3.png", "idle_3");
	
	//g_test = LoadGraph("Images/Characters/zako1_1.png");

	// 画像ロード失敗判定
	for(int i : tmp)
		assert(i != -1 && "ZakoSample : 画像ロード");

	printfDx("%d", g_test);

	Initialize();
}


ZakoSample::~ZakoSample()
{
	DeleteGraph(g_test);
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
	DrawGraph(pos.x, pos.y, g_test, true);
}


void ZakoSample::Move()
{
}


bool ZakoSample::HitCheck()
{
	return false;
}
