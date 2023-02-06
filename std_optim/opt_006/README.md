## `constexpr` specifier (since C++11)

### Short introduce
The constexpr specifier declares that it is possible to evaluate the value of the function or variable at compile time. Such variables and functions can then be used where only compile time constant expressions are allowed (provided that appropriate function arguments are given).

### Why we should use `constexpr`?
To improve performance of programs by doing computations in compile time rather than run time.  
Note that, `const` variables will be calculated in run time, opposting `constexpr`.

### Run with bazel
```bash
bazel run //std_optim/opt_006:exec
```

### References
- [cppreference](https://en.cppreference.com/w/cpp/language/constexpr)
- [geeksforgeeks](https://www.geeksforgeeks.org/understanding-constexper-specifier-in-cpp/)
