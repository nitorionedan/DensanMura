/*
@brief	Zako1.hpp�̎���
@author	��`
*/
#include "Include/Zako1.hpp"
#include "Include/Graphics2D.hpp"
#include "Include/Keyboard.hpp"
#include <cassert>
#include <algorithm>
#undef min
#undef max


Zako1::Zako1()
	: img(new Image)
	, Gravity(0.5)
	, Move_interval(120)
	, Jump_interval(180)
{
	gh[0] = LoadGraph("Images/Characters/zako1_1.png");
	gh[1] = LoadGraph("Images/Characters/zako1_2.png");
	gh[2] = LoadGraph("Images/Characters/zako1_3.png");

	Initialize();
}


Zako1::~Zako1()
{
	for (auto i : gh)
		DeleteGraph(i);
}


void Zako1::Initialize()
{
	shadow.pos.SetVec(320, 240);
	pos.SetVec(shadow.pos.x, shadow.pos.y - BD_BOTTOM_CHARA);
	shadow.vmove.SetZero();
	vmove.SetZero();
	time = 0;
	walkSpeed = 3;
	jumpPower = -15;
	isMove = false;
	isJumping = false;
}


void Zako1::Update(const Player& player)
{
	time++;

	/* �����Ă�����isMove�𗧂Ă� */
	const bool& IsMoving = (shadow.vmove.x != 0. || shadow.vmove.y != 0.);
	if (IsMoving)
		isMove = true;
	else
		isMove = false;

	Move(player.GetPos());

	/* �L�����̈ʒu�𒲐� */
	const double& Bottom = (shadow.pos.y - BD_BOTTOM_CHARA);
	pos.x = shadow.pos.x;
	if (isJumping)
		pos.y = std::min(Bottom, pos.y);
	else
		pos.y = Bottom;

	/* ���n���� */
	const double& IsGround = (pos.y == Bottom);
	if (IsGround && isJumping)
	{
		isJumping = false;
		vmove.y = 0;
	}

	/* ���W��͈͓��ɔ[�߂� */
	Boundary(&shadow.pos.x, &shadow.pos.y);
	if (IsGround)
		pos.y = Bottom;

	HitCheck();
}


void Zako1::Draw()
{
	DrawAnime(pos.x, pos.y, 0., time, _countof(gh), 100, gh);
	DrawCircle(shadow.pos.x, shadow.pos.y, 4, GetColor(255, 0, 0), TRUE);

	/* TEST */
	//if (isJumping)
	//	DrawFormatString(320, 240, GetColor(255, 0, 0), "jumping");
	//else
	//	DrawFormatString(320, 240, GetColor(255, 0, 0), "not jumping");
}


void Zako1::Move(const Vector2D& vec)
{
	/* �X�g�b�v���S�[ */
	const bool& MoveTime = (time % Move_interval == 0);
	if (MoveTime)
	{
		walkSpeed = GetRand(3) + 1;

		if (isMove == false)
			GoTo(vec);
		else
			shadow.vmove.SetZero();
	}

	/* �W�����v */
	const bool& JumpTime = (time % Jump_interval == 0);
	if (JumpTime)
	{
		jumpPower = -GetRand(6) - 10;
		Jump();
	}

	/* ���܂Ƀv���C���[�ɍ��킹�� */
	const bool& IsFollowToPlayer = (Keyboard_Get(KEY_INPUT_C) == 1 &&	// �v���C���[���W�����v����Ƃ�
									isJumping == false &&				// �W�����v���Ă��Ȃ��Ƃ�
									GetRand(2) == 2);					// �R���̂P�̊m����
	if (IsFollowToPlayer)
		GoTo(vec);

	/* �d�͂ɂ�闎�� */
	if (isJumping)
		vmove.y += Gravity; // ������

	/* �ǂŎ~�܂� */
	/// TODO:�K�v�������

	/* �x�N�g�����Z */
	shadow.pos += shadow.vmove;
	pos += (vmove + shadow.vmove);
}


void Zako1::GoTo(const Vector2D& vec)
{
	Vector2D tmp = Vector2D::GetVec2(shadow.pos, vec);
	shadow.vmove.x = tmp.Normalize().x * walkSpeed;
	shadow.vmove.y = tmp.Normalize().y * walkSpeed;
}


inline void Zako1::Boundary(double * x, double * y)
{
	*x = std::max(std::min(*x, (double)BD_RIGHT), (double)BD_LEFT); // BD_RIGHt  <= x <= BD_LEFT
	*y = std::max(std::min(*y, (double)BD_BOTTOM), (double)BD_TOP); // BD_BOTTOM <= y <= BD_TOP
}


void Zako1::Jump()
{
	if (isJumping)	return;

	isJumping = true;
	vmove.y = jumpPower;
}


bool Zako1::HitCheck()
{
	return false;
}