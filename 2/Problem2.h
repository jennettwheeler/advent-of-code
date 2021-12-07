#include <IProblem.h>

#include <vector>

namespace aoc2021
{
class Problem2 : public IProblem
{
public:
    void Init(int partNum);
    void ParseLine(std::string line);
    long long Calculate();

private:
    int m_partNum = 1;
    int m_horizontal = 0;
    int m_vertical = 0;
    int m_depth = 0;
};
}