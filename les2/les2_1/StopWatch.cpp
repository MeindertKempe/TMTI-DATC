#include "StopWatch.h"

typedef std::chrono::steady_clock clk;
typedef std::chrono::milliseconds ms;
typedef std::chrono::steady_clock::time_point time_point;

StopWatch::StopWatch() {
	startTime = clk::now();
}

void StopWatch::start() {
	startTime = clk::now();
}

void StopWatch::stop() {
	endTime = clk::now();
}

ms StopWatch::getElapsedTime() {
	return std::chrono::duration_cast<ms>(endTime - startTime);
}

time_point StopWatch::getStartTime() {
	return startTime;
}

time_point StopWatch::getEndTime() {
	return endTime;
}
