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
	bool HitCheck() override;				// �v���C���[�̍U���Ƃ̓����蔻��
	void Move(const Vector2D& vec);			// �����̂�
	void GoTo(const Vector2D& vec);			// �v���C���[�Ɍ�����
	void Boundary(double* x, double* y);	// ���W�����E�l�ɒ���
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