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

| Id.                           | Title                             | Note    |
| ------                        | ------                            | ------  |
| [opt_001](std_optim/opt_001)  | `likely`, `unlikely` attributes   | [README](std_optim/opt_001/README.md) |
| [opt_002](std_optim/opt_002)  | `noexecpt` operator               | [README](std_optim/opt_002/README.md) |
| [opt_003](std_optim/opt_003)  | `variant` class template          | [README](std_optim/opt_003/README.md) |

### 2. External optimzation
In this secton, it is a collection of several techniques or methods that I've read on books, papers or on my own experiments.

| Id.                           | Title                                                                                | Note    |
| ------                        | ------                                                                               | ------  |
| [opt_001](ext_optim/opt_001)  | Explicitly disallow the use of compiler-generated <br /> functions you do not want   | [README](ext_optim/opt_001/README.md) |
| [opt_002](ext_optim/opt_002)  | Avoiding duplication in `const` and `non-const` <br /> member functions              | [README](ext_optim/opt_002/README.md) |

## Useful documentation
- [Effective Modern C++](docs/Effective_Modern_C__.pdf)
- [Effective C++ 3rd Edition](docs/Effective%20C++%203rd%20ed.pdf)  