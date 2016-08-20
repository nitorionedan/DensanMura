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
	fh_msg = LoadFontDataToHandle("FontData.dft", 1);
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
		(*itr)->Draw(60, 40 + (10 * i), fh_msg);
		i++;
	}
}


void EventMessage::SendMsg(std::string msg)
{
	mMsg.emplace(std::end(mMsg), new Message(msg));
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


void EventMessage::Message::Draw(int x, int y, const int& FontHandle)
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, counter);
	DrawFormatStringToHandle(x, y, White, FontHandle, msg.c_str());
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
