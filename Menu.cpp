#include <DxLib.h>

#include "Include\Menu.hpp"
#include "Include\Keyboard.hpp"



Menu::Menu(ISceneChanger * changer)
	: BaseScene(changer)
{
	Initialize();
}


Menu::~Menu()
{
	Finalize();
}


void Menu::Initialize()
{
}


void Menu::Finalize()
{
}


void Menu::Update()
{
	if (Keyboard_Get(KEY_INPUT_Z) == 1)	mSceneChanger->ChangeScene(eScene_Game);
}


void Menu::Draw()
{
	DrawFormatString(260, 280, GetColor(255, 255, 255), "PRESS Z KEY");
}

//EOF