#pragma once
#include <mutex>
#include <condition_variable>


class CorruptedThread
{
public:

	CorruptedThread(int threads);

	int victim = 0;

	int threads = 0;

	void add();


	void subtract(int b);




	void divide(int c);
	


};

