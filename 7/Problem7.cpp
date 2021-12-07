#include <Problem7.h>
#include <Utility.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>

namespace aoc2021
{
    void Problem7::Init(int partNum)
    {
        m_partNum = partNum;
    }

    void Problem7::ParseLine(std::string line)
    {
        nums = SplitStringToInt(line, ',');
    }

    long long Problem7::Calculate()
    {
        int min = *std::min_element(nums.begin(), nums.end());
        int max = *std::max_element(nums.begin(), nums.end());
        int minFuelCost = std::numeric_limits<int>::max();
        for (int pos = min; pos <= max; pos++)
        {
            int fuelCost = 0;
            for (int num : nums)
            {
                int dst = std::abs(num - pos);
                fuelCost += (m_partNum == 1 ? dst : dst * (dst + 1) / 2);
            }
            if (fuelCost < minFuelCost) minFuelCost = fuelCost;
        }
        return minFuelCost;
    }
}