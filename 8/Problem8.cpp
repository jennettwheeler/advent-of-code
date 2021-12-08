#include <Problem8.h>

#include <Utility.h>
#include <algorithm>
#include <iostream>

namespace aoc2021
{

    Problem8::Display::Display(std::string notes) 
    {
        auto notePair = SplitStringToPair(notes, " | ");
        
        auto patterns = SplitString(notePair.first, ' '); 
        for (int i=0; i < patterns.size(); i++)
        {
            std::sort(patterns[i].begin(), patterns[i].end());
            all_patterns_[i] = patterns[i];
        }

        auto digits = SplitString(notePair.second, ' ');
        for (int i=0; i < digits.size(); i++)
        {
            std::sort(digits[i].begin(), digits[i].end());
            digits_[i] = digits[i];
            all_patterns_[i+10] = digits[i];
            int size = digits_[i].size();
            if (size == 2) count1s++;
            else if (size == 4) count4s++;
            else if (size == 3) count7s++;
            else if (size == 7) count8s++;
        }
    }
    
    int Problem8::Display::Count(int digit)
    {
        if (digit == 1) return count1s;
        if (digit == 4) return count4s;
        if (digit == 7) return count7s;
        if (digit == 8) return count8s;
        return 0;
    }

    int Problem8::Display::PatternToInt(std::string pattern)
    {
        if (pattern == zero) return 0;
        if (pattern == one) return 1;
        if (pattern == two) return 2;
        if (pattern == three) return 3;
        if (pattern == four) return 4;
        if (pattern == five) return 5;
        if (pattern == six) return 6;
        if (pattern == seven) return 7;
        if (pattern == eight) return 8;
        if (pattern == nine) return 9;

        return -1;
    }

    bool Problem8::Display::CalculateValue()
    {
        int multiplier = 1000;
        int newValue = 0;
        for (std::string pattern : digits_)
        {
            int digit = PatternToInt(pattern);
            if (digit < 0)
            {
                return false;
            }
            newValue += digit * multiplier;
            multiplier /= 10;
        }
        value = newValue;
        return true;
    }

    
    int Problem8::Display::Calculate()
    {
        std::vector<std::string> unknownPatterns(all_patterns_.begin(), all_patterns_.end());
        for (std::vector<std::string>::iterator it=unknownPatterns.begin(); it!=unknownPatterns.end(); )
        {
            std::string pattern = *it;
            int size = pattern.size();
            if (size == 2)
            {
                one = pattern;
            }
            else if (size == 4)
            {
                four = pattern;
            }
            else if (size == 3)
            {
                seven = pattern;
            }
            else if (size == 7)
            {
                eight = pattern;
            }
            else
            {
                ++it;
                continue;
            }
            it = unknownPatterns.erase(it);
        }
        if (CalculateValue()) return value;

        if (one.size() == 0) return -1;
        for (std::vector<std::string>::iterator it=unknownPatterns.begin(); it!=unknownPatterns.end(); )
        {
            std::string pattern = *it;
            int count_without_one = pattern.size();
            for (char ch : one)
            {
                if (pattern.find(ch) != std::string::npos)
                {
                    count_without_one--;
                }
            }
            if (pattern.size() == 5 && count_without_one == 3)
            {
                three = pattern;
                it = unknownPatterns.erase(it);
                continue;
            }
            if (pattern.size() == 6 && count_without_one == 5)
            {
                six = pattern;
                it = unknownPatterns.erase(it);
                continue;
            }
            ++it;
        }
        if (CalculateValue()) return value;

        if (four.size() == 0) return -1;
        for (std::vector<std::string>::iterator it=unknownPatterns.begin(); it!=unknownPatterns.end(); )
        {
            std::string pattern = *it;
            int count_without_four = pattern.size();
            for (char ch : four)
            {
                if (pattern.find(ch) != std::string::npos)
                {
                    count_without_four--;
                }
            }
            if (pattern.size() == 5 && count_without_four == 3)
            {
                two = pattern;
                it = unknownPatterns.erase(it);
                continue;
            }
            if (pattern.size() == 6 && count_without_four == 2)
            {
                nine = pattern;
                it = unknownPatterns.erase(it);
                continue;
            }
            ++it;
        }
        if (CalculateValue()) return value;

        for (std::vector<std::string>::iterator it=unknownPatterns.begin(); it!=unknownPatterns.end(); )
        {
            std::string pattern = *it;
            int count_without_four = 0;
            if (pattern.size() == 5)
            {
                five = pattern;
                it = unknownPatterns.erase(it);
                continue;
            }
            if (pattern.size() == 6)
            {
                zero = pattern;
                it = unknownPatterns.erase(it);
                continue;
            }
            ++it;
        }
        if (CalculateValue()) return value;

        return -1;
    }
    
    void Problem8::Init(int partNum)
    {
        m_partNum = partNum;
        displays.clear();
    }

    void Problem8::ParseLine(std::string line)
    {
        displays.push_back(Display(line));
    }

    long long Problem8::Calculate()
    {
        long long count = 0;
        for (Display display : displays)
        {
            if (m_partNum == 1)
            {
                count += display.Count(1);
                count += display.Count(4);
                count += display.Count(7);
                count += display.Count(8);
            }
            else 
            {
                int displayValue = display.Calculate();
                if (displayValue > 0) 
                {
                    count += display.Calculate();
                }
                else
                {
                    std::cerr << "Returned negative number" << std::endl;
                    return -1;
                }
            }
        }
        return count;
    }
}