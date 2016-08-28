#pragma once
#include "ZakoEnemy.hpp"
#include "Vector2D.hpp"


enum class eZako
{
	Sample,
	Zako1,
	Zako2,
	Ika,
	Tako,
};


class ZakoEnemyTask
{
public:
	ZakoEnemyTask(eZako type);
	~ZakoEnemyTask();
	void Update(const Player& player);
	void Draw();
	const Vector2D& GetPos() const;

private:
	ZakoEnemy* mZako;
};


// Inline--------------------------------------------------------
inline 	ZakoEnemyTask::~ZakoEnemyTask() {
	delete mZako;
}


inline void ZakoEnemyTask::Update(const Player& player) {
	mZako->Update(player);
}


inline void ZakoEnemyTask::Draw(){
	mZako->Draw();
}


inline const Vector2D& ZakoEnemyTask::GetPos() const {
	return mZako->GetPos();
}