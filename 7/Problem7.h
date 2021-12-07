#include <IProblem.h>

#include <string>
#include <vector>
#include <optional>
#include <memory>

namespace aoc2021
{
class Problem7 : public IProblem
{
public:
    void Init(int partNum);
    void ParseLine(std::string line);
    long long Calculate();

private:
    int m_partNum = 1;
    std::vector<int> nums;
};
}