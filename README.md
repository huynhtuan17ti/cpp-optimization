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
| [opt_004](std_optim/opt_004)  | `static_cast` conversion          | [README](std_optim/opt_004/README.md) |
| [opt_005](std_optim/opt_005)  | `move` function                   | [README](std_optim/opt_005/README.md) |
| [opt_006](std_optim/opt_006)	| `constexpr` specifier				| [README](std_optim/opt_006/README.md) |
| [opt_007](std_optim/opt_007)	| `emplace_back` in vector			| [README](std_optim/opt_007/README.md)	|
| [opt_008](std_optim/opt_008)  | `string_view`                     | [README](std_optim/opt_008/README.md) |
| [opt_009](std_optim/opt_009)  | `thread`                          | [README](std_optim/opt_009/README.md) |

### 2. External optimzation
In this secton, it is a collection of several techniques or methods that I've read on books, papers or on my own experiments.

| Id.                           | Title                                                                                | Note    |
| ------                        | ------                                                                               | ------  |
| [opt_001](ext_optim/opt_001)  | Explicitly disallow the use of compiler-generated <br /> functions you do not want   | [README](ext_optim/opt_001/README.md) |
| [opt_002](ext_optim/opt_002)  | Avoiding duplication in `const` and `non-const` <br /> member functions              | [README](ext_optim/opt_002/README.md) |
| [opt_003](ext_optim/opt_003)  | Advantage of cache coherency                                                         | [README](ext_optim/opt_003/README.md) |
| [opt_004](ext_optim/opt_004)  | Data structure alignment                                                             | [README](ext_optim/opt_004/README.md) |
| [opt_005](ext_optim/opt_005)	| SIMD (single instruction, multiple data)											   | [README](ext_optim/opt_005/README.md) |

## Useful documentation
- [Effective Modern C++](docs/Effective_Modern_C__.pdf)
- [Effective C++ 3rd Edition](docs/Effective%20C++%203rd%20ed.pdf)  
