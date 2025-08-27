#include "CorruptedThread.h"
#include <chrono>
#include <iostream>


CorruptedThread::CorruptedThread(int threads)
{
	this->threads = threads;
}

void CorruptedThread::createWorkersByAddFunction()
{
	//Corrupted
	; // start before thread creating

	for (int i = 0; i < threads; i++)
	{
		
		workers.emplace_back([&] { add(); });
				
	}

	std::cout << victim << '\n';

}



void CorruptedThread::add()
{
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 1000000; i++)
	{
		victim++;
	}
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::cout << "Worker created " << double(duration.count()) / 1000.0 << " milisecond" << '\n' ;
}


void CorruptedThread::subtract(int b)
{

	victim -= b;
}



void CorruptedThread::divide(int c)
{

	victim /= c;
}



