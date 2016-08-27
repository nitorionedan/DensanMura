#pragma once
#include "ZakoEnemy.hpp"
#include "Image.hpp"
#include "Vector2D.hpp"
#include <memory>


class ZakoSample : public ZakoEnemy
{
public:
	ZakoSample();
	~ZakoSample();
	void Update(const Player& player) override;
	void Draw() override;
	Vector2D& GetPos() override {
		return pos;
	}

private:
	void Initialize() override;
	bool HitCheck() override;	// �v���C���[�̍U���Ƃ̓����蔻��
	void Move();				// �����̂�
	void Boundary(double* x, double* y);

	std::unique_ptr<Image> img;
	Vector2D shadowPos, vmove;
	int gh[3];
	int time;
	double walkSpeed;
	double jumpPower;
	bool isArrived;
};