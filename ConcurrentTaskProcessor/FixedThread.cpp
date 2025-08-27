#include "FixedThread.h"






std::mutex mtx;


void FixedThread::add(int a)
{
	std::lock_guard<std::mutex> lock(mtx);
	fixedVictim += a;
}


void FixedThread::subtract(int b)
{
	std::lock_guard<std::mutex> lock(mtx);
	fixedVictim -= b;
}



void FixedThread::divide(int c)
{
	std::lock_guard<std::mutex> lock(mtx);
	fixedVictim /= c;
}



