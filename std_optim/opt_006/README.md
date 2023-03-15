## `constexpr` (since C++11) and `consteval` (since C++20)

### Short introduce
The constexpr specifier declares that it is possible to evaluate the value of the function or variable at compile time. Such variables and functions can then be used where only compile time constant expressions are allowed (provided that appropriate function arguments are given).

The consteval specifies that a function is an immediate function, that is, every call to the function must produce a compile-time constant

### Why we should use `constexpr`?
To improve performance of programs by doing computations in compile time rather than run time.  
Note that, `const` variables will be calculated in run time, opposting `constexpr`.

## Why we have `consteval`?
It declares immediate functions, that is, functions that must be evaluated at compile time to produce a constant. (It used to be spelled `constexpr!` in a previous revision of the paper.) In contrast, `constexpr` functions **may be evaluated at compile time or run time**, and need not produce a constant in all cases.

### Run with bazel
```bash
bazel run //std_optim/opt_006:exec
```

### References
- [cppreference](https://en.cppreference.com/w/cpp/language/constexpr)
- [geeksforgeeks](https://www.geeksforgeeks.org/understanding-constexper-specifier-in-cpp/)
- [stackoverflow - what is consteval?](https://stackoverflow.com/a/53347377)
