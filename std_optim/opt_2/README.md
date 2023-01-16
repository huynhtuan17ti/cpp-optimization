## `noexcept` operator (since C++11)

### Short introduce
The noexcept operator performs a compile-time check that returns `true` if an expression is declared to not throw any exceptions.

### Why we need `noexcept`?
This operator does not offer better runtime or memory consumption, but it will reduce the cost of implementation and provide clearer coding semantics for developers as well.

### Run with bazel
```bash
bazel run //std_optim/opt_2:exec
```

### Experiment
```bash
Is may_throw() noexcept? false
Is no_throw() noexcept? true
```

### References
- [cppreference](https://en.cppreference.com/w/cpp/language/noexcept)
- [stackoverflow dicussion](https://stackoverflow.com/questions/10787766/when-should-i-really-use-noexcept)