#pragma once

#include <string>
#include <vector>
#include <memory>


class EventMessage 
{
	class Message
	{
	public:
		explicit Message(std::string msg);
		void Update();
		void Draw(int x, int y, const int& FontHandle);
		inline bool GetIsAlive() {
			return isAlive;
		}

	private:
		static unsigned int const White;
		unsigned int const ChangeSpeed = 1U;
		int const ShowTime = 180;

		std::string msg;
		int time;				// 経過時間
		int x, y;				// 座標
		unsigned int counter;	// 透過カウンター
		bool isAlive;			// 生きているかどうか 
	};

public:
	EventMessage();
	~EventMessage();
	void Update();
	void Draw();
	void SendMsg(std::string msg);

private:
	void Initialize();
	
	int fh_msg;
	std::vector<std::shared_ptr<Message>> mMsg;
};