//------------------------------------------------------------------------------
/// @file
/// @brief    Graphics2Dクラス
/// @author   PG班 矢風！
///
/// @copyright  Copyright 2016 Shohei.Y
/// @attention  このファイルの利用は、同梱のREADMEにある
///             利用条件に従ってください

//------------------------------------------------------------------------------

#pragma once


// 拡張？描画クラス
class Graphics2D
{
public:
	Graphics2D();

	// @param[in]	num	使うコマ数
	Graphics2D(int Gr_Handle[], int num);
	~Graphics2D();

	// @brief		疑似的にラスタースクロールをさせる
	// @param[in]	X, Y		描画する中心座標
	// @param[in]	Gr_Handle	画像ハンドル
	// @param[in]	Cycle		周期（ぐにゃぐにゃの速さ）
	// @param[in]	Snake		振幅（ぐにゃる距離）
	// @attention	倍率の変更に未対応
	void Raster_Scroll(const int &X, const int &Y, const int &Gr_Handle, double Cycle, double Shake);

	// @brief		Graphics2D::Raster_Scroll() をこのゲーム用に手を加えたもの
	// @param[in]	X, Y		描画する中心座標
	// @param[in]	Cycle		周期（ぐにゃぐにゃの速さ）
	// @param[in]	Snake		振幅（ぐにゃる距離）
	// @param[in]	Gr_Handle	画像ハンドル
	// @param[in]	isVertical	縦に揺らすか？
	// @attention	倍率の変更に未対応
	void DrawRasterScroll(const int &X, const int &Y, double Cycle, double Shake, const int &Gr_Handle, bool isVertical = true);

	// @brief		透明度だけを設定しながら画像を描画
	// @param[in]	X, Y		描画する中心座標
	// @param[in]	EXRATE_		描画するときの拡大倍率
	// @param[in]	ANGLE_		回転値
	// @param[in]	Blend_ADD	加算値（０～２５５）
	// @param[in]	Gr_Handle	画像ハンドル
	// @param[in]	TransFlag	向きの反転フラグ
	void DrawBlendAdd(const int &X, const int &Y, const double &EXRATE_, const double &ANGLE_, int Blend_ADD, const int &Gr_Handle, bool TransFlag_ = true);
	
	// @brief		輝度だけを設定しながら画像を描画
	// @param[in]	X, Y		描画座標
	// @param[in]	EXRATE		描画倍率
	// @param[in]	Gr_Handle	画像ハンドル
	// @param[in]	R, G, B		輝度（RGB値）
	// @attention	この関数は最後に輝度を（255, 255, 255）に設定している
	void DrawColorGraph(const int& X, const int& Y, const double& EXRATE, const int &Gr_Handle, int R, int G, int B);

	// @brief					コマアニメを描画
	// @param[in]	ANIME_SPEED	コマを送る速さ（１枚毎のフレーム数）
	// @attention				Graphics2Dクラスの引数付きコンストラクタで格納されたオブジェクトのみ使用可能
	void DrawAnimation(const double& X, const double& Y, const double& EXRATE, const double& ANGLE, const int& ANIME_SPEED);

	// @brief					指定した時間だけ描画
	// @param[in]	X, Y		描画座標
	// @param[in]	EXRATE		描画倍率
	// @param[in]	Gr_Handle	画像ハンドル
	// @param[in]	time		描画する時間（フレーム）
	void DrawForTime(const double& X, const double& Y, const double& EXRATE, const double& ANGLE, const int &Gr_Handle, int time){}

private:
	const int FRAME_NUM;
	int* gh;
	int count;
};


// @brief					アニメーション再生関数・改
// @pram[in]	PosX, PosY	描画中心座標
// @pram[in]	ANGLE		描画角度
// @pram[in]	TIME		毎フレーム１増える変数
// @pram[in]	FRAME_NUM	アニメーションの総枚数
// @pram[in]	TIME_FRAME	１コマの表示時間（フレーム数）
// @pram[in]	Gr_Handle[]	画像ハンドル配列
// @attention				配列の総合計を超えた値を入れないでください。倍率は２倍にされています。
void DrawAnime(const double& PosX, const double& PosY, const double& ANGLE, const int& TIME, const int& FRAME_NUM, const int& TIME_FRAME, int Gr_Handle[]);


// @biref					時間を全て同じにするためのアニメーション再生関数
// @pram[in]	PosX, PosY	描画中心座標
// @pram[in]	ANGLE		描画角度
// @pram[in]	FRAME_NUM	アニメーションの総枚数
// @pram[in]	TIME_FRAME	１コマの表示時間（フレーム数）
// @pram[in]	Gr_Handle[]	画像ハンドル配列
// @attention				配列の総合計を超えた値を入れないでください。倍率は２倍にされています。
void DrawAnime(const double& PosX, const double& PosY, const double& ANGLE, const int& FRAME_NUM, const int& TIME_FRAME, int Gr_Handle[]);


/* メモ */
// newで確保するとヒープ領域に記憶される

// EOF