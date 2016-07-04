//------------------------------------------------------------------------------
/// @file
/// @brief    TESTÉNÉâÉXÇ∆TESTÉtÉäÅ[ä÷êî
/// @author   ñÓì`„ƒïΩ
///
/// @copyright  Copyright 2016 ñÓì`„ƒïΩ

//------------------------------------------------------------------------------

#ifndef DEF_TEST_HPP
#define DEF_TEST_HPP


#include "DxLib.h"


void Test_Initialize();
void Test_Update();
void Test_Draw();
void Test_Finalize();

class TestGraphics
{
public:
	TestGraphics() {}
	TestGraphics(char* FILE_NAME, double posX, double posY, double exrate_, double angle_, bool TransFlag)
		: gh(LoadGraph(FILE_NAME))
		, pos_x(posX)
		, pos_y(posY)
		, exrate(exrate_)
		, angle(angle_)
		, isTrans(TransFlag)
	{
		if (gh == -1)	printfDx("ì«Ç›çûÇ›é∏îs...\n");
	}
	~TestGraphics()
	{
		DeleteGraph(gh);
//		MessageBox(NULL, "åƒÇŒÇÍÇΩÇÊ", "title", MB_OK);
	}
	void Draw() {
		DrawRotaGraph(pos_x, pos_y, exrate, angle, gh, isTrans);
	}

	int gh;
	double	pos_x,
		pos_y,
		angle,
		exrate;
	bool isTrans;

private:
};


#endif // !DEF_TEST_HP

// EOF