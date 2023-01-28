## `move` (since C++14 or C++11)

### Short introduce
`std::move` is used to indicate that an object t may be "moved from", i.e. allowing the efficient transfer of resources from t to another object.

### Why we should use `std::move`?
[stackoverflow answer](https://stackoverflow.com/a/27026280)

### Run with bazel
```bash
bazel run //std_optim/opt_005:exec
```

### Experiment
```bash
Time: 74225577 nanosecs swap with std::move
Time: 85519997 nanosecs normal swap
```
### References
- [cppreference](https://en.cppreference.com/w/cpp/utility/move)
- [stackoverflow](https://stackoverflow.com/questions/3413470/what-is-stdmove-and-when-should-it-be-used)