#include <Problem2.h>

namespace aoc2021
{
    void Problem2::Init(int partNum)
    {
        m_partNum = partNum;
        m_horizontal = 0;
        m_vertical = 0;
        m_depth = 0;
    }
    void Problem2::ParseLine(std::string line)
    {
        if (line[0] == 'f') {
            int value = std::stoi(line.substr(7));
            m_horizontal += value;
            m_depth += m_vertical * value;
        }
        else if (line[0] == 'd') {
            m_vertical += std::stoi(line.substr(4));
        }
        else if (line[0] == 'u') {
            m_vertical -= std::stoi(line.substr(2));
        }
    }
    long long Problem2::Calculate()
    {
        if (m_partNum == 1)
        {
            return m_horizontal * m_vertical;
        }
        else if (m_partNum == 2)
        {
            return m_horizontal * m_depth;
        }
        return 0;
    }
}
