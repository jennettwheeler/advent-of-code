#include <Problem3.h>

#include <iostream>
#include <sstream>
#include <algorithm>

namespace aoc2021
{
    void Problem3::Init(int partNum)
    {
        m_partNum = partNum;
        lines.clear();
    }

    void Problem3::ParseLine(std::string line)
    {
        lines.push_back(line);
    }

    std::pair<std::string, std::string> Problem3::CommonBits(std::vector<std::string> lines)
    {
        std::vector<int> bitCounts;
        for (std::string line : lines)
        {
            while (bitCounts.size() < line.length())
            {
                bitCounts.push_back(0);
            }
            for (int i = 0; i < bitCounts.size(); i++)
            {
                bitCounts[i] += line[i] == '1' ? 1 : 0;
            }
        }

        int halfSize = lines.size() / 2 + lines.size() % 2;
        std::stringstream common, uncommon;
        for (int i = 0; i < bitCounts.size(); i++)
        {
            if (bitCounts[i] >= halfSize)
            {
                common << "1";
                uncommon << "0";
            }
            else
            {
                common << "0";
                uncommon << "1";
            }
        }
        return std::pair<std::string, std::string>{common.str(), uncommon.str()};
    }

    std::string Problem3::FilterByBits(bool byCommon, std::vector<std::string> lines, int currentBit)
    {
        auto commonBits = CommonBits(lines);
        std::string filterBits = byCommon ? commonBits.first : commonBits.second;

        auto filter = [currentBit, filterBits](std::string const &line)
        {
            return line[currentBit] != filterBits[currentBit];
        };
        lines.erase(std::remove_if(lines.begin(), lines.end(), filter), lines.end());

        if (lines.size() > 1)
        {
            return FilterByBits(byCommon, lines, currentBit + 1);
        }
        return lines[0];
    }

    long long Problem3::Calculate()
    {
        if (m_partNum == 1)
        {
            auto commonBits = CommonBits(lines);
            int gammaRate = std::stoi(commonBits.first, nullptr, 2);
            int epsilonRate = std::stoi(commonBits.second, nullptr, 2);
            return gammaRate * epsilonRate;
        }
        else {
            std::vector<std::string> oxygenLines(lines);
            std::vector<std::string> co2Lines(lines);
            int oxygen = std::stoi(FilterByBits(true, oxygenLines), nullptr, 2);
            int co2 = std::stoi(FilterByBits(false, co2Lines), nullptr, 2);
            return oxygen * co2;
        }
    }
}