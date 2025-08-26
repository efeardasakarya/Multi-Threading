#include "CorruptedThread.h"




	int victim = 0;
	std::mutex mtx;


	void CorruptedThread::add(int a)
	{
		std::lock_guard<std::mutex> lock(mtx);
		victim +=a;
	}


	void CorruptedThread::subtract(int b)
	{
		std::lock_guard<std::mutex> lock(mtx);
		victim -=b;
	}



	void CorruptedThread::divide(int c)
	{
		std::lock_guard<std::mutex> lock(mtx);
		victim /= c;
	}



