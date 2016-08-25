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
	, mZakoTask(new ZakoEnemyTask(eZako::Sample))
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
	if (Keyboard_Get(KEY_INPUT_F1) == 1)
	{
		int dmg = GetRand(100);

		mEveMsg->SendMsg(GetRand(60) - 30, GetRand(60) - 60,
			GetColor(255, 0, 0), std::to_string(dmg));
	}
	if (Keyboard_Get(KEY_INPUT_H) == 1)
	{
		mEveMsg->SendMsg("Hello");
	}
	
	if (isPause)	return;

	/* キャラ */
	stage->Update();
	player->Update();
	prcn->Update();
	mZakoTask->Update();

	/* ステータス */
	mEveMsg->Update();
}


void Game::Draw()
{
	/* 背景 */
	stage->Draw();

	/* キャラ */
	if (player->GetPos().y >= 380.)
	{
		//prcn->Draw();
		player->Draw();
	}
	else
	{
		player->Draw();
		//prcn->Draw();
	}

	mZakoTask->Draw();

	/* ステータス */
	mEveMsg->Draw(static_cast<int>(player->GetPos().x), static_cast<int>(player->GetPos().y));

	// TEST---------------------------------------------------
	//DrawFormatString(20, 20, GetColor(255, 0, 0), "NOW_GAME_SCENE");
	//DrawFormatString(20, 40, GetColor(0, 0, 0), "JUMP	: [C]");
	DrawFormatString(20, 40, GetColor(0, 0, 0), "EVENT  MSG	: [H]");
	DrawFormatString(20, 60, GetColor(0, 0, 0), "DAMAGE MSG	: [J]");
	if (isPause)	DrawFormatString(320, 240, GetColor(255, 0, 0), "ポーズ中");
}