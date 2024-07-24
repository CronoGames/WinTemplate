/*
 * © 2024 CronoGames. All rights reserved.
 * Basic header files i use in most files
 */

#include "CroTimer.h"

using namespace std::chrono;

CroTimer::CroTimer() noexcept
{
    last = steady_clock::now();
}

float CroTimer::Mark() noexcept
{
	const auto old = last;
	last = steady_clock::now();
	const duration<float> frameTime = last - old;
	return frameTime.count();
}

float CroTimer::Peek() const noexcept
{
	return duration<float>( steady_clock::now() - last ).count();
}