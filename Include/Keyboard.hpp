//------------------------------------------------------------------------------
/// @file
/// @brief    キーボード入力状態管理関数
/// @author   矢伝翔平
///
/// @copyright  Copyright 2016 矢伝翔平

//------------------------------------------------------------------------------

#ifndef DEF_KEYBOARD_HPP
#define DEF_KEYBOARD_HPP


// キーの入力状態を更新する
void Keyboard_Update();

// 引数のキーコードのキーの入力状態を返す
int Keyboard_Get(int KeyCode);

// 一度押しかどうか
bool KeyPush(int KeyCode);

// 押し続けるとき
bool KeyDown(int KeyCode);

#endif

// EOF