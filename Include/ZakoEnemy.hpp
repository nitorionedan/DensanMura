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
	virtual bool HitCheck() = 0; // プレイヤーの攻撃との当たり判定

protected:
	virtual void Initialize() {}

	Vector2D pos;
	bool isDead; // 死んだか？
};