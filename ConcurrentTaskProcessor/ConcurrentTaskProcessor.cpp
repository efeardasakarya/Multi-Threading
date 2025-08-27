// ConcurrentTaskProcessor.cpp : This file contains the 'main' function. Program execution begins and ends there.0
//Headers
#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <mutex>
#include <atomic>
#include <chrono>
#include <queue>
#include <condition_variable>
#include <functional>
#include <sstream>
#include <map>

#include "CorruptedThread.h"
#include "FixedThread.h"

//Variables
std::atomic<bool> running{ true };
int threadIndex = 0;
std::queue < std::function<void()> > tasks;
std::mutex ioMutex;
std::mutex qMutex;
std::mutex idMutex;
std::condition_variable cv;
std::map <std::thread::id, std::string > idList;


void registerThread(std::thread::id id, const  std::string& name)
{
	std::lock_guard<std::mutex> idLock(idMutex);
	idList.emplace(id, name);

}

void appendNumbers(int a, int b)
{
	std::lock_guard<std::mutex> lock(ioMutex);
	std::cout << std::to_string(a) + std::to_string(b) << " -> Append worked. Worker name -> " << idList.at(std::this_thread::get_id()) << std::endl;
}

void addNumbers(int a, int b)
{
	std::lock_guard<std::mutex> lock(ioMutex);
	std::cout << a + b << " -> Add worked. Worker name ->" << idList.at(std::this_thread::get_id()) << std::endl;
}

void printReverse(std::string text)
{
	std::lock_guard<std::mutex> lock(ioMutex);
	for (int i = static_cast<int>(text.size()) - 1; i >= 0; i--)
	{
		std::cout << text[i];

	}
	std::cout << " -> Reverse worked. Worker name -> " << idList.at(std::this_thread::get_id()) << std::endl;
}

void producer()
{

	while (running)
	{
		{
			std::lock_guard<std::mutex> lk(qMutex);

			switch (threadIndex % 3)
			{
			case 0:
				tasks.emplace([=] { appendNumbers(threadIndex + 1, threadIndex); });    // [=] -> that operator catch the threadIndex in thah moment. So when the function call later dont take																				// wrong value
				break;
			case 1:
				tasks.emplace([=] {addNumbers(threadIndex + 1, threadIndex * 2); });
				break;
			case 2:
				tasks.emplace([] { printReverse("thread has been worked"); });
				break;
			default:
				break;
			}
			threadIndex++;
		}


		cv.notify_one();
		std::this_thread::sleep_for(std::chrono::milliseconds(250));
	}
}

void worker()
{
	while (true)
	{
		std::function<void()> job;
		{
			std::unique_lock<std::mutex> lk(qMutex);
			cv.wait(lk, [] {return !tasks.empty() || !running; });
			if (!running && tasks.empty())
			{
				return;
			}
			job = std::move(tasks.front());
			tasks.pop();
		}
		job();
	}
}



int main()
{
	/*
		std::jthread w1(worker), w2(worker), w3(worker);

		registerThread(w1.get_id(), "w1");
		registerThread(w2.get_id(), "w2");
		registerThread(w3.get_id(), "w3");

		std::jthread p1(producer);


		std::this_thread::sleep_for(std::chrono::seconds(10)); // 10 sn çalıştır

		running = false;
		cv.notify_all();
		*/
	
	
	for (int i = 1 ; i < 25; i++)
	{
		std::cout << "----- Start "<< i <<"count thread with Racing condition and 1 count thread with Safe condition---- - " << '\n';

		CorruptedThread corruptedThread(i);
	
		corruptedThread.createWorkersByAddFunction();

		FixedThread fixedThread(i);

		fixedThread.createWorkersByAddFunction();

		std::cout << "----- End "<< i<<" count thread with Racing condition and 1 count thread with Safe condition ----- " << '\n';
		std::cout << '\n';
	}
	




}

