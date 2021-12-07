#include <Problem5.h>
#include <Utility.h>

#include <iostream>

namespace aoc2021
{
    void Problem5::Init(int partNum)
    {
        m_partNum = partNum;
        maxX = 0;
        maxY = 0;
        lines.clear();
    }

    Problem5::Grid::Grid(int width, int height)
    {
        for (int y=0; y <= height; y++)
        {
            std::vector<int> row;
            for (int x=0; x <= width; x++)
            {
                row.push_back(0);
            }
            grid.push_back(row);
        }
    }
    

    void Problem5::Grid::Add(int x, int y)
    {
        grid[y][x]++;
    }

    int Problem5::Grid::GetDanger()
    {
        int dangerCount = 0;
        for (int y=0; y < grid.size(); y++)
        {
            for (int x=0; x < grid[y].size(); x++)
            {
                if (grid[y][x] >= 2)
                {
                    dangerCount++;
                }
            }
        }
        return dangerCount;
    }

    Problem5::Line::Line(int x1, int y1, int x2, int y2)
        : x1_(x1), y1_(y1), x2_(x2), y2_(y2)
    {
        lowerX = x1_ < x2_ ? x1_ : x2_;
        upperX = x1_ > x2_ ? x1_ : x2_;
        lowerY = y1_ < y2_ ? y1_ : y2_;
        upperY = y1_ > y2_ ? y1_ : y2_;
}

    bool Problem5::Line::IsHorizontal()
    {
        return (y1_ == y2_);
    }
    
    bool Problem5::Line::IsVertical()
    {
        return (x1_ == x2_);
    }

    bool Problem5::Line::IsDiagonal()
    {
        return std::abs(x1_ - x2_) == std::abs(y1_ - y2_);
    }
    
    void Problem5::Line::Cover(Grid& grid, bool allowDiag)
    {
        if (IsHorizontal())
        {
            for (int x = lowerX; x <= upperX; x++)
            {
                grid.Add(x, y1_);
            }
        }
        else if (IsVertical())
        {
            for (int y = lowerY; y <= upperY; y++)
            {
                grid.Add(x1_, y);
            }
        }
        else if (allowDiag && IsDiagonal())
        {
            int x = lowerX;
            bool upAcross = (x1_ < x2_ && y1_ < y2_) || (x1_ > x2_ && y1_ > y2_);
            int y = upAcross ? lowerY : upperY;

            while (x <= upperX)
            {
                grid.Add(x, y);
                x++;
                y += upAcross ? 1 : -1;
            }
        }
    }
    
    void Problem5::ParseLine(std::string line)
    {
        auto coords = SplitStringToPair(line, " -> ");

        auto coord1 = SplitStringToPair(coords.first, ",");
        int x1 = std::stoi(coord1.first);
        int y1 = std::stoi(coord1.second);

        auto coord2 = SplitStringToPair(coords.second, ",");
        int x2 = std::stoi(coord2.first);
        int y2 = std::stoi(coord2.second);
        
        if (x1 > maxX) maxX = x1;
        if (x2 > maxX) maxX = x2;
        if (y1 > maxY) maxY = y1;
        if (y2 > maxY) maxY = y2;

        lines.push_back(Line(x1, y1, x2, y2));
    }

    long long Problem5::Calculate()
    {
        std::vector<Line> filteredLines;
        for (Line line : lines)
        {
            if (line.IsHorizontal() || line.IsVertical() || (m_partNum != 1 && line.IsDiagonal()))
            {
                filteredLines.push_back(line);
            }
        }

        Grid grid(maxX, maxY);
        for (Line line : filteredLines)
        {
            line.Cover(grid, m_partNum != 1);
        }
        return grid.GetDanger();;
    }
}