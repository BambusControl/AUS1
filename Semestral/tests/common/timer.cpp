#include "Timer.h"

Timer::Timer() :
	startTime(), stopTime(), totalSum(0)
{}

void Timer::start()
{
	startTime = hrc::now();
}

duration Timer::timeSpan(Time from, Time to)
{
	return ch::duration_cast<duration>(to - from);
}

double Timer::stop()
{
	stopTime = hrc::now();
	double count = timeSpan(startTime, stopTime).count();
	totalSum += count;
	return count;
}

void Timer::reset()
{
	startTime = Time();
	stopTime = Time();
	totalSum = 0;
}

double Timer::getTotalSum()
{
	return totalSum;
}

std::string Timer::getTimeUnit()
{
	return "microsecond";
	//return "millisecond";
}
