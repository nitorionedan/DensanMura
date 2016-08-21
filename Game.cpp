#include <DxLib.h>
#include "Include\Game.hpp"
#include "Include\Player.hpp"
#include "Include\Keyboard.hpp"


static unsigned int const Red = GetColor(255, 0, 0);
static unsigned int const White = GetColor(255, 0, 0);


Game::Game(ISceneChanger * changer)
	: BaseScene(changer)
	, player(new Player)
	, prcn(new BEnemy)
	, stage(new Stage)
	, mEveMsg(new EventMessage)
{
	Initialize();
}


Game::~Game()
{
	Finalize();
}


void Game::Initialize()
{
	isPause = false;
}


void Game::Finalize()
{
}


void Game::Update()
{
	if (Keyboard_Get(KEY_INPUT_Q) == 1)	isPause = !isPause;
	if (Keyboard_Get(KEY_INPUT_H) == 1)
	{
		int dmg = GetRand(100);

		mEveMsg->SendMsg(GetRand(60) - 30, GetRand(60) - 60,
			GetColor(255, 0, 0), std::to_string(dmg));
	}
	
	if (isPause)	return;

	stage->Update();
	player->Update();
	prcn->Update();
	mEveMsg->Update();
}


void Game::Draw()
{
	stage->Draw();

	if (player->GetPos().y >= 380.)
	{
		prcn->Draw();
		player->Draw();
	}
	else
	{
		player->Draw();
		prcn->Draw();
	}

	mEveMsg->Draw(static_cast<int>(player->GetPos().x), static_cast<int>(player->GetPos().y));

	// TEST---------------------------------------------------
	//DrawFormatString(20, 20, GetColor(255, 0, 0), "NOW_GAME_SCENE");
	//DrawFormatString(20, 40, GetColor(0, 0, 0), "JUMP	: [C]");
	DrawFormatString(20, 40, GetColor(0, 0, 0), "EVENT  MSG	: [H]");
	DrawFormatString(20, 60, GetColor(0, 0, 0), "DAMAGE MSG	: [J]");
	if (isPause)	DrawFormatString(320, 240, GetColor(255, 0, 0), "É|Å[ÉYíÜ");
}