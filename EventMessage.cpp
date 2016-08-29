#include "Include\EventMessage.hpp"
#include <DxLib.h>
#include <algorithm>
#include <cassert>
#undef max
#undef min


static unsigned int const White = GetColor(255, 255, 255);


/*-----------------------------------------------
�C�x���g���b�Z�[�W�Ǘ�
-----------------------------------------------*/
EventMessage::EventMessage()
{
	mMsg.reserve(100);  // �z�񐔂�\��
	mMsg2.reserve(100); // ����
	fh_msg = LoadFontDataToHandle("Resource/FontData.dft", 1);
	assert(fh_msg != -1 && "EventMessage::EventMessage()");

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
	/* ����̃��b�Z�[�W */
	for (auto &&ary : mMsg)
	{
		ary->Update();

		if (ary->GetIsAlive() == false)
		{
			Delete(mMsg, ary);
			break;
		}
	}

	/* �C�ӂ̍��W�̃��b�Z�[�W */
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
	/* ����̃��b�Z�[�W */
	int i = 0; // �z��̓Y����
	for(const auto &ary : mMsg)
	{
		/* �v���C���[�̎ז��ɂȂ�ɂ悤�Ȉʒu�ɒ������� */
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

	/* �C�ӂ̍��W�̃��b�Z�[�W */
	for(const auto &ary : mMsg2)
		ary->Draw(ary->x + x, ary->y + y, fh_msg);
}


void EventMessage::SendMsg(std::string msg)
{
	// ���b�Z�[�W����
	mMsg.emplace_back( new Message(msg) );

	/* �����������C�x���g���b�Z�[�W�̃Z�b�e�B���O */
	mMsg.at(mMsg.size() - 1)->x = 60;
	mMsg.at(mMsg.size() - 1)->y = 40 + (mMsg.size() * 14);
	mMsg.at(mMsg.size() - 1)->color = White;
}


void EventMessage::SendMsg(int x, int y, unsigned int ColorCode, std::string msg)
{
	// ���b�Z�[�W����
	mMsg2.emplace_back(new Message(msg));

	/* �����������C�x���g���b�Z�[�W�̃Z�b�e�B���O */
	mMsg2.at(mMsg2.size() - 1)->x = x;
	mMsg2.at(mMsg2.size() - 1)->y = y;
	mMsg2.at(mMsg2.size() - 1)->color = ColorCode;
}


template<class T>
void EventMessage::Delete(std::vector<T>& vec, T var)
{
	// erase�����ł͈��S�ł͂Ȃ�����remove���g�p
	vec.erase(std::remove(std::begin(vec), std::end(vec), var), std::end(vec));
}



/*-----------------------------------------------
���b�Z�[�W
-----------------------------------------------*/
EventMessage::Message::Message(std::string msg)
{
	time = 0;
	counter = 256;	//>> ���ߒl��0�`255�܂łł��邽��256
	this->msg = msg;
	isAlive = true;
}


void EventMessage::Message::Update()
{
	time += 1;							// �o�ߎ���
	counter -= ChangeSpeed;				// �i�X����

	counter = std::max(counter, 0U);	// �����Œ�~
	if (time > ShowTime)				// �\�����Ԃ��߂����
		isAlive = false;				// ���ݖ���
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