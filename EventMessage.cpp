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
	fh_msg = LoadFontDataToHandle("Resource/FontData.dft", 1);
	assert(fh_msg != -1);

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
	for (auto ary : mMsg)
	{
		ary->Update();

		if (ary->GetIsAlive() == false)
		{
			Delete(mMsg, ary);
			break;
		}
	}

	/* 任意の座標のメッセージ */
	for (auto ary : mMsg2)
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
	int i = 0;
	for (auto itr = std::begin(mMsg); itr != std::end(mMsg); itr++)
	{
		/* プレイヤーの邪魔にならにような位置に調整する */
		int adjX, adjY;
		adjX = 40;
		adjY = 20 + (14 * i);
		if (i % 6 == 0 || i >= 6)
		{
			adjX += 40 * (i / 6);
			adjY -= 84 * (i / 6);
		}

		(*itr)->Draw(adjX, adjY, fh_msg);
		i++;
	}

	/* 任意の座標のメッセージ */
	for(auto itr = std::begin(mMsg2); itr != std::end(mMsg2); itr++)
	{
		(*itr)->Draw((*itr)->x + x, (*itr)->y + y, fh_msg);
	}
}


void EventMessage::SendMsg(std::string msg)
{
	mMsg.emplace(std::end(mMsg), new Message(msg));

	// 今生成したイベントメッセージのセッティング
	mMsg[mMsg.size() - 1]->x = 60;
	mMsg[mMsg.size() - 1]->y = 40 + (mMsg.size() * 14);
	mMsg[mMsg.size() - 1]->color = White;
}


void EventMessage::SendMsg(int x, int y, unsigned int ColorCode, std::string msg)
{
	mMsg2.emplace(std::end(mMsg2), new Message(msg));

	// 今生成したイベントメッセージのセッティング
	mMsg2[mMsg2.size() - 1]->x = x;
	mMsg2[mMsg2.size() - 1]->y = y;
	mMsg2[mMsg2.size() - 1]->color = ColorCode;
}


template<class T, class U>
void EventMessage::Delete(std::vector<T>& vec, U val)
{
	vec.erase(std::remove(std::begin(vec), std::end(vec), val), std::end(vec));
}



/*-----------------------------------------------
メッセージ
-----------------------------------------------*/
EventMessage::Message::Message(std::string msg)
{
	time = 0;
	counter = 256;
	this->msg = msg;
	isAlive = true;
}


void EventMessage::Message::Update()
{
	time += 1;
	counter -= ChangeSpeed;

	counter = std::max(counter, 0U);
	if (time > ShowTime)	isAlive = false;
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
