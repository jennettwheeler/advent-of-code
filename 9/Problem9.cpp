#include <Problem9.h>

#include <iostream>
#include <array>
#include <algorithm>

namespace aoc2021
{
    Problem9::Point::Point(int x, int y, int height) : x_(x), y_(y), height_(height)
    {
    }

    bool Problem9::Point::IsLow(const std::vector<std::vector<Point>>& map)
    {
        bool lower_than_up = y_ == 0 || height_ < map[y_ - 1][x_].height_;
        bool lower_than_down = y_ == map.size() - 1 || height_ < map[y_ + 1][x_].height_;
        bool lower_than_left = x_ == 0 || height_ < map[y_][x_ - 1].height_;
        bool lower_than_right = x_ == map[y_].size() - 1 || height_ < map[y_][x_ + 1].height_;

        return lower_than_up && lower_than_down && lower_than_left && lower_than_right;
    }

    int Problem9::Point::GetRisk(const std::vector<std::vector<Point>>& map)
    {
        if (IsLow(map))
        {
            return height_ + 1;
        }
        return 0;
    }


    void Problem9::Point::NonNine(const std::vector<std::vector<Point>>& map, std::set<Point>& output, bool checkVertical)
    {
        // std::set<Point> newPoints;
        // int sizeBefore = output.size();
        if (checkVertical)
        {
            int checkY = y_ - 1;

            while (checkY >= 0)
            {
                auto point = map[checkY][x_];
                if (point.height_ == 9 || output.find(point) != output.end())
                    break;
                output.insert(point);
                point.NonNine(map, output, !checkVertical);
                checkY--;
            }
            checkY = y_ + 1;
            while (checkY < map.size())
            {
                auto point = map[checkY][x_];
                if (point.height_ == 9 || output.find(point) != output.end())
                    break;
                output.insert(point);
                point.NonNine(map, output, !checkVertical);
                checkY++;
            }
        }
        else
        {
            int checkX = x_ - 1;

            while (checkX >= 0)
            {
                auto point = map[y_][checkX];
                if (point.height_ == 9 || output.find(point) != output.end())
                    break;
                output.insert(point);
                point.NonNine(map, output, !checkVertical);
                checkX--;
            }
            checkX = x_ + 1;
            while (checkX < map[y_].size())
            {
                auto point = map[y_][checkX];
                if (point.height_ == 9 || output.find(point) != output.end())
                    break;
                output.insert(point);
                point.NonNine(map, output, !checkVertical);
                checkX++;
            }
        }
    }

    int Problem9::Point::GetBasin(const std::vector<std::vector<Problem9::Point>>& map)
    {
        if (IsLow(map))
        {
            std::set<Point> points;
            NonNine(map, points, true);
            NonNine(map, points, false);
            return points.size();
        }
        return 0;
        
    }

    void Problem9::Init(int partNum)
    {
        m_partNum = partNum;
        map.clear();
    }

    void Problem9::ParseLine(std::string line)
    {
        int y = map.size();
        int x = 0;
        std::vector<Point> row;
        for (char height : line)
        {
            row.push_back(Point(x, y, (int)height - 48));
            x++;
        }
        map.push_back(row);
        y++;
    }

    long long Problem9::Calculate()
    {
        if (m_partNum == 1)
        {
            int result = 0;
            for (auto row : map)
            {
                for (Point point : row)
                {
                    result += point.GetRisk(map);
                }
            }
            return result;
        }
        else
        {
            int first = 0;
            int second = 0;
            int third = 0;
            for (auto row : map)
            {
                for (Point point : row)
                {
                    int basin = point.GetBasin(map);
                    if (basin > 0)
                    {
                        if (basin > first)
                        {
                            third = second;
                            second = first;
                            first = basin;
                        }
                        else if (basin > second)
                        {
                            third = second;
                            second = basin;
                        }
                        else if (basin > third)
                        {
                            third = basin;
                        }
                    }
                }
            }
            return first * second * third;
        }
    }
}