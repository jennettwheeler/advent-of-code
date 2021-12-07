#include <register_problems.h>

#include <ProblemRunner.h>

#include <Problem1.h>

namespace aoc2021
{
    void RegisterProblems()
    {
        ProblemRunner::RegisterProblem<Problem1>("1");
    }
}