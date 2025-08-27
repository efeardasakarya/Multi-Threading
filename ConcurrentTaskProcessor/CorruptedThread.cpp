#include "CorruptedThread.h"
#include <chrono>
#include <iostream>
#include <latch>


CorruptedThread::CorruptedThread(int threads)
{
	this->threads = threads;
}

void CorruptedThread::createWorkersByAddFunction()
{

	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < threads; i++)
	{

		workers.emplace_back([&] { add();  });

	}

	
	for (auto& w : workers) 
	{
		if (w.joinable() )
		{
			w.join();
		}
		
	}
	workers.clear();


	auto end = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	std::cout << "Workers created and destroyed in corrupted " << double(duration.count()) / 1000.0 << " second" << '\n';


	std::cout <<  victim << '\n';

}

void CorruptedThread::add()
{
	for (int i = 0; i < 1000000; i++)
	{
		victim++;
	}

}

