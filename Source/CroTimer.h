#ifndef CROTIMER_H
#define CROTIMER_H
/*
 * © 2024 CronoGames. All rights reserved.
 * Basic header files i use in most files
 */

#include <chrono>

class CroTimer
{
private:
    std::chrono::steady_clock::time_point last;
public:
    CroTimer() noexcept;
    float Mark() noexcept;
	float Peek() const noexcept;
};

#endif