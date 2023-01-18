## Avoiding duplication in `const` and `non-const` member functions

### Overview
For example, you have a class named `TextBlock`, you have to implement both of `const` and `non-const` versions. Each of member functions, you have to copy and paste respective code, this will create a duplicate issue in your code. This programming method will resolve this problem.

### Run with bazel
```bash
bazel run //ext_optim/opt_002:exec
```

### Experiment
```bash
[*] TextBlockV1 object
Before operation: t
After operation: T
[*] TextBlockV2 object
Before operation: t
After operation: T
```

### References
- Effective C++ 3rd Edition (page 23).
- [static_cast cppreference](https://en.cppreference.com/w/cpp/language/static_cast)
- [const_cast cppreference](https://en.cppreference.com/w/cpp/language/const_cast)