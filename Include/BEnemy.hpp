#ifndef DEF_BENEMY_HPP
#define DEF_BENEMY_HPP

#include "Vector2D.hpp"
#include "Image.hpp"

#include <memory>


class BEnemy
{
public:
	BEnemy();
	~BEnemy();
	void Initialize();
	void Update();
	void Draw();
	Vector2D& GetPos();

private:
	void Move();

	Vector2D pos, shadowPos;
	std::unique_ptr<Image> img;
	
	float c_move;
};


#endif // !DEF_BENEMY_HPP

// EOF