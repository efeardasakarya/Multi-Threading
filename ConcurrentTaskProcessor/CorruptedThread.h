#pragma once
#include <mutex>
#include <condition_variable>
#include <vector>
#include <chrono>
#include <iostream>



class CorruptedThread
{
public:

	int victim = 0;

	int threads = 0;

	std::vector<std::jthread> workers;

	CorruptedThread(int threads);  //CONSTRUCTOR

	void createWorkersByAddFunction();

	void add();

};

