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
	void Update() override;
	void Draw() override;
	Vector2D& GetPos() override {
		return pos;
	}

private:
	void Initialize() override;
	bool HitCheck() override;	// �v���C���[�̍U���Ƃ̓����蔻��
	void Move();				// �����̂�

	std::unique_ptr<Image> img;
};