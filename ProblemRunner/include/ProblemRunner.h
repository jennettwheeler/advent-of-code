#pragma once

#include <memory>
#include <string>
#include <unordered_map>

namespace aoc2021
{
  class IProblem;

  class ProblemRunner
  {
  public:
    static bool Run(const std::string& identifier, const std::string& input_path);

    template <typename T>
    static void RegisterProblem(const std::string& identifier)
    {
      static_assert(std::is_base_of<IProblem, T>::value);
      instance().problems_.emplace(identifier, std::make_unique<T>());
    };

    static long long GetResult(int partNum);

    ProblemRunner(const ProblemRunner&) = delete;
    ProblemRunner& operator=(const ProblemRunner&) = delete;

  private:
    long long part1Result = 0;
    long long part2Result = 0;
    ProblemRunner();
    std::unordered_map<std::string, std::unique_ptr<IProblem>> problems_;

    static ProblemRunner& instance();
  };
}