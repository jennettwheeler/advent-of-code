#include <IProblem.h>

#include <string>
#include <array>
#include <vector>

namespace aoc2021
{
class Problem5 : public IProblem
{
    class Grid
    {
        public:
            Grid(int width, int height);
            void Add(int x, int y);
            int GetDanger();

        private:
            std::vector<std::vector<int>> grid;
    };
    class Line
    {
        public:
            Line(int x1, int y1, int x2, int y2);
            bool IsHorizontal();
            bool IsVertical();
            bool IsDiagonal();
            void Cover(Grid& grid, bool allowDiag = false);

        private:
            int x1_, y1_, x2_, y2_, lowerX, upperX, lowerY, upperY;
    };
public:
    void Init(int partNum);
    void ParseLine(std::string line);
    long long Calculate();

private:
    int m_partNum = 1;
    std::vector<Line> lines;
    int maxX = 0;
    int maxY = 0;
};
}