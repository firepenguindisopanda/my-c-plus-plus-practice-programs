# my-c-plus-plus-practice-programs

This Repository contains programs I have written in the c++ to gain a better understanding in using the language.

## First Folder HistogramOfNumbers

This folder contains a single histogram.cpp file and a single numbers.txt file. The program opens reads the data from the numbers.txt file and certain evaluations based on the data.

![Demonstration for HistogramOfNumbers](https://github.com/firepenguindisopanda/my-c-plus-plus-practice-programs/blob/main/readme_assets/histogram-output.gif)

---

## Configuration in tasks.json for args

```json
"args": [
    "-fdiagnostics-color=always",
    "-g",
    "-ggdb",
    "-O2",
    "-DNDEBUG",
    "-pedantic-errors",
    "-Wall",
    "-Weffc++",
    "-Wextra",
    "-Wsign-conversion",
    "-Werror",
    "-std=c++17",
    "${file}",
    "-o",
    "${fileDirname}\\${fileBasenameNoExtension}.exe"
],
```
