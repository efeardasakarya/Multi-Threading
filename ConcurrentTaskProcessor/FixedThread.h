#pragma once
#include <mutex>

class FixedThread
{

public:

	int fixedVictim = 0;

	void add(int a);

	void subtract(int b);

	void divide(int c);

};

