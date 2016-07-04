#ifndef DEF_CAMERA_HPP
#define DEF_CAMERA_HPP


#include "Vector2D.hpp"


class Camera
{
public:
	Camera();
	~Camera();
	void Initialize();
	void Update(const double& PosX = 0., const double& PosY = 0.);
	void Draw();

private:
	const int WIDTH, HEIGHT;

	Vector2D pos;
};


#endif

// EOF