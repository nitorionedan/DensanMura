#ifndef DEF_ZAKO1_HPP
#define DEF_ZAKO1_HPP

#include "ZakoEnemy.hpp"
#include "Image.hpp"
#include "Vector2D.hpp"
#include <memory>


class Zako1 : public ZakoEnemy
{
	struct Shadow
	{
		Vector2D pos, vmove;
	};

public:
	Zako1();
	~Zako1();
	void Update(const Player& player) override;
	void Draw() override;
	Vector2D& GetPos() override {
		return pos;
	}

private:
	void Initialize() override;
	bool HitCheck() override;				// プレイヤーの攻撃との当たり判定
	void Move(const Vector2D& vec);			// 動きのみ
	void GoTo(const Vector2D& vec);			// プレイヤーに向かう
	void Boundary(double* x, double* y);	// 座標を限界値に調整
	void Jump();

	static const int BD_BOTTOM_CHARA = 40;
	const double Gravity;

	std::unique_ptr<Image> img;
	Shadow shadow;
	Vector2D vmove;
	int gh[3];
	int time;
	double walkSpeed;
	double jumpPower;
	bool isMove;
	bool isJumping;
};


#endif // !DEF_ZAKO1_HPP