#include "Include\ZakoEnemyTask.hpp"

/* Zakoes */
#include "Include\ZakoSample.hpp"
#include "Include\Zako1.hpp"

#include <cassert>


ZakoEnemyTask::ZakoEnemyTask(eZako type)
{
	switch (type)
	{
	case eZako::Sample:	mZako = (ZakoEnemy*)(new ZakoSample);	break;
	case eZako::Zako1:	mZako = (ZakoEnemy*)(new Zako1);		break;
	default:	assert("ZakoEnemyTask::ZakoEnemyTask()");
	}
}