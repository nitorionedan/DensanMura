#include "DxLib.h"

#include "Player.hpp"
#include "Keyboard.hpp"

#include <algorithm>

#undef max
#undef min


Player::Player()
	: POS_Y_LIMIT(300.)
	, GRAVITY(1.)
	, WALK_SPEED(4.)
	, img(new Image)
	, sound(new Sound)
{
	img->Load("Images/Characters/player.png", "player");
	img->Load("Images/Objects/kage.png", "shadow");
	sound->Load("Sounds/pse00_2.mp3", "jump");
	Initialize();
}


Player::~Player()
{
	Finalize();
}


void Player::Initialize()
{
	shadowPos.SetVecor2D(20., POS_Y_LIMIT);
	pos.SetVecor2D(shadowPos.x, shadowPos.y - 50.);
	elapsedTime = 0;
	vec_jump = 0.;
	vmove.SetVecor2D(0., 0.);
	isJump = false;
	isLeft = false;
}


void Player::Update()
{
	// �o�ߎ��Ԍv��
	elapsedTime++;
	
	// �ړ�
	Move();

	// �l�̒Ǐ]
	pos.x = shadowPos.x;
	if (!isJump)	pos.y = shadowPos.y - 50.;

	// �v���C���[�̌�����ύX
	if (Keyboard_Get(KEY_INPUT_RIGHT) >= 1)	isLeft = false;
	
	if (Keyboard_Get(KEY_INPUT_LEFT) >= 1)	isLeft = true;
}


void Player::Draw()
{
	// �e
	const double& VEC_JUMP = std::fabs(vec_jump);

	if (isJump){
		img->DrawRota(shadowPos.x, shadowPos.y, 1. - (20. - VEC_JUMP) / 20., 0., "shadow", true);
	}else{
		img->DrawRota(shadowPos.x, shadowPos.y, 1., 0., "shadow", true);
	}

	img->DrawRota(pos.x, pos.y, 1., 0., "player",true, !isLeft);

	// �Z���t
	//if(isJump)	DrawFormatString(pos.x + 10., pos.y - 40., GetColor(0, 0, 0), "���ł܁[��");

	// �f�o�b�O���
	//DrawFormatString(20, 80, GetColor(0, 0, 0), "Player : x(%lf), y(%lf)", shadowPos.x, shadowPos.y);
}


Vector2D& Player::GetPos(){
	return shadowPos;
}


void Player::Move()
{
	const bool& IS_GROUND = (pos.y > shadowPos.y - 50 && isJump);

	// �Ƃ肠����
	vmove.SetZero();

	// �n�ʂɂ���Ƃ�
	if (IS_GROUND)
	{
		pos.y   = shadowPos.y - 50;
		vec_jump = 0.;
		isJump  = false;
	}

	if (isJump)	vec_jump -= GRAVITY;

	if (Keyboard_Get(KEY_INPUT_C) == 1 && !isJump)
	{
		// �W�����v������
		// @attention
		//�@�����̊����� [��] �� [��] �� [SPACE] �܂��́A
		//�@[��] �� [��]��[SPACE] �̓��������̓n�[�h��̐���łł��Ȃ������B
		vec_jump = 20.;
		isJump = true;
		sound->PlayMem("jump", DX_PLAYTYPE_BACK);
	}

	// �����x�N�^�[
	if (Keyboard_Get(KEY_INPUT_RIGHT) >= 1)
	{
		if (Keyboard_Get(KEY_INPUT_UP) >= 1 || Keyboard_Get(KEY_INPUT_DOWN) >= 1){
			vmove.x = WALK_SPEED / 1.41421356237;
		}
		else {
			vmove.x = WALK_SPEED;
		}
	}
	
	if (Keyboard_Get(KEY_INPUT_LEFT) >= 1)
	{
		if (Keyboard_Get(KEY_INPUT_UP) >= 1 || Keyboard_Get(KEY_INPUT_DOWN) >= 1) {
			vmove.x = -WALK_SPEED / 1.41421356237;
		}
		else {
			vmove.x = -WALK_SPEED;
		}
	}
	
	if (Keyboard_Get(KEY_INPUT_UP)    >= 1)	vmove.y = WALK_SPEED;
	
	if (Keyboard_Get(KEY_INPUT_DOWN)  >= 1)	vmove.y = -WALK_SPEED;

	// �ړ�������
	if(isJump)	pos.y -= vec_jump + vmove.y;
	shadowPos.x += vmove.x;
	shadowPos.y -= vmove.y;

	shadowPos.x = std::max(std::min(shadowPos.x, FLOOR_RIGHT), FLOOR_LEFT);
	shadowPos.y = std::max(std::min(shadowPos.y, FLOOR_BOTTOM), FLOOR_TOP);
}

// EOF