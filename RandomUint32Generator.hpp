#pragma once

#include <random>
#include <chrono>

class RandomUint32Generator
{
public:
    void RandomizeGenerator();
    uint32_t GenerateRandomInRange(uint32_t,uint32_t);
private:
    std::default_random_engine rand_generator;
};
