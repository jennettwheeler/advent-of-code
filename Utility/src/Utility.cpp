#include <Utility.h>

namespace aoc2021
{
  std::vector<std::string> SplitString(const std::string& s, const char delim)
  {
      std::vector<std::string> output;
      std::string temp = "";
      for(int i=0;i<s.length();++i)
      {
          if(s[i]==delim)
          {
              if (temp.size() > 0)
              {
                  output.push_back(temp);
                  temp = "";
              }
          }
          else
          {
              temp.push_back(s[i]);
          }
      }
      output.push_back(temp);
      return output;
  }

  std::vector<int> SplitStringToInt(const std::string& s, const char delim)
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
  
  std::pair<std::string, std::string> SplitStringToPair(const std::string& input, const std::string& delimiter)
  {
      std::pair<std::string, std::string> result;
      int split_pos = input.find(delimiter);
      result.first = input.substr(0, split_pos);
      result.second = input.substr(split_pos + delimiter.size());
      return result;
  }
}
