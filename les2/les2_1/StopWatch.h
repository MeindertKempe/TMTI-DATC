#ifndef STOP_WATCH_H
#define STOP_WATCH_H
#pragma once

#include <chrono>

class StopWatch {
private:
	std::chrono::steady_clock::time_point startTime, endTime;

public:
	StopWatch();
	void start();
	void stop();
	std::chrono::milliseconds getElapsedTime();
	std::chrono::steady_clock::time_point getStartTime();
	std::chrono::steady_clock::time_point getEndTime();
};

#endif /* STOP_WATCH_H */
