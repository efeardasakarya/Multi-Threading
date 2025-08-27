#pragma once
#include <mutex>
#include <vector>
#include <thread>
#include <atomic>

class FixedThread
{

public:

	std::mutex mtx;

	std::vector<std::jthread> workers;

	int threads = 0;

	std::atomic<int> fixedVictim{ 0 };

	FixedThread(int threads);

	int iterator = 1;

	void createWorkersByAddFunction();

	void add();

	

};

