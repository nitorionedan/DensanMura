#include "Include\EventMessage.hpp"
#include <DxLib.h>
#include <algorithm>
#include <cassert>
#undef max
#undef min


static unsigned int const White = GetColor(255, 255, 255);


/*-----------------------------------------------
イベントメッセージ管理
-----------------------------------------------*/
EventMessage::EventMessage()
{
	mMsg.reserve(100);  // 配列数を予約
	mMsg2.reserve(100); // 同上
	fh_msg = LoadFontDataToHandle("Resource/FontData.dft", 1);
	assert(fh_msg != -1 && "読み込み失敗：フォント");

	Initialize();
}


EventMessage::~EventMessage()
{
	DeleteFontToHandle(fh_msg);
}


void EventMessage::Initialize()
{
}


void EventMessage::Update()
{
	/* 左上のメッセージ */
	for (auto &&ary : mMsg)
	{
		ary->Update();

		if (ary->GetIsAlive() == false)
		{
			Delete(mMsg, ary);
			break;
		}
	}

	/* 任意の座標のメッセージ */
	for (auto &&ary : mMsg2)
	{
		ary->Update();

		if (ary->GetIsAlive() == false)
		{
			Delete(mMsg2, ary);
			break;
		}
	}
}


void EventMessage::Draw(int x, int y)
{
	/* 左上のメッセージ */
	int i = 0; // 配列の添え字
	for(const auto &ary : mMsg)
	{
		/* プレイヤーの邪魔にならにような位置に調整する */
		int adjX = 40;
		int adjY = 20 + (14 * i);
		if (i % 6 == 0 || i >= 6)
		{
			adjX += 40 * (i / 6);
			adjY -= 84 * (i / 6);
		}

		ary->Draw(adjX, adjY, fh_msg);
		i++;
	}

	/* 任意の座標のメッセージ */
	for(const auto &ary : mMsg2)
		ary->Draw(ary->x + x, ary->y + y, fh_msg);
}


void EventMessage::SendMsg(std::string msg)
{
	// メッセージ生成
	mMsg.emplace_back( new Message(msg) );

	/* 今生成したイベントメッセージのセッティング */
	mMsg.at(mMsg.size() - 1)->x = 60;
	mMsg.at(mMsg.size() - 1)->y = 40 + (mMsg.size() * 14);
	mMsg.at(mMsg.size() - 1)->color = White;
}


void EventMessage::SendMsg(int x, int y, unsigned int ColorCode, std::string msg)
{
	// メッセージ生成
	mMsg2.emplace_back(new Message(msg));

	/* 今生成したイベントメッセージのセッティング */
	mMsg2.at(mMsg2.size() - 1)->x = x;
	mMsg2.at(mMsg2.size() - 1)->y = y;
	mMsg2.at(mMsg2.size() - 1)->color = ColorCode;
}


template<class T>
void EventMessage::Delete(std::vector<T>& vec, T var)
{
	// eraseだけでは安全ではないためremoveを使用
	vec.erase(std::remove(std::begin(vec), std::end(vec), var), std::end(vec));
}



/*-----------------------------------------------
メッセージ
-----------------------------------------------*/
EventMessage::Message::Message(std::string msg)
{
	time = 0;
	counter = 256;	//>> 透過値は0～255までであるため256
	this->msg = msg;
	isAlive = true;
}


void EventMessage::Message::Update()
{
	time += 1;							// 経過時間
	counter -= ChangeSpeed;				// 段々透過

	counter = std::max(counter, 0U);	// 下限で停止
	if (time > ShowTime)				// 表示時間を過ぎると
		isAlive = false;				// 存在抹消
}


void EventMessage::Message::Draw(const int & FontHandle)
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, counter);
	DrawFormatStringToHandle(x, y, color, FontHandle, msg.c_str());
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}


void EventMessage::Message::Draw(int x, int y, const int& FontHandle)
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, counter);
	DrawFormatStringToHandle(x, y, color, FontHandle, msg.c_str());
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
