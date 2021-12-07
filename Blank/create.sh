#!/bin/bash

num=${1:?Error! Missing Problem Number}

blank_dir="$(readlink -f "$(dirname "${BASH_SOURCE:-$0}")")"
root_dir="$(readlink -f "$(dirname "${blank_dir}")")"
this_script="$(basename "${BASH_SOURCE:-$0}")"

new_dir="${root_dir}/${num}"
if [[ -d "${new_dir}" ]]; then
    echo "Directory already exists" >&2
    exit 1
fi

cp -R ${blank_dir} ${new_dir}
rm "${new_dir}/${this_script}"

mv "${new_dir}/Problem0.h" "${new_dir}/Problem${num}.h"
mv "${new_dir}/Problem0.cpp" "${new_dir}/Problem${num}.cpp"

sed -i "s/set[(]PROBLEM_NUM 0[)]/set(PROBLEM_NUM ${num})/" "${new_dir}/CMakeLists.txt"
sed -i "s/Problem0/Problem${num}/" "${new_dir}/Problem${num}.h"
sed -i "s/Problem0/Problem${num}/" "${new_dir}/Problem${num}.cpp"
sed -i "s/Problem0/Problem${num}/" "${new_dir}/Test.cpp"
sed -i "s/std[:][:]string problemNum = \"0\"[;]/std::string problemNum = \"${num}\";/" "${new_dir}/Test.cpp"

last_add_dir_line=$(grep -n "add_subdirectory([0-9]*).*$" "${root_dir}/CMakeLists.txt" | tail -1 | cut -f1 -d':')
sed -i "${last_add_dir_line}a add_subdirectory(${num})" "${root_dir}/CMakeLists.txt"
