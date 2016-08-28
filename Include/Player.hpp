#ifndef DEF_PLAYER_HPP
#define DEF_PLAYER_HPP


#include "CharaTask.hpp"
#include "Vector2D.hpp"
#include "Texture.hpp"
#include "Image.hpp"
#include "Sound.hpp"
#include <memory>


class Player : public CharaTask
{
public:
	Player();
	~Player();
	void Update() override;
	void Draw() override;
	const Vector2D& GetPos() const;

private:
	const double FLOOR_TOP		= 208.;
	const double FLOOR_BOTTOM	= 472.;
	const double FLOOR_LEFT		= 20.;
	const double FLOOR_RIGHT	= 620.;

private:
	void Initialize() override;
	void Finalize() override {};
	void Move();

	// プレイヤーの基準点
	const double POS_Y_LIMIT;
	
	// 落ちる加速度
	const double GRAVITY;
	
	// 歩くスピード
	const double WALK_SPEED;

	Vector2D pos, vmove, shadowPos;
	std::unique_ptr<Image> img;
	std::shared_ptr<Sound> sound;

	//int sh_jump;
	int elapsedTime;
	double vec_jump;
	bool isJump;
	bool isLeft;
};


#endif // !DEF_PLAYER_HPP

// EOF