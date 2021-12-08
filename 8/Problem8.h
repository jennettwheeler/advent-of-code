#include <IProblem.h>

#include <string>
#include <array>
#include <vector>

namespace aoc2021
{
class Problem8 : public IProblem
{
    struct Display
    {
        public:
            Display(std::string notes);
            int Count(int digit);
            int Calculate();

        private:
            std::array<std::string, 14> all_patterns_;
            std::array<std::string, 4> digits_;
            int count1s = 0;
            int count4s = 0;
            int count7s = 0;
            int count8s = 0;
            std::string zero, one, two, three, four, five, six, seven, eight, nine;
            int value = 0;

            bool CalculateValue();
            int PatternToInt(std::string pattern);
    };

public:
    void Init(int partNum);
    void ParseLine(std::string line);
    long long Calculate();

private:
    int m_partNum = 1;
    std::vector<Display> displays;
};
}