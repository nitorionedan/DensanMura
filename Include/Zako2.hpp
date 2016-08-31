/*
@brief	Zako2クラス
@author	吉村
*/
#pragma once

#include "ZakoEnemy.hpp"
#include "Image.hpp"
#include "Vector2D.hpp"
#include <memory>


class Zako2 : public ZakoEnemy
{
	struct Shadow {
		Vector2D pos, vmove;
	};

public:
	Zako2();
	~Zako2();
	virtual void Update(const Player& player) override;
	virtual void Draw() override;
	const Vector2D& GetPos() const override {
		return pos;
	}

private:
	int const Movintime;
	int const Wait;
	int const attacktime;

	int YoshimMoveflag=0;
	int movin_count = 0;
	int attackPhase = 0;
	int movemuki = 0;
	void Initialize() override;
	bool HitCheck() override;	// プレイヤーの攻撃との当たり判定
	void Move();				// 動きのみ

	std::unique_ptr<Image> img;
	Shadow shadow;
};
