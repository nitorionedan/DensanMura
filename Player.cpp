#include "Include\Player.hpp"
#include "Include\Keyboard.hpp"
#include <DxLib.h>
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
	shadowPos.SetVec(20., POS_Y_LIMIT);
	pos.SetVec(shadowPos.x, shadowPos.y - 50.);
	elapsedTime = 0;
	vec_jump = 0.;
	vmove.SetVec(0., 0.);
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

#ifdef _DEBUG
	// �Z���t
	//if(isJump)	DrawFormatString(pos.x + 10., pos.y - 40., GetColor(0, 0, 0), "���ł܁[��");
	//DrawFormatString(20, 80, GetColor(0, 0, 0), "Player : x(%lf), y(%lf)", shadowPos.x, shadowPos.y);
#endif // _DEBUG
}


const Vector2D& Player::GetPos() const {
	return shadowPos;
}


void Player::Move()
{
	const bool& IS_GROUND = (pos.y >= shadowPos.y - 50 && isJump);

	vmove.SetZero();

	if (isJump)	vec_jump -= GRAVITY;

	if (Keyboard_Get(KEY_INPUT_C) == 1 && !isJump)
	{
		// �W�����v������
		// @attention	�����̊����� [��] �� [��] �� [SPACE] �܂��́A
		//				[��] �� [��]��[SPACE] �̓��������̓n�[�h��̐���łł��Ȃ������B
		vec_jump = 20.;
		isJump = true;
		sound->PlayMem("jump", DX_PLAYTYPE_BACK);
	}

	// �ړ��x�N�g���␳�iTODO:�L���̋c�_�j
	double walkSpeed = WALK_SPEED;
	if(Keyboard_Get(KEY_INPUT_LEFT) >= 1 || Keyboard_Get(KEY_INPUT_RIGHT) >= 1)
	{
		if (Keyboard_Get(KEY_INPUT_UP) >= 1 || Keyboard_Get(KEY_INPUT_DOWN) >= 1)
		{
			walkSpeed = walkSpeed / 1.7;
		}
	}

	// �����x�N�^�[
	if (Keyboard_Get(KEY_INPUT_RIGHT) >= 1)	vmove.x = walkSpeed;
	if (Keyboard_Get(KEY_INPUT_LEFT) >= 1)	vmove.x = -walkSpeed;
	if (Keyboard_Get(KEY_INPUT_UP) >= 1)	vmove.y = -walkSpeed;
	if (Keyboard_Get(KEY_INPUT_DOWN) >= 1)	vmove.y = walkSpeed;

	/* �ړ������� */
	if(isJump)
		pos.y -= vec_jump + vmove.y;
	shadowPos += vmove;

	shadowPos.x = std::max(std::min(shadowPos.x, FLOOR_RIGHT), FLOOR_LEFT);
	shadowPos.y = std::max(std::min(shadowPos.y, FLOOR_BOTTOM), FLOOR_TOP);

	/* �n�ʂɂ���Ƃ� */
	if (IS_GROUND)
	{
		pos.y = shadowPos.y - 50;
		vec_jump = 0.;
		isJump = false;
	}
}


// EOF