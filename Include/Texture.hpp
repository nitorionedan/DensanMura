#ifndef DEF_TEXTURE_HPP
#define DEF_TEXTURE_HPP

#include "DxLib.h"


class Texture
{
public:
	Texture(const TCHAR* FILENAME);
	~Texture();

	void LoadGraph(const TCHAR* FILENAME);
	int GetHandle();
	void Draw(int x, int y, int TransFlag);
	void DrawRota(int x, int y, double ExRate, double Angle, int TransFlag, int TurnFlag = 0);
private:
	Texture();
	int gh;
};


#endif