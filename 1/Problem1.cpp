#include <Problem1.h>

namespace aoc2021
{
    void Problem1::Init(int partNum)
    {
        windowSize = partNum == 1 ? 1 : 3;
        nums.clear();
    }

    void Problem1::ParseLine(std::string line)
    {
        nums.push_back(std::stoi(line));
    }

    long long Problem1::Calculate()
    {
        int count = 0;
        std::deque<int> window;
        int prevSum = 0;
        for (int value : nums)
        {
            window.push_back(value);

            if (window.size() > windowSize)
            {
                window.pop_front();

                int new_sum = SumWindow(window);
                if (new_sum > prevSum)
                {
                    count++;
                }
                prevSum = new_sum;
            }
            else
            {
                prevSum = SumWindow(window);
            }
        }
        return count;
    };

    int Problem1::SumWindow(const std::deque<int>& window)
    {
        int sum = 0;
        for (auto &n: window)
            sum += n;
        return sum;
    }
}
