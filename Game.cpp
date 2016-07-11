#include "DxLib.h"

#include "Game.hpp"
#include "Player.hpp"
#include "Keyboard.hpp"


Game::Game(ISceneChanger * changer)
	: BaseScene(changer)
	, player(new Player)
	, prcn(new BEnemy)
	, stage(new Stage)
	, mainCamera(new Camera)
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
	mainCamera->Update(player->GetPos().x, player->GetPos().y);
}


void Game::Draw()
{
	stage->Draw();

	if (player->GetPos().y >= prcn->GetPos().y)
	{
		prcn->Draw();
		player->Draw();
	}
	else
	{
		player->Draw();
		prcn->Draw();
	}

	mainCamera->Draw();

	// TEST---------------------------------------------------
	DrawFormatString(20, 20, GetColor(255, 0, 0), "NOW_GAME_SCENE");
	DrawFormatString(20, 40, GetColor(0, 0, 0), "JUMP	: [C]");
	DrawFormatString(20, 60, GetColor(0, 0, 0), "WALK	: [��][��]");
	if (isPause)	DrawFormatString(320, 240, GetColor(255, 0, 0), "�|�[�Y��");
}

// EOF
