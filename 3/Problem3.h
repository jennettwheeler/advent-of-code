#include <IProblem.h>

#include <vector>

namespace aoc2021
{
class Problem3 : public IProblem
{
public:
    void Init(int partNum);
    void ParseLine(std::string line);
    long long Calculate();

private:
    std::pair<std::string, std::string> CommonBits(std::vector<std::string> lines);
    std::string FilterByBits(bool byCommon, std::vector<std::string> lines, int currentBit = 0);

    int m_partNum = 1;
    std::vector<std::string> lines;
};
}