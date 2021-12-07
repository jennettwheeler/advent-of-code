#include <IProblem.h>
#include <deque>
#include <vector>

namespace aoc2021
{
class Problem1 : public IProblem
{
public:
    void Init(int partNum);
    void ParseLine(std::string line);
    long long Calculate();

private:
    int windowSize = 1;
    std::vector<int> nums;

    int SumWindow(const std::deque<int>& window);
};
}
