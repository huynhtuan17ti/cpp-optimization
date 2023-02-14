## `thread` (since C++17)

### Short introduce
`std::thread` is a class to represent individual threads of execution. By using multithreading, we can speed up our program systematically.

### Run with bazel
```bash
# to run multithreading program
bazel run //std_optim/opt_009:multi_exec
# to run single-thread program
bazel run //std_optim/opt_009:single_exec
```

### Experiment
```bash
Time: 31950112 nanosecs (multithreading)
Time: 83823357 nanosecs (single thread)
```

### References
- [cppreference](https://en.cppreference.com/w/cpp/thread/thread)
- [educative.io article](https://www.educative.io/blog/modern-multithreading-and-concurrency-in-cpp)
