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
		void Draw(const int& FontHandle);
		void Draw(int x, int y, const int& FontHandle);
		inline bool GetIsAlive() {
			return isAlive;
		}
		int x, y;				// 座標
		unsigned int color;

	private:
		unsigned int const ChangeSpeed = 1U;
		int const ShowTime = 180;

		std::string msg;
		int time;				// 経過時間
		unsigned int counter;	// 透過カウンター
		bool isAlive;			// 生きているかどうか 
	};

public:
	EventMessage();
	~EventMessage();
	void Update();
	void Draw(int x, int y);
	void SendMsg(std::string msg);
	void SendMsg(int x, int y, unsigned int ColorCode, std::string msg);

private:
	void Initialize();
	template<class T, class U>
	void Delete(std::vector<T>& vec, U val);
	
	int fh_msg;
	std::vector<std::shared_ptr<Message>> mMsg;
	std::vector<std::shared_ptr<Message>> mMsg2;
};