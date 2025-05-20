#pragma once
#include <chrono>

class Timer {
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime, endTime;

public:
    void start() {
        startTime = std::chrono::high_resolution_clock::now();
    }

    void stop() {
        endTime = std::chrono::high_resolution_clock::now();
    }

    double elapsedSeconds() {
        return std::chrono::duration<double>(endTime - startTime).count();
    }
};
