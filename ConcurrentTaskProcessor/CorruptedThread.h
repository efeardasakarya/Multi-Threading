#pragma once
#include <mutex>
#include <condition_variable>


class CorruptedThread
{
public:

	int victim = 0;


	void add(int a);


	void subtract(int b);




	void divide(int c);
	


};

