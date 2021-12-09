#include <IProblem.h>

#include <string>
#include <set>
#include <vector>

namespace aoc2021
{
class Problem9 : public IProblem
{
    class Point
    {
        public:
            Point(int x, int y, int height);
            int GetRisk(const std::vector<std::vector<Point>>& map);
            int GetBasin(const std::vector<std::vector<Point>>& map);
            bool operator==(const Point &other)
            {
                return x_ == other.x_ && y_ == other.y_;
            }
            bool operator<(const Point &other) const
            {
                return y_ < other.y_ || y_ == other.y_ && x_ < other.x_;
            }
        private:
            bool IsLow(const std::vector<std::vector<Point>>& map);
            void NonNine(const std::vector<std::vector<Point>>& map, std::set<Point>& output, bool checkVertical);
            int x_, y_, height_;
    };
public:
    void Init(int partNum);
    void ParseLine(std::string line);
    long long Calculate();

private:
    int m_partNum = 1;
    std::vector<std::vector<Point>> map;
};
}