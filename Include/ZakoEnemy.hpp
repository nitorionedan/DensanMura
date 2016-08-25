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

	/* 移動限界値 */
	static const int BD_TOP = 208;
	static const int BD_BOTTOM = 472;
	static const int BD_LEFT = 20;
	static const int BD_RIGHT = 620;

	Vector2D pos;	// 座標
	bool isDead;	// 死んだか？
};