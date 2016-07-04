#include "Character.hpp"


Character::Character(CharaTask* chara)
	: mCharaTask(chara)
{
	Initialize();
}


Character::~Character()
{
	Finalize();
}


void Character::Initialize()
{
	mCharaTask->Initialize();
}


void Character::Finalize()
{
	mCharaTask->Finalize();
}


void Character::Update()
{
	mCharaTask->Update();
}


void Character::Draw()
{
	mCharaTask->Draw();
}

// EOF