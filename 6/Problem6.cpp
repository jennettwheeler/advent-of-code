#include <Problem6.h>

#include <iostream>

namespace aoc2021
{
    void Problem6::Init(int partNum)
    {
        m_partNum = partNum;
        for (int i=0; i < 7; i++)
        {
            timerCounts[i] = 0;
            if (i < 2) newFishes[i] = 0;
        }
    }

    void Problem6::ParseLine(std::string line)
    {
        while(line.size()){
            int index = line.find(',');
            if(index != std::string::npos)
            {
                timerCounts[std::stoi(line.substr(0, index))]++;
                line = line.substr(index + 1);
                if(line.size() == 0)
                {
                    timerCounts[std::stoi(line)]++;
                }
            }
            else
            {
                timerCounts[std::stoi(line)]++;
                line = "";
            }
        }
    }

    long long Problem6::Calculate()
    {
        int numDays = m_partNum == 1 ? 80 : 256;
        for (int day = 1; day <= numDays; day++)
        {
            long long createdFishes = timerCounts[0];
            auto b = std::begin(timerCounts);
            std::rotate(b, b + 1, std::end(timerCounts));

            timerCounts[6] += newFishes[0];
            newFishes[0] = newFishes[1];
            newFishes[1] = createdFishes;
        }
        long long numFishes = 0;
        for (int i=0; i < 7; i++)
        {
            numFishes += timerCounts[i];
        }
        numFishes += newFishes[0];
        numFishes += newFishes[1];
        return numFishes;
    }
}