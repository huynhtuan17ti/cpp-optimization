## `emplace_back` in vector (since C++11)

### Short introduce
Inserts a new element at the end of the vector, right after its current last element. This new element is constructed in place using args as the arguments for its constructor.

### What is the difference between `push_back` and `emplace_back`?
- While performing `push_back`, the object is copied and moved into the container.
- Same as `push_back`, `emplace_back` is still inserting an object but the variadic arguments will be forwarded into the constructor of appended item.

### Run with bazel
```bash
bazel run //std_optim/opt_007:exec
```

### Experiments
```bash
Run #1:
Time: 478120444 nanosecs (push_back)
Time: 475256712 nanosecs (emplace_back)
Run #2:
Time: 486174944 nanosecs (push_back)
Time: 477987985 nanosecs (emplace_back)
Run #3:
Time: 483941625 nanosecs (push_back)
Time: 471608414 nanosecs (emplace_back)
Run #4:
Time: 492727997 nanosecs (push_back)
Time: 480036037 nanosecs (emplace_back)
Run #5:
Time: 501338600 nanosecs (push_back)
Time: 479169342 nanosecs (emplace_back)
```

### References
- [cppreference](https://en.cppreference.com/w/cpp/container/vector/emplace_back)
- [stackoverflow](https://stackoverflow.com/questions/4303513/push-back-vs-emplace-back)
