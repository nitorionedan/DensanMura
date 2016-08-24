#pragma once
#include "ZakoEnemy.hpp"
#include "Vector2D.hpp"


enum class eZako
{
	Sample,
};


class ZakoEnemyTask
{
public:
	ZakoEnemyTask(eZako type);
	inline ~ZakoEnemyTask(){
		delete mZako;
	}
	inline void Update() {
		mZako->Update();
	}
	inline void Draw() {
		mZako->Draw();
	}
	inline Vector2D& GetPos() {
		return mZako->GetPos();
	}

private:
	ZakoEnemy* mZako;
};