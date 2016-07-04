//------------------------------------------------------------------------------
/// @file
/// @brief    ISceneChangerクラス
/// @author   矢伝翔平
///
/// @copyright  Copyright 2016 矢伝翔平

//------------------------------------------------------------------------------

#ifndef DEF_ISCENEMNG_HPP
#define DEF_ISCENEMNG_HPP


typedef enum
{
	eScene_Menu,	// メニュー画面
	eScene_Game,	// ゲーム画面

	eScene_None,	// 無し
} eScene;


//シーンを変更するためのインターフェイスクラス
class ISceneChanger
{
public:
	virtual ~ISceneChanger() = 0;
	virtual void ChangeScene(eScene NextScene) = 0; //指定シーンに変更する
};


#endif

// EOF