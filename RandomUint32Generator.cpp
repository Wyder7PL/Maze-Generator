#include "RandomUint32Generator.hpp"

void RandomUint32Generator::RandomizeGenerator()
{
    uint32_t seed = std::chrono::system_clock::now().time_since_epoch().count();
    rand_generator.seed(seed);
}


uint32_t RandomUint32Generator::GenerateRandomInRange(uint32_t rangestart,uint32_t rangeend)
{
    std::uniform_int_distribution<uint32_t> distribution(rangestart,rangeend);
    return distribution(rand_generator);
}
