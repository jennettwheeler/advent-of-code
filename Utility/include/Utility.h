#pragma once

#include <string>
#include <vector>

namespace aoc2021
{
  std::vector<std::string> SplitString(const std::string& s, const char delim = ' ');
  std::vector<int> SplitStringToInt(const std::string& s, const char delim = ' ');
  std::pair<std::string, std::string> SplitStringToPair(const std::string& input, const std::string& delimiter);
}