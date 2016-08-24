#pragma once
#include "Vector2D.hpp"


class ZakoEnemy 
{
public:
	ZakoEnemy(){}
	virtual ~ZakoEnemy(){}
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual Vector2D& GetPos() = 0;
	virtual bool HitCheck() = 0; // �v���C���[�̍U���Ƃ̓����蔻��

protected:
	virtual void Initialize() {}

	Vector2D pos;
	bool isDead; // ���񂾂��H
};