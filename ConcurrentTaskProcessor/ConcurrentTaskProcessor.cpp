
#include "CorruptedThread.h"
#include "FixedThread.h"

//Variables

int main()
{
	
	for (int i = 1 ; i < 25; i++)
	{
		std::cout << "----- Start "<< i <<"count thread with Racing condition and 1 count thread with Safe condition---- - " << '\n';

		CorruptedThread corruptedThread(i);  // Create corrupted object and add 'increment' function i times
	
		corruptedThread.createWorkersByAddFunction();

		FixedThread fixedThread(i);			//Create fixed object and add 'increment' function i times

		fixedThread.createWorkersByAddFunction();

		std::cout << "----- End "<< i<<" count thread with Racing condition and 1 count thread with Safe condition ----- " << '\n';
		std::cout << '\n';
	}
	
}

