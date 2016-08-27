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
	inline void Update(const Player& player) {
		mZako->Update(player);
	}
	inline void Draw() {
		mZako->Draw();
	}
	inline Vector2D& GetPos() const {
		return mZako->GetPos();
	}

private:
	ZakoEnemy* mZako;
};