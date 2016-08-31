#pragma once
#include "Vector2D.hpp"
#include "Player.hpp"


class ZakoEnemy 
{
public:
	ZakoEnemy(){}
	virtual ~ZakoEnemy(){}
	virtual void Update(const Player& player) = 0;
	virtual void Draw() = 0;
	virtual const Vector2D& GetPos() const = 0;
	virtual bool HitCheck() = 0; // �v���C���[�̍U���Ƃ̓����蔻��

protected:
	virtual void Initialize() {}

	/* �ړ����E�l */
	static const int BD_TOP = 208;
	static const int BD_BOTTOM = 472;
	static const int BD_LEFT = 20;
	static const int BD_RIGHT = 620;

	Vector2D pos;	// ���W
	bool isDead;	// ���񂾂��H
};