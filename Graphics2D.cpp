//------------------------------------------------------------------------------
/// @file
/// @brief    Graphics2D.hppの実装
/// @author   PG班 矢風！
///
/// @copyright  Copyright 2016 Shohei.Y
/// @attention  このファイルの利用は、同梱のREADMEにある
///             利用条件に従ってください

//------------------------------------------------------------------------------

#include "DxLib.h"

#include "Include/Graphics2D.hpp"

#include <cmath>
#include <algorithm>

#undef max
#undef min


Graphics2D::Graphics2D()
	: FRAME_NUM(0)
	, gh(nullptr)
{
}


Graphics2D::Graphics2D(int Gr_Handle[], int num)
	: FRAME_NUM(num)
	, count(0)
{
	gh = new int[FRAME_NUM];

	for (int i = 0; i < FRAME_NUM; i++)
		gh[i] = Gr_Handle[i];
}


Graphics2D::~Graphics2D()
{
	delete[] gh;
}


void Graphics2D::Raster_Scroll(const int &X, const int &Y, const int &Gr_Handle, double Cycle,  double Shake)
{
	int Width = 0, Height = 0;	// 画像の横幅と縦幅
	int Correction = 0;			// ラスタースクロールの補正

	GetGraphSize(Gr_Handle, &Width, &Height);

	for (int I = 0; I < Height; ++I)
	{
		const int DestX = X - Width / 2 + std::cos((I + Correction) / 180.0 * DX_PI * Cycle) * Shake;
		const int DestY = Y - Height / 2 + I;

		DrawRectGraph
		(
			DestX, DestY,
			0, I,
			Width, 1,
			Gr_Handle,
			TRUE, FALSE
		);
	}

	++Correction;
}


void Graphics2D::DrawRasterScroll(const int& X, const int& Y, double Cycle, double Shake, const int& Gr_Handle, bool isVertical)
{
	int Width = 0, Height = 0;					// 画像の横幅と縦幅
	static int Correction = 0;					// ラスタースクロールの補正

	GetGraphSize(Gr_Handle, &Width, &Height);	// 画像のサイズを得る

	switch (isVertical)
	{
	case true :
		for (int I = 0; I < Height; ++I)
		{
			const int& DestX = X - Width / 2 + std::cos((I + Correction) / 180.0 * DX_PI * Cycle) * Shake;	// cosの値で左右に揺らす
			const int& DestY = Y - Height / 2 + I;

			// 画像の分割描画（縦に１pixずつ）
			DrawRectGraph(
				DestX, DestY,
				0, I,
				Width, 1,
				Gr_Handle,
				TRUE, FALSE
				);
		}	break;

	case false :
		for (int I = 0; I < Width; ++I)
		{
			const int DestX = X - Width / 2 + I;
			const int DestY = Y - Height / 2 + std::cos((I + Correction) / 180. * DX_PI * Cycle) * Shake;

			// 画像の分割描画（横に１pixずつ）
			DrawRectGraph(
				DestX, DestY,
				I, 0,
				1, Height,
				Gr_Handle,
				TRUE, FALSE
				);
		}	break;
	}

	++Correction;
}


void Graphics2D::DrawBlendAdd(const int &X, const int &Y, const double &ExRate_, const double &Angle_, int Blend_ADD, const int &Gr_Handle, bool TransFlag_)
{
	const int& BLEND_ADD = std::min( 255, std::max(0, Blend_ADD) );

	SetDrawBlendMode(DX_BLENDMODE_ADD, BLEND_ADD);					// 加算ブレンドモード
	DrawRotaGraph(X, Y, ExRate_, Angle_, Gr_Handle, TransFlag_);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);						//ブレンドモードをオフ
}


void Graphics2D::DrawColorGraph(const int& X, const int& Y, const double& Exrate, const int& Gr_Handle, int R, int G, int B)
{
	SetDrawBright(R, G, B);
	DrawRotaGraph(X, Y, Exrate, 0.0, Gr_Handle, true);
	SetDrawBright(255, 255, 255);
}


// 失敗出来損ない～～～～
void Graphics2D::DrawAnimation(const double& X, const double& Y, const double& EXRATE, const double& ANGLE, const int & ANIME_SPEED)
{
	if (gh != nullptr){
		printfDx("読み込みエラー(G2D)\n");	return;
	}
	const int& ALL_NUM = ANIME_SPEED * FRAME_NUM;

	for (int i = 0; i < FRAME_NUM; i++)
	{
		for (int j = 0; j < ALL_NUM; j++)
		{
			if (count >= j && count <= j + (j * ANIME_SPEED))
			{
				DrawRotaGraph(X, Y, EXRATE, ANGLE, gh[i], true);
				break;
			}
		}
	}

	count++;

	if (count == ALL_NUM)	count = 0;
}


void DrawAnime(const double & PosX, const double & PosY, const double & ANGLE, const int & TIME, const int& FRAME_NUM, const int & TIME_FRAME, int Gr_Handle[])
{
	// 余りをもとめるため、１を足して調整
	const int& SUM_FRAME_TIME = (FRAME_NUM * TIME_FRAME + 1);

	// アニメーション
	for (int j = 0; j < FRAME_NUM; j++)
	{
		const bool& IS_PLAYTIME = ( TIME % SUM_FRAME_TIME < j * TIME_FRAME ||
									TIME % SUM_FRAME_TIME > TIME_FRAME + (j * TIME_FRAME) );
		if (IS_PLAYTIME)	continue;

		DrawRotaGraph(PosX, PosY, 2.0, ANGLE, Gr_Handle[j], true);
		break;
	}
}


void DrawAnime(const double & PosX, const double & PosY, const double & ANGLE, const int & FRAME_NUM, const int & TIME_FRAME, int Gr_Handle[])
{
	// 余りをもとめるため、１を足して調整
	const int& SUM_FRAME_TIME = (FRAME_NUM * TIME_FRAME + 1);
	
	static int aniTime = 0;
	aniTime++;

	// アニメーション
	for (int j = 0; j < FRAME_NUM; j++)
	{
		const bool& IS_PLAYTIME = ( aniTime % SUM_FRAME_TIME < j * TIME_FRAME ||
									aniTime % SUM_FRAME_TIME > TIME_FRAME + (j * TIME_FRAME) );
		if (IS_PLAYTIME)	continue;

		DrawRotaGraph(PosX, PosY, 2.0, ANGLE, Gr_Handle[j], true);

		break;
	}
}