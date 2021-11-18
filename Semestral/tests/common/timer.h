#pragma once
#include <chrono>

namespace ch = std::chrono;
using hrc = ch::high_resolution_clock;
//using duration = ch::duration<double, std::milli>;
using duration = ch::duration<double, std::micro>;
using Time = hrc::time_point;

class Timer
{

public:

	Timer();

	void start();

	static duration timeSpan(Time from, Time to);

	double stop();

	void reset();

	double getTotalSum();

	std::string getTimeUnit();

private:

	Time startTime;
	Time stopTime;
	double totalSum;

};