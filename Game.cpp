#include <DxLib.h>

#include "Include\Game.hpp"
#include "Include\Player.hpp"
#include "Include\Keyboard.hpp"


Game::Game(ISceneChanger * changer)
	: BaseScene(changer)
	, player(new Player)
	, prcn(new BEnemy)
	, stage(new Stage)
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

	if (isPause)	return;

	stage->Update();
	player->Update();
	prcn->Update();
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

	// TEST---------------------------------------------------
	DrawFormatString(20, 20, GetColor(255, 0, 0), "NOW_GAME_SCENE");
	DrawFormatString(20, 40, GetColor(0, 0, 0), "JUMP	: [C]");
	DrawFormatString(20, 60, GetColor(0, 0, 0), "WALK	: [Å©][Å®]");
	if (isPause)	DrawFormatString(320, 240, GetColor(255, 0, 0), "É|Å[ÉYíÜ");
}

// EOF
