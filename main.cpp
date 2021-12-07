#include <ProblemRunner.h>
#include <IProblem.h>
#include <register_problems.h>
#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

int main(int argc, char *argv[]){
    if (argc < 2) {
        std::cerr << "Must supply the input file" << std::endl;
        return EXIT_FAILURE;
    }
    const fs::path root_dir(argv[1]);

    if (argc < 3) {
        std::cerr << "Must supply an day [1-25]" << std::endl;
        return EXIT_FAILURE;
    }
    const std::string problem_num = argv[2];
    const fs::path problem_input(argv[2]);

    aoc2021::RegisterProblems();
    
    if (aoc2021::ProblemRunner::Run(problem_num, problem_input.u8string()))
    {
        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}
