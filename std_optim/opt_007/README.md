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

### References
- [cppreference](https://en.cppreference.com/w/cpp/container/vector/emplace_back)
- [stackoverflow](https://stackoverflow.com/questions/4303513/push-back-vs-emplace-back)
