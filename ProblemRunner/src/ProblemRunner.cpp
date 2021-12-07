#include <IProblem.h>
#include <ProblemRunner.h>

#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

namespace aoc2021
{
  ProblemRunner::ProblemRunner()
  {
  }

  bool ProblemRunner::Run(const std::string& identifier, const std::string& input_path)
  {
    IProblem* problem = instance().problems_[identifier].get();

    if (problem == nullptr)
    {
      std::cerr << "Could not find problem: " << identifier << std::endl;
      return false;
    }

    std::cout << "Solving for: " << input_path << std::endl;
    for (int partNum = 1; partNum <= 2; partNum++)
    {

      auto t_start = std::chrono::high_resolution_clock::now();
      problem->Init(partNum);

      std::fstream newfile;
      newfile.open(input_path, std::ios::in);
      if (newfile.is_open())
      {
        std::string line;
        while(std::getline(newfile, line))
        {
          problem->ParseLine(line);
        }
        newfile.close();
      }
      else
      {
        std::cerr << "Could not open file: " << input_path << std::endl;
        return false;
      }
      long long result = problem->Calculate();
      auto t_end = std::chrono::high_resolution_clock::now();

      if (partNum == 1)
      {
        instance().part1Result = result;
      }
      else
      {
        instance().part2Result = result;
      }
      std::cout << "Problem " << identifier << " Pt" << partNum << " in " << std::chrono::duration<double, std::milli>(t_end-t_start).count() << "ms\t=\t" << result << std::endl;
    }
    return true;
  }
  long long ProblemRunner::GetResult(int partNum)
  {
    if (partNum == 1)
    {
      return instance().part1Result;
    }
    else
    {
      return instance().part2Result;
    }
  }

  ProblemRunner& ProblemRunner::instance()
  {
    static ProblemRunner instance;
    return instance;
  }
}
