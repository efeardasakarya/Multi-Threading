#pragma once
#include <mutex>
#include <condition_variable>
#include <vector>


class CorruptedThread
{
public:

	CorruptedThread(int threads);

	void createWorkersByAddFunction();

	int victim = 0;

	int threads = 0;

	void add();


	void subtract(int b);

	std::vector<std::jthread> workers;


	void divide(int c);
	


};

