#include <IProblem.h>

#include <string>
#include <vector>
#include <optional>
#include <memory>

namespace aoc2021
{
class Problem6 : public IProblem
{
public:
    void Init(int partNum);
    void ParseLine(std::string line);
    long long Calculate();

private:
    int m_partNum = 1;
    long long timerCounts[7];
    long long newFishes[2];
};
}