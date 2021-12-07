#include <Problem4.h>

namespace aoc2021
{
    std::vector<int> Problem4::SplitStringToInt(const std::string& s, const char delim)
    {
        std::vector<int> output;
        std::string temp = "";
        for(int i=0;i<s.length();++i)
        {
            if(s[i]==delim)
            {
                if (temp.size() > 0)
                {
                    output.push_back(std::stoi(temp));
                    temp = "";
                }
            }
            else
            {
                temp.push_back(s[i]);
            }
        }
        output.push_back(std::stoi(temp));
        return output;
    }

    Problem4::BingoBoard::BingoBoard(std::vector<int> numbers, std::vector<std::string>& board)
    {
        int y = 0;
        for (std::string line : board)
        {
            int x = 0;
            for (int val : SplitStringToInt(line))
            {
                board_[y][x] = val;
                x++;
            }
            y++;
        }
        for (int num : numbers)
        {
            for (int x=0; x<5; x++)
            {
                for (int y=0; y<5; y++)
                {
                    if (board_[y][x] == num)
                    {
                        board_[y][x] = 0;
                    }
                }
            }
            if (hasWon())
            {
                winningNum_ = num;
                break;
            }
            winsIn_++;
        }
    }

    int Problem4::BingoBoard::WinsIn()
    {
        return winsIn_;
    }

    int Problem4::BingoBoard::Score()
    {
        int sum = 0;
        for (int x=0; x<5; x++)
        {
            for (int y=0; y<5; y++)
            {
                sum += board_[y][x];
            }
        }
        return sum * winningNum_;
    }

    bool Problem4::BingoBoard::hasWon()
    {
        for (int x=0; x<5; x++)
        {
            for (int y=0; y<5; y++)
            {
                if (board_[y][x] != 0) break;
                if (y == 4) return true;
            }
        }
        for (int y=0; y<5; y++)
        {
            for (int x=0; x<5; x++)
            {
                if (board_[y][x] != 0) break;
                if (x == 4) return true;
            }
        }
        return false;
    }

    void Problem4::Init(int partNum)
    {
        m_partNum = partNum;
        nums.clear();
        boards.clear();
    }

    void Problem4::ParseLine(std::string line)
    {
        if (nums.size() == 0)
        {
            nums = SplitStringToInt(line, ',');
        }
        
        if (line.size() < 9)
        {
            temp.clear();
            return;
        }

        temp.push_back(line);
        if (temp.size() == 5)
        {
            boards.push_back(BingoBoard(nums, temp));
        }
    }

    long long Problem4::Calculate()
    {
        if (m_partNum == 1)
        {
            auto winner = boards[0];
            for (auto board : boards)
            {
                if (board.WinsIn() < winner.WinsIn())
                {
                    winner = board;
                }
            }
            return winner.Score();
        }
        else {
            auto looser = boards[0];
            for (auto board : boards)
            {
                if (board.WinsIn() > looser.WinsIn())
                {
                    looser = board;
                }
            }
            return looser.Score();
        }
    }
}
