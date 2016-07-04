#ifndef DEF_CHARACTER_HPP
#define DEF_CHARACTER_HPP


#include "CharaTask.hpp"
#include <memory>


class Character
{
public:
	Character(CharaTask* chara);
	~Character();
	void Update();
	void Draw();

private:
	void Initialize();
	void Finalize();

	std::unique_ptr<CharaTask> mCharaTask;
};


#endif