#include "FixedThread.h"
#include <chrono>
#include <iostream>





FixedThread::FixedThread(int threads)
{
	this->threads = threads;
}

void FixedThread::createWorkersByAddFunction()
{

	auto start = std::chrono::high_resolution_clock::now();

	

	
	for ( iterator=0; iterator < threads ; iterator++ )
	{
		
		workers.emplace_back([&] { add();  });
		

	}
	std::cout << "Start" << iterator << "count thread with Safe Condition" << '\n';
	std::cout << '\n';

	for (auto& w : workers)
	{
		if (w.joinable())
		{
			w.join();
		}

	}
	workers.clear();


	auto end = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	

	std::cout << fixedVictim << '\n';
	std::cout << '\n';

	std::cout << "End "<< iterator << "count thread with Safe Condition. End in " << double(duration.count()) / 1000.0 << " second" << '\n';
	std::cout << '\n';
}

void FixedThread::add()
{
	std::scoped_lock<std::mutex> lock(mtx);
	for (int i = 0; i < 1000000; i++)
	{
		fixedVictim++;
	}

}





