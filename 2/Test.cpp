#include <Problem2.h>
#include <ProblemRunner.h>

#include <iostream>
#include <filesystem>
#include <string>
namespace fs = std::filesystem;

std::string problemNum = "2";

int main(int argc, char *argv[]){
    if (argc < 2) {
        std::cerr << "Must supply the root dir of input files" << std::endl;
        return EXIT_FAILURE;
    }
    const fs::path root_dir(argv[1]);
    const fs::path example_file("example.txt");
    const fs::path example_path = root_dir/example_file;
    const fs::path input_file("input.txt");
    const fs::path input_path = root_dir/input_file;

    aoc2021::ProblemRunner::RegisterProblem<aoc2021::Problem2>(problemNum);
    if (aoc2021::ProblemRunner::Run(problemNum, example_path.u8string()))
    {
        if (aoc2021::ProblemRunner::GetResult(1) != 150) return EXIT_FAILURE;
        if (aoc2021::ProblemRunner::GetResult(2) != 900) return EXIT_FAILURE;

        if (aoc2021::ProblemRunner::Run(problemNum, input_path.u8string()))
        {
            if (aoc2021::ProblemRunner::GetResult(1) != 1698735) return EXIT_FAILURE;
            if (aoc2021::ProblemRunner::GetResult(2) != 1594785890) return EXIT_FAILURE;
            return EXIT_SUCCESS;
        }
    }

    return EXIT_FAILURE;
}