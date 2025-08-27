#include "CorruptedThread.h"


CorruptedThread::CorruptedThread(int threads)
{
	this->threads = threads;
}

	



	void CorruptedThread::add()
	{
		for (int i = 0; i < 1000000; i++)
		{
			victim++;
		}
		
	}


	void CorruptedThread::subtract(int b)
	{
		
		victim -=b;
	}



	void CorruptedThread::divide(int c)
	{
	
		victim /= c;
	}



