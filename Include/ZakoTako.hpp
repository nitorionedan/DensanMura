#pragma once
#include "ZakoEnemy.hpp"
#include "Image.hpp"
#include "Vector2D.hpp"
#include "Player.hpp"
#include <memory>


class ZakoTako : public ZakoEnemy
{
public:
	ZakoTako();
	~ZakoTako();
	virtual void Update(const Player& player) override;
	virtual void Draw() override;
	const Vector2D& GetPos() const override {
		return pos;
	}

private:
	//�͂��ؒǉ��ϐ��A���\�b�h
	int PlaX, PlaY;
	const unsigned char PLAYER_SIZE_X, PLAYER_SIZE_Y, TAKO_SIZE_X, TAKO_SIZE_Y;
	const double TFOLLW_SPEED, TESCAPE_SPEED;
	enum{
		Tfollow,
		Tescape
	}Tmode;


	//�f�t�H���g
	void Initialize();
	virtual bool HitCheck() override;	// �v���C���[�̍U���Ƃ̓����蔻��
	void Move();				// �����̂�

	std::unique_ptr<Image> img;
};