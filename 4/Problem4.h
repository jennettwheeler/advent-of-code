#include <IProblem.h>

#include <string>
#include <vector>

namespace aoc2021
{
class Problem4 : public IProblem
{
    static std::vector<int> SplitStringToInt(const std::string& s, const char delim = ' ');
    class BingoBoard
    {
        public:
            BingoBoard(std::vector<int> numbers, std::vector<std::string>& board);
            int WinsIn();
            int Score();

        private:
            int winsIn_ = 1;
            int winningNum_ = 0;
            int board_[5][5];
            bool hasWon();
    };
public:
    void Init(int partNum);
    void ParseLine(std::string line);
    long long Calculate();

private:
    int m_partNum = 1;
    std::vector<int> nums;
    std::vector<std::string> temp;
    std::vector<BingoBoard> boards;
};

}
