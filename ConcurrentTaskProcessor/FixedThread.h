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

	FixedThread(int threads);

	void createWorkersByAddFunction();

	std::atomic<int> fixedVictim{0};

	int threads = 0;

	void add();

	void subtract(int b);

	void divide(int c);

};

