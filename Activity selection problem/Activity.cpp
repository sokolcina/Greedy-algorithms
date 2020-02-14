#include "Activity.h"






Activity::~Activity()
{
}


int Activity::getStart()
{
	
	return start;
}


int Activity::getFinish()
{
	
	return finish;
}


void Activity::setStart(int s)
{
	start = s;
}


void Activity::setFinish(int f)
{
	finish= f;
}
