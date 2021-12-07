#include <IProblem.h>

#include <string>

namespace aoc2021
{
class Problem23 : public IProblem
{
public:
    void Init(int partNum);
    void ParseLine(std::string line);
    long long Calculate();

private:
    int m_partNum = 1;
};
}