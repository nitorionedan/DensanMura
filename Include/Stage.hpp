#ifndef DEF_STAGE_HPP
#define DEF_STAGE_HPP


#include "Image.hpp"
#include "Vector2D.hpp"
#include <memory>


class Stage
{
public:
	Stage();
	~Stage();
	void Initialize();
	void Update();
	void Draw();

private:
	void Move();
	void TestMove();

	std::unique_ptr<Image> img;
	Vector2D pos;
	int rightEnd, leftEnd;
};


#endif