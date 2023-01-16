## `likely` and `unlikely` (since C++20)

### Short introduce
Allow the compiler to optimize for the case where paths of execution including that statement are more or less likely than any alternative path of execution that does not include such a statement.

### Run with bazel
```bash
bazel run //std_optim/opt_1:exec
```

### Experiment
```bash
Result: 501846
Time: 88.0000000000 nanosecs (without attributes)
Result: 501846
Time: 29.0000000000 nanosecs (with attributes)
```
### References
- [cppreference](https://en.cppreference.com/w/cpp/language/attributes/likely)