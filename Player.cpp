#include <DxLib.h>

#include "Include\Player.hpp"
#include "Include\Keyboard.hpp"

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
	// 経過時間計測
	elapsedTime++;
	
	// 移動
	Move();

	// 人の追従
	pos.x = shadowPos.x;
	if (!isJump)	pos.y = shadowPos.y - 50.;

	// プレイヤーの向きを変更
	if (Keyboard_Get(KEY_INPUT_RIGHT) >= 1)	isLeft = false;
	
	if (Keyboard_Get(KEY_INPUT_LEFT) >= 1)	isLeft = true;
}


void Player::Draw()
{
	// 影
	const double& VEC_JUMP = std::fabs(vec_jump);

	if (isJump){
		img->DrawRota(shadowPos.x, shadowPos.y, 1. - (20. - VEC_JUMP) / 20., 0., "shadow", true);
	}else{
		img->DrawRota(shadowPos.x, shadowPos.y, 1., 0., "shadow", true);
	}

	img->DrawRota(pos.x, pos.y, 1., 0., "player",true, !isLeft);

	// セリフ
	//if(isJump)	DrawFormatString(pos.x + 10., pos.y - 40., GetColor(0, 0, 0), "飛んでまーす");

	// デバッグ情報
	//DrawFormatString(20, 80, GetColor(0, 0, 0), "Player : x(%lf), y(%lf)", shadowPos.x, shadowPos.y);
}


Vector2D& Player::GetPos(){
	return shadowPos;
}


void Player::Move()
{
	const bool& IS_GROUND = (pos.y > shadowPos.y - 50 && isJump);

	// とりあえず
	vmove.SetZero();

	// 地面にいるとき
	if (IS_GROUND)
	{
		pos.y   = shadowPos.y - 50;
		vec_jump = 0.;
		isJump  = false;
	}

	if (isJump)	vec_jump -= GRAVITY;

	if (Keyboard_Get(KEY_INPUT_C) == 1 && !isJump)
	{
		// ジャンプさせる
		// @attention
		//　自分の環境だと [↓] と [→] と [SPACE] または、
		//　[↑] と [→]と[SPACE] の同時押しはハード上の制約でできなかった。
		vec_jump = 20.;
		isJump = true;
		sound->PlayMem("jump", DX_PLAYTYPE_BACK);
	}

	// 歩きベクター
	if (Keyboard_Get(KEY_INPUT_RIGHT) >= 1)	vmove.x = WALK_SPEED;
	if (Keyboard_Get(KEY_INPUT_LEFT)  >= 1)	vmove.x = -WALK_SPEED;
	if (Keyboard_Get(KEY_INPUT_UP)    >= 1)	vmove.y = WALK_SPEED;
	if (Keyboard_Get(KEY_INPUT_DOWN)  >= 1)	vmove.y = -WALK_SPEED;

	// 移動させる
	if(isJump)	pos.y -= vec_jump + vmove.y;
	shadowPos.x += vmove.x;
	shadowPos.y -= vmove.y;

	shadowPos.x = std::max(std::min(shadowPos.x, FLOOR_RIGHT), FLOOR_LEFT);
	shadowPos.y = std::max(std::min(shadowPos.y, FLOOR_BOTTOM), FLOOR_TOP);
}

// EOF