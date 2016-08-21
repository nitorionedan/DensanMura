#include "Include\EventMessage.hpp"
#include <DxLib.h>
#include <algorithm>
#undef max
#undef min

unsigned int const EventMessage::Message::White = GetColor(255, 255, 255);

/*-----------------------------------------------
イベントメッセージ管理
-----------------------------------------------*/
EventMessage::EventMessage()
{
	fh_msg = LoadFontDataToHandle("Resource/FontData.dft", 1);
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
	if (mMsg.empty())	return;

	for (auto itr : mMsg)
	{
		itr->Update();

		if (itr->GetIsAlive() == false)
		{
			mMsg.erase(std::remove(std::begin(mMsg), std::end(mMsg), itr), std::end(mMsg));
			break;
		}
	}
}


void EventMessage::Draw()
{
	if (mMsg.empty())	return;

	int i = 0;
	for (auto itr = std::begin(mMsg); itr != std::end(mMsg); itr++)
	{
		/* プレイヤーの邪魔にならにような位置に調整する */
		int x, y;
		x = 40;
		y = 20 + (14 * i);
		if (i % 6 == 0 || i >= 6)
		{
			x += 40 * (i / 6);
			y -= 84 * (i / 6);
		}

		(*itr)->Draw(x, y, fh_msg);
		i++;
	}
}


void EventMessage::SendMsg(std::string msg)
{
	mMsg.emplace(std::end(mMsg), new Message(msg));

	mMsg[mMsg.size() - 1]->x = 60;
	mMsg[mMsg.size() - 1]->y = 40 + (mMsg.size() * 14);
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
	DrawFormatStringToHandle(this->x, this->y, White, FontHandle, msg.c_str());
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}


void EventMessage::Message::Draw(int x, int y, const int& FontHandle)
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, counter);
	DrawFormatStringToHandle(x, y, White, FontHandle, msg.c_str());
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
