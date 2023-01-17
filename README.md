# CPP Optimization
This repository is a collection of everything relating to the topic "Optimization in C/C++" that I'm researching.

## Note
- All codes of this project can be run with [bazel](https://bazel.build/) (A powerful compile tool developed by Google).
- Some of codes must be compiled with `C++20`.

## Overview
In this repo, I split the topic into 2 smaller topics:  
1. A collection of standard provided functions or attributes to optimize cpp code.
2. A collection of valuable methods/techniques from several docs to optimize cpp code.

### 1. Standard optimization
In this section, I note all provided functions/attributes from the C++ standard libraries that can offer better runtime and more cache-friendly.

| No.                       | Name                              | Note    |
| ------                    | ------                            | ------  |
| [opt_1](std_optim/opt_1)  | `likely`, `unlikely` attributes   | [README](std_optim/opt_1/README.md) |
| [opt_2](std_optim/opt_2)  | `noexecpt` operator               | [README](std_optim/opt_2/README.md) |
| [opt_3](std_optim/opt_3)  | `variant` class template          | [README](std_optim/opt_3/README.md) |

### 2. External optimzation
In this secton, it is a collection of several techniques or methods that I've read on books, papers or on my own experiments.

## Useful documentation
- [Effective Modern C++](docs/Effective_Modern_C__.pdf)
- [Effective C++ 3rd Edition](docs/Effective%20C++%203rd%20ed.pdf)  