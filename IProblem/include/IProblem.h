#pragma once

#include <string>

namespace aoc2021
{
  class IProblem
  {
  public:
    virtual ~IProblem() = default;

    virtual void Init(int partNum) = 0;
    virtual void ParseLine(std::string line) = 0;
    virtual long long Calculate() = 0;
  };
}
