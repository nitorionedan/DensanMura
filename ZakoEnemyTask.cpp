#include "Include/ZakoEnemyTask.hpp"
#include "Include/ZakoSample.hpp"
#include <cassert>

ZakoEnemyTask::ZakoEnemyTask(eZako type)
{
	switch (type)
	{
	case eZako::Sample:
		mZako = (ZakoEnemy*)(new ZakoSample);
		break;

	default:
		assert("ZakoEnemyTask::ZakoEnemyTask()");
	}
}